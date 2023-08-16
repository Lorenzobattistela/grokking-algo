#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    int val;
    struct Node *neighbors[];
};

struct Queue {
    int size;
    int occupied;
    int last;
    struct Node *arr[];
};


struct Node *createNode(int val, struct Node *neighbors, int neighborsSize);
void deleteNode(struct Node *n);
struct Queue *createQueue(int size);
void deleteQueue(struct Queue *q);
void enqueue(struct Queue *q, struct Node *n);
struct Node *dequeue(struct Queue *q);

struct Node *dequeue(struct Queue *q) {
    if(!q) exit(1);

    return q->arr[q->last];
    q->last += 1;
}

void enqueue(struct Queue *q, struct Node *n) {
    if(!q || !n) exit(1);

    q->arr[q->occupied] = n;
    q->occupied += 1;
}

void deleteQueue(struct Queue *q) {
    if(!q) exit(1);
    free(q);
}

struct Queue *createQueue(int size) {
    struct Queue *q = malloc(sizeof(struct Queue) + size * sizeof(struct Node));
    if(!q) exit(1);
    
    q->size = size;
    q->occupied = 0;
    q->last = 0;
    return q;
}

void deleteNode(struct Node *n) {
    if(n) free(n);
}

struct Node *createNode(int val, struct Node *neighbors, int neighborsSize) {
    struct Node *n = malloc(sizeof(struct Node) + neighborsSize * sizeof(struct Node));
    if(!n) exit(1);
    n->val = val;
    for(int i = 0; i < neighborsSize; i++) {
        n->neighbors[i] = NULL;
    }
    return n;
}

int main(void) {
    struct Node *n = 
}