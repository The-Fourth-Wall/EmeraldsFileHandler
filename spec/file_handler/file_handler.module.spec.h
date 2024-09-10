#ifndef __FILE_HANDLER_MODULE_SPEC_H_
#define __FILE_HANDLER_MODULE_SPEC_H_

#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/file_handler/file_handler.h"

static EmeraldsFileHandler *loader;
static void setup_file_loader(void) { loader = file_handler_new(); }

module(T_file_handler, {
  before_each(&setup_file_loader);

  describe("File Loader", {
    it("creates a file_loader object", {
      EmeraldsFileHandler *fl = file_handler_new();
      assert_that(fl isnot NULL);
    });

    context("on opening an existing file", {
      file_handler_open(loader, "new_file.txt", "w");

      it("reads file: `new_file.txt`", {
        int actual = file_handler_open(loader, "new_file.txt", "r");
        assert_that(actual is true);
      });

      file_handler_close(loader);
    });

    context("on opening an non existent file", {
      it("fails to read a file that is not yet created", {
        int actual =
          file_handler_open(loader, "this_filename_does_not_exist", "r");
        assert_that(actual is false);
      });
    });

    context("on closing a file loader", {
      it("opens a file and successfully closes the buffer", {
        file_handler_open(loader, "new_file.txt", "r");

        int actual = file_handler_close(loader);
        assert_that(actual is true);
      });
    });
  });

  after({
    remove("new_file.txt");
    remove("test_file.txt");
  });
})

#endif
