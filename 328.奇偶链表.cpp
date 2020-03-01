/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
 		ListNode *odd = NULL, *even = NULL;
		ListNode *even_h = NULL;
		ListNode *curr = head;
		int count = 1;
		while (curr)
		{
			if (count == 1)
				odd = curr;
			else if (count == 2)
				even = even_h = curr;
			else
			{
				if (count % 2 != 0)
				{
					odd->next = curr;
					odd = odd->next;
				}
				else
				{
					even->next = curr;
					even = even->next;
					//even->next = NULL;
				}
			}
			count++;
			curr = curr->next;
		}
        // if (odd)
		    odd->next = even_h;
		// if (even)
            even->next = NULL;
		return head;
    }
};
// @lc code=end

