#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

  printf("parent here\n");
  printf("parent pid: %d\n", getpid());

  printf("forking once\n");
  int fork1 = fork();
  int fork2 = 0;

  if (fork1) {
  printf("forking twice\n");
    fork2 = fork();
    if (fork2) {
      int stats, w;
      w = wait(&stats);
      int r = WEXITSTATUS(stats);
      printf("child pid: %d\nSleeping for %d seconds\n", stats, r);
      printf("parent done\n");
      exit(0);
    }
    else {
      printf("child 2 pid: %d\n", getpid());
      srand(time(NULL));
      int r = (rand() % 4) + 2;
      sleep(r);
      printf("child 2 finished sleeping\n");
      return 0;
    }
  }
  else {
    printf("child 1 pid: %d\n", getpid());
    srand(time(NULL));
    int r = (rand() % 4) + 2;
    sleep(r);
    printf("child 1 finished sleeping\n");
    return 0;
  }

}
