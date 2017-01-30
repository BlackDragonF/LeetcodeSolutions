typedef struct Heap {
	int capacity;
	int size;
	int * elements;
}Heap;

Heap * createHeap(int capacity) {
	Heap * heap = malloc(sizeof(Heap));
	heap->capacity = capacity;
	heap->size = 0;
	heap->elements = malloc(sizeof(int) * (capacity + 1));
	heap->elements[0] = INT_MIN;	
	return heap;	
}

void destroyHeap(Heap * heap) {
	free(heap->elements);
	free(heap);
}

bool isHeapEmpty(Heap * heap) {
	return (heap->size == 0);
}

void heapInsert(Heap * heap, int element) {
	int index;
	for (index = ++(heap->size) ; heap->elements[index / 2] > element ; index /= 2) {
		(heap->elements)[index] = (heap->elements)[index / 2];
	}
	(heap->elements)[index] = element;
}

int heapDelete(Heap * heap) {
	int min, last;	
	min = (heap->elements)[1];
	last = (heap->elements)[heap->size--];
	int index, child;
	for (index = 1 ; index * 2 <= heap->size ; index = child) {
		child = index * 2;
		if (child != heap->size && (heap->elements)[child + 1] < (heap->elements)[child]) {
			child++;
		}
		if (last > (heap->elements)[child]) {
			heap->elements[index] = heap->elements[child];
		} else {
			break;
		}
	}
	heap->elements[index] = last;
	return min;
}

int kthSmallest(int** matrix, int matrixRowSize, int matrixColSize, int k) {
	Heap * heap = createHeap(matrixRowSize * matrixColSize);
	int i, j;
	for (i = 0 ; i < matrixRowSize ; ++i) {
		for (j = 0 ; j < matrixColSize ; ++j) {
			heapInsert(heap, matrix[i][j]);
		}
	}
	int result;	
	for (i = 0 ; i < k ; ++i) {
		result = heapDelete(heap);
	}
	return result;
}
