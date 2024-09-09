#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    struct dirent *de;  // Pointer for directory entry
    DIR *dr;

    // Open the directory specified by the user, or use the current directory if none provided
    if (argc == 2) {
        dr = opendir(argv[1]);
    } else {
        dr = opendir(".");
    }

    if (dr == NULL) {
        perror("Error opening directory");
        return 1;
    }

    // Read and print the directory entries
    while ((de = readdir(dr)) != NULL) {
        printf("%s\n", de->d_name);
    }

    closedir(dr);
    return 0;
}
