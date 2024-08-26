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
    ListNode* merg(ListNode* first,ListNode*second){
        ListNode*ans = first;
        while(first->next!=NULL&&second!=NULL){
            ListNode*next1 = first->next;
            ListNode*next2 = second->next;
           if(second->val>=first->val&&next1->val>=second->val){
                     first->next = second;
                     second->next = next1;
                     first=first->next;
                     second = next2;
           }
           else{
            first=next1;
            next1 = next1->next;
           }
        }
        if(second!=NULL){
            first->next=second;
        }
        return ans;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        return list2;
        else if(list2==NULL)
        return list1;

        if(list1->val>list2->val){
           return merg(list2,list1);
        }
        else{
            return merg(list1,list2);
        }   
    }
};