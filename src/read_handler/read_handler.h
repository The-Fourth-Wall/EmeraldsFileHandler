#ifndef __READ_HANDLER_H_
#define __READ_HANDLER_H_

#include "../file_handler/file_handler.h"

/**
 * @brief Reads a file character by character into a vector
 * @param filepath -> The name of the file to read from
 * @return string*
 */
char *file_handler_read(const char *filepath);

#endif
