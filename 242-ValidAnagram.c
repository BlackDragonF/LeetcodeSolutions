bool isAnagram(char* s, char* t) {
	int table_s[26], table_t[26];
	memset(table_s, 0, 26 * sizeof(int));
	memset(table_t, 0, 26 * sizeof(int));
	while (*s) {
		table_s[*s-'a']++;
		s++;	
	}
	while (*t) {
		table_t[*t-'a']++;
		t++;
	}	
	int index;
	for (index = 0 ; index < 26 ; ++index) {
		if (table_s[index] != table_t[index]) {
			return false;
		}
	}
	return true;	
}
