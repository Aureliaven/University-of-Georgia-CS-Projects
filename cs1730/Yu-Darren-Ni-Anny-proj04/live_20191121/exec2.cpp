#include <iostream>
#include <unistd.h>

using namespace std;

int main() {

  char * args[] = {
		   (char*) "ls",
		   (char*) "-al",
		   (char*) NULL
  };

  if(execvp("ls", args) == -1) {
    perror("error execing");
    return 1;
  }

  cout << "after exec" << endl;
  
  return 0;
}
