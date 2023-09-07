# [92. Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=daily-question&envId=2023-09-07)

## Solution 1: Iterative Reverse
Go through list, once it reaches left keep track of Node before reversed portion(before), and keep track of node that is start of reversed portion(start). Reverse the linked list using the strategy from reverse linked list problem on leetcode. Then attach before to end of reversed portion(prev) and attach start to next node after reversed portion(cur).
```cpp
// OJ: https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=daily-question&envId=2023-09-07
// Author: https://github.com/spookyflame10
// Time: O(n) you go through linked list once
// Space: O(1) no storage in this algo
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next) return head;
        ListNode* sentinel=new ListNode(); sentinel->next = head;
        ListNode* cur;ListNode* prev;
        cur=head; prev= NULL; //next = head->next;
        int i =1;
        while(cur){
            if(i==left){
                ListNode* before = prev;//before reverse
                ListNode* start = cur; // start of reverse
                prev = NULL;// so that cur->next = NULL.
                while(cur&&i<=right){
                    ListNode* temp = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = temp;
                    i++;
                }
                if(before){
                    before->next = prev;
                    
                }else{
                    sentinel->next = prev;
                }
                start->next = cur;
                
                break;
            }
            prev = cur;
            cur = cur->next;
            i++;
        }
        return sentinel->next;
    }
};
```