#include <iostream>
#include <unistd.h>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <source_file> <link_name>" << endl;
        return 1;
    }

    // Create a hard link from source_file to link_name
    if (link(argv[1], argv[2]) == -1) {
        perror("Error creating hard link");
        return 1;
    }

    cout << "Hard link created successfully from " << argv[1] << " to " << argv[2] << endl;
    return 0;
}
