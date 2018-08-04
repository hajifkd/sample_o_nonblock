#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include <stdio.h>
#include <stdbool.h>

#define COUNT 16
#define STDOUT_FD 1

void main() {
  int fd = open("./hoge", O_RDONLY | O_NONBLOCK);
  char buf[COUNT];

  while (true) {
    int result = read(fd, buf, COUNT);

    if (result == 0) {
      puts("End of file");
      break;
    } else if (result < 0) {
      switch (errno) {
        case EAGAIN:
          puts("EAGAIN");
#if EAGAIN != EWOULDBLOCK
        case EWOULDBLOCK:
          puts("EWOULDBLOCK");
#endif
          sleep(1);
          break;
        default:
          puts("Unknown errno");
      }
    } else if (result > 0) {
      write(STDOUT_FD, buf, (size_t) result);
    }

  }


  close(fd);
}

