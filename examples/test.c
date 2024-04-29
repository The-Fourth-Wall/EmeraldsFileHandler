#include "../export/ReadHandler.h" /* IWYU pragma: keep */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *line1            = NULL;
  char *line2            = NULL;
  struct read_handler *h = read_handler_new();

  if(read_handler_open(h, "file.txt")) {
    line1 = read_handler_read_line(h);
    line2 = read_handler_read_line(h);
  }

  printf("%s\n", line1);
  printf("%s\n", line2);

  free(line1);
  free(line2);

  read_handler_close(h);
}
