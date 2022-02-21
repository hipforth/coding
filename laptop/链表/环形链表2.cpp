#include <bits/stdc++.h>

using namespace std;



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        unordered_map<ListNode*, int> mp;
        int i = 0;
        while (head != nullptr)
        {
            auto it = mp.find(head);
            if(it != mp.end())
            {
                return it->first;
            }
            mp[head] = i++;
            head = head->next;
        }
        return nullptr;
        
    }
};


int main()
{

    return 0;
}

