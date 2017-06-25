char findTheDifference(char* s, char* t) {
	char result = *t;
	t++;	
	while (*t) {
		result = result ^ (*t);
		t++;	
	}	
	while (*s) {
		result = result ^ (*s);
		s++;
	}
	return result;	
}
