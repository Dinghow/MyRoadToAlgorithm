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
#include<vector>
#include<map>
#include<algorithm>

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> node_value;
        vector<ListNode*> node_addr;
        map<int, int> val2pos;
        map<int, int> val2pos_last;
        map<int, int> valcounts;
        int i = 0; /* list length */
        int k = 0; /* set length */
        ListNode* new_head = nullptr;
        while(head){
            node_addr.push_back(head);
            if (val2pos.find(head->val) == val2pos.end()){
                val2pos[head->val] = i;
                val2pos_last[head->val] = i;
                valcounts[head->val] = 1;
                node_value.push_back(head->val);
                k++;
            }
            else{
                node_addr[val2pos_last[head->val]]->next = head;
                val2pos_last[head->val] = i;
                valcounts[head->val]++;
            }
            head = head->next;
            i++;
        }
        sort(node_value.begin(), node_value.end());
        for(int j = 0; j < k; j++){
            ListNode* cur_addr = node_addr[val2pos[node_value[j]]];
            if(j == 0) new_head = cur_addr;
            ListNode* next_addr = (j==k-1)? nullptr: node_addr[val2pos[node_value[j+1]]];
            if(valcounts[node_value[j]] == 1) cur_addr->next = next_addr;
            else{
                for(int m = 1; m < valcounts[node_value[j]]; m++) cur_addr = cur_addr->next;
                cur_addr->next = next_addr;
            }
        }
        return new_head;
    }
};