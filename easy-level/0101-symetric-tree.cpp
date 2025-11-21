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
    bool isSymmetric(TreeNode* root) {
        vector<int> treeA, treeB;
        inorderTraversalLeft(root->left, treeA);
        inorderTraversalRight(root->right, treeB);
        return treeA == treeB;
    }

    void inorderTraversalLeft(TreeNode* root, vector<int>& rest) {
        if (root == nullptr) {
            rest.push_back(999);
            return;
        }
        rest.push_back(root->val);
        inorderTraversalLeft(root->left, rest);
        inorderTraversalLeft(root->right, rest);
    }

    void inorderTraversalRight(TreeNode* root, vector<int>& rest) {
        if (root == nullptr) {
            rest.push_back(999);
            return;
        }
        rest.push_back(root->val);
        inorderTraversalRight(root->right, rest);
        inorderTraversalRight(root->left, rest);
    }
};

auto main() -> int {
    TreeNode * root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right-> = new TreeNode(2);

    Solution sol;
    cout << "\n" << sol.isSymmetric(root);
    return 0;
}