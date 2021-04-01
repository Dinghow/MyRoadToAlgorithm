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
# include<vector>
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> address_list;
        address_list.push_back(head);
        ListNode* cur = head;
        while(cur->next){
            address_list.push_back(cur->next);
            cur = cur->next;
        }
        int length = address_list.size();
        if(length == 1) head = nullptr;
        else if (length == n) head = address_list[1];
        else if (n == 1) address_list[length-1-n]->next = nullptr;
        else address_list[length-n-1]->next = address_list[length-n+1];

        return head;
    }
};
