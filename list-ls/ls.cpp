#include <iostream>
#include <dirent.h>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
    DIR *dr;
    struct dirent *de;  // Pointer for directory entry

    // Open the directory specified by the user, or use the current directory if none provided
    if (argc == 2) {
        dr = opendir(argv[1]);
    } else {
        dr = opendir(".");
    }

    if (dr == nullptr) {
        perror("Error opening directory");
        return 1;
    }

    // Read and print the directory entries
    while ((de = readdir(dr)) != nullptr) {
        cout << de->d_name << endl;
    }

    closedir(dr);
    return 0;
}
