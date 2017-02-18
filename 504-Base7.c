char* convertToBase7(int num) {
    char result[11];
    result[10] = '\0';
    int sign = (num >= 0) ? 1 : -1;
    num *= sign;
    int index = 9;
    int digit;
    do {
        digit = num % 7;
        num = num / 7;
        result[index--] = digit + '0';
    } while (num);
    if (sign < 0) result[index--] = '-';
    char * returnResult = malloc(sizeof(char) * (10 - index - 1));
    strcpy(returnResult, result + index + 1);
    return returnResult;
}
