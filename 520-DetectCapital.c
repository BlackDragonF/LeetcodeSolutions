bool detectCapitalUse(char* word) {
    int state; //0->full-capital 1->capital 2->non-capital
    if (*word && isupper(*word++)) {
        if (!*word) {
            return true;
        } else if (isupper(*word++)) {
            state = 0;
        } else {
            state = 1;
        }
    } else {
        state = 2;
    }
    if (state == 1 || state == 2) {
        while (*word) {
            if (isupper(*word++)) {
                return false;
            }
        }
    } else {
        while (*word) {
            if (islower(*word++)) {
                return false;
            }
        }
    }
    return true;
}
