int firstUniqChar(char* s) {
	int charHash[128];
	char * temp = s;	
	char * base = s;	
	memset(charHash, 0, sizeof(int) * 128);	
	while(*s) {
		charHash[*s]++;
	   	s++;
	}
	while (*temp) {
		if (charHash[*temp] == 1) {
			return (temp-base);
		}
		temp++;
	}
	return -1;	
}
