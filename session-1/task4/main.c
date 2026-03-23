
#include <stdio.h>
#include <stdlib.h>

#include "node_structures.h"
#include "node.h"
#include "queue_structures.h"
#include "queue.h"

int main( void ) {

    // create an empty queue
    Queue *queue = createQueue();

    // test join 
    // - use traverseI() to display the nodes
    // - which pointer do you pass to traverseI(): front or back?
    join(queue, 1);
    join(queue, 2);
    join(queue, 3);
    join(queue, 4);
    traverseI(queue->front);

    // test leave 
    // - take care to free detached memory
    Node *detached_node = leave(queue);
    free(detached_node);
    traverseI(queue->front);

    // free queue memory
    freeNodes( queue->front );
    // free queue
    free(queue);

    return 0;
}
