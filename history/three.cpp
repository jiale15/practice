/*
 * @Author: jiale 
 * @Date: 2021-05-08 08:35:10 
 * @Last Modified by: jiale
 * @Last Modified time: 2021-05-08 09:45:56
 */

// 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

// push(x) —— 将元素 x 推入栈中。
// pop() —— 删除栈顶的元素。
// top() —— 获取栈顶元素。
// getMin() —— 检索栈中的最小元素。
//  

// 示例:

// 输入：
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// 输出：
// [null,null,null,null,-3,null,0,-2]
// 提示：
// pop、top 和 getMin 操作总是在 非空栈 上调用
// 解释：
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> 返回 -3.
// minStack.pop();
// minStack.top();      --> 返回 0.
// minStack.getMin();   --> 返回 -2
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    int g[100];
    int t = 0;
    void push(int val) {
        g[t] = val;
        t++;
    }
    
    void pop() {
        if (t == 0)
            exit(EXIT_FAILURE);
        t--;
    }
    
    int top() {
        if (t == 0)
            exit(EXIT_FAILURE);
        return g[t-1];
    }
    
    int getMin() {
        if (t == 0)
            exit(EXIT_FAILURE);
        if (t == 1)
            return g[0];
        int min = g[0];
        for (int i = 1; i < t; i++)
        {
            if (g[i] < min)
                min = g[i];
        }
        return min;
    }
};
int main()
{
    MinStack* obj = new MinStack();
    obj->push(2);
    obj->push(0);
    obj->push(3);
    obj->push(0);
    obj->getMin();
    obj->pop();
    obj->getMin();
    obj->pop();
    obj->getMin();
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    cout << param_3 << param_4 << std::endl;
    return 0;
}
// ["MinStack","push","push","push","push","getMin","pop","getMin","pop","getMin","pop","getMin"]
// [[],[2],[0],[3],[0],[],[],[],[],[],[],[]]

// Line 10: Char 9: runtime error: index 100 out of bounds for type 'int [100]' (solution.cpp)
// SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:15:9
// 数组长度不够导致测试报错，把数组长度置为10000000通过
    // void push(int val) {
        
    // }
    
    // void pop() {

    // }
    
    // int top() {

    // }
    
    // int getMin() {

    // }
