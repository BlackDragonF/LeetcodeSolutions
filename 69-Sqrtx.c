int mySqrt(int x) {
    int low = 1, high = x;
    int mid = x;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if ((long)mid * mid == x) {
            return mid;
        } else if ((long)mid * mid > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if ((long)mid * mid <= x) {
        return mid;
    } else {
        return mid - 1;
    }
}
