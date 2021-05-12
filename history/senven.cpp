/*
 * @Author: jiale 
 * @Date: 2021-05-11 15:19:00 
 * @Last Modified by: jiale
 * @Last Modified time: 2021-05-11 17:42:27
 */

// 682. 棒球比赛
// 你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。
// 比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 ops，其中 ops[i] 是你需要记录的第 i 项操作，ops 遵循下述规则：
// 整数 x - 表示本回合新获得分数 x
// "+" - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。
// "D" - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。
// "C" - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。
// 请你返回记录中所有得分的总和。
// 示例 1：
// 输入：ops = ["5","2","C","D","+"]
// 输出：30
// 解释：
// "5" - 记录加 5 ，记录现在是 [5]
// "2" - 记录加 2 ，记录现在是 [5, 2]
// "C" - 使前一次得分的记录无效并将其移除，记录现在是 [5].
// "D" - 记录加 2 * 5 = 10 ，记录现在是 [5, 10].
// "+" - 记录加 5 + 10 = 15 ，记录现在是 [5, 10, 15].
// 所有得分的总和 5 + 10 + 15 = 30
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;
class Solution {
public:
    // 优化，删除最后的遍历栈的操作，改为在遍历输入记录时计算分数
    int calPoints(vector<string>& ops) {
        int res = 0;
        stack<int> nums;
        for (auto point : ops)
        {
            if (isdigit((int)point[0]) || point.substr(0,1) == "-")
            {
                nums.push(stoi(point));
                res += stoi(point);
            }
            else if (point == "C")
            {
                // remove last element
                res -= nums.top();
                nums.pop();
            }
            else if (point == "D")
            {
                // double last element
                res += nums.top() + nums.top();
                nums.push(nums.top() + nums.top());
            }
            else if (point == "+")
            {
                // add last two element
                int top1 = nums.top();
                nums.pop();
                int top2 = nums.top();
                nums.push(top1);
                nums.push(top1 + top2);
                res += top1 + top2;
            }
        }
        return res;
    }
    int calPoints0(vector<string>& ops) {
        int res = 0;
        stack<int> nums;
        for (auto point : ops)
        {
            if (isdigit((int)point[0]) || point.substr(0,1) == "-")
            {
                nums.push(stoi(point));
            }
            else if (point == "C")
            {
                // remove last element
                nums.pop();
            }
            else if (point == "D")
            {
                // double last element
                nums.push(nums.top() + nums.top());
            }
            else if (point == "+")
            {
                // add last two element
                int top1 = nums.top();
                nums.pop();
                int top2 = nums.top();
                nums.push(top1);
                nums.push(top1 + top2);
            }
        }
        while (!nums.empty())
        {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};
int main()
{
    // vector<string> ops = {"1"};
    // vector<string> ops = {"5","2","C","D","+"};
    vector<string> ops = {"5","-2","4","C","D","9","+","+"};
    Solution *solu = new Solution();
    cout << solu->calPoints(ops);
    return 0;
}