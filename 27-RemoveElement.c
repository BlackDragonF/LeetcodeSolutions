int removeElement(int* nums, int numsSize, int val) {
	int * head = nums, * tail = head;
	int temp;	
	
	if (numsSize <= 0) return 0;	
	
	while(1) {
				
		while (*head != val) {
	   		head++;
   			tail++;
			if (tail - nums >= numsSize) return (head-nums);	
		}	
	
		while (*tail == val) {
			tail++;
			if (tail - nums >= numsSize) return (head-nums);	
		}

		temp = *head;
		*head = *tail;
		*tail = temp;	
	}	

}
