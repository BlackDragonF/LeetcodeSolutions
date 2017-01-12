void merge(int* nums1, int m, int* nums2, int n) {
	int * insertPtr = nums1 + m + n;
	int * numsPtr1 = nums1 + m - 1;
	int * numsPtr2 = nums2 + n - 1;

	while (insertPtr - nums1 >= 0) {	
		insertPtr--;
		if (numsPtr1 - nums1 < 0 || (numsPtr2 - nums2 >= 0 && *numsPtr1 < *numsPtr2)) {
			*insertPtr = *numsPtr2;
			numsPtr2--;	
			continue;	
		} 
		if (numsPtr2 - nums2 < 0 || (numsPtr1 - nums1 >= 0 && *numsPtr1 >= *numsPtr1)) {
			*insertPtr = *numsPtr1;
			numsPtr1--;
			continue;	
		}
	}
}
