/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: list1 = [], list2 = []
Output: []

Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
*/
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

//The time and space complexity will be O(n) where n is the total no. of nodes in both the input linked lists

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
        {
            return list2;
        }

        if(list2 == NULL)
        {
            return list1;
        }

        ListNode* newHead = new ListNode();
        ListNode* newTail = new ListNode();

        if(list1 -> val > list2 -> val)
        {
            newHead = list2;
            newTail = list2;
            list2 = list2 -> next;
        }

        else
        {
            newHead = list1;
            newTail = list1;
            list1 = list1 -> next;
        }

        while(list1 != NULL && list2 != NULL)
        {
            if(list1 -> val > list2 -> val)
            {
                newTail -> next = list2;
                newTail = newTail -> next;
                list2 = list2 -> next;
            }

            else
            {
                newTail -> next = list1;
                newTail = newTail -> next;
                list1 = list1 -> next;
            }
        }

        if(list1 == NULL)
        {
            newTail -> next = list2;
        }

        if(list2 == NULL)
        {
            newTail -> next = list1;
        }
        return newHead;

    }
};
