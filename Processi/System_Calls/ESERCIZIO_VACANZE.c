// esercizio 1 systemcalls modificato, leggere 8 byte al posto di 1 per ogni riga

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      printf("Numero argomenti sbagliato\n");
      exit(1);
   }

   int fd, nread;
   char buff[8];
   int cont = 0; // conta quanti caratteri ha scritto

   fd = open(argv[1], O_RDONLY);

   while ((nread = read(fd, buff, sizeof(buff))) > 0)
   {
      write(1, buff, nread);
      cont += nread;

      if (cont >= 8)
      {
         printf("\n");
         cont = 0;
      }
   }

   close(fd);

   return 0;
}
