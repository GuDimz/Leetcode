

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* resList;
		for (; ;) {
			if (!list1 && !list2) {
				break;
			}
			if (!list1) {
				resList->next = list2;
				list2 = list2->next;
			} else if (!list2) {
				resList->next = list1;
				list1 = list1->next;
			} else if (list1->val < list2->val) {
				resList->next = list1;
				list1 = list1->next;
			} else {
				resList->next = list2;
				list2 = list2->next;
			}
			resList = resList->next;
		}
		resList->next = nullptr;
		return resList;
	}
};