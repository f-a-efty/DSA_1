#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

using namespace std;

int z = 2;

int main() {
    while (fork() == 0) {
        z++;
        cout << z;
        cout<<"\n";
        if (z % 3) break;
    }
    wait(NULL);
    int rc;
    if ((rc = fork())) {
        cout << rc;
        cout<<"\n";
        wait(NULL);
        exit(0);
     }
}
