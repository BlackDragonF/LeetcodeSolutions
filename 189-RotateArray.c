void reverse(int* nums, int numsSize) {
	int * head = nums;
	int * tail = nums + numsSize - 1;
	int temp;
	
	while (tail - head > 0) {
		temp = *head;
		*head = *tail;
		*tail = temp;
		head++;
		tail--;
	}
}


void rotate(int* nums, int numsSize, int k) {
	k = k % numsSize;
	reverse(nums, numsSize);
	reverse(nums, k);
	reverse(nums + k, numsSize - k);
}
