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
    ListNode* swapPairs(ListNode* head) {
        if (head != nullptr && head->next != nullptr) {
            ListNode* temp = head;
            ListNode* aux = head->next;
            head = temp->next;
            temp->next = aux->next;
            aux->next = temp;
            ListNode* ant = temp;

            while(temp != nullptr && temp->next != nullptr){
                temp = temp->next;
                if(temp == nullptr) break;
                aux = temp->next;
                if(aux == nullptr) break;
                ant->next = temp->next;
                temp->next = aux->next;
                aux->next = temp;
                ant = temp;
            }
        }
        return head;
    }
};