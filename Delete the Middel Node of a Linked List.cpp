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
    ListNode* deleteMiddle(ListNode* head) {
        int contador = 0;
        ListNode* cont = head;
        while(cont != nullptr){
            contador++;
            cont = cont->next;
        }
        if(contador == 1){
            return nullptr;
        }
        contador = (contador/2)+1;
        
        ListNode* temp = head;
        int num = 1;
        while(temp != nullptr){
            if(num == contador-1){
                temp->next = temp->next->next;
                break;
            }else{
                temp = temp->next;
            }
            num++;
        }

        return head; 
    }
};