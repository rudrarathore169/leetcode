class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
       if (!head || !head->next || k == 0) return head;
        
      
        ListNode* temp = head;
        int length = 1;
        while (temp->next != NULL) {
            temp = temp->next;
            length++;
        }
        
      
        k = k % length;
        if (k == 0) return head;
        
        
        temp->next = head;
        
        
        int stepsToNewHead = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        
        return newHead;
    }
};