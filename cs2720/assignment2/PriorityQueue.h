#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class QueueFull {};
class QueueEmpty {};

template <class ItemType>
struct QNode {
  ItemType info;
  int priority;
  QNode<ItemType>* next;
};

template <class ItemType>
class PriorityQueue {
public:
  PriorityQueue();
  // Class constructor.

  PriorityQueue(int max);
  // Parameterized class constructor.

  ~PriorityQueue();
  // Class destructor.
   
  void makeEmpty();
  // Function: Initializes the queue to an empty state.
  // Post: Queue is empty.

  bool isEmpty() const;
  // Function: Determines whether the queue is empty.
  // Post: Function value = (queue is empty)

  bool isFull() const;
  // Function: Determines whether the queue is full.
  // Post: Function value = (queue is full)

  void enqueue(ItemType newItem);
  void enqueue(ItemType newItem, int priority);
  // Function: Adds newItem to the rear of the queue.
  // Post: If (queue is full) QueueFull exception is thrown
  //       else newItem is at rear of queue.

  ItemType dequeue();
  // Function: Removes front item from the queue and returns it
  // in item.
  // Post: If (queue is empty) QueueEmpty exception is thrown
  //       and item is undefined
  //       else front element has been removed from queue and
  //       item is a copy of removed element.
  ItemType peek();
  // returns the item at the front of the queue without
  // removing the item from the queue
  int peekPriority();
  // returns the priority of the item with the highest priority
  int queueLength();
  // returns the number of items in the queue
  void printQueue(ofstream&);
  // displays queue items
private:
  QNode<ItemType>* front;
  int length;
};
