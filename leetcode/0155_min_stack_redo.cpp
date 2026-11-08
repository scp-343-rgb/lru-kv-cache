#include <vector>
using namespace std;
class MinStack {
    vector<int>stack;
    vector<int>minData;
public:
    void push(int value)
    {
        stack.push_back(value);
        getMin(value);
    }

    void getMin(int value)
    {
        if (minData.empty()) minData.push_back(value);
        else if (minData.back() >= value) minData.push_back(value);
    }

    void pop()
    {
        if (stack.back() == minData.back()) minData.pop_back();
        stack.pop_back();
    }

    int top()
    {
        return stack.back();
    }

    int getMin()
    {
        return minData.back();
    }
};