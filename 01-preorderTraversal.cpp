/*
 * Leetcode 144 
 * 使用迭代实现的前序遍历
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

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    stack<TreeNode *> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty())
    {
        TreeNode *tmp = nodeStack.top();
        nodeStack.pop();

        if (tmp->right)
        {
            nodeStack.push(tmp->right);
        }
        if (tmp->left)
        {
            nodeStack.push(tmp->left);
        }
        ans.push_back(tmp->val);
    }
    return ans;
}