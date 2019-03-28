class Solution {
private:
    stack<int> stackInt;
    stack<int> stackMin;//辅助栈，用来存放每次push后的最小值
public:
    void push(int value) {
        stackInt.push(value);
        if(stackMin.empty())
           stackMin.push(value);
       else  if(value<stackMin.top())
            stackMin.push(value);
        else
            stackMin.push(stackMin.top());
    }
    void pop() {
        stackInt.pop();
        stackMin.pop();
    }
    int top() {
        return stackInt.top();
    }
    int min() {
        return stackMin.top();
    }
};