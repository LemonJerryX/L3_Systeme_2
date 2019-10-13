#include <stdio.h> // fprintf , stderr
#include <stdlib.h> // exit
#include <unistd.h> // execlp

void erreur(char *message) {
    fprintf(stderr, " Erreur : %s\n", message);
    exit(1);
}

int main(int argc, char *argv[]) {
    printf("the quick brown fox jumped over ");
    execlp(" echo ", " echo ", "the ", " lazy ", " dogs ",
           NULL);
    erreur(" execlp ");
}
