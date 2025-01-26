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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>rev;
        ListNode*temp=head;
        int i = 1;
        while(temp != nullptr){
            if(i>=left && i<=right){
                rev.push_back(temp->val);
            }
            temp = temp->next;
            i++;
        }
        temp = head;
        reverse(rev.begin(),rev.end());
        i = 1;
        int indice = 0;
        while(temp != nullptr){
            if(i>=left && i<=right){
                temp->val = rev[indice];
                indice++;
            }
            temp = temp->next;
            i++;
        }

        return head;
    }
};