// Test driver
#include <iostream>
using namespace std;
#include <fstream>
#include <string>

#include "PriorityQueue.cpp"


void help()
{
  cout << "enqueue value: Enqueue a value at the end of the Queue\ndequeue: Remove the most urgent item \npeek: Peeks at the first item without removing it\npeekPriority: Peeks at the first item's priority\nmakeEmpty: Clears the queue.\nisEmpty: Reports whether the queue is empyty\n\nisFull: Reports whether the queue is full\nlength: Prints the length of the queue\nlist: Reports the items in the queue, in the order they will be processed\nhelp: Prints this message\n";
}
int main()
{

  ofstream outFile;
  ifstream inFile;
  string command;

  outFile.open("outFile.txt");
  inFile.open("inFile.txt");
  if(!outFile)
    {
      std::cout << "error opening output file" << endl;
      return 1;
    }
  char item;
  int priority;
  PriorityQueue<char> queue;
  int numCommands=0;
  //std::cout << "Enter a command:\n";
  help();
  while (true)
    {

      inFile >> command;

      try
	{
	  if (command == "enqueue")
	    {
	      inFile >> item;
	      inFile >> priority;
	      queue.enqueue(item, priority);
	      outFile << item << " is enqueued with priority " << priority << endl;
	    }
	  else if (command == "dequeue")
	    {
	      outFile << queue.dequeue() << " is dequeued. " << endl;
	    }
	  else if (command == "isEmpty")
	    {
	      if (queue.isEmpty())
		outFile << "Queue is Empty\n";
	      else
		outFile << "Queue is Not Empty\n";
	    }
	  else if (command == "isFull")
	    if (queue.isFull())
	      outFile << "Queue is full." << endl;
	    else outFile << "Queue is not full." << endl;
	  else if (command == "length")
	    outFile << "Number of items in the Queue is: " << queue.queueLength() << endl;
	  else if (command == "makeEmpty")
	    queue.makeEmpty();
	  else if (command == "list")
	    queue.printQueue(outFile);
	  else if (command == "peek") {
	    char x= queue.peek();
	    outFile << "Item at the front of the queue is " << x << endl;
	  }
	  else if (command == "peekPriority") {
	    int x= queue.peekPriority();
	    outFile << "Item at the front's priority is " << x << endl;
	  }
	  else if (command == "help")
	    help();
	  else if (command == "Quit")
	    break;
	  else outFile << " Invalid Command" << endl;
	}
      catch (QueueFull)
	{
          outFile << "Queue full, exception thrown!" << endl;
	}

      catch (QueueEmpty)
	{
	  outFile << "Queue empty, exception thrown!" << endl;
	}
      numCommands++;
      cout <<  " Command number " << numCommands << " completed."
	   << endl;

    }

  cout << "Testing completed."  << endl;
  outFile.close();
  return 0;
}
