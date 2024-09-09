#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <source> <destination>" << endl;
        return 1;
    }

    // Use the rename() system call to move/rename the file
    if (rename(argv[1], argv[2]) == -1) {
        perror("Error moving/renaming file");
        return 1;
    }

    return 0;
}
