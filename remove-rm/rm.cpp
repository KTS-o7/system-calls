#include <iostream>
#include <unistd.h>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <file>" << endl;
        return 1;
    }

    // Use the unlink() system call to remove the file
    if (unlink(argv[1]) == -1) {
        perror("Error deleting file");
        return 1;
    }

    return 0;
}
