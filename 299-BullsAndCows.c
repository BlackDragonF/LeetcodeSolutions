char* getHint(char* secret, char* guess) {
	int digitHashS[10], digitHashG[10];
	memset(digitHashS, 0, sizeof(int) * 10);
	memset(digitHashG, 0, sizeof(int) * 10);
	int bulls = 0, cows = 0;
	char * tempS = secret, * tempG = guess;
	while (*tempS) {
		if (*tempS == *tempG) {
			bulls++;
		}
		digitHashS[*tempS - '0']++;
		digitHashG[*tempG - '0']++;
		tempS++;
		tempG++;
	}	
	int index;
	for (index = 0 ; index < 10 ; ++index) {
		if (digitHashS[index] <= digitHashG[index]) {
			cows += digitHashS[index];
		} else {
			cows += digitHashG[index];
		}
	}
	cows -= bulls;
   	char * result = malloc(sizeof(char) * 100001);
	snprintf(result, 100000, "%dA%dB", bulls, cows);
	return result;	
}
