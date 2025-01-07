/* Scrivere un programma in linguaggio C che scriva l'alfabeto su un file
il cui nome deve essere letto da argv[1] */

#include <stdio.h>
#include <stlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    char alfabeto[] = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    int fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
    write(fd, alfabeto, strlen(alfabeto));
    close(fd);

    return 0;
}
