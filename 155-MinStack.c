typedef struct minStack{
	int maxSize;
	int * base;
	int top;
	struct minStack * min;	
} MinStack;

MinStack* minStackCreate(int maxSize) {
	MinStack * stack = malloc(sizeof(MinStack));
	stack->maxSize = maxSize;
   	stack->top = -1;
	stack->base = malloc(sizeof(int) * maxSize);
	stack->min = malloc(sizeof(MinStack));
	stack->min->maxSize = maxSize;
	stack->min->top = -1;	
	stack->min->base = malloc(sizeof(int) * maxSize);	
	stack->min->min = NULL;	
	return stack;	
}

void minStackPush(MinStack* obj, int x) {	
	if (obj->top == -1) {
		obj->min->base[++obj->min->top] = x;
	} else if (obj->min->base[obj->min->top] >= x) {
		obj->min->base[++obj->min->top] = x;
	}
	obj->base[++obj->top] = x;
}

void minStackPop(MinStack* obj) {
	int temp = obj->base[obj->top];
	obj->top--;
	if (temp == obj->min->base[obj->min->top]) {
		obj->min->top--;
	}
}

int minStackTop(MinStack* obj) {
	return obj->base[obj->top];
}

int minStackGetMin(MinStack* obj) {
	return obj->min->base[obj->min->top];
}

void minStackFree(MinStack* obj) {
	free(obj->min->base);
	free(obj->min);
	free(obj->base);	
	free(obj);
}
