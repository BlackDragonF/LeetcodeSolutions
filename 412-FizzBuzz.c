char * fizz = "Fizz";
char * buzz = "Buzz";
char * fizzbuzz = "FizzBuzz";

void fromIntToChar(int n, char ** pstr) {
	char temp[33];
	temp[32] = '\0';
	int index = 31;	
	while (n > 0) {
		temp[index] = n % 10 + '0';
		index--;
		n /= 10;
	}
	*pstr = malloc(sizeof(char) * (32-index));
	strcpy(*pstr, temp+index+1);
	return;	
}

char** fizzBuzz(int n, int* returnSize) {
	*returnSize = n;
	char ** results = malloc(sizeof(char *) * n);
	int index;
	int threeCount = 2;
	int fiveCount = 4;	
	for (index = 0 ; index < n ; ++index) {
		if (!threeCount & !fiveCount) {
			results[index] = malloc(sizeof(char) * 9);
			strcpy(results[index], fizzbuzz);	
			threeCount = 3;	
			fiveCount = 5;	
		} else if (!threeCount)	{
		   	results[index] = malloc(sizeof(char) * 5);
			strcpy(results[index], fizz);
			threeCount = 3;	
		} else if (!fiveCount) {
			results[index] = malloc(sizeof(char) * 5);
			strcpy(results[index], buzz);
			fiveCount = 5;	
		} else {
			fromIntToChar(index+1, results+index);
		}			
		fiveCount--;
		threeCount--;	
	}
	return results;
}
