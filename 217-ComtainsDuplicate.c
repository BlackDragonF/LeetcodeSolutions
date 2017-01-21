typedef struct Entry {
	int number;
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
		(hash->base)[index]->number = -1;
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
			return false;
		}
		temp = temp->next;
	}
	Entry * newEntry = malloc(sizeof(Entry));
	newEntry->number = number;
	newEntry->next = (hash->base)[index]->next;
	(hash->base)[index]->next = newEntry;
	return true;
}

bool containsDuplicate(int* nums, int numsSize) {
	Hash * hash = createHash(numsSize * 2);
	int index;
	bool result;
	for (index = 0 ; index < numsSize ; ++index) {
		result = hashInsert(hash, nums[index]);
		if (!result) {
			return true;
		}
	}
	return false;
}
