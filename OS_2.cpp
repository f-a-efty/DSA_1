#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

using namespace std;

int main() {
    if (fork() > 0) {
        cout << " This is parent " << endl;
        int i = 3;
        while (i > 0 || fork() > 0) {
            cout << i << endl;
            i--;
            if (i < 0) break;
        }
        while (wait(NULL) > 0);
        if (i < 0) cout << " This is parent again " << endl;
        else cout << " This is a child " << endl;
    } else {
        cout << " This is another child " << endl;
        char * args[2];
        args[0] = strdup("./ bar "); // Assuming "./bar" executable
        args[1] = NULL;
        execvp(args[0], args);
        if (fork() == 0) cout << " This is grandchild " << endl;
    }
}
