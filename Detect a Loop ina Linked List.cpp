/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p = head;
        ListNode *q = head;

        if((head == NULL) or (head->next == NULL)){
            return false;
        }
        
        do{
            p = p->next;
            q = q->next;
            if(q)
                q = q->next;
            else{
                q=NULL;
            }
        }while((p) and (q) and (p != q));

        if(p == q){
            return true;
        }
        return false;
    }
};
