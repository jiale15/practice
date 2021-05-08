/*
 * @Author: jiale 
 * @Date: 2021-05-08 09:47:13 
 * @Last Modified by: jiale
 * @Last Modified time: 2021-05-08 16:56:43
 */
// 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通队列的全部四种操作（push、top、pop 和 empty）。

// 实现 MyStack 类：

// void push(int x) 将元素 x 压入栈顶。
// int pop() 移除并返回栈顶元素。
// int top() 返回栈顶元素。
// boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

// 注意：
// 你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
// 你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。

// 示例：
// 输入：
// ["MyStack", "push", "push", "top", "pop", "empty"]
// [[], [1], [2], [], [], []]
// 输出：
// [null, null, null, 2, 2, false]

// 解释：
// MyStack myStack = new MyStack();
// myStack.push(1);
// myStack.push(2);
// myStack.top(); // 返回 2
// myStack.pop(); // 返回 2
// myStack.empty(); // 返回 False
//  

// 提示：

// 1 <= x <= 9
// 最多调用100 次 push、pop、top 和 empty
// 每次调用 pop 和 top 都保证栈不为空
//  
// 进阶：你能否实现每种操作的均摊时间复杂度为 O(1) 的栈？换句话说，执行 n 个操作的总时间复杂度 O(n) ，
// 尽管其中某个操作可能需要比其他操作更长的时间。你可以使用两个以上的队列。
#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if (!tag)
        {
            queue0.push(x);
            int size = queue1.size();
            for (int i = 0; i < size; i++)
            {
                queue0.push(queue1.front());
                queue1.pop();
            }
        }
        else
        {
            queue1.push(x);
            int size = queue0.size();
            for (int i = 0; i < size; i++)
            {
                queue1.push(queue0.front());
                queue0.pop();
            }
            // swap(queue0, queue1);
        }
        tag = !tag;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        if (tag)
        {
            res = queue0.front();
            queue0.pop();
        }
        else 
        {
            res = queue1.front();
            queue1.pop();
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        if (tag)
        {
            if (queue0.size() == 0)
                exit(EXIT_FAILURE);
        }
        else 
        {
            if (queue1.size() == 0)
                exit(EXIT_FAILURE);
        }
        return tag ? queue0.front() : queue1.front();
    }
    /** Returns whether the stack is empty. */
    bool empty() {
        return tag ? queue0.empty() : queue1.empty();
    }
private:
    queue<int> queue0, queue1;
    bool tag = false; //下一次：0使用queue0,1使用queue1
};
int main()
{
    MyStack* obj = new MyStack();
    obj->push(2);
    obj->push(0);
    // obj->push(3);
    obj->push(4);
    int param_2 = obj->pop();
    obj->pop();
    obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    cout << param_4 << param_3 << std::endl;
    return 0;
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// 使用swap方法，简化了类
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        queue1.push(x);
        while (!queue0.empty())
        {
            queue1.push(queue0.front());
            queue0.pop();
        }
        swap(queue0, queue1);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = queue0.front();
        queue0.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        if (queue0.size() == 0)
            exit(EXIT_FAILURE);
        return queue0.front();
    }
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue0.empty();
    }
private:
    queue<int> queue0, queue1; // 使用queue0,使用queue1作为辅助
};