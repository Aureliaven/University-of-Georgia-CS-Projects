#include "UnsortedList.h"
// Class constructors
template <class ItemType> UnsortedList<ItemType>::UnsortedList() {
  Max_Items = 50;
  length = 0;
  info = new ItemType[Max_Items];
}

template <class ItemType> UnsortedList<ItemType>::UnsortedList(int size) {
  Max_Items = size;
  length = 0;
  info = new ItemType[Max_Items];
}

// Class destructor.
template <class ItemType> UnsortedList<ItemType>::~UnsortedList() {
  makeEmpty();
  delete[] info;
}

template <class ItemType> bool UnsortedList<ItemType>::isEmpty() const {
  if (length > 0) {
    return false;
  }
  return true;
}

template <class ItemType> bool UnsortedList<ItemType>::isFull() const {
  if (length == Max_Items) {
    return true;
  }
  return false;
}

template <class ItemType> void UnsortedList<ItemType>::makeEmpty() {
  if (info != nullptr) {
    delete[] info;
  }
  info = new ItemType[Max_Items];
  length = 0;
}

template <class ItemType> void UnsortedList<ItemType>::putItem(ItemType newItem) {
  if (isFull()) {
    throw FullList();
  }
  if (findIndex(newItem) != -1) {
    throw DuplicateItem();
  }
  info[length] = newItem;
  length++;
}

template <class ItemType> void UnsortedList<ItemType>::deleteItem(ItemType item) {
  int index = findIndex(item);
  if (index == -1) {
    throw ItemNotFound();
  }
  else {
    for (int i = index; index < length; i++) {
      if (i == length-1) {
	length--;
	return;
      }
      info[i] = info[i+1];
    }
  }
}

template <class ItemType> int UnsortedList<ItemType>::getLength() const {
  return length;
}

template <class ItemType> ItemType UnsortedList<ItemType>::getAt(int index) const {
  if (index < 0 || index >= length) {
    throw OutofBound();
  }
  return info[index];
}

template <class ItemType> int UnsortedList<ItemType>::findIndex(ItemType item) const {
  for (int i = 0; i < length; i++) {
    if (info[i] == item) {
      return i;
    }
  }
  return -1;
}
