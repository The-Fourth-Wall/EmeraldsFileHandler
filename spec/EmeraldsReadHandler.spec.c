#include "read_handler_base/file_loader.module.spec.h"
#include "read_handler_base/read_handler_base.module.spec.h"

spec_suite({
  T_read_handler();
  file_loader_spec();
});

int main(void) { run_spec_suite("all"); }
