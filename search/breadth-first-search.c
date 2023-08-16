#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct Queue {
    int size;
    int occupied;
    int last;
    struct Node **arr;
};

struct Node *createNode(int val);
struct Queue *createQueue(int size);
void enqueue(struct Queue *q, struct Node *n);
struct Node *dequeue(struct Queue *q);

struct Node *createNode(int val) {
    struct Node *n = malloc(sizeof(struct Node));
    if (!n) exit(1);
    n->val = val;
    n->next = NULL;
    return n;
}

struct Queue *createQueue(int size) {
    struct Queue *q = malloc(sizeof(struct Queue));
    if (!q) exit(1);
    q->size = size;
    q->occupied = 0;
    q->last = 0;
    q->arr = malloc(size * sizeof(struct Node *));
    if (!q->arr) exit(1);
    return q;
}

void enqueue(struct Queue *q, struct Node *n) {
    if (!q || !n) exit(1);

    q->arr[q->occupied] = n;
    q->occupied += 1;
}

struct Node *dequeue(struct Queue *q) {
    if (!q) exit(1);
    struct Node *node = q->arr[q->last];
    q->last += 1;
    return node;
}

int main(void) {
    struct Node *nodes[3];
    nodes[0] = createNode(0);
    nodes[1] = createNode(1);
    nodes[2] = createNode(5);

    nodes[0]->next = nodes[1];
    nodes[1]->next = nodes[2];

    int target = 5;
    struct Queue *q = createQueue(10);
    enqueue(q, nodes[0]);

    while (q->last != q->occupied) {
        struct Node *neighbor = dequeue(q);
        printf("val: %d\n", neighbor->val);
        if (neighbor->val == target) {
            printf("Found target!\n");
            return 0;
        }
        struct Node *current = neighbor->next;
        while (current != NULL) {
            enqueue(q, current);
            current = current->next;
        }
    }
    return 1;
}
