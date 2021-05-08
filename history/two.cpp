/*
 * @Author: jiale 
 * @Date: 2021-05-07 10:41:43 
 * @Last Modified by: jiale
 * @Last Modified time: 2021-05-07 15:58:36
 */

// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。

// 示例 1：
// 输入：s = "()"
// 输出：true
// 提示：
// 1 <= s.length <= 104
// s 仅由括号 '()[]{}' 组成
#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool isValid(string s);
int main()
{
    bool b;
    b = isValid("(") ? true : false;
    std::cout << b << std::endl;
    b = isValid("()") ? true : false;
    std::cout << b << std::endl;
    b = isValid("()[]") ? true : false;
    std::cout << b << std::endl;
    b = isValid("(){}}{") ? true : false;
    std::cout << b << std::endl;
    b = isValid("()}{");
    std::cout << b << std::endl;
    b = isValid("([)]") ? true : false;
    std::cout << b << std::endl;
    b = isValid("(([]){})");
    std::cout << b << std::endl;
     b = isValid("[{()}]");
    std::cout << b << std::endl;
    return 0;
}
bool isValid(string s) {
    stack<char> w;
    const char *c = "(){}[]";
    for(auto i : s)
    {
        if (i == c[0] || i == c[2] || i == c[4])
        {
            w.push(i);
        }
        else if (i == c[1] && w.size() != 0)
            if(w.top() == c[0])
                w.pop();
            else 
                return false;
        else if (i == c[3] && w.size() != 0)
            if(w.top() == c[2])
                w.pop();
            else 
                return false;
        else if (i == c[5] && w.size() != 0)
            if(w.top() == c[4])
                w.pop();
            else 
                return false;
        else return false;
    }
    if (w.size() != 0)
        return false;
    return true;
}
bool isValid0(string s) {
    const char * c = s.c_str();
    stack<char> w;
    for(auto i : s)
    {
        std::cout << i << std::endl;
    }
    // 三个类型括号都是true才行
    bool b[3] = {true, true, true};
    // 六个括号出现次数
    int n[6] = {0};
    //  '('，')'，'{'，'}'，'['，']' 
    for(auto i : s)
    {
        switch (i)
        {
        case '(':
            n[0]++;
            b[0] = (n[0] != n[1]) ? false : true;
            break;
        case ')':
            n[1]++;
            if (!(b[1] && b[2]) && (w.top() != '('))
                return false;
            b[0] = (n[0] != n[1]) ? false : true;
            break;
        case '{':
            n[2]++;
            b[1] = (n[2] != n[3]) ? false : true;
            break;
        case '}':
            n[3]++;
            if (!(b[0] && b[2]) && (w.top() != '{'))
                return false;
            b[1] = (n[2] != n[3]) ? false : true;
            break;
        case '[':
            n[4]++;
            b[2] = (n[4] != n[5]) ? false : true;
            break;
        case ']':
            n[5]++;
            if (!(b[0] && b[1]) && (w.top() != '['))
                return false;
            b[2] = (n[4] != n[5]) ? false : true;
            break;
        default:
            break;
        }
        w.push(i);
    }
    b[0] = (n[0] != n[1]) ? false : true;
    cout << "b12:" << b[0] << n[1] <<n[0];
    b[1] = (n[2] != n[3]) ? false : true;
    
    b[2] = (n[4] != n[5]) ? false : true;
    std::cout << "c1、c2：" << b[0] << b[1] << b[2] << std::endl;
    return b[0] && b[1] && b[2];
}