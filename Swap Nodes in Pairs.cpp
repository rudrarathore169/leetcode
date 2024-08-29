/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
       ListNode* prev = NULL;
       ListNode* next = NULL;
       ListNode* curr = head;
       ListNode* newer = head->next;
      
       while(curr!=NULL&&curr->next!=NULL){
        ListNode* nextwindow = curr->next->next;
        ListNode* second = curr->next;
        second->next = curr;
        curr->next = nextwindow;
        if(prev!=NULL)
          prev->next= second;

          prev = curr;
          curr = nextwindow;
       }
        return newer;
        
    }
};