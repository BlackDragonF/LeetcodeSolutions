typedef struct Node {
	int number;
	struct LinkedList * next;
}Node;

typedef struct List {
	Node * current;
	Node * head; 
	Node * tail;
}List;

bool isSubsequence(char* s, char* t) {
	List charHash[26];
	int index;
	for (index = 0 ; index < 26 ; ++index) {
		charHash[index].head = malloc(sizeof(Node));
		charHash[index].head->next = NULL;
		charHash[index].head->number = 0;	
		charHash[index].tail = charHash[index].head;	
		charHash[index].current = charHash[index].head;	
	}
	index = 1;	
	char * temp = t;
	while (*temp) {
		Node * node = malloc(sizeof(Node));
		node->number = index++;
		node->next = NULL;
		charHash[*temp - 'a'].tail->next = node;
		charHash[*temp - 'a'].tail = charHash[*temp - 'a'].tail->next;	
		temp++;
	}
	temp = s;
	index = 0;
	while (*temp) {
	    do {
	        charHash[*temp - 'a'].current = charHash[*temp - 'a'].current->next;
	    } while (charHash[*temp - 'a'].current && charHash[*temp - 'a'].current->number 
<= index);
		if (!charHash[*temp - 'a'].current) return false;
		index = charHash[*temp - 'a'].current->number;
		temp++;
	}
	return true;	
}

