/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Entry {
	int number;
	int mark;
	struct Entry * next;
}Entry;

typedef struct Hash {
	int bounds;
	Entry ** base;
	int number;
}Hash;

Hash * createHash(int factor) {
	Hash * hash = malloc(sizeof(Hash));
	hash->bounds = factor;
	hash->number = 0;	
	hash->base = malloc(sizeof(Entry *) * factor);
	int index;
	for (index = 0 ; index < factor ; ++index) {
		(hash->base)[index] = malloc(sizeof(Entry));
		(hash->base)[index]->number = -1;
		(hash->base)[index]->mark = 0;
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

bool hashInsert(Hash * hash, int number, int mark) {
	int index = abs(number) % hash->bounds;
	Entry * temp = (hash->base)[index]->next;
	while(temp) {
		if (temp->number == number) {
		    if (temp->mark & mark) {
		        return false;
		    } else {
		        temp->mark += mark;
		        hash->number++;
		        return true;
		    }
		}
		temp = temp->next;
	}
	Entry * newEntry = malloc(sizeof(Entry));
	newEntry->number = number;
	newEntry->mark = mark;
	newEntry->next = (hash->base)[index]->next;
	(hash->base)[index]->next = newEntry;
	return true;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	Hash * hash = createHash(nums1Size + nums2Size);
	int index;
	for (index = 0 ; index < nums1Size ; ++index) {
		hashInsert(hash, nums1[index], 1);
	}
	for (index = 0 ; index < nums2Size ; ++index) {
		hashInsert(hash, nums2[index], 2);
	}
	*returnSize = hash->number;
	int * result = malloc(sizeof(int) * (*returnSize));
	int count = 0;	
	for (index = 0 ; index < nums1Size + nums2Size ; ++index) {
		Entry * temp = (hash->base)[index]->next;
		while (temp) {
			if (temp->mark == 3) {
			    result[count] = temp->number;
			    count++;
			}
			temp = temp->next;
		}
	}
	return result;
}	


