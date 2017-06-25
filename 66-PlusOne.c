int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int * last = digits + digitsSize - 1;
	int flag = 0;

	(*last)++;	
	
	while (last - digits >= 0) {
		if (flag == 1) {
			(*last)++;
			flag = 0;
		}	
		if (*last > 9) {
			*last = 0;
			flag = 1;
		}
		last--;
	}

	int * returnArray = NULL;
	if (flag == 1) {
		*returnSize = digitsSize + 1;
		returnArray = malloc(sizeof(int) * (digitsSize + 1));
		memcpy(returnArray + 1, digits, sizeof(int) * digitsSize);
		returnArray[0] = 1;
	} else {
		*returnSize = digitsSize;
		returnArray = malloc(sizeof(int) * digitsSize);
		memcpy(returnArray, digits, sizeof(int) * digitsSize);
	}
	return returnArray;	
}
