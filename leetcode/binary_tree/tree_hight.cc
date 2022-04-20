// https://leetcode-cn.com/problems/balanced-binary-tree/

#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return abs(Height(root->left) - Height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    int Height(TreeNode *root) {
        if (!root) return 0;
        return max(Height(root->left), Height(root->right)) + 1;
    }
};