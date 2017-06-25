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
	int index = number % hash->bounds;
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

bool isHappy(int n) {
	int m = 0;
	Hash * hash = createHash(19);
	hashInsert(hash, n);	
	do {	
		while (n) {
			m += (n % 10) * (n % 10);
			n /= 10;
		}
		if (m == 1) return true;
		n = m;
		m = 0;	
	} while (hashInsert(hash, n));
	return false;
}
