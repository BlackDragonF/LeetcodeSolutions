typedef struct Node {
	int number;
	struct LinkedList * next;
}Node;

typedef struct List {
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
	}
	index = 1;	
	char * temp = s;
	while (*temp) {
		Node * node = malloc(sizeof(Node));
		node->number = index++;
		node->next = NULL;
		charHash[*temp - 'a'].tail->next = node;
		charHash[*temp - 'a'].tail = charHash[*temp - 'a'].tail->next;	
		temp++;
	}
	int len = index;
	Node * mark[26];
	for (index = 0 ; index < 26 ; ++index) {
	    mark[index] = charHash[index].head->next;
	}
	temp = t;
	index = 1;
	while (*temp) {
	    if (mark[*temp - 'a'] && index == mark[*temp - 'a']->number) {
	        mark[*temp - 'a'] = mark[*temp - 'a']->next;
	        index++;
	    }
		temp++;
	}
	return (index == len);	
}

