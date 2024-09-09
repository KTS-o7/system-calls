#include <iostream>
#include <fstream>

using namespace std;

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <source> <destination>" << endl;
        return 1;
    }

    // Open the source file
    ifstream sourceFile(argv[1], ios::binary);
    if (!sourceFile) {
        cerr << "Error opening source file: " << argv[1] << endl;
        return 1;
    }

    // Open/Create the destination file
    ofstream destFile(argv[2], ios::binary);
    if (!destFile) {
        cerr << "Error opening/creating destination file: " << argv[2] << endl;
        return 1;
    }

    char buffer[BUFFER_SIZE];
    streamsize bytesRead;

    while ((bytesRead = sourceFile.readsome(buffer, BUFFER_SIZE)) > 0) {
        destFile.write(buffer, bytesRead);
        if (!destFile) {
            cerr << "Error writing to destination file" << endl;
            return 1;
        }
    }

    if (sourceFile.bad()) {
        cerr << "Error reading source file" << endl;
        return 1;
    }

    cout << "File copied successfully." << endl;

    return 0;
}
