char* longestCommonPrefix(char** strs, int strsSize) {
	if (!strs[0]) return "";
	char * cursor = strs[0];
	int length = 0;
	int index;
	while (strsSize > 1) {
		for (index = 1 ; index < strsSize ; ++index) {
			if(*cursor != strs[index][length]) {
				char * result = malloc(sizeof(char) * (length + 1));
				strncpy(result, strs[0], length);
				result[length] = '\0';
				return result;
			}
		}
		cursor++;
		length++;	
	}
	return strs[0];
}
