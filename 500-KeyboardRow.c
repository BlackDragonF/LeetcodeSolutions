char** findWords(char** words, int wordsSize, int* returnSize) {
    if (wordsSize <= 0) return NULL;
    char charHash[26] = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};
    char * string[wordsSize];
    int index;
    char * temp = NULL;
    int result;
    int count = 0;
    for (index = 0 ; index < wordsSize ; ++index) {
        temp = words[index];
        do {
            result = charHash[tolower(*temp) - 'a'];
            temp++;
        } while (*temp && result == charHash[tolower(*temp) - 'a']);
        if (!*temp) {
            string[count++] = words[index];
        }
    }
    *returnSize = count;
    char ** resultString = malloc(sizeof(char *) * count);
    for (index = 0 ; index < count ; ++index) {
         resultString[index] = malloc(sizeof(char) * strlen(string[index] + 1));
         strcpy(resultString[index], string[index]);
    }
    return resultString;
}
