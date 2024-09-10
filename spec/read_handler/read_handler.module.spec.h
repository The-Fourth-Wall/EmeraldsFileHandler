#ifndef __READ_HANDLER_MODULE_SPEC_H_
#define __READ_HANDLER_MODULE_SPEC_H_

#include "../../libs/cSpec/export/cSpec.h"
#include "../../src/read_handler/read_handler.h"
#include "../../src/write_handler/write_handler.h"

module(T_read_handler, {
  describe("#reader open", {
    it("loads text character by character", {
      file_handler_write("test.marg", "text");

      char *text = file_handler_read("test.marg");
      assert_that_int(text[0] equals to 't');
      assert_that_int(text[1] equals to 'e');
      assert_that_int(text[2] equals to 'x');
      assert_that_int(text[3] equals to 't');
      assert_that_charptr(text equals to "text");
    });
  });

  after({ remove("test.marg"); });
})

#endif
