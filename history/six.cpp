/*
 * @Author: jiale 
 * @Date: 2021-05-11 10:53:27 
 * @Last Modified by: jiale
 * @Last Modified time: 2021-05-11 14:39:15
 */

// 496. 下一个更大元素 I
// 给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。
// 请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。
// nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。
// 示例 1
// 输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
// 输出: [-1,3,-1]
// 解释:
//     对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
//     对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
//     对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
// 示例 2:
// 输入: nums1 = [2,4], nums2 = [1,2,3,4].
// 输出: [3,-1]
// 解释:
//     对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
//     对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
// 提示：
// 1 <= nums1.length <= nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 104
// nums1和nums2中所有整数 互不相同
// nums1 中的所有整数同样出现在 nums2 中
 
// 进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int count1 = nums1.size();
        for (int i = 0; i < count1; i++)
        {
            int tag = -1;
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            for (; it != nums2.end(); it++)
            {
                if (nums1[i] < *it)
                {
                    tag =*it;
                    break;
                }
            }
            res.push_back(tag);
        }
        return res;
        // for (auto it1 : nums1)
        // {
        //     int tag = -1;
        //     // cout<<it1<<" ";
        //     for (auto it2 : nums2)
        //     {
        //         if (it1 < it2)
        //         {
        //             tag = it2;
        //             break;
        //         }
        //     }
        //     res.push_back(tag);
            
        //     // while (!nums2.empty())
        //     // {
        //     //     cout << *nums2.end()--;
        //     // }
        // }
        for (auto it1 : res)
            cout<<it1<<" ";
        // cout << *nums1.begin() << *nums2.rend();
        return nums1;
    }
    void ShowVec(const vector<int>& valList)
    {
        for_each(valList.cbegin(), valList.cend(), [](const int& val)->void{cout << val << endl; });
    }
};
int main()
{
    // int arr1[3] = {4,1,2}, arr2[4] = {1,3,4,2};
    int arr1[3] = {2,4}, arr2[4] = {1,2,3,4};
    vector<int> nums1(arr1, arr1+2), nums2(arr2, arr2+4);
    Solution *solu = new Solution();
    solu->nextGreaterElement(nums1, nums2);
    return 0;
}