#include "SortedList.h"

template<class ItemType>SortedList<ItemType>::SortedList() {
  length = 0;
  listData = NULL;
}
    
template<class ItemType>SortedList<ItemType>::~SortedList() {
  delete listData;
}
  
template<class ItemType>void SortedList<ItemType>::makeEmpty() {
  length = 0;
  delete listData;
  listData = NULL;
}
   
template<class ItemType>bool SortedList<ItemType>::isEmpty() const {
  if (length == 0 || listData == NULL) {
    return true;
  }
  return false;
}
   
template<class ItemType>bool SortedList<ItemType>::isFull() const {
  try {
    Node<ItemType> * test = new Node<ItemType>();
    delete test;
    return false;
  }
  catch (bad_alloc err) {
    return true;
  }
}
  
template<class ItemType> void SortedList<ItemType>::putItem(ItemType newItem) {
  if (isFull()) {
    throw FullList();
  }
  Node<ItemType> * pred;
  if (findItem(newItem, pred)) {
    throw DuplicateItem();
  }
  Node<ItemType> * temp = NULL;
  temp->info = newItem;
  if (pred == NULL) {
    temp->next = listData;
    listData = temp;
    delete temp;
  }
  else {
    temp->next = pred->next;
    pred->next = temp;
  }
  delete pred;
  length++;
}
  
template<class ItemType>void SortedList<ItemType>::deleteItem(ItemType Item) {
  if (isEmpty()) {
    throw EmptyList();
  }
  Node<ItemType> * pred;
  if (!findItem(Item, pred)) {
    throw DeletingMissingItem();
  }
  if (pred == NULL) {
    Node<ItemType> * temp = pred->next->next;
    delete pred->next;
    listData = temp;
    delete temp;
  }
  else {
    pred->next = pred->next->next;
    delete pred->next;
  }
  delete pred;
  length--;
}

template<class ItemType>int SortedList<ItemType>::getLength()const {
  if (isEmpty()) {
    return 0;
  }
  return length;
}
  
template<class ItemType>ItemType SortedList<ItemType>::getAt(int index) {
  if (index < 1 || index > length) {
    throw OutOfBound();
  }
  Node<ItemType> * curr = listData;
  for (int i = 1; i < index; i++) {
    curr = curr->next;
  }
  ItemType item = curr->info;
  delete curr;
  return item;
}
  
template<class ItemType>void SortedList<ItemType>::merge(SortedList& list) {
  if (isEmpty() && !list.isEmpty()) {
    listData = list.listData;
    list.makeEmpty();
    return;
  }
  Node<ItemType> * p = listData;
  Node<ItemType> * q = list.listData;
  Node<ItemType> * curr;
  if (p->info < q->info) {
    curr = p;
    p = p->next;
  } else {
    curr = q;
    q = q->next;
  }
  while (p != NULL && q != NULL) {
    if (p->info < q->info) {
      curr->next = p;
      curr = p;
      p = p->next;
    } else if (p->info > q->info) {
      curr->next = q;
      curr = q;
      q = q->next;
    } else {
      curr->next = p;
      curr = p;
      p = p->next;
      q = q->next;
    }
  }
  delete p;
  delete q;
}
  
template<class ItemType>void SortedList<ItemType>::printList(ofstream& outFile) {
  Node<ItemType> * curr = listData;
  while (curr != NULL) {
    outFile << curr->info << endl;
    curr = curr->next;
  }
  delete curr;
}

template<class ItemType>bool SortedList<ItemType>::findItem(ItemType item,
					Node<ItemType> *& predecessor) {
  Node<ItemType> * curr = listData;
  predecessor = NULL;
  while (curr != NULL) {
    if (curr->info == item) {
      delete curr;
      return true;
    } else if (curr->info > item) {
      delete curr;
      return false;
    } else {
      predecessor = curr;
      curr = curr->next;
    } 
  }
  delete curr;
  return false;
}


