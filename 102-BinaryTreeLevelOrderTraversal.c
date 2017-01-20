/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Not: Both returned array and *columnSizes array must be malloced, assume caller calls 
free().
 */

typedef struct Queue {
	struct TreeNode ** base;
	int capacity;
	int front;
	int rear;
}Queue;

Queue * createQueue(int capacity) {
	Queue * queue = malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = 0;
	queue->rear = 0;
	queue->base = malloc(sizeof(struct TreeNode*) * capacity);
	return queue;
}

void destroyQueue(Queue * queue) {
	free(queue->base);
	free(queue);
}

bool isQueueEmpty(Queue * queue) {
	return (queue->front == queue->rear);
}

bool isQueueFull(Queue * queue) {
	return ((queue->rear + 1) % queue->capacity == queue->front);
}

void enqueue(Queue * queue, struct TreeNode * elem) {
	if(isQueueFull(queue)) return;
	queue->base[queue->rear] = elem;
	queue->rear = (queue->rear + 1) % queue->capacity;
}

struct TreeNode * frontAndDequeue(Queue * queue) {
	if (isQueueEmpty(queue)) return NULL;
	struct TreeNode * front = queue->base[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	return front;
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
	Queue * queue = createQueue(10000);
	enqueue(queue, root);
	struct TreeNode * levelEnd = root, * nextLevelEnd = NULL;
	int levelNumber = 0;	
	int index = 0;	
	struct TreeNode * node;	
	int level[1024];
	int	lists[1024][1024];	
	while (!isQueueEmpty(queue) && (node = frontAndDequeue(queue))) {
		lists[levelNumber][index] = node->val;		
		index++;
		if (node->right) {
				nextLevelEnd = node->right;
			} else if (node->left) {
				nextLevelEnd = node->left;
		} 
		if (node == levelEnd) {
			level[levelNumber] = index;	
			levelNumber++;	
			index = 0;	
			levelEnd = nextLevelEnd;
			nextLevelEnd = NULL;
		}
		if (node->left) enqueue(queue, node->left);
		if (node->right) enqueue(queue, node->right);
	}
	*returnSize = levelNumber;	
	int ** result = malloc(sizeof(int *) * levelNumber);
	int * levelResult = malloc(sizeof(int) * levelNumber);
	int i, j;
	for (i = 0 ; i < levelNumber ; ++i) {
		result[i] = malloc(sizeof(int) * level[i]);
		levelResult[i] = level[i];	
		for (j = 0 ; j < level[i] ; ++j) {
			result[i][j] = lists[i][j];
		}
	}
	*columnSizes = levelResult;
	return result;
}
