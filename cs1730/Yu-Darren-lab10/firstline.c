// copy input to output until first newline character
#include <unistd.h> 
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

  int fd = open(argv[1], O_RDONLY);

  if (fd < 0){
    perror("File not found");
    exit(1);
  }

  char c;

  while (c != '\n'){
    if (read(fd, &c, 1) == 0) {
      c = '\n';
    }
    write(STDOUT_FILENO, &c, 1);
  }

  close(fd);

  return EXIT_SUCCESS;
  
}
