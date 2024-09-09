#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    int source_fd, dest_fd;
    ssize_t nread;
    char buffer[BUFFER_SIZE];

    // Open the source file
    source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        return 1;
    }

    // Open/create the destination file with read/write permissions
    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Error opening/creating destination file");
        close(source_fd);
        return 1;
    }

    // Copy data from source to destination
    while ((nread = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest_fd, buffer, nread) != nread) {
            perror("Error writing to destination file");
            close(source_fd);
            close(dest_fd);
            return 1;
        }
    }

    if (nread == -1) {
        perror("Error reading source file");
    }

    // Close file descriptors
    close(source_fd);
    close(dest_fd);

    return 0;
}
