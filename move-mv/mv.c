#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    // Use the rename() system call to move/rename the file
    if (rename(argv[1], argv[2]) == -1) {
        perror("Error moving/renaming file");
        return 1;
    }

    return 0;
}
