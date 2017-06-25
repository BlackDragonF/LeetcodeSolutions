bool isIsomorphic(char* s, char* t) {
	if (!*s) return false;	
	int charHashS[128], charHashT[128];
   	memset(charHashS, 0, sizeof(int) * 128);
	memset(charHashT, 0, sizeof(int) * 128);
	while (*s) {
		if (charHashS[*s] == 0 && charHashT[*t] == 0) {
		   	charHashS[*s] = *t;
			charHashT[*t] = *s;
		} else if (charHashS[*s] != *t || charHashT[*t] != *s) {
			return false;
		}
		s++;
		t++;
	}
	return true;
}
