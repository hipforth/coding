#include <bits/stdc++.h>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        //if(head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        head = mergNode(head, reverseNode(slow));
    }
private:
    ListNode* reverseNode(ListNode* head)
    {
        ListNode* l = head;
        ListNode* r = head->next;
        ListNode* tmp = r;
        l->next = nullptr;
        while (r != nullptr)
        {
            tmp = tmp->next;
            r->next = l;
            l = r;
            r = tmp;
        }
        return l;
    }
    ListNode* mergNode(ListNode* l1, ListNode* l2)
    {
        ListNode* head = l1;
        while (l1->next != nullptr && l2->next != nullptr)
        {
            ListNode* tmp = l1->next;
            ListNode* tmpp = l2->next;
            l1->next = l2;
            l2->next = tmp;
            l1 = tmp;
            l2 = tmpp;
        }
        return head;
    }
};


int main()
{

    return 0;
}