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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr){
            return head;
        }
        ListNode*temp = head;
        vector<int>menores;
        vector<int>mayI;
        while(temp!=nullptr){
            if(temp->val < x){
                menores.push_back(temp->val);
            }else{
                mayI.push_back(temp->val);
            }
            temp = temp->next;
        }

        if(menores.size()>0){
            head->val = menores[0];
            temp = head;
            int i = 1;
            while(i<menores.size() && temp != nullptr && temp->next != nullptr){
                temp=temp->next;
                temp->val = menores[i];
                i++;
            }
            int j = 0;
            while(j<mayI.size() && temp != nullptr &&  temp->next != nullptr){
                temp=temp->next;
                temp->val = mayI[j];
                j++;
            }
        }else{
            head->val = mayI[0];
            temp = head;
            int j = 1;
            while(j<mayI.size() && temp != nullptr && temp->next != nullptr){
                temp=temp->next;
                temp->val = mayI[j];
                j++;
            }
        }
        
        return head;
    }
};