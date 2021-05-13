/*
 * @Author: jiale 
 * @Date: 2021-05-12 10:58:11 
 * @Last Modified by: jiale
 * @Last Modified time: 2021-05-12 15:30:06
 */
// 844. 比较含退格的字符串
// 给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。
// 注意：如果对空文本输入退格字符，文本继续为空。
// 示例 1：
// 输入：S = "ab#c", T = "ad#c"
// 输出：true
// 解释：S 和 T 都会变成 “ac”。
// 示例 2：
// 输入：S = "ab##", T = "c#d#"
// 输出：true
// 解释：S 和 T 都会变成 “”。
// 示例 3：
// 输入：S = "a##c", T = "#a#c"
// 输出：true
// 解释：S 和 T 都会变成 “c”。
// 示例 4：
// 输入：S = "a#c", T = "b"
// 输出：false
// 解释：S 会变成 “c”，但 T 仍然是 “b”。
// 提示：
// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S 和 T 只含有小写字母以及字符 '#'。
//  进阶：
// 你可以用 O(N) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stack0, stack1;
        char back = '#';
        for (auto i : s)
        {
            // if (strcmp(i, back) == 0)
        // for (int i = 0; i < s.size(); i++)
            // if (i == back && !stack0.empty())
            if (i == back)
            {    
                if (!stack0.empty())
                    stack0.pop();
                continue;
            }
            stack0.push(i);
        }
        for (auto i : t)
        {
            if (i == back)
            {    
                if (!stack1.empty())
                    stack1.pop();
                continue;
            }
            stack1.push(i);
        }
        if (stack0.size() != stack1.size())
            return false;
        while (!stack0.empty())
        {
            if (stack0.top() != stack1.top())
                return false;
            stack0.pop();
            stack1.pop();
        }
        return true;
    }
};
int main()
{
    // string S = "ab#c", T = "ad#c";
    // string S = "ab##", T = "c#d#";
    string S = "a#c", T = "b";
    Solution *solu = new Solution();
    cout << solu->backspaceCompare(S, T);
    return 0;
}