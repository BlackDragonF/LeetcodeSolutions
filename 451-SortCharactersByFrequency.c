typedef struct CharHash {
	char key;
	int number;
}CharHash;

typedef struct Entry {
	CharHash * charHash;
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
		(hash->base)[index]->charHash = NULL;
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

bool hashInsert(Hash * hash, CharHash * charHash) {
	int index = charHash->number % hash->bounds;
	Entry * temp = (hash->base)[index]->next;
	while(temp) {
		if (temp->charHash->key == charHash->key) {
			return false;
		}
		temp = temp->next;
	}
	Entry * newEntry = malloc(sizeof(Entry));
	newEntry->charHash = charHash;
	newEntry->next = (hash->base)[index]->next;
	(hash->base)[index]->next = newEntry;
	return true;
}


char* frequencySort(char* s) {
	CharHash charHash[128];
	int index;
	for (index = 0 ; index < 128 ; ++index) {
		charHash[index].key = index;
		charHash[index].number = 0;	
	}	
	char * temp = s;
	int count = 0;
	while (*temp) {
		charHash[*temp].number++;
		temp++;
		count++;	
	}
	Hash * hash = createHash(count + 1);
	for (index = 0 ; index < 128 ; ++index) {
		if(charHash[index].number) {
		    hashInsert(hash, &charHash[index]);
		}
	}
	char * result = malloc(sizeof(char) * (count + 1));
	temp = result;			
	Entry * entry;
	for (index = count ; index > 0 ; --index) {
	    entry = (hash->base)[index]->next;
	    while (entry) {
	        count = index;
	        while (count > 0) {
	            *temp = (entry->charHash)->key;
	            temp++;
	            count--;
	        }
	        entry = entry->next;
	    }
	}
	*temp = '\0';
	return result;	
}

