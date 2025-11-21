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
    vector<int> rest;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return rest;
        inorderTraversal(root->left);
        rest.push_back(root->val);
        inorderTraversal(root->right);
        return rest;
    }
};

auto main() -> int {
    TreeNode * root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> rest = sol.inorderTraversal(root);
    for (const auto& x : rest) {
        cout << x << " ";
    }
    return 0;
}