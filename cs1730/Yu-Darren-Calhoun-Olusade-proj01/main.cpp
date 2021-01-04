#include "proj1.h"
#include <string>
using namespace std;

// main function, takes arguments from command line

int main(int argc, char * argv[]) {

  // declare variables that will be passed into the function
  string mode;
  int int1, int2, int3, int4, int5;
  int e;

  // iterate through the arguments and set them to the variables
  for (int i = 0; i < argc; i++) {

    string current = argv[i];
    if (current == "-a" || current == "-b") {
      mode = current;
    } // if

    if (current == "-e") {
      e = atoi(argv[i + 1]);
    } // if

    // converts the next 5 arguments to integers
    if (current == "-v") {
      int1 = atoi(argv[i + 1]);
      int2 = atoi(argv[i + 2]);
      int3 = atoi(argv[i + 3]);
      int4 = atoi(argv[i + 4]);
      int5 = atoi(argv[i + 5]);
    } // if
    
  } // for

  // calls the search function
  search(mode, int1, int2, int3, int4, int5, e);
  return EXIT_SUCCESS;
  
} // main
