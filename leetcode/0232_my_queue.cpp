#include <stack>
using namespace std;
class MyQueue {
    stack<int>input;
    stack<int>output;
public:
    MyQueue() {

    }

    void push(int x) {
        input.push(x);
    }

    void reverse() {
        if (output.empty() && (!input.empty())) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

    int pop() {
        reverse();
        int temp = output.top();
        output.pop();
        return temp;
    }

    int peek() {
        reverse();
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};