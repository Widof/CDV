#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> 

int main(int argc, char *argv[])
{
  char *fileName;
  pid_t pid;
  FILE *stream;

  if (argc != 2 || strcmp(argv[1], "--help") == 0)
  {
    printf("Sposob uzycia: %s filename.txt\n", argv[0]);
    return 1;
  } else {
    fileName = argv[1];
  }
  

  // Tworzenie dziecka
  if ((pid = fork()) == -1)
  {
    printf("Blad przy tworzeniu dziecka\n");
    exit(1);
  }

  if (pid == 0) // DziaĹ‚ania dziecka
  {
    // Buforowane otwarcie pliku
    if (!(stream = fopen(fileName, "w")))
    {
      printf("Blad przy otworzeniu/utworzeniu pliku\n");
      exit(1);
    }

    // Liczby podzielne przez 3 od 1 do 50
    int i = 1;
    for (; i <= 50; i++)
    {
      if (i % 3 == 0)
      {
        // Zapis do pliku
        fprintf(stream, "%i\n", i);
      }
    }

    // Zamkniecie pliku
    if (fclose(stream) == EOF)
    {
      printf("Blad przy zamykaniu pliku\n");
      exit(1);
    }

    exit(0); // koniec dziecka
  };

  // czekaj na dziecko
  int child_status;
  wait(&child_status);
  if (child_status != 0)
  {
    printf("Dziecko zakonczone z bledem.\n");
    exit(1);
  }
  printf("Dziecko zakonczone poprawnie.\n");


  // Sprawdzenie dĹ‚ugoĹ›Ä‡i pliku - niebuforowane
  int textFile;
  int textFileLength;

  if (!(textFile = open(fileName, O_WRONLY, 0644))) {
    printf("\nBĹ‚Ä…d przy otwieraniu pliku\n");
    exit(1);
  }

  textFileLength = lseek(textFile, 0, SEEK_END);

  printf("Created file size: %i\n", textFileLength);


  if ((close(textFile)) == -1) {
    printf("Blad przy zamykaniu pliku\n");
    exit(1);
  }

  return 0;
}