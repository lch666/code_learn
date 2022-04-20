// https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/

#include <vector>
#include <queue>
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

class Solution
{
public:
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int count = q.size();
            vector<int> vec;
            for (int i = 0; i < count; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                vec.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};