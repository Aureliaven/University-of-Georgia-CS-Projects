#include "QueType.h"
template<class ItemType>QueType<ItemType>::QueType() {
  items = new ItemType[500];
  maxQue = 500;
  front = 0;
  rear = 0;
}
// Class constructor.

template<class ItemType>QueType<ItemType>::QueType(int max) {
  items = new ItemType[max];
  maxQue = max;
  front = -1;
  rear = -1;
}
// Parameterized class constructor.

template<class ItemType>QueType<ItemType>::~QueType() {
  delete [] items;
}
// Class destructor.
template<class ItemType>void QueType<ItemType>::makeEmpty() {
  delete [] items;
  items = new ItemType[maxQue];
  front = -1;
  rear = -1;
}
// Function: Initializes the queue to an empty state.
// Post: Queue is empty.

template<class ItemType>bool QueType<ItemType>::isEmpty() const {
  return front==-1;
}
// Function: Determines whether the queue is empty.
// Post: Function value = (queue is empty)

template<class ItemType>bool QueType<ItemType>::isFull() const {
  int count;
  if (isEmpty()) {
    count = 0;
  }
  if (rear >= front) {
    count = rear - front + 1;
  }
  else {
    count = maxQue - rear + front + 1;
  }
  return count == maxQue;
}
// Function: Determines whether the queue is full.
// Post: Function value = (queue is full)

template<class ItemType>void QueType<ItemType>::enqueue(ItemType newItem) {
  if (isFull()) {
    throw QueueOverflow();
  }
  if (isEmpty()) {
    front = 0;
    rear = 0;
    items[rear] = newItem;
  }
  else if (rear == maxQue - 1) {
    items[0] = newItem;
    rear = 0;
  }
  else {
    items[rear+1] = newItem;
    rear++;
  }
}
// Function: Adds newItem to the rear of the queue.
// Post: If (queue is full) FullQueue exception is thrown
//       else newItem is at rear of queue.

template<class ItemType>void QueType<ItemType>::dequeue(ItemType& item) {
  if (isEmpty()) {
    throw QueueUnderflow();
  }
  if (length() == 1) {
    item = items[front];
    makeEmpty();
  }
  else if (front == maxQue - 1) {
    item = items[front];
    front = 0;
  }
  else {
    item = items[front];
    front++;
  }
}
// Function: Removes front item from the queue and returns it
//in item.
// Post: If (queue is empty) EmptyQueue exception is thrown
//       and item is undefined
//       else front element has been removed from queue and
//       item is a copy of removed element.

template<class ItemType>ItemType QueType<ItemType>::peek() {
  if (front == -1) {
    throw QueueUnderflow();
  }
  return items[front];
}
// returns the item at the front of the queue without
//removing the item from the queue

template<class ItemType>int QueType<ItemType>::length() {
  if (isEmpty()) {
    return 0;
  }
  if (rear >= front) {
    return rear - front + 1;
  }
  else {
    return maxQue - rear + front + 1;
  }
}
// Function: returns the number of items in the queue

template<class ItemType>void QueType<ItemType>::printQueue(ofstream& stream) {
  if (isEmpty()) {
    throw QueueUnderflow();
  }
  if (rear >= front) {
    for (int i = front; i <= rear; i++) {
      stream << items[i] << endl;
    }
  }
  else {
    for (int i = front; i < maxQue; i++) {
      stream << items[i] << endl;
    }
    for (int j = 0; j <= rear; j++) {
      stream << items[j] << endl;
    }
  }
}
