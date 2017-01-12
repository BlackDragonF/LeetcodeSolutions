int commonPrefixLength(char * s, char * t) {
	int count = 0;
	while (*s && *t && *s == *t) {
		count++;
		s++;
		t++;	
	}
	return count;
}


char* longestCommonPrefix(char** strs, int strsSize) {
	if (!strs[0]) return "";
	int longestPrefixLength = strlen[strs[0]];
	int prefixLength;
	int count;
	for (count = 1 ; count < strsSize - 1 ; ++count) {
		prefixLength = commonPrefixLength(strs[count], strs[count+1]);
		if (prefixLengh < longestPrefixLength) {
			longestPrefixLength = prefixLength;
		}
	}
	char * result = malloc(sizeof(char) * (longestPrefixLength + 1));	
	memset(result, 0, (longestPrefixLength + 1));
	strncpy(result, strs[0], longestPrefixLength);
   	return result;
}
