#include "builtin.h"

static const char * const checkout_usage[] = {
    "gpgdir encrypt [<options>] <dir_path>",
    NULL,
};

struct encrypt_opts {
};

int cmd_encrypt(int argc, const char **argv)
{
    printf("%s\n", argv[1]);
}
