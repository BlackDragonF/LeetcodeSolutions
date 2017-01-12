int maxProfit(int* prices, int pricesSize) {
	int lowestPrice = prices[0];
	int maxProfit = 0;	
	int index;
	for (index = 1 ; index < pricesSize ; ++index) {
		if (prices[index] - lowestPrice > maxProfit) {
			maxProfit = prices[index] - lowestPrice;
		}
		if (prices[index] < lowestPrice) {
			lowestPrice = prices[index];
		}
	}
	return maxProfit;
}
