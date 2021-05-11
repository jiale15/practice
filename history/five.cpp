/*
 * @Author: jiale 
 * @Date: 2021-05-8 10:43:42 
 * @Last Modified by: jiale
 * @Last Modified time: 2021-05-11 10:44:02
 */
// 2个栈实现队列
// 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
// 实现 MyQueue 类：
// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false
//  
// 说明：
// 你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
// 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
//  
// 进阶：
// 你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。
//  
// 示例：
// 输入：
// ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
// 输出：
// [null, null, null, 1, 1, false]
// 解释：
// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
// myQueue.peek(); // return 1
// myQueue.pop(); // return 1, queue is [2]
// myQueue.empty(); // return false
//  
// 提示：
// 1 <= x <= 9
// 最多调用 100 次 push、pop、peek 和 empty
// 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        // stack0作为队列对象，stack1作为辅助
        // 一次出栈入栈操作就把栈的元素的顺序倒序了
        while (!stack0.empty())
        {
            stack1.push(stack0.top());
            stack0.pop();
        }
        stack1.push(x);
        while (!stack1.empty())
        {
            stack0.push(stack1.top());
            stack1.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = stack0.top();
        stack0.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if (stack0.size() == 0)
            exit(EXIT_FAILURE);
        return stack0.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack0.empty();
    }
private:
    stack<int> stack0, stack1;
};


int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    // obj->push(4);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    cout << param_2 << param_3 << param_4 << endl;
    return 0;
}