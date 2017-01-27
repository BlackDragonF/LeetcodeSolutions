typedef struct Entry {
	int number;
	int frequency;	
	struct Entry * next;
}Entry;

typedef struct Hash {
	int bounds;
	Entry ** base;
}Hash;

Hash * createHash(int factor) {
	Hash * hash = malloc(sizeof(Hash));
	hash->bounds = factor;
	hash->base = malloc(sizeof(Entry *) * factor);
	int index;
	for (index = 0 ; index < factor ; ++index) {
		(hash->base)[index] = malloc(sizeof(Entry));
		(hash->base)[index]->next = NULL;
	}	
	return hash;
}

void destroyHash(Hash * hash) {
	int index;
	Entry * temp;	
	for (index = 0 ; index < hash->bounds ; ++index) {
		while((hash->base)[index]->next) {
			temp = (hash->base)[index]->next;
			(hash->base)[index]->next = temp->next;
			free(temp);
		}
		free((hash->base)[index]);
	}
	free(hash->base);
	free(hash);
}

bool hashInsert(Hash * hash, int number) {
	int index = abs(number) % hash->bounds;
	Entry * temp = (hash->base)[index]->next;
	while(temp) {
		if (temp->number == number) {
			temp->frequency++;	
			return false;
		}
		temp = temp->next;
	}
	Entry * newEntry = malloc(sizeof(Entry));
	newEntry->number = number;
	newEntry->frequency = 1;	
	newEntry->next = (hash->base)[index]->next;
	(hash->base)[index]->next = newEntry;
	return true;
}

typedef struct Heap {
	int capacity;
	int size;
	Entry ** elements;
}Heap;

Heap * createHeap(int capacity) {
	Heap * heap = malloc(sizeof(Heap));
	heap->capacity = capacity;
	heap->size = 0;
	heap->elements = malloc(sizeof(Entry *) * (capacity + 1));
	heap->elements[0] = malloc(sizeof(Entry));	
	heap->elements[0]->frequency = INT_MAX;	
	return heap;	
}

void destroyHeap(Heap * heap) {
	free((heap->elements)[0]);
	free(heap->elements);
	free(heap);
}

bool isHeapEmpty(Heap * heap) {
	return (heap->size == 0);
}

void heapInsert(Heap * heap, Entry * element) {
	int index;
	for (index = ++(heap->size) ; heap->elements[index / 2]->frequency < element->frequency ; index /= 2) {
		(heap->elements)[index] = (heap->elements)[index / 2];
	}
	(heap->elements)[index] = element;
}

Entry * heapDelete(Heap * heap) {
	Entry * minEntry, * lastEntry;
	minEntry = (heap->elements)[1];
	lastEntry = (heap->elements)[heap->size--];
	int index, child;
	for (index = 1 ; index * 2 <= heap->size ; index = child) {
		child = index * 2;
		if (child != heap->size && (heap->elements)[child + 1]->frequency > (heap->elements)[child]->frequency) {
			child++;
		}
		if (lastEntry->frequency < (heap->elements)[child]->frequency) {
			heap->elements[index] = heap->elements[child];
		} else {
			break;
		}
	}
	heap->elements[index] = lastEntry;
	return minEntry;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
	Entry * temp;	
	Hash * hash = createHash(numsSize * 2);
	int index;
	for (index = 0 ; index < numsSize ; ++index) {
		hashInsert(hash, nums[index]);
	}
	Heap * heap = createHeap(numsSize);
	for (index = 0 ; index < hash->bounds ; ++index) {
		temp = (hash->base)[index]->next;
		while (temp) {
			heapInsert(heap, temp);
			temp = temp->next;
		}
	}
	*returnSize = k;	
	int * result = malloc(sizeof(int) * k);
	for (index = 0 ; index < k ; ++index) {
		temp = heapDelete(heap);
		result[index] = temp->number;
	}	
	return result;	
}
