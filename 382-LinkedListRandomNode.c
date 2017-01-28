/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct {
	int res;
	int num;	
	struct ListNode * head;
} Solution;

/** @param head The linked list's head.
       Note that the head is guaranteed to be not null, so it contains at least one node. 
*/
Solution* solutionCreate(struct ListNode* head) {
	Solution * sol = malloc(sizeof(Solution));
	sol->res = 0;
	sol->num = 0;
	sol->head = head;
	return sol;
}

/** Returns a random node's value. */
int solutionGetRandom(Solution* obj) {
	struct ListNode * temp = obj->head->next;
	int ran;	
	obj->res = obj->head->val;
	obj->num = 1;
	while (temp) {	
		ran = rand() % (obj->num + 1);
		if (ran == 0) {
			obj->res = temp->val;
		}
		obj->num++;
		temp = temp->next;	
	}	
	return obj->res;
}

void solutionFree(Solution* obj) {
	free(obj); 
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 * solutionFree(obj);
 */
