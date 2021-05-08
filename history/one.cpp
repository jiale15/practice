/*
 * @Author: jiale 
 * @Date: 2021-05-07 09:20:41 
 * @Last Modified by: jiale
 * @Last Modified time: 2021-05-07 10:33:57
 */

// 数组异或操作
#include <iostream>
int main()
{
    int start = 0, n;
    // const int n = 5;
    // int nums[n] = {};
    // for (int i = 0; i < n; i++)
    // {
    //     nums[i] = start + 2 * i;
    // }
    
    // 0异或任何数=任何数
    int res = 0; 
    // for(auto i : nums)
    // {
    //     res ^= i;
    // }
    std::cin >> start >> n;
    for (int i = 0; i < n; i++)
    {
        res ^= start + 2 * i;
    }
    
    std::cout << res << std::endl;
    return 0;
}
