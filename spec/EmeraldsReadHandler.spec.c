#include "read_handler_base/file_loader.module.spec.h"
#include "read_handler_base/read_handler_base.module.spec.h"

int main(void) {
  cspec_run_suite("all", {
    T_read_handler();
    file_loader_spec();
  });
}
