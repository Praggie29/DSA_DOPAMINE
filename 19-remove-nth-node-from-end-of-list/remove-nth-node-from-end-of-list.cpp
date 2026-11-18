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
        int cnt = 0;
        ListNode* temp = head;
        while(temp) {
            cnt++;
            temp = temp -> next;
        }
        if ( cnt == n ) {
            ListNode* newNode = head -> next;
            head -> next = nullptr;
            delete(head);
            return newNode;
        }
        int nodeToBeRemoved = cnt - n;
        temp = head;
        while ( temp ) {
            nodeToBeRemoved--;
            if ( nodeToBeRemoved == 0 ) {
               break;
            }
            temp = temp -> next;
        }
        ListNode* deleteNode = temp -> next;
        temp -> next = temp -> next -> next;
        deleteNode -> next = nullptr;
        delete(deleteNode);
        return head;
    }
};