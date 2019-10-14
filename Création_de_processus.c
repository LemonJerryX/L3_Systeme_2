#include <stdio.h> // printf
#include <stdlib.h> // exit
#include <unistd.h> // fork, getpid

void fils(int pid) {
    printf("Fils %d: reçu %d\n", getpid(), pid);
    exit(0);
}

void pere(int pid) {
    printf("Père %d: reçcu %d\n", getpid(), pid);
    exit(0);
}

void erreur(char *message) {
    fprintf(stderr, " Erreur : %s\n", message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int pid;
    switch (pid = fork()) {
        case -1:
            erreur(" fork ");
        case 0:
            fils(pid);
    }
    pere(pid);
}
