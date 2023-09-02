/*Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]
*/

//The time complexity will be O(n) and space complexity will be O(1)

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
        
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        
        ListNode *fast = head;
        ListNode *slow = head;

        for(int i = 0; i < n + 1; i++)
        {
            if(fast == NULL)
            {
                dummy = dummy -> next;
                return dummy -> next;
            }

            fast = fast -> next;
        }

        while(fast != NULL)
        {
            fast = fast -> next;
            slow = slow -> next;
        }

        slow -> next = slow -> next -> next;

        ListNode *newHead = dummy -> next;
        delete dummy;

        return newHead;
    }
};