#include <bits/stdc++.h>

using namespace std;

class CQueue {
public:
    CQueue() {
        while(!stack1.empty())
            stack1.pop();
        while(!stack2.empty())
            stack2.pop();
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        int head = -1;
        if(!stack2.empty())
        {
            head = stack2.top();
            stack2.pop();
        }   
        else
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }

            if(!stack2.empty())
            {
                head = stack2.top();
                stack2.pop();
            }
        }
        return head;
    }
private:
    stack<int> stack1, stack2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main()
{
    CQueue* obj = new CQueue();
    obj->appendTail(1);
    int param_2 = obj->deleteHead();
    return 0;
}