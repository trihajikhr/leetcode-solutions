#include<iostream>
#include<vector>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> treeA, treeB;
        inorderTraversal(p, treeA);
        inorderTraversal(q, treeB);
        return treeA == treeB;
    }

    void inorderTraversal(TreeNode* root, vector<int>& rest) {
        if (root == nullptr) {
            rest.push_back(INT_MAX);
            return;
        }
        rest.push_back(root->val);
        inorderTraversal(root->left, rest);
        inorderTraversal(root->right, rest);
    }
};

auto main() -> int {
    TreeNode * p = new TreeNode(2);
    p->right = new TreeNode(2);
    p->left = new TreeNode(2);
    p->left->left = new TreeNode(2);
    p->left->left->left = new TreeNode(2);

    TreeNode * q = new TreeNode(2);
    q->right = new TreeNode(2);
    q->right->right = new TreeNode(2);
    q->left = new TreeNode(2);
    q->left->left = new TreeNode(2);

    Solution sol;
    cout << sol.isSameTree(p,q);
    return 0;
}