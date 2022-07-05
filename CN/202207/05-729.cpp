#include <vector>

using namespace std;



class SegmentTree {
public:
    SegmentTree *left;
    SegmentTree *right;
    int mark;
    int value;

    SegmentTree() {
        left = nullptr;
        right = nullptr;
        mark = 0;
        value = 0;
    }

    ~SegmentTree() {
        delete left;
        delete right;
    }
};

class MyCalendar {
private:
    const int MAXN = 1000000000 + 10;

    SegmentTree *root;

    void update(SegmentTree *node, int start, int end, int left, int right, int value) {
        if(left <= start && right >= end) {
            node->value += (end - start + 1) * value;
            node->mark += value;
            return;
        }

        int mid = (start + end) / 2;
        push_down(node, mid - start + 1, end - mid);
        if(left <= mid) {
            update(node->left, start, mid, left, right, value);
        }
        if(right > mid) {
            update(node->right, mid + 1, end, left, right, value);
        }
        push_up(node);
    }

    void push_down(SegmentTree *node, int left, int right) {
        if(node->left == nullptr) {
            node->left = new SegmentTree();
        }
        if(node->right == nullptr) {
            node->right = new SegmentTree();
        }

        if(node->mark == 0) {
            return;
        }

        node->left->value += (node->mark * left);
        node->right->value += (node->mark * right);

        node->left->mark += node->mark;
        node->right->mark += node->mark;

        node->mark = 0;
    }

    void push_up(SegmentTree *node) {
        node->value = node->left->value + node->right->value;
    }

    int query(SegmentTree *node, int start, int end, int left, int right) {
        if(left <= start && right >= end) {
            return node->value;
        }

        int res = 0;
        int mid = (start + end) / 2;
        push_down(node, mid - start + 1, end - mid);
        if(left <= mid) {
            res += query(node->left, start, mid, left, right);
        }
        if(right > mid) {
            res += query(node->right, mid + 1, end, left, right);
        }

        return res;
    }

public:
    MyCalendar() {
        root = new SegmentTree();
    }

    ~MyCalendar() {
        delete root;
    }
    
    bool book(int start, int end) {
        if(query(root, 0, MAXN, start, end - 1) != 0) {
            return false;
        }

        update(root, 0, MAXN, start, end - 1, 1);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */