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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cero = new ListNode(0);
        if (head != nullptr && head->next != nullptr) {
            while (head != nullptr) {
                if (head->next != nullptr && head->val == head->next->val) {
                    while (head->next != nullptr &&
                           head->val == head->next->val) {
                        head = head->next;
                    }
                    head = head->next;
                } else {
                    break;
                }
            }
        }
        cero->next = head;

        if (head != nullptr && head->next != nullptr) {
            ListNode* dupli = head->next;
            ListNode* noDupli = head;
            while (dupli != nullptr) {
                if (dupli != nullptr && dupli->next != nullptr &&
                    dupli->val == dupli->next->val) {
                    while (dupli->next != nullptr &&
                           dupli->val == dupli->next->val) {
                        dupli = dupli->next;
                    }
                    noDupli->next = dupli->next;
                    dupli = dupli->next;
                } else {
                    dupli = dupli->next;
                    noDupli = noDupli->next;
                }
            }
        }

        return cero->next;
    }
};