/*
 * Leetcode 46
 * 全排列实现
 * 如果能使排列每次的变化值都是最小，就可以无遗漏地列出所有排列
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    int size = nums.size();
    int left = size - 2;
    int right = size - 1;

    // 必须先排序才能得到全排列
    sort(nums.begin(), nums.end());

    ans.push_back(nums);
    while (1)
    {
        // 从左往右出现递减的瞬间结束循环，注意必须先检查left是否大于等于0
        while (left >= 0 && nums[left] >= nums[left + 1])
        {
            --left;
        }
        // left小于0代表当前排列是递减的
        if (left < 0)
        {
            return ans;
        }
        while (nums[right] <= nums[left] && right > left)
        {
            --right;
        }
        swap(nums[left], nums[right]);
        reverse(nums.begin() + left + 1, nums.end());
        ans.push_back(nums);
        left = size - 2;
        right = size - 1;
    }
    return ans;
}