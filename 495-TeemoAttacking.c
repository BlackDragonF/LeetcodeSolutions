int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
	int index;
	int last = timeSeries[0];	
	int result = 0;	
	for (index = 0 ; index < timeSeriesSize ; ++index) {
		if (last <= timeSeries[index]) {
			result += duration;
		} else {
			result += timeSeries[index] - last + duration;
		}	
		last = timeSeries[index] + duration;
	}
	return result;
}
