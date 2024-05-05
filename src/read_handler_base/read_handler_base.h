#ifndef __READ_HANDLER_BASE_H_
#define __READ_HANDLER_BASE_H_

#include "../../libs/EmeraldsBool/export/EmeraldsBool.h"

#include <stdio.h>  /* FILE, fopen, fclose, printf */
#include <stdlib.h> /* malloc, realloc, free */
#include <string.h> /* strcat, strlen, strcpy, strrchr */

/**
 * @brief File handler for making file read operations more intuitive
 * @param fd -> The current file descriptor
 * @param filepath -> The name of the file to read from
 */
typedef struct EmeraldsReadHandler {
  FILE *fd;
  const char *filepath;
} EmeraldsReadHandler;

/**
 * @brief Creates a new instance of a EmeraldsReadHandler struct
 * @return EmeraldsReadHandler* -> The newly allocated EmeraldsReadHandler
 */
EmeraldsReadHandler *read_handler_new(void);

/**
 * @brief Open a file in read mode
 * @param filepath -> The path to open
 * @return a boolean signaling if the opening was successful
 */
bool read_handler_open(EmeraldsReadHandler *self, const char *filepath);

/**
 * @brief Read a new line from the file descriptor
 * @return The line read
 */
char *read_handler_read_line(EmeraldsReadHandler *self);

/**
 * @brief Attempts to close the buffers to avoid memory overflows
 */
bool read_handler_close(EmeraldsReadHandler *self);

#endif
