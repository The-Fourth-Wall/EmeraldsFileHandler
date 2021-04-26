#include "headers/read_handler_base.h"

/**
 * @func: read_handler_file_does_not_exist
 * @brief Check if the path file exists in the filesystem
 * @return true if it does not exist
 */
static bool read_handler_file_does_not_exist(struct read_handler *self) {
    /* Try to open for reading */
    FILE *f;
    if((f = fopen(self->filepath, "r"))) {
        fclose(f);
        return false;
    }
    printf("File: `%s` does not exist\n", self->filepath);
    return true;
}

struct read_handler *read_handler_new(void) {
    struct read_handler *h = (struct read_handler *)malloc(sizeof(struct read_handler));
    h->filepath = NULL;
    h->fd = NULL;
    return h;
}

bool read_handler_open(struct read_handler *self, char *filepath) {
    self->filepath = filepath;

    if(read_handler_file_does_not_exist(self)) return false;

    if(!(self->fd = fopen(self->filepath, "r"))) {
        printf("Error on reading file: `%s`\n", self->filepath);
        return false;
    }
    return true;
}



char *read_handler_read_line(struct read_handler *self) {
    /* TODO -> ARBITRARY LINE LENGTH */
    char *ret = (char*)malloc(sizeof(char) * 4096);
    char *tmp = NULL;
    ret[0] = '\0';
    ret[1023] = '\0';
    
    if(fgets(ret, 1024, self->fd) == NULL) {
        *ret = '\0';
        return ret;
    }
    else if ((tmp = strrchr(ret, '\n')) != NULL)
        *tmp = '\0';
    
    return ret;
}

bool read_handler_close(struct read_handler *self) {
    if(self == NULL)
        return false;
    if((fclose(self->fd))) {
        printf("Error on closing file: `%s`\n", self->filepath);
        free(self);
        return false;
    }
    free(self);
    return true;
}
