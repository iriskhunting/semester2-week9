
#include <stdio.h>
#include <stdlib.h>

#include "queue_structures.h"
#include "queue.h"

int main( void ) {

    Queue *queue = createQueue();

    // code to test join, leave and display functions
    join(queue, createData(1));
    join(queue, createData(2));
    join(queue, createData(3));
    join(queue, createData(4));
    displayQueue(queue);

    Data *discarded_item = leave(queue);
    printf("%d has left the queue\n",discarded_item->value);
    displayQueue(queue);

    // free queue dynamic memory
    freeQueue( queue );
    free( queue );
    
    return 0;
}
