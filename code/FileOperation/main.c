#include <stdio.h>

#include "FileOperation.h"

#define     RESP_MAX_LENGTH     1024

int main(int argc, char *argv[])
{
    int ret = 0;
    char cmd[256] = {0};
    char resp[RESP_MAX_LENGTH] = {0};

    sprintf(cmd, "ls");

    ret = _exec_rfs_cmd_return_str(cmd, resp, RESP_MAX_LENGTH);

    printf("resp = %s\n", resp);

    return 0;
}