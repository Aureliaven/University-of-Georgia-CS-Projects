#include "PriorityQueue.h"

template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue() {
  front = NULL;
  length = 0;
}

template<class ItemType>
PriorityQueue<ItemType>::~PriorityQueue() {
  delete front;
  length = 0;
}

template<class ItemType>
void PriorityQueue<ItemType>::makeEmpty() {
  delete front;
  front = NULL;
  length = 0;
}

template<class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const {
  if (front == NULL) {
    return true;
  }
  return false;
}

template<class ItemType>
bool PriorityQueue<ItemType>::isFull() const {
  try {
    QNode<ItemType> * test = new QNode<ItemType>();
    delete test;
    return false;
  }
  catch (bad_alloc err) {
    return true;
  }
}

template<class ItemType>
void PriorityQueue<ItemType>::enqueue(ItemType newItem) {
  enqueue(newItem, 1);
}

template<class ItemType>
void PriorityQueue<ItemType>::enqueue(ItemType newItem, int priority) {
  if (isFull()) {
    throw QueueFull();
  }
  QNode<ItemType>* newNode = new QNode<ItemType>();
  newNode->info = newItem;
  newNode->priority = priority;
  length++;
  if (isEmpty()) {
    front = newNode;
    front->next = NULL;
  }
  else {
    QNode<ItemType>* pred = new QNode<ItemType>();
    pred->next = front;
    for (int i = 0; i < length-1; i++) {
      if (pred->next->priority > newNode->priority) {
	if (pred->next == front) {
	  newNode->next = front;
	  front = newNode;
	}
	else {
	  newNode->next = pred->next;
	  pred->next = newNode;
	}
      }
      else {
	pred = pred->next;
	if (pred->next == NULL) {
	  pred->next = newNode;
	  newNode->next = NULL;
	}
      }
    }
  }
}

template<class ItemType>
ItemType PriorityQueue<ItemType>::dequeue() {
  if (isEmpty()) {
    throw QueueEmpty();
  }
  ItemType item = front->info;
  QNode<ItemType>* temp = front->next;
  delete front;
  front = temp;
  length--;
  return item;
}

template<class ItemType>
ItemType PriorityQueue<ItemType>::peek() {
  if (isEmpty()) {
    throw QueueEmpty();
  }
  return front->info;
}

template<class ItemType>
int PriorityQueue<ItemType>::peekPriority() {
  if (isEmpty()) {
    throw QueueEmpty();
  }
  return front->priority;
}

template<class ItemType>
int PriorityQueue<ItemType>::queueLength() {
  return length;
}

template<class ItemType>
void PriorityQueue<ItemType>::printQueue(ofstream& stream) {
  if (isEmpty()) {
    stream << endl;
  }
  QNode<ItemType>* curr = front;
  for (int i = 0; i < length; i++) {
    stream << curr->info << endl;
    curr = curr->next;
  }
}
