// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include "UnsortedList.cpp"
#include "Student.cpp"
using namespace std;
void testIntegerList();
void testCharacterList();
void testStudentList();
int main()
{
  int datatype;
  // Prompt user to enter type of elements 
  cout << "Enter Elements Type\n1 for integer\n2 for character\n3 for Student\n";
  cin >> datatype;
  switch (datatype)
    {
    case 1: testIntegerList();
      break;
    case 2: testCharacterList();
      break;
    case 3: testStudentList();
      break;
    }
  //�.append any needed code here
  return 0;
}


void testIntegerList()
{
  UnsortedList<int> list(5);
  string command;
  ifstream inFile;
  ofstream outFile;
  inFile.open("intcommands.txt");
  outFile.open("outFile.txt");
  int number;
  inFile >> command; // read commands from a text file

  while (command != "Quit")
    {
      try

	{
	  if (command == "MakeEmpty")
	    list.makeEmpty();

	  else if (command == "IsEmpty")
	    if (list.isEmpty())
	      outFile << "list is empty\n";
	    else
	      outFile << "list is not empty\n";
	  else if (command == "IsFull")
	    {
	      if (list.isFull())
		outFile << "List is full\n";
	      else
		outFile << "List is not full\n";
	    }
	  else if (command == "PutItem")
	    {
	      inFile >> number;
	      list.putItem(number);
	    }
	  else if (command == "DeleteItem")
	    {
	      inFile >> number;
	      list.deleteItem(number);
	    }

	  else if (command == "GetLength")
	    outFile << list.getLength() << "\n";
	  else if (command == "PrintList")
	    {
	      outFile << "List Items: ";
	      int value;
	      for (int index = 0; index < list.getLength(); index++)
		{
		  value = list.getAt(index);
		  outFile << value << " ";
		}
	      outFile << "\n";
	    }

	  else if (command == "GetAt")
	    {
	      int index;
	      inFile >> index;
	      outFile << "Item at index " << index << " is:" << list.getAt(index) << endl;
	    }
	  else
	    outFile << "Unrecognized command";
	  inFile >> command;
			
	} // try

      catch (FullList)
	{
	  outFile << "List is full, Insertion failed" << endl;
	  inFile >> command;
	}

      catch (EmptyList)
	{
	  outFile << "List is empty" << endl;
	  inFile >> command;
	}

      catch (DuplicateItem)
	{
	  outFile << "Duplicate Item, Insertion failed" << endl;
	  inFile >> command;
	}
      catch (OutofBound)
	{
	  outFile << "Index is out of range" << endl;
	  inFile >>command;
	}
      catch (ItemNotFound)
	{
	  outFile << "Item is not in the list" <<endl;
	  inFile >> command;
	}
    } // while
} // testIntegerList

void testStudentList()
{
  UnsortedList<Student> list(10);
  string command;
  ifstream inFile;
  ofstream outFile;
  inFile.open("studcommands.txt");
  outFile.open("outFile.txt");
  int nextID;
  string nextName;
  inFile >> command; // read commands from a text file

  while (command != "Quit")
    {
      try

	{
	  if (command == "MakeEmpty")
	    list.makeEmpty();

	  else if (command == "IsEmpty")
	    if (list.isEmpty())
	      outFile << "list is empty\n";
	    else
	      outFile << "list is not empty\n";
	  else if (command == "IsFull")
	    {
	      if (list.isFull())
		outFile << "List is full\n";
	      else
		outFile << "List is not full\n";
	    }
	  else if (command == "PutItem")
	    {
	      inFile >> nextID;
	      inFile >> nextName;
	      Student student(nextID, nextName);
	      list.putItem(student);
	    }
	  else if (command == "DeleteItem")
	    {
	      inFile >> nextID;
	      Student student(nextID, nextName);
	      list.deleteItem(student);
	    }

	  else if (command == "GetLength")
	    outFile << list.getLength() << "\n";
	  else if (command == "PrintList")
	    {
	      outFile << "List Items: ";
	      for (int index = 0; index < list.getLength(); index++)
		{
		  Student value = list.getAt(index);
		  outFile << value.getStudentID() << " " << value.getStudentName() << ", ";
		}
	      outFile << "\n";
	    }

	  else if (command == "GetAt")
	    {
	      int index;
	      inFile >> index;
	      outFile << "Item at index " << index << " is: " << list.getAt(index).getStudentID() << " " << list.getAt(index).getStudentName() << endl;
	    }
	  else
	    outFile << "Unrecognized command";
	  inFile >> command;
			
	} // try

      catch (FullList)
	{
	  outFile << "List is full, Insertion failed" << endl;
	  inFile >> command;
	}

      catch (EmptyList)
	{
	  outFile << "List is empty" << endl;
	  inFile >> command;
	}

      catch (DuplicateItem)
	{
	  outFile << "Duplicate Item, Insertion failed" << endl;
	  inFile >> command;
	}
      catch (OutofBound)
	{
	  outFile << "Index is out of range" << endl;
	  inFile >>command;
	}
      catch (ItemNotFound)
	{
	  outFile << "Item is not in the list" << endl;
	  inFile >> command;
	}
    } // while
} // test StudentList

void testCharacterList()
{
  // add code to test the characters list, similar to testIntegerslist
  UnsortedList<char> list;
  string command;
  ifstream inFile;
  ofstream outFile;
  inFile.open("chcommands.txt");
  outFile.open("outFile.txt");
  char number;
  inFile >> command; // read commands from a text file

  while (command != "Quit")
    {
      try

	{
	  if (command == "MakeEmpty")
	    (list.makeEmpty());

	  else if (command == "IsEmpty")
	    if (list.isEmpty())
	      outFile << "list is empty\n";
	    else
	      outFile << "list is not empty\n";
	  else if (command == "IsFull")
	    {
	      if (list.isFull())
		outFile << "List is full\n";
	      else
		outFile << "List is not full\n";
	    }
	  else if (command == "PutItem")
	    {
	      inFile >> number;
	      list.putItem(number);
	    }
	  else if (command == "DeleteItem")
	    {
	      inFile >> number;
	      list.deleteItem(number);
	    }

	  else if (command == "GetLength")
	    outFile << list.getLength() << "\n";
	  else if (command == "PrintList")
	    {
	      outFile << "List Items: ";
	      char value;
	      for (int index = 0; index < list.getLength(); index++)
		{
		  value = list.getAt(index);
		  outFile << value << " ";
		}
	      outFile << "\n";
	    }

	  else if (command == "GetAt")
	    {
	      int index;
	      inFile >> index;
	      outFile << "Item at index " << index << " is:" << list.getAt(index) << endl;
	    }
	  else
	    outFile << "Unrecognized command";
	  inFile >> command;
			
	} // try

      catch (FullList)
	{
	  outFile << "List is full, Insertion failed" << endl;
	  inFile >> command;
	}

      catch (EmptyList)
	{
	  outFile << "List is empty" << endl;
	  inFile >> command;
	}

      catch (DuplicateItem)
	{
	  outFile << "Duplicate Item, Insertion failed" << endl;
	  inFile >> command;
	}
      catch (OutofBound)
	{
	  outFile << "Index is out of range" << endl;
	  inFile >>command;
	}
      catch (ItemNotFound)
	{
	  outFile << "Item is not in the list" <<endl;
	  inFile >> command;
	}
    } // while
} // testCharacterList 
