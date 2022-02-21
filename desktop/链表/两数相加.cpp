#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int pre = 0, sum = 0;
        ListNode* head = new ListNode();
        ListNode* result = head;
        while(l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            sum  = n1 + n2 + pre;
            int tmp = sum % 10;
            pre = sum / 10;
            head->next = new ListNode(tmp);
            head = head->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(pre > 0)
        {
            head->next = new ListNode(pre);
        }
        return result->next;
    }
};

int main()
{

    return 0;
}