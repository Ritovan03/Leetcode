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
        //first take k%size 
        // keep pointer for head and pointer for second last tail
        ListNode* temp = head;
        if(head == nullptr || k==0)
        {
            return head;
        }
        int size = 0;
        while(temp!=nullptr)
        {
            size++;
            temp = temp->next;
        }
        k = k%size;
        while(k>0)
        {
            //actual reversing logic
            temp = head;
            ListNode* tail = head;
            while(tail != nullptr && tail->next->next != nullptr)
            {
                tail = tail->next;
            }
            ListNode* rem = tail->next;
            rem->next = temp;
            tail->next = nullptr;
            head = rem;
            k--;
        }
        return head; 
    }
};