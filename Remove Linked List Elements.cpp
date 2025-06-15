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
    ListNode* removeElements(ListNode* head, int val) {
        if (head != nullptr && head->val == val) {
            while (head != nullptr && head->val == val) {
                head = head->next;
            }
        }
        if (head != nullptr && head->next != nullptr) {
            ListNode* temp = head;
            ListNode* aux = head->next;

            while (aux != nullptr) {
                if (aux->val == val) {
                    aux = aux->next;
                } else {
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