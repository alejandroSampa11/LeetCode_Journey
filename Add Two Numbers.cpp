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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int adicional = 0;

        while (l1 != nullptr && l2 != nullptr) {
            if ((l1->val + l2->val + adicional) > 9) {
                int sobra = (l1->val + l2->val + adicional) % 10;
                adicional = 1;
                temp->next = new ListNode(sobra);
            } else {
                int sobra2 = (l1->val + l2->val + adicional) % 10;
                adicional = 0;
                temp->next = new ListNode(sobra2);
            }
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }

        while (l1 != nullptr) {
            if ((l1->val + adicional) > 9) {
                int sobra3 = (l1->val + adicional) % 10;
                adicional = 1;
                temp->next = new ListNode(sobra3);
            } else {
                int sobra4 = (l1->val + adicional) % 10;
                adicional = 0;
                temp->next = new ListNode(sobra4);
            }
            l1 = l1->next;
            temp = temp->next;
        }

        while (l2 != nullptr) {
            if ((l2->val + adicional) > 9) {
                int sobra3 = (l2->val + adicional) % 10;
                adicional = 1;
                temp->next = new ListNode(sobra3);
            } else {
                int sobra4 = (l2->val + adicional) % 10;
                adicional = 0;
                temp->next = new ListNode(sobra4);
            }
            l2 = l2->next;
            temp = temp->next;
        }

        if (adicional == 1) {
            temp->next = new ListNode(1);
        }

        return dummy->next;
    }
};