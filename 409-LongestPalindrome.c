#define mapFunc(x) ((x)>=65&&(x)<=90)?((x)-'A'):(((x)>=97&&(x)<=122)?((x)-'a'+26):52)


int longestPalindrome(char* s) {
	int charHash[53];
	memset(charHash, 0, sizeof(int) * 53);
	char * temp = s;
   	while(*temp) {
		charHash[mapFunc(*temp)]++;
		temp++;	
	}
	int midFlag = 0;
	int result = 0;	
	int index;	
	for (index = 0 ; index < 52 ; ++index) {
		if (charHash[index] % 2 == 1) {
			midFlag = 1;
		}
		result += charHash[index] / 2;
	}
	return result * 2 + midFlag;	
}
