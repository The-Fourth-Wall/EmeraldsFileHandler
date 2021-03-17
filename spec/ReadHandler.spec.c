#include "ReadHandler.spec.h"

module(T_ReadHandler, {
    describe("#get_value", {
        it("returns `Hello, World!`", {
            assert_that_charptr(get_value() equals to "Hello, World!");
        });
    });
});

spec_suite({
    T_ReadHandler();
});

spec({
    run_spec_suite("all");
});
