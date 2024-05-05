#include "read_handler_base.h"

/**
 * @brief Check if the path file exists in the filesystem
 * @return true if it does not exist
 */
static bool read_handler_file_does_not_exist(EmeraldsReadHandler *self) {
  /* Try to open for reading */
  FILE *f;
  if((f = fopen(self->filepath, "r"))) {
    fclose(f);
    return false;
  }
  printf("File: `%s` does not exist\n", self->filepath);
  return true;
}

EmeraldsReadHandler *read_handler_new(void) {
  EmeraldsReadHandler *h =
    (EmeraldsReadHandler *)malloc(sizeof(EmeraldsReadHandler));
  h->filepath = NULL;
  h->fd       = NULL;
  return h;
}

bool read_handler_open(EmeraldsReadHandler *self, const char *filepath) {
  self->filepath = filepath;

  if(read_handler_file_does_not_exist(self)) {
    return false;
  }

  if(!(self->fd = fopen(self->filepath, "r"))) {
    printf("Error on reading file: `%s`\n", self->filepath);
    return false;
  }
  return true;
}

char *read_handler_read_line(EmeraldsReadHandler *self) {
  /* TODO -> ARBITRARY LINE LENGTH */
  size_t linesize   = 4096;
  char *ret         = (char *)malloc(sizeof(char) * linesize);
  char *tmp         = NULL;
  ret[0]            = '\0';
  ret[linesize - 1] = '\0';

  if(fgets(ret, linesize, self->fd) == NULL) {
    *ret = '\0';
    return ret;
  } else if((tmp = strrchr(ret, '\n')) != NULL) {
    *tmp = '\0';
  }

  return ret;
}

bool read_handler_close(EmeraldsReadHandler *self) {
  if(self == NULL) {
    return false;
  }
  if((fclose(self->fd))) {
    printf("Error on closing file: `%s`\n", self->filepath);
    free(self);
    return false;
  }
  free(self);
  return true;
}
