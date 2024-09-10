#include "file_handler.h"

#include <stdlib.h> /* malloc */

EmeraldsFileHandler *file_handler_new(void) {
  EmeraldsFileHandler *self =
    (EmeraldsFileHandler *)malloc(sizeof(EmeraldsFileHandler));

  self->filepath = NULL;
  self->fd       = NULL;

  return self;
}

bool file_handler_open(
  EmeraldsFileHandler *self, const char *filepath, const char *mode
) {
  self->filepath = filepath;

  if(!(self->fd = fopen(self->filepath, mode))) {
    return false;
  } else {
    return true;
  }
}

bool file_handler_close(EmeraldsFileHandler *self) {
  if(self == NULL) {
    return false;
  } else if((fclose(self->fd))) {
    free(self);
    return false;
  } else {
    free(self);
    return true;
  }
}
