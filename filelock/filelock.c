#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void lock_file(int fd, int lock_type)
{
    struct flock lock;
    lock.l_type = lock_type; // F_RDLCK for read, F_WRLCK for write, F_UNLCK for unlock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; // 0 means lock the whole file

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        if (errno == EACCES || errno == EAGAIN)
        {
            printf("File is already locked by another process.\n");
        }
        else
        {
            perror("Error applying lock");
        }
        exit(1);
    }

    if (lock_type == F_RDLCK)
    {
        printf("Read lock applied on file.\n");
    }
    else if (lock_type == F_WRLCK)
    {
        printf("Write lock applied on file.\n");
    }
    else if (lock_type == F_UNLCK)
    {
        printf("File lock released.\n");
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDWR);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    // Apply write lock
    lock_file(fd, F_WRLCK);

    // Simulate file operation
    printf("Simulating file operation...\n");
    sleep(5); // Simulate some operation

    // Unlock the file
    lock_file(fd, F_UNLCK);

    close(fd);
    return 0;
}
