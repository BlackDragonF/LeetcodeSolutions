char* toHex(int num) {
	char alphabet[] = "0123456789abcdef";
	char temp[9];
	temp[8] = '\0';	
	char * result;	
	int index = 0;
	int mask = 0xf;
	for (index = 7 ; num && index >= 0 ; --index) {
		temp[index] = alphabet[num & mask];
		num >>= 4;
	}
	if (index == 7) {
		result = malloc(sizeof(char) * 2);
		result[0] = '0';
		result[1] = '\0';
	} else {
		result = malloc(sizeof(char) * (8 - index));
		strncpy(result, temp+index+1, 8-index);
	}
	return result;	
}
