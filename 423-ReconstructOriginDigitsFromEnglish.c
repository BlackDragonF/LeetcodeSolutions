char* originalDigits(char* s) {
	int charHash[26];
	memset(charHash, 0, sizeof(int) * 26);	
	char * temp = s;
	while (*temp) {
		charHash[*temp - 'a']++;	
		temp++;
	}
	int digitHash[10];
	memset(digitHash, 0, sizeof(int) * 10);	
	while (charHash['z' - 'a']) {
		charHash['z' - 'a']--;
		charHash['e' - 'a']--;
		charHash['r' - 'a']--;
		charHash['o' - 'a']--;
		digitHash[0]++;	
	}
	while (charHash['w' - 'a']) {
		charHash['t' - 'a']--;
		charHash['w' - 'a']--;
		charHash['o' - 'a']--;
		digitHash[2]++;	
	}
	while (charHash['u' - 'a']) {
		charHash['f' - 'a']--;
		charHash['o' - 'a']--;
		charHash['u' - 'a']--;
		charHash['r' - 'a']--;
		digitHash[4]++;	
	}
	while (charHash['x' - 'a']) {
		charHash['s' - 'a']--;
		charHash['i' - 'a']--;
		charHash['x' - 'a']--;
		digitHash[6]++;	
	}
	while (charHash['g' - 'a']) {
		charHash['e' - 'a']--;
		charHash['i' - 'a']--;
		charHash['g' - 'a']--;
		charHash['h' - 'a']--;
		charHash['t' - 'a']--;	
		digitHash[8]++;	
	}
	digitHash[3] += charHash['r' - 'a'];
	digitHash[1] += charHash['o' - 'a'];
	digitHash[5] += charHash['f' - 'a'];
	digitHash[7] += charHash['s' - 'a'];
	digitHash[9] += charHash['i' - 'a'] - digitHash[5];
	char * result = malloc(sizeof(char) * 16667);
	memset(result, 0, sizeof(char) * 16667);
	temp = result;
	int index;
	for (index = 0 ; index < 10 ; ++index) {
		while (digitHash[index]) {
			*temp = '0' + index;
			temp++;
			digitHash[index]--;
		}
	}
	return result;	
}
