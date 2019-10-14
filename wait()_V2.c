#include <stdio.h> // printf
#include <stdlib.h> // exit
#include <unistd.h> // fork, getpid

void fils() {
    printf(" Fils %d - se termine \n", getpid());
    exit(0);
}

void pere() {
    printf("Père %d - en pause \n", getpid());
// wait(NULL);
    sleep(30);
    exit(0);
}

void erreur(char *message) {
    fprintf(stderr, " Erreur : %s\n", message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int pid, nb = 0;
    for (;; nb++) {
        switch (pid = fork()) {
            case 0:
                exit(0);
            case -1:
                printf("nb =%d\n", nb);
                exit(1);
            default:
                printf("pid =%d\n", pid);
// wait(NULL);
        }
    }
}
