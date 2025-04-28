// gcc -o shm_client shm_client.c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

int main()
{
    int shm_fd = shm_open("/myshm", O_RDWR, 0666);
    if (shm_fd == -1)
    {
        perror("shm_open");
        exit(1);
    }

    char *shm = mmap(0, 4096, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
    if (shm == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }

    printf("Client read: %s\n", shm);

    munmap(shm, 4096);
    return 0;
}