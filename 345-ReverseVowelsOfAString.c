char* reverseVowels(char* s) {	
	char * head = s;
	char * tail = s;
	char temp;	
	while (*tail) {
		tail++;
	}
	--tail;
	while (1) {
		while (*head && *head != 'a' && *head != 'e' && *head != 'i' && *head != 'o' && *head != 'u' && *head != 'A' && *head != 'E' && *head != 'I' && *head != 'O' && *head != 'U') {
			head++;
		}
		while (*tail && *tail != 'a' && *tail != 'e' && *tail != 'i' && *tail != 'o' && *tail != 'u' && *tail != 'A' && *tail != 'E' && *tail != 'I' && *tail != 'O' && *tail != 'U') {
			tail--;
		}
		if (head >= tail) {
			return s;
		}
		temp = *head;
		*head = *tail;
		*tail = temp;
		head++;
		tail--;
	}		
		
	return s;
}
