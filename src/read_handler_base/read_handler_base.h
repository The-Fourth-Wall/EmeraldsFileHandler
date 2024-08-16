#ifndef __READ_HANDLER_BASE_H_
#define __READ_HANDLER_BASE_H_

#include "../../libs/EmeraldsBool/export/EmeraldsBool.h"

#include <stdio.h>  /* FILE, fopen, fclose, printf */
#include <stdlib.h> /* malloc, free */

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
 * @brief Loads each character into a vector
 * @param self -> The file_loader to read from
 * @param filepath -> The name of the file to read from
 * @return string*
 */
char *read_handler_load(EmeraldsReadHandler *self, const char *filepath);

/**
 * @brief Attempts to close the buffers to avoid memory overflows
 */
bool read_handler_close(EmeraldsReadHandler *self);

#endif
