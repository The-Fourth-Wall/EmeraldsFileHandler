#ifndef __FILE_LOADER_SPEC_H_
#define __FILE_LOADER_SPEC_H_

#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/read_handler_base/read_handler_base.h"

static EmeraldsReadHandler *loader;
static void setup_file_loader(void) { loader = read_handler_new(); }

module(file_loader_spec, {
  before_each(&setup_file_loader);

  describe("File Loader", {
    it("creates a file_loader object", {
      EmeraldsReadHandler *fl = read_handler_new();
      assert_that(fl isnot NULL);
    });

    context("on opening an existing file", {
      FILE *fd = fopen("new_file.txt", "w");

      it("reads file: `new_file.txt`", {
        int actual = read_handler_open(loader, "new_file.txt");
        assert_that(actual is true);
      });

      fclose(fd);
    });

    context("on opening an non existent file", {
      it("fails to read a file that is not yet created", {
        int actual = read_handler_open(loader, "this_filename_does_not_exist");
        assert_that(actual is false);
      });
    });

    context("on closing a file loader", {
      it("opens a file and successfully closes the buffer", {
        read_handler_open(loader, "new_file.txt");

        int actual = read_handler_close(loader);
        assert_that(actual is true);
      });
    });

    it("loads text character by character", {
      FILE *fd = fopen("test.marg", "w");
      fprintf(fd, "%s", "text");
      fclose(fd);

      char *text = read_handler_load(loader, "test.marg");
      assert_that_int(text[0] equals to 't');
      assert_that_int(text[1] equals to 'e');
      assert_that_int(text[2] equals to 'x');
      assert_that_int(text[3] equals to 't');
      assert_that_charptr(text equals to "text");
    });
  });

  after({
    remove("new_file.txt");
    remove("test_file.txt");
    remove("test.marg");
  });
})

#endif
