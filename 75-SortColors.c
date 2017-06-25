void sortColors(int* nums, int numsSize) {
	int * head = nums;
	int * tail = nums + numsSize - 1;
	int * current = head;
	int temp;	
	while (current <= tail) {
		if (*current == 0) {
			temp = *head;
			*head = *current;
			*current = temp;
			do {
			    head++;
			} while (*head == 0);
			if (head - current > 0) current = head;
		} else if (*current == 2) {
			temp = *tail;
			*tail = *current;
			*current = temp;
			do {
			    tail--;
			} while (*tail == 2);
		} 
		while (*current == 1) {
				current++;
		}
	}
}

