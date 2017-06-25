int countPrimes(int n) {
    if (n == 0) {
        return 0;
    }
	char array[n];
	int index;
	int die;
	int max = sqrt(n);
	int count = 0;
	for (index = 1 ; index < n ; ++index) {
		array[index] = 1;
	}
	for (die = 2 ; die <= max ; ++die) {
	    if (array[die]) {
	        index = die * 2;
	        while (index < n) {
	            array[index] = 0;
	            index += die;
	        }
	    }
	}
	for (index = 2 ; index < n ; ++index) {
		if (array[index]) {
			count++;
		}
	}
	return count;	
}

