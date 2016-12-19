#include "builtin.h"
#include "version.h"

int cmd_version(int argc, const char **argv)
{
    printf("gpgdir version %s\n", gpgdir_version_string);
    return 0;
}
