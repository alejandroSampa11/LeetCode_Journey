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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,int>numeros;
        for(auto& x : nums){
            numeros[x]++;
        }

        while(head != nullptr && head->next != nullptr){
            if(numeros[head->val] > 0){
                head = head->next; 
            }else{
                break;
            }
        }

        if(head != nullptr && head->next != nullptr){
            ListNode* temp = head;
            ListNode* aux = head->next;
            while(aux != nullptr){
                if(numeros[aux->val] > 0){
                    aux = aux->next;
                }else{
                    temp->next = aux;
                    aux = aux->next;
                    temp = temp->next;
                }
            }
            temp->next = aux;
            
        }
        return head;
    }
};