#include <string>
using namespace std;
struct Stack {
    char* data;
    int top;
};
Stack* initiall()
{
    Stack* stack = new Stack;
    char* d = new char[10000];
    stack->data = d;
    stack->top = -1;
    return stack;
}
void destroy(Stack* s)
{
    delete[]s->data;
    delete s;
}
bool isEmpty(Stack* s)
{
    return s->top == -1;
}
void push(Stack* s, char a)
{
    s->top++;
    s->data[s->top] = a;
}
void pop(Stack* s)
{
    if (isEmpty(s)) return;
    s->top--;
}
bool isValid(string s)
{
    Stack* stack;
    stack = initiall();
    bool found = true;
    for (auto& i : s) {
        if (i == '(' || i == '[' || i == '{') push(stack, i);
        else if (i == ')') {
            if (!isEmpty(stack) && stack->data[stack->top] == '(') pop(stack);
            else found = false;
        }
        else if (i == ']') {
            if (!isEmpty(stack) && stack->data[stack->top] == '[') pop(stack);
            else found = false;
        }
        else if (i == '}') {
            if (!isEmpty(stack) && stack->data[stack->top] == '{') pop(stack);
            else found = false;
        }
    }
    if (isEmpty(stack) && found == true) {
        destroy(stack);
        return true;
    }
    else {
        destroy(stack);
        return false;
    }
}