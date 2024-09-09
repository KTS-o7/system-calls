#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // Use the unlink() system call to remove the file
    if (unlink(argv[1]) == -1)
    {
        perror("Error deleting file");
        return 1;
    }

    return 0;
}
