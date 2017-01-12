bool isPalindrome(char* s) {
	char * head = s;
	char * tail = s;
	char sign = '\0';	

	while (*tail) {
		tail++;
	}
	tail--;

	while (tail > head) {
		while (!isdigit(*head) && !isalpha(*head)) {
			head++;
			if (tail < head) {
				head = &sign;	
				break;
			}	
		}
		while (!isdigit(*tail) && !isalpha(*tail)) {
			tail--;
			if (tail < head) {
				tail = &sign;
				break;
			}	
		}
		if (tolower(*tail) != tolower(*head)) {
			return false;
		}	
	   	head++;
	   	tail--;
	}
	return true;	

}
