#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <source_file> <link_name>\n", argv[0]);
        return 1;
    }

    // Create a hard link from source_file to link_name
    if (link(argv[1], argv[2]) == -1)
    {
        perror("Error creating hard link");
        return 1;
    }

    printf("Hard link created successfully from %s to %s\n", argv[1], argv[2]);
    return 0;
}
