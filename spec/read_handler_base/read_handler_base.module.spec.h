#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/read_handler_base/read_handler_base.h"

static EmeraldsReadHandler *T_read_handler_object;
static void setup_read_handler_object(void) {
  T_read_handler_object = read_handler_new();
}

module(T_read_handler, {
  before_each(&setup_read_handler_object);

  describe("#reader open", {
    context("on reading an existing file", {
      fopen("new_file.txt", "w");

      it("reads file: `new_file.txt`", {
        bool actual = read_handler_open(T_read_handler_object, "new_file.txt");
        assert_that(actual is true);
      });
    });

    context("on reading an non existent file return false", {
      it("fails to read a file that is not yet created", {
        bool actual = read_handler_open(
          T_read_handler_object, "this_filename_does_not_exist"
        );
        assert_that(actual is false);
      });
    });
  });

  describe("#reader close", {
    it("opens a file and successfully closes the buffer", {
      read_handler_open(T_read_handler_object, "new_file.txt");

      bool actual = read_handler_close(T_read_handler_object);
      assert_that(actual is true);
    });
  });

  after({
    remove("new_file.txt");
    remove("test_file.txt");
  });
})
