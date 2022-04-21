# Queue-in-C
Queue implementation using Linked Lists in C.

Functions:

  queue* queue_name = new_queue();      // Creates and Initialize a queue (You may create multiple queues).
  
  enqueue(queue_name, value);           // Adds values to a queue.
  
  dequeue(queue_name);                  // Removes and returns a value from a queue.
  
  get_size(queue_name);                 // Gets (returns) the size of a queue.
  
  clear_queue(queue_name);              // Clears all the values from a queue.
  
  delete_queue(queue_name);             // Clears all the values and deletes a queue.
