#include "write_handler.h"

#include "../read_handler/read_handler.h"

bool file_handler_write(const char *filename, const char *str) {
  char *mode                = NULL;
  EmeraldsFileHandler *self = file_handler_new();

  if(!file_handler_read(filename)) {
    mode = "w";
  } else {
    mode = "a";
  }

  if(!file_handler_open(self, filename, mode)) {
    return false;
  } else {
    fprintf(self->fd, "%s", str);
    file_handler_close(self);
    return true;
  }
}

bool file_handler_write_line(const char *filename, const char *line) {
  if(!file_handler_write(filename, line)) {
    return false;
  }

  if(!file_handler_write(filename, "\n")) {
    return false;
  }

  return true;
}
