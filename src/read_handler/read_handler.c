#include "read_handler.h"

#include "../../libs/EmeraldsString/export/EmeraldsString.h"

char *file_handler_read(const char *filepath) {
  EmeraldsFileHandler *self = file_handler_new();

  if(!file_handler_open(self, filepath, "r")) {
    file_handler_close(self);
    return NULL;
  } else {
    char ch;
    char *result = string_new("");

    while((ch = fgetc(self->fd)) != EOF) {
      string_addf(&result, "%c", ch);
    }

    file_handler_close(self);
    return result;
  }
}
