class Solution {
private:
    stack<int> stackInt;
    stack<int> stackMin;//����ջ���������ÿ��push�����Сֵ
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