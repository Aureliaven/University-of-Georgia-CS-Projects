#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
  printf("Main process id: %i\n", getpid());
  printf("Parent process id: %i\n", getppid());

  int pid = fork();
  if (pid == 0) {
    // in child
    printf("Starting child process\n");
    printf("Child process id: %i\n", getpid());
    printf("Child's parent id: %i\n", getppid());
  } else {
    // in parent
    waitpid(pid, NULL, 0);
    printf("Parent process id: %i\n", getppid());
  }

  return 0;
}
