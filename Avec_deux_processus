#include <stdio.h> // printf
#include <stdlib.h> // exit
#include <unistd.h> // fork, getpid
#include <string.h> //strlen

void fils(int *pfd) {
    char buffer[100];
    close(pfd[1]);
    read(pfd[0], buffer, sizeof(buffer));
    printf(" Fils lit : %s", buffer);
    close(pfd[0]);
    exit(0);
}

void pere(int *pfd) {
    close(pfd[0]);
    write(pfd[1], " Hello World \n",
          strlen(" Hello World \n") * sizeof(char));
    close(pfd[1]);
    exit(0);
}

void erreur(char *message) {
    fprintf(stderr, " Erreur : %s\n", message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int pfd[2];
    if (pipe(pfd) == -1) erreur(" pipe ");

    switch (fork()) {
        case -1:
            erreur(" fork ");
        case 0:
            fils(pfd);
    }
    pere(pfd);
}
