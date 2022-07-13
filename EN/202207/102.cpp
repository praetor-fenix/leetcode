#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> level;
            vector<TreeNode*> next;
            while(!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left != nullptr) {
                    next.push_back(node->left);
                }
                if(node->right != nullptr) {
                    next.push_back(node->right);
                }
            }

            res.push_back(level);
            for(int i = 0; i < next.size(); ++i) {
                q.push(next[i]);
            }
        }

        return res;
    }
};