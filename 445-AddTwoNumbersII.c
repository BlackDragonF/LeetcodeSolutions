struct ListNode* recursiveAddTwoNumbers(struct ListNode* node1, struct ListNode* node2, int* flag) {
	struct ListNode * resultList = NULL;
	if (node1->next) {
		resultList = recursiveAddTwoNumbers(node1->next, node2->next, flag);
	} else {
		struct ListNode * resultList = malloc(sizeof(struct ListNode));
		resultList->next = NULL;
		resultList->val = node1->val + node2->val;
		if (resultList->val >= 10) {
			resultList->val -= 10;
			*flag = 1;
		} else {
			*flag = 0;
		}
		return resultList;
	}
	
	struct ListNode * newNode = malloc(sizeof(struct ListNode));	newNode->next = resultList;
	newNode->val = node1->val + node2->val + *flag;
	if (newNode->val >= 10) {
		newNode->val -= 10;
		*flag = 1;
	} else {
		*flag = 0;
	}
	
	return newNode;	
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	if (!(l1 && l2)) return NULL; 

	struct ListNode * node1 = l1;
	struct ListNode * node2 = l2;
	while (node1 && node2) {
		node1 = node1->next;
		node2 = node2->next;
	}

	int flag = 0;
	struct ListNode * resultList = NULL;
	if (node1 || node2) {
		struct ListNode * firstNode = NULL;
		struct ListNode * secondNode = NULL;
		struct ListNode * tailNode = NULL;
		if (!node2) {
			firstNode = l1;
			secondNode = node1;	
			node2 = l1;
		}
		if (!node1) {
			firstNode = l2;
			secondNode = node2;	
			node2 = l2;
		}

		node1 = malloc(sizeof(struct ListNode));
		node1->next = NULL;
		node1->val = 0;
		tailNode = node1;
		while (secondNode->next) {
			firstNode = firstNode->next;
			secondNode = secondNode->next;
			tailNode->next = malloc(sizeof(struct ListNode));
			tailNode = tailNode->next;
			tailNode->next = NULL;
			tailNode->val = 0;
		}
		tailNode->next = (node2 == l1)?l2:l1;
	} else {
		node1 = l1;
		node2 = l2;
	}
		
	resultList = recursiveAddTwoNumbers(node1, node2, &flag);
	if (flag == 0) {
		return resultList;
	} else {
		struct ListNode * newNode = malloc(sizeof(struct ListNode));
		newNode->next = resultList;
		newNode->val = 1;
		return newNode;
	}	

	return NULL;
}
