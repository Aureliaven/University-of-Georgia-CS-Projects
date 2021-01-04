#include <iostream>
#include <unistd.h>

using namespace std;

int main() {

  if(execl("ls", "ls", "-al", (char*) NULL) == -1) {
    perror("error execing");
    return 1;
  }

  cout << "after exec" << endl;
  
  return 0;
}
