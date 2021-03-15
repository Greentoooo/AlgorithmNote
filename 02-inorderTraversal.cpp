/*
 * Leetcode 94 
 * 使用迭代实现的中序遍历
 */
#include <vector>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    stack<TreeNode *> nodeStack;
    nodeStack.push(root);
    while (nodeStack.top()->left)
    {
        nodeStack.push(nodeStack.top()->left);
    }

    while (!nodeStack.empty())
    {
        TreeNode *tmp = nodeStack.top();
        nodeStack.pop();
        ans.push_back(tmp->val);

        if (tmp->right)
        {
            nodeStack.push(tmp->right);
            while (nodeStack.top()->left)
            {
                nodeStack.push(nodeStack.top()->left);
            }
        }
    }
    return ans;
}