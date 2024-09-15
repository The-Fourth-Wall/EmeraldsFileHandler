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
 * @brief Initializes a file_handler
 * @param self -> The file_handler to initialize
 */
#define file_handler_init(self) \
  do {                          \
    (self)->filepath = NULL;    \
    (self)->fd       = NULL;    \
  } while(0)

/**
 * @brief Open a file in read mode
 * @param name -> The path to open
 * @param mode -> The mode to open the file in
 * @return a boolean signaling if the opening was successful
 */
#define file_handler_open(self, name, mode)      \
  ((self)->filepath = (name),                    \
   ((self)->fd = fopen((self)->filepath, mode)), \
   (self)->fd == NULL ? false : true)

/**
 * @brief Write a string in the file
 * @param filename -> The name of the file to write to
 * @param str -> The string to write
 */
#define file_handler_write(filename, str)           \
  do {                                              \
    FILE *f;                                        \
    char *mode;                                     \
    EmeraldsFileHandler self = {0};                 \
    if((f = fopen((filename), "r"))) {              \
      mode = "a";                                   \
      fclose(f);                                    \
    } else {                                        \
      mode = "w";                                   \
    }                                               \
    file_handler_init(&self);                       \
    (void)file_handler_open(&self, filename, mode); \
    fprintf(self.fd, "%s", (str));                  \
    file_handler_close(&self);                      \
  } while(0)

/**
 * @brief Writes a line in the file (with `\n`)
 * @param filename -> The name of the file to write to
 * @param line -> The line to write
 */
#define file_handler_write_line(filename, line) \
  do {                                          \
    file_handler_write(filename, line);         \
    file_handler_write(filename, "\n");         \
  } while(0)

/**
 * @brief Attempts to close the buffers to avoid memory overflows
 * @param self -> The file_handler to close
 * @return a boolean signaling if closing was successful
 */
#define file_handler_close(self) \
  do {                           \
    if((self)) {                 \
      fclose((self)->fd);        \
    }                            \
  } while(0)

#define file_handler_deinit(self) \
  do {                            \
    file_handler_close(self);     \
    (self)->fd       = NULL;      \
    (self)->filepath = NULL;      \
  } while(0)

#endif
