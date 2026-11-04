#include <vector>
using namespace std;
class MinStack {
    vector<int>data;
    vector<int>minData;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        data.push_back(value);
        if (minData.empty()) minData.push_back(value);
        else if (value <= minData.back()) {
            minData.push_back(value);
        }
    }
    
    void pop() {
        if (data.back() == minData.back()) minData.erase(minData.end() - 1);
        data.erase(data.end() - 1);
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return minData.back();
    }
};