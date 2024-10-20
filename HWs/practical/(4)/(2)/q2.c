#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
int main(void)
{


    size_t amount = (float)3 / sizeof(int) * pow(2, 30);

    int fd[2];
    pipe(fd);

    pid_t consumer_pid = fork();
    if (consumer_pid < 0)
    {
        printf("Error in forking consumer\n");
    }

    else if (consumer_pid == 0)
    {

        int *data = (int *)malloc(sizeof(int) * (size_t)amount);

        write(fd[1], &data, sizeof(int *));

        sleep(10);

        exit(0);
    }


    int *localData = (int *)malloc(sizeof(int) * amount);

    int *writtenData;

    struct iovec iov[2];
    struct iovec remote[2];

    read(fd[0], &writtenData, sizeof(int *));

    memset(localData, rand() % 10, sizeof(int) * (size_t)amount);
    ssize_t nwritten = 0;

    for (int i = 0; i < 2; i++)
    {
        iov[i].iov_base = &localData[i * 2 * amount / 4];
        iov[i].iov_len = 2 * amount;

        remote[i].iov_base = &writtenData[i * 2 * amount / 4];
        remote[i].iov_len = 2 * amount;
    }

    for (int i = 0; i < 2; i++)
    {
        nwritten += process_vm_writev(consumer_pid, &iov[i], 1, &remote[i], 1, 0);
        printf("written %ld\n", nwritten);
    }

    if (nwritten == 4 * amount)
    {
        printf("3Gb data is written succesfully!");
    }
    sleep(5);

    wait(NULL);
    return 0;
}