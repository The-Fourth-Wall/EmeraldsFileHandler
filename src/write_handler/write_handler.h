#ifndef __WRITE_HANDLER_H_
#define __WRITE_HANDLER_H_

#include "../file_handler/file_handler.h"

/**
 * @brief Write a string in the file
 * @param filename -> The name of the file to write to
 * @param str -> The string to write
 * @return a boolean signaling if writing was successful
 */
bool file_handler_write(const char *filename, const char *str);

/**
 * @brief Writes a line in the file (with `\n`)
 * @param filename -> The name of the file to write to
 * @param line -> The line to write
 * @return a boolean signaling if writing was successful
 */
bool file_handler_write_line(const char *filename, const char *line);

#endif
