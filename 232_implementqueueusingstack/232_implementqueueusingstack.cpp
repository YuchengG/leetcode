// Implement the following operations of a queue using stacks.

// push(x) -- Push element x to the back of queue.
//   pop() -- Removes the element from in front of queue.
//   peek() -- Get the front element.
//   empty() -- Return whether the queue is empty.

//   Notes:

// You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
//   Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
//   You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

// Author: Songpeng Zu
// Time: August 7, 2016

#include<stack>

using namespace std;

// Solver 1
// Accepted

#include<stack>
using namespace std;
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        data.push(x);
    }
    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> tmp;
        while(!data.empty()){
            tmp.push(data.top());
            data.pop();
        }
        tmp.pop();
        while(!tmp.empty()){
            data.push(tmp.top());
            tmp.pop();
        }
    }
    // Get the front element.
    int peek(void) {
        if(data.size() == 1) {return data.top();}
        stack<int> tmp;
        while(!data.empty()){
            tmp.push(data.top());
            data.pop();
        }
        int result = tmp.top();
        while(!tmp.empty()){
            data.push(tmp.top());
            tmp.pop();
        }
        return result;
    }
    // Return whether the queue is empty.
    bool empty(void) {
        return data.size() < 1 ? true : false;
    }
private:
    stack<int> data;
};
