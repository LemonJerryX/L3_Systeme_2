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
    char buffer[100];

    int pfd[2];
    if (pipe(pfd) == -1) erreur(" pipe ");

    if (write(pfd[1], " Hello World \n",
              strlen(" Hello World \n") * sizeof(char)) == -1)
        erreur(" write ");

    if (read(pfd[0], buffer, sizeof(buffer)) == -1)
        erreur(" read ");
    printf("%s", buffer);

    if (close(pfd[0]) == -1) erreur(" close ");
    if (close(pfd[1]) == -1) erreur(" close ");
}
