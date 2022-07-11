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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        vector<int> num;
        vector<TreeNode*> level;

        queue<TreeNode*> q;
        if(root != nullptr) {
            q.push(root);
        }
        
        while(!q.empty()) {
            while(!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                num.push_back(node->val);
                if(node->left != nullptr) {
                    level.push_back(node->left);
                }
                if(node->right != nullptr) {
                    level.push_back(node->right);
                }
            }

            for(int i = 0; i < level.size(); ++i) {
                q.push(level[i]);
            }

            res.push_back(num[num.size() - 1]);
            num.clear();
            level.clear();
        }

        return res;
    }
};