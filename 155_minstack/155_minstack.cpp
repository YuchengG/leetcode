// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

//   push(x) -- Push element x onto stack.
//   pop() -- Removes the element on top of the stack.
//   top() -- Get the top element.
//   getMin() -- Retrieve the minimum element in the stack.

//   Example:

//   MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


// Author: Songpeng Zu
// Time: July 14, 2016

#include<stack>
using namespace std;

// Solver 1
// Accepted

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {curMin = 0;}

    void push(int x) {
        if(store.size() == 0) {store.push(x); curMin = x;}
        else{
            store.push(x);
            if(x < curMin) {curMin = x;}
        }
    }

    void pop() {
        if(store.top() > curMin || store.size() == 1) {store.pop();}
        else{
            store.pop();
            stack<int> tmp;
            int tmpNum;
            curMin = store.top();
            while(!store.empty()){
                tmpNum = store.top();
                curMin = (curMin <= tmpNum) ? curMin : tmpNum;
                tmp.push(tmpNum);
                store.pop();
            }
            while(!tmp.empty()){
                store.push(tmp.top());
                tmp.pop();
            }
        }
    }

    int top() {
        return store.top();
    }

    int getMin() {
        if(store.size() == 0) {cout<<"No element, return zero!"<<endl; return 0;}
        else{return curMin;}
    }

private:
    stack<int> store;
    int curMin;
};
