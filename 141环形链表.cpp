/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
给定一个链表，判断链表中是否有环。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
		ListNode *temp_head = head;
		unordered_set<ListNode*> list_pt_map;
        while(temp_head!=NULL){
			if(list_pt_map.count(temp_head)){
				return true;
				break;
			}
			else{
				list_pt_map.insert(temp_head);
			}
			temp_head = temp_head->next;
		}
		return false;
    }

	 bool hasCycle2(ListNode *head) {
		ListNode *fast = head;
		ListNode *slow = head;
        while((fast!= nullptr)&&(fast->next!= nullptr)){
			fast = fast->next->next;
			slow = slow->next;
			if(fast == slow)
				return true;
		}
		return false;
    }
};