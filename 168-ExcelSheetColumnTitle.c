char* convertToTitle(int n) {
	char result[8];
	result[7] = '\0';
	int index = 6;
	while (n) {
		result[index] = (n - 1) % 26 + 'A';
		n = (n - 1) / 26;
		index--;
	}
	char * result2 = malloc(sizeof(char) * (7 - index));
	strcpy(result2, result + index + 1);
	return result2;
}
