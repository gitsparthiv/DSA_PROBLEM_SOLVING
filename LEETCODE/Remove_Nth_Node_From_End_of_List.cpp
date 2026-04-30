class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front = head;
        ListNode* back = head;
        int count = 0;
        if(!head -> next){
            head = NULL;
            return head;
        }
        while(count != n){
           back = back -> next;
           count++;
        }
        if(back == NULL)
    return head->next;
        while(back -> next != NULL){
            back = back -> next;
            front = front -> next;
        }
            front -> next = front -> next -> next;
        return head;
    }
};
