#include <stdio.h>

// Save input to file
void saveArrayToFile(int array_data[], int array_size, char* file_name) {
  FILE * fp;
  int i;
  fp = fopen (file_name,"w");

  /* write 10 lines of text into the file stream*/
  for(i = 0; i < array_size;i++){
    fprintf (fp, "%d\r\n", array_data[i]);
  }

  fclose (fp);
}