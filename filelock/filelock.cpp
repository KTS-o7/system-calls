#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

using namespace std;

void lock_file(int fd, int lock_type) {
    struct flock lock;
    lock.l_type = lock_type; // F_RDLCK for read, F_WRLCK for write, F_UNLCK for unlock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; // 0 means lock the whole file

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        if (errno == EACCES || errno == EAGAIN) {
            cerr << "File is already locked by another process." << endl;
        } else {
            cerr << "Error applying lock: " << strerror(errno) << endl;
        }
        exit(1);
    }

    if (lock_type == F_RDLCK) {
        cout << "Read lock applied on file." << endl;
    } else if (lock_type == F_WRLCK) {
        cout << "Write lock applied on file." << endl;
    } else if (lock_type == F_UNLCK) {
        cout << "File lock released." << endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <file>" << endl;
        return 1;
    }

    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        cerr << "Error opening file: " << strerror(errno) << endl;
        return 1;
    }

    // Apply write lock
    lock_file(fd, F_WRLCK);

    // Simulate file operation
    cout << "Simulating file operation..." << endl;
    sleep(5); // Simulate some operation

    // Unlock the file
    lock_file(fd, F_UNLCK);

    close(fd);
    return 0;
}
