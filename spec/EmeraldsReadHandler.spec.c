#include "../libs/cSpec/export/cSpec.h"
#include "file_handler/file_handler.module.spec.h"
#include "read_handler/read_handler.module.spec.h"
#include "write_handler/write_handler.module.spec.h"

int main(void) {
  cspec_run_suite("all", {
    T_file_handler();
    T_read_handler();
    T_write_handler();
  });
}
