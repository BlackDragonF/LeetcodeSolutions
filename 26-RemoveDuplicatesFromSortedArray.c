int removeDuplicates(int* nums, int numsSize) {
	int * head = nums, * tail = nums;
	if (numsSize <= 0) return 0;
	while (1) {	
	    while (*head == *tail) {
	   		tail++;
			if (tail-nums >= numsSize) return (head-nums+1);
		}
	  	head++;
		*head = *tail;	
	}
	return 0;
}
