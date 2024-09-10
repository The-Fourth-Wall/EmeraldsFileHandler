#ifndef __FILE_HANDLER_H_
#define __FILE_HANDLER_H_

#include "../../libs/EmeraldsBool/export/EmeraldsBool.h"

#include <stdio.h> /* FILE */

/**
 * @brief File handler for making file read operations more intuitive
 * @param fd -> The current file descriptor
 * @param filepath -> The name of the file to read from
 */
typedef struct EmeraldsFileHandler {
  FILE *fd;
  const char *filepath;
} EmeraldsFileHandler;

/**
 * @brief Creates a new instance of a EmeraldsFileHandler struct
 * @return EmeraldsFileHandler* -> The newly allocated EmeraldsFileHandler
 */
EmeraldsFileHandler *file_handler_new(void);

/**
 * @brief Open a file in read mode
 * @param filepath -> The path to open
 * @param mode -> The mode to open the file in
 * @return a boolean signaling if the opening was successful
 */
bool file_handler_open(
  EmeraldsFileHandler *self, const char *filepath, const char *mode
);

/**
 * @brief Attempts to close the buffers to avoid memory overflows
 * @param self -> The file_handler to close
 * @return a boolean signaling if closing was successful
 */
bool file_handler_close(EmeraldsFileHandler *self);

#endif
