/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Entry {
	int number;
    int count;
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
	int index = labs(number) % hash->bounds;
	Entry * temp = (hash->base)[index]->next;
	while(temp) {
		if (temp->number == number) {
            temp->count++;
            return true;
		}
		temp = temp->next;
	}
	Entry * newEntry = malloc(sizeof(Entry));
	newEntry->number = number;
    newEntry->count = 1;
	newEntry->next = (hash->base)[index]->next;
	(hash->base)[index]->next = newEntry;
	return true;
}

bool hashDelete(Hash * hash, int number) {
    int index = labs(number) % hash->bounds;
    Entry * temp = (hash->base)[index]->next;
    while(temp) {
        if (temp->number == number) {
            if (temp->count > 0) {
                temp->count--;
                return true;
            } else {
                return false;
            }
        }
        temp = temp->next;
    }
    return false;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    Hash * hash = createHash(nums2Size + nums1Size);
    int index;
    for (index = 0 ; index < nums1Size ; ++index) {
        hashInsert(hash, nums1[index]);
    }
    int * result = malloc(sizeof(int) * nums2Size);
    int count = 0;
    for (index = 0 ; index < nums2Size ; ++index) {
        if (hashDelete(hash, nums2[index]) == true) {
            result[count++] = nums2[index];
        }
    }
    *returnSize = count;
    return result;
}
