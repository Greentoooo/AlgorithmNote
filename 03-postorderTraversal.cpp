/*
 * Leetcode 145 
 * 使用迭代实现的中序遍历
 * 总结：
 *  前序遍历要求父节点在子节点前输出，代码中在push子节点前会先pop父节点
 *  中序遍历要求父节点在左节点后，右节点前输出，代码中先push所有左节点，
 * pop左节点后再pop父节点，之后推入右节点
 *  后序遍历要求父节点在子节点后输出，代码中先推入所有左节点，然后推入右节点，
 * 最后pop时如果pop的节点是左节点，那么就推入该节点的父节点的右节点
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

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    stack<TreeNode *> nodeStack;
    TreeNode *tmp = root;

    while (tmp)
    {
        nodeStack.push(tmp);
        if (tmp->left)
        {
            tmp = tmp->left;
        }
        else
        {
            tmp = tmp->right;
        }
    }

    while (!nodeStack.empty())
    {
        tmp = nodeStack.top();
        nodeStack.pop();
        ans.push_back(tmp->val);

        if (!nodeStack.empty() && tmp == nodeStack.top()->left)
        {
            TreeNode *current = nodeStack.top()->right;
            while (current)
            {
                nodeStack.push(current);
                if (current->left)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
        }
    }
}