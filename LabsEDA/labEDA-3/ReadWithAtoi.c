#include <stdlib.h>
#include <stdio.h>

int main(){

  // Open File
  const char fname[] = "testEntrada.txt";

  FILE *fp = fopen(fname, "r");

  if( !fp )
    goto error_open_file;
  printf("Opened file: %s\n", fname); 

  // Count Lines
  char cr;
  size_t lines = 0;

  while( cr != EOF ) {
    if ( cr == '\n' ) {
        lines++;
    }
    cr = getc(fp);
  }
  printf("Number of lines: %ld\n", lines); 
  rewind(fp);

  // Read data
  {// 'goto' + data[lines] causes error, introduce block as a workaround
    char *data[lines];
    size_t n;

    for (size_t i = 0; i < lines; i++) {
        data[i] = NULL;
        size_t n = 0;

        getline(&data[i], &n, fp);

        if ( ferror( fp ) )
            goto error_read_file;

    }

    for (size_t i = 0; i < lines; i++) {
      printf("%s", data[i]);
      free(data[i]);
    }

  }

  // Close File
  fclose(fp);

  return 0;

error_read_file:
  perror("fopen ");
  return 1;

error_open_file:
  perror("getline ");
  return 2;

}