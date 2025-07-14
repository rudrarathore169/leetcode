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
   
    int getDecimalValue(ListNode* head) {
       int count=0;
       int ans=0;
       ListNode* temp = head;

       while(temp){
        count++;
        temp= temp->next;
       }
       while(head){
        if(head->val==1){
            ans+=pow(2,count-1);
        }
        head = head->next;
        count--;
       }
        return ans;
        
    }
};