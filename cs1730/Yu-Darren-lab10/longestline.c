// writes the length of the longest line
#include<unistd.h> 
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char * argv[]){

  int fd = open(argv[1], O_RDONLY);
  if (fd < 0){
    perror("File not found");
    exit(1);
  }

  char c;
  int n = 0;
  int count = 0;
  while (read(fd, &c, 1) != 0) {
    while (c != '\n'){
      if (read(fd, &c, 1) == 0){
	c = '\n';
      }
      count++;
    }
    if (count > n) {
      n = count;
    }
    count = 0;
  }
  printf("%d\n", n);

  close(fd);

  return EXIT_SUCCESS;

}
