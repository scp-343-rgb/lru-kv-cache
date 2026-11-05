#include <queue>
using namespace std;
class MyStack {
    queue<int>q1;
    queue<int>q2;
public:
    MyStack() {

    }

    void swapQueue() {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void push(int x) {
        q2.push(x);
        swapQueue();
    }

    int pop() {
        int temp = q1.front();
        q1.pop();
        return temp;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};