
#include <stdio.h>
#include <stdlib.h>

#include "queue_structures.h"
#include "queue.h"

/*
 * create a Data item for the queue
 */
Data *createData(int val ) {
  Data *new = malloc(sizeof(Data));
  new->value = val;
  return new;
}

/*
 * allocate and initialise a queue data structure 
 */
Queue *createQueue( void ) {
    Queue *new = malloc(sizeof(Queue));
    new->blockSize = 10;
    new->size = new->blockSize;
    new->data = calloc(new->size,sizeof(Data *));  // allocate an initial block for queue storage

    // set initial values for back, front and length
    new->back = 0;
    new->front = 0;
    new->length = 0;

    return new;
}

/*
 * reallocate dynamic array data if we have reached queue->size
 */
void enlargeQueue( Queue *queue ) {
    queue->size += queue->blockSize;
    queue->data = realloc(queue->data,queue->size); // allocate a further 'block' to the queue to increase size
    return;
}

/*
 * join a Data item onto the queue at the back
 */
void join( Queue *queue, Data *new ) {

    // add new item at the back
    // increment back index
    // increment length
    queue->data[queue->back] = new;
    queue->back++;
    queue->length++;

    return;
}

/*
 * remove the front Data item from the queue
 */
Data *leave( Queue *queue ) {

    // remove front item
    // increment front index
    // decrement length
    Data *front_item = queue->data[queue->front];
    queue->front++;
    queue->length--;

    return front_item;
}

/*
 * display queue data - traverse list from front to back
 */
void displayQueue ( Queue *queue ) {
    printf("Queue length %d\n",queue->length);
    for( int k=queue->front; k<queue->back; ++k )
        printf(" %d",queue->data[k]->value);
    printf("\n");
    return;
}

/*
 * free dynamic array data
 */
void freeQueue( Queue *queue ) {
    for( int k=0; k<queue->size; ++k )
        free( queue->data[k] ); // free queue Data item
    free( queue->data );        // free queue Data array
    return;
}
