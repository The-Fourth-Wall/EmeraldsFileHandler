# ReadHandler

A safe file reader api.

# Installation

Install the library

`em list`
`em install`
`em build lib`

## Usage

```c
#include "ReadHandler.h"

int main(void) {
    char *line1;
    char *line2;
    struct read_handler *h = read_handler_new();
    
    if(read_handler_open(h, "file.txt")) {
        line1 = read_handler_read_line();
        line2 = read_handler_read_line();
    }

    printf("%s\n", line1);
    printf("%s\n", line2);

    free(line1);
    free(line2);

    read_handler_close(h);
}
```

## Development

## Contributing

1. Fork it (<https://github.com/Oblivious-Oblivious/ReadHandler/fork>)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Contributors

- [Oblivious](https://github.com/Oblivious-Oblivious) - creator and maintainer
