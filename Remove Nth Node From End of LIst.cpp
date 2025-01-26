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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        ListNode *busc = head;
        vector<int>num;
        int numero = 0;
        while(busc != nullptr){
            numero++;
            busc = busc->next;
        }
        cout<<numero<<endl;
        int contador = 0;
        if(numero-n<1  && head->next == nullptr){
            head = nullptr;
        }
        else if(numero-n<1 && head->next != nullptr){
            head = head->next;
        }
        else{
            while(temp != nullptr){
                contador++;
                if(contador == numero-n){
                    temp->next = temp->next->next;
                    break;
                }
                temp = temp->next;
            }
        }
        // cout<<num[num.size()-n]<<endl;
        return head;
    }
};