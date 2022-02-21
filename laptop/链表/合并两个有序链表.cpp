#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
};

ListNode* mergList(ListNode* l1, ListNode* l2)
{
    ListNode* node = new ListNode();
    ListNode* result = node;
    while(l1 && l2)
    {
        if(l1->val <= l2->val)
        {
            node->next = l1;
            l1 = l1->next;
        }
        else
        {
            node->next = l2;
            l2 = l2->next;
        }
        node = node->next;
    }
    if(l1 == nullptr) node->next = l2;
    if(l2 == nullptr) node->next = l1;
    return result->next;
}


int main()
{

    return 0;
}