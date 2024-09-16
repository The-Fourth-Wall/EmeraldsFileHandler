/**
 * A safe file reader api.
 *
 * Copyright (C) 2024 oblivious
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __EMERALDSFILEHANDLER_H_
#define __EMERALDSFILEHANDLER_H_

#include "../libs/EmeraldsBool/export/EmeraldsBool.h"
#include "../libs/EmeraldsPreprocessor/export/EmeraldsPreprocessor.h"
#include "../libs/EmeraldsString/export/EmeraldsString.h"

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

p_inline char *file_handler_read(const char *filepath) {
  EmeraldsFileHandler self = {0};
  file_handler_init(&self);

  if(!file_handler_open(&self, filepath, "r")) {
    file_handler_close(&self);
    return NULL;
  } else {
    char ch;
    char *result = string_new("");

    while((ch = fgetc(self.fd)) != EOF) {
      string_addf(&result, "%c", ch);
    }

    file_handler_close(&self);
    return result;
  }
}

#endif
