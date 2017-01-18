int compare(int * a, int * b) {
	return (*a) - (*b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
	qsort(g, gSize, sizeof(int), compare);
	qsort(s, sSize, sizeof(int), compare);
	int * gPtr = g;
	int * sPtr = s;
	while (gPtr - g < gSize && sPtr- s < sSize && *sPtr) {
		if (*gPtr <= *sPtr) {
			gPtr++;
		}
		sPtr++;
	}
	return gPtr - g;
}
