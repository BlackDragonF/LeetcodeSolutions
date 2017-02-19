bool isPerfectSquare(int num) {
    unsigned long low = 1;
    unsigned long high = (num + 1) / 2;
    unsigned long mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        printf("%15d", mid * mid);
        if (mid * mid == num) {
            return true;
        } else if (mid * mid > num || mid * mid < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return false;
}
