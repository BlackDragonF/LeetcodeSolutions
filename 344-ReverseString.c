char* reverseString(char* s) {	
	char * head = s;
	char * tail = s;
	char temp;	
	while (*tail) {
		tail++;
	}
	--tail;
	while (tail > head) {
		temp = *tail;
		*tail = *head;
		*head = temp;
		head++;
		tail--;
	}
	return s;
}
