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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int>numeros;
        while(head != nullptr){
            numeros.push_back(head->val);
            head = head->next;
        }

        int n = numeros.size();
        if(n == 0){
            return nullptr;
        }
        k = k % n;
        vector<int>copia = numeros;

        for(int i = 0;i<n;i++){
            numeros[(i+k)%n] = copia[i];
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        for(auto& x : numeros){
            temp->next = new ListNode(x);
            temp = temp->next;
        }

        return dummy->next;
    }
};