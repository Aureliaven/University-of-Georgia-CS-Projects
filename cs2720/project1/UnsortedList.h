#ifndef UNSORTEDLIST_H 
#define UNSORTEDLIST_H 
#include<string>
class FullList
{};
class EmptyList
{};
class DuplicateItem
{};
class OutofBound
{};
class ItemNotFound
{};

template <class ItemType>
class UnsortedList
{
public:
	// Class constructors
	UnsortedList();
	UnsortedList(int);
	// Class destructor.
	~UnsortedList();
	// Function: makeEmpty initializes the list to an empty state.
	// Post: list is empty.
	
	bool isEmpty() const;
	// Function: isFull determines whether the list is full.
	// Post: Function value = (list is full)
	bool isFull() const;
	// Function: Adds newItem to the end of the list.
	// Post: If (List is full) FullList exception is thrown
	//       If item is already in the list DuplicateItem exception is thrown
	//       else newItem is at end of the list.
	void makeEmpty();
	// Function: isEmpty determines whether the list is empty.
	// Post: Function value = (list is empty)
	void putItem(ItemType newItem);
	// Function: deletes Item from the list.
	// Post: If List is empty EmptyList exception is thrown
	//       If item is not in the list an exception is thrown
	//       else newItem is not in the list.
	void deleteItem(ItemType Item);
	// Function: returns the number of items in the list
	int getLength()const;
	ItemType getAt(int index) const;

private:
	ItemType* info;
	int Max_Items;
	int length;
	// Function: Returns the index of element item
   //pre: list is initialized
  // post: If item is in the list then function value =  
  //       index of item.
  //       If item is not in the list -1 is returned
	int findIndex(ItemType item) const;
};


#endif
