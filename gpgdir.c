#include "builtin.h"

// TODO: add help related to list of all available subcommands
const char *gpgdir_usage_string = "gpgdir [version] [help] <command> [<args>]";

struct cmd_struct {
    const char *cmd;
    int (*fn)(int, const char **);
};

static int run_builtin(struct cmd_struct *p, int argc, const char **argv)
{
    int status;

    status = p->fn(argc, argv);
    if (status) {
        return status;
    }
    return 0;
}

static struct cmd_struct commands[] = {
    // { "decrypt", cmd_decrypt },
    { "encrypt",    cmd_encrypt },
    // { "help",    cmd_help    },
    { "version",    cmd_version },
};

static struct cmd_struct *get_builtin(const char *s)
{
    size_t i;
    for (i = 0; i < ARRAY_SIZE(commands); i++) {
        struct cmd_struct *p = commands + i;
        if (!strcmp(s, p->cmd))
            return p;
    }
    return NULL;
}

static void handle_builtin(int argc, const char **argv)
{
    const char *cmd;
    struct cmd_struct *builtin;

    cmd = argv[0];
    builtin = get_builtin(cmd);
    if (builtin) {
        exit(run_builtin(builtin, argc, argv));
    }
}

int main(int argc, const char **argv)
{
    // Look for flags...
    argv++;
    argc--;

    if (argc == 0) {
        // The user didn't specify a command: give them help.
        printf("usage: %s\n\n", gpgdir_usage_string);
        exit(1);
    }
    handle_builtin(argc, argv);
}
