#include <stdio.h>
#include <stdlib.h>
 

struct queue
{
    int *items;    
    int maxsize;    
    int front;      
    int rear;        
    int size;       
};
 

struct queue* newQueue(int size)
{
    struct queue *pt = NULL;
    pt = (struct queue*)malloc(sizeof(struct queue));
 
    pt->items = (int*)malloc(size * sizeof(int));
    pt->maxsize = size;
    pt->front = 0;
    pt->rear = -1;
    pt->size = 0;
 
    return pt;
}
 

int size(struct queue *pt) {
    return pt->size;
}
 

int isEmpty(struct queue *pt) {
    return !size(pt);
}
 

int front(struct queue *pt)
{
    if (isEmpty(pt))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    return pt->items[pt->front];
}
 

void enqueue(struct queue *pt, int x)
{
    if (size(pt) == pt->maxsize)
    {
        printf("Overflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    printf("Inserting %d\t", x);
 
    pt->rear = (pt->rear + 1) % pt->maxsize;    
    pt->items[pt->rear] = x;
    pt->size++;
 
    printf("front = %d, rear = %d\n", pt->front, pt->rear);
}
 

void dequeue(struct queue *pt)
{
    if (isEmpty(pt))    
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    printf("Removing %d\t", front(pt));
 
    pt->front = (pt->front + 1) % pt->maxsize;  
    pt->size--;
 
    printf("front = %d, rear = %d\n", pt->front, pt->rear);
}
 
int main()
{
    struct queue *pt = newQueue(5);
 
    enqueue(pt, 1);
    enqueue(pt, 2);
    enqueue(pt, 3);
    enqueue(pt, 4);
 
    dequeue(pt);
    dequeue(pt);
    dequeue(pt);
    dequeue(pt);
 
    enqueue(pt, 5);
    enqueue(pt, 6);
 
    printf("size = %d\n", size(pt));
 
    if (isEmpty(pt)) {
        printf("The queue is empty");
    }
    else {
        printf("The queue is not empty");
    }
 
    return 0;
}
