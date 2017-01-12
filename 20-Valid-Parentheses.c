struct Stack {
	char * content;
	int capacity;
	int top;
};

struct Stack* stack_create(int capacity) {
	struct Stack* stack = malloc(sizeof(struct Stack));
	stack->content = malloc(sizeof(char) * capacity);
	stack->capacity = capacity;
	stack->top = -1;
	return stack;
}

void stack_destroy(struct Stack* stack) {
	free(stack->content);
	free(stack);
}

void push(struct Stack* stack, char elem) {
	if (stack->top < stack->capacity) {
		stack->top++;
		stack->content[stack->top] = elem;
	}
}

void pop(struct Stack* stack) {
	if (stack->top > -1) {
		stack->top--;
	}
}

char top(struct Stack* stack) {
	if (stack->top > -1) {
		return stack->content[stack->top];
	} else {
		return '\0';
	}
}

int is_empty(struct Stack* stack) {
	return (stack->top == -1);
}

bool isValid(char* s) {
	struct Stack * stack = stack_create(strlen(s));
	char * ptr = s;
	char temp;	
	while (*ptr) {
		temp = '\0';	
		if (*ptr == '(' || *ptr == '[' || *ptr == '{') {
			push(stack, *ptr);
		}
		if (*ptr == ')') {
			temp = top(stack);
			if (temp != '(') {
				return false;
			}
			pop(stack);
		}
		if (*ptr == ']') {
			temp = top(stack);
			if (temp != '[') {
				return false;
			}
	   		pop(stack);
		}
		if (*ptr == '}') {
			temp = top(stack);
			if (temp != '{') {
				return false;
			}
			pop(stack);
		}
		ptr++;
	}
	if (is_empty(stack)) {
		return true;
	} else {
		return false;
	}
}
