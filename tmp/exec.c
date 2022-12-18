#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    /*以NULL結尾的字符串數組的指針，適合包含v的exec函數參數*/
    char * arg[] = {"ls", "-a", NULL};

    /*
    創建子進程並調用函數execl
    execl 中希望接收以逗號分隔的參數列表，並以NULL指針為結束標誌
    */
    if (fork() == 0) {
        printf("1.execl:\n");
        if (execl("/bin/ls", "ls", "-a", NULL) == -1) {
            perror("execl error");
            exit(1);
        }
    }

    /*
    創建子進程並調用函數execv
    execv 中希望接受一個以NULL結尾的字符串數組的指針
    */
    if (fork() == 0) {
        printf("2.execv:\n");
        if (execv("/bin/ls", arg) < 0) {
            perror("execv error");
            exit(1);
        }
    }

    /*
    創建子進程並調用函數execlp
    execlp 中
    1. l 是希望接收以逗號分隔的參數列表，列表以NULL指針作為結束標誌
    2. p 是一個以NULL結尾的字符串數組指針，函數可以DOS的PATH變量查找子程序文件
    */
    if (fork() == 0) {
        printf("4.execvp:\n");
        if (execvp("ls", arg) < 0) {
            perror("execvp error");
            exit(1);
        }
    }

    /*
    創建子進程並調用函數execle
    1. l 是希望接收以逗號分隔的參數列表，列表以NULL指針作為結束標誌
    2. e 是指函數傳遞指定參數envp, 允許改變子進程的環境，無後綴 e 時，子進程使用當前進程的環境
    */
    if (fork() == 0) {
        printf("5.execle:\n");
        if (execle("/bin/ls", "ls", "-a", NULL, NULL) == -1) {
            perror("execle error");
            exit(1);
        }
    }

    /*
    創建子進程並調用函數execve
    1. v 是希望接收到一個以NULL結尾的字符串數組的指針
    2. e 是指函數傳遞指定參數envp, 允許改變子進程的環境，無後綴 e 時，子進程使用當前進程的環境
    */
    if (fork() == 0) {
        printf("6.execve:\n");
        if (execve("/bin/ls", arg, NULL) == 0) {
            perror("execve error");
            exit(1);
        }
    }

    return 0;
}

