#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/read_handler/read_handler.h"
#include "../../src/write_handler/write_handler.h"

module(T_write_handler, {
  describe("#write", {
    it("writes `test data` to input file named `test_write.txt`", {
      bool actual = file_handler_write("test_write.txt", "test data");
      assert_that(actual is true);
    });
  });

  describe("#write line", {
    it("writes `test data` to file `test_write_line.txt` with a newline", {
      bool actual = file_handler_write_line("test_write_line.txt", "test data");
      assert_that(actual is true);

      char *res = file_handler_read("test_write_line.txt");
      assert_that_charptr(res equals to "test data\n");
    });
  });

  after({
    remove("test_write.txt");
    remove("test_write_line.txt");
  });
})
