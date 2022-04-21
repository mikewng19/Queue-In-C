#include <stdio.h>

typedef struct {
    int value;
    struct node* next;
} node;

typedef struct {
    int size;
    node* head;
    node* tail;
} queue;

queue* new_queue() {
    // initializes the queue.
    queue* q = (queue*)malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

int main() {
    /*
    Functions:
        queue* queue_name = new_queue(); // Creates and Initialize a queue (You may create multiple queues).
        enqueue(queue_name, value);      // Adds values to a queue.
        dequeue(queue_name);             // Removes and returns a value from a queue.
        get_size(queue_name);            // Gets (returns) the size of a queue.
        clear_queue(queue_name);         // Clears all the values from a queue.
        delete_queue(queue_name);        // Clears all the values and deletes a queue.
    */

    queue* q = new_queue();  // initializes the queue and stores the pointer.
}

void enqueue(queue* q, int value) {
    node* n = (node*)malloc(sizeof(node));  // Creates a new node
    n->value = value;                       // Gives the node the specified value.
    if (q->size == 0) {                     // If there is no head, set the head to the new node.
        q->head = n;                        // Points the head to the new node if there wasn't a head.
    } else {
        q->tail->next = n;  // Set the tails next pointer to the new node.
    }

    q->tail = n;  // Tail becomes the new node.
    q->size++;    // Increment Size the Size of the Queue.
    printf("Enqueue/Tail Value: %d, SIZE: %d\n", q->tail->value, q->size);
}

int dequeue(queue* q) {
    if (q->size <= 0) {  // Checks if the queue is empty.
        printf("Queue is empty!\n");
        exit(1);
    }
    // Dequeues by Moving the head.
    int value = q->head->value;  // Gets the value of the head before the dequeue.
    node* next = q->head->next;  // Stores the pointer of the node after the head.
    free(q->head);               // Frees the memory of the current head.
    q->head = next;              // Head becomes the node after the removed head.
    q->size--;                   // Decrement the Size of the Queue.
    printf("Dequeue/Head Value: %d, SIZE: %d\n", value, q->size);
    return value;
}

int get_size(queue* q) {
    // Returns the size of a queue.
    return q->size;
}

void clear_queue(queue* q) {
    // CLEARS all of the nodes in the Queue.
    while (q->head) {
        node* next = q->head->next;
        free(q->head);
        q->head = next;
    }
    q->tail = NULL;
    q->size = 0;
    printf("Cleared all of the Queue's Values.\n");
}

void delete_queue(queue* q) {
    // Clears all of the nodes first, then it deletes the actual queue.
    clear_queue(q);
    free(q);
    printf("Deleted the Queue.\n");
}
