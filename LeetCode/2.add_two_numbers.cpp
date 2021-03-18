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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode *root, *cur = NULL, *nex = NULL, *p = l1, *q = l2;
        int sum;
        while(p && q){
            sum = p->val + q->val;
            p = p->next;
            q = q->next;
            if(carry){
                sum += 1;
                carry = false;
            }
            if(sum >= 10){
                carry = true;
                sum -= 10;
            }
            if(!cur){
                cur = new ListNode(sum);
                root = cur;
            }
            else{
                nex = new ListNode(sum);
                cur->next = nex;
                cur = nex;
            }
        }
        while(p){
            sum = p->val;
            p = p->next;
            if(carry){
                sum++;
                carry = false;
            }
            if(sum >= 10){
                carry = true;
                sum -= 10;
            }
            nex = new ListNode(sum);
            cur->next = nex;
            cur = nex;
        }
        while(q){
            sum = q->val;
            q = q->next;
            if(carry){
                sum++;
                carry = false;
            }
            if(sum >= 10){
                carry = true;
                sum -= 10;
            }
            nex = new ListNode(sum);
            cur->next = nex;
            cur = nex;
        }
        if(carry){
            nex = new ListNode(1);
            cur->next = nex;
        }
        return root;
    }
};