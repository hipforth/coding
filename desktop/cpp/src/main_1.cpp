#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val, ListNode* _next) : val(_val), next(_next) {}
};

ListNode* inverse(ListNode* head)
{

}

bool hasCycle(ListNode *head) {
    unordered_set<ListNode *> ListSet;
    while(head)
    {
        if(ListSet.count(head)) return true;
        ListSet.insert(head);
        head = head->next;
    }
    return false;

}

bool hasCycle_1(ListNode* head)
{
    if(head == nullptr || head->next == nullptr) return false;
    ListNode* fast = head->next;
    ListNode* slow = head;
    while(fast)
    {
        if(fast == slow)
        {
            return true;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> nums;
    int i = 0, j = 0;
    for( ; i < m && j < n; )
    {
        if(nums1[i] <= nums2[j])
        {
            nums.push_back(nums1[i]);
            i++;
        }
        else
        {
            nums.push_back(nums2[j]);
            j++;
        }
    }
    if(j == n && i < m)
    {
        for(int x = i; x < m; x++)
        {
            nums.push_back(nums1[x]);
        }
    }
    if(i == m && j < n)
    {
        for(int x = j; x < n; x++)
        {
            nums.push_back(nums2[x]);
        }
    }
    nums1 = nums;
}

bool isValid(string s) 
{
    int n = s.size();
    if(n % 2 != 0) return false;
    unordered_map<char, char> ump = {
        {'{', '}'},{'(', ')'},{'[', ']'}
    };
    stack<char> Stack;
    Stack.push(s[0]);
    for(int i = 1; i < n; i++)
    {   
        char c = Stack.top();
        if(c == s[i])
        {
            Stack.pop();
        }
        else
        {
            Stack.push(s[i]);
        }
    }
    if(Stack.empty()) return true;
    else return false;
}

    bool isValid_1(string s) {
        unordered_map<char,int> m{{'(',1},{'[',2},{'{',3},
                                {')',4},{']',5},{'}',6}};
        stack<char> st;
        bool istrue = true;
        for(char c:s)
        {
            int flag = m[c];
            if(flag >= 1 && flag <= 3) st.push(c);
            else 
                if(!st.empty() && m[st.top()] == flag-3) st.pop();
                else 
                {
                    return false;
                }
        }
        if(!st.empty()) return false;
        else return true;
    }


int main()
{

    return 0;
}

