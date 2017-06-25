bool canConstruct(char* ransomNote, char* magazine) {
	int charHash[26];
	memset(charHash, 0, sizeof(int) * 26);	
	char * temp = magazine;
	while (*temp) {
		charHash[*temp - 'a']++;
		temp++;
	}
	temp = ransomNote;
	while (*temp) {
		if (charHash[*temp - 'a']) {
			charHash[*temp - 'a']--;
		} else {
			return false;
		}
		temp++;
	}
	return true;	
}
