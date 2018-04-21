#include <stdio.h>

struct report_struct
{
    char sortName[20];
    int moves;
    int iterations;
    float benchmark_time;
};

// Generate report
void relatorio(int array_size, char* file_name, struct report_struct reports[], int reports_size) {
  FILE * fp;
  int i;

  // Clear old data
  fp = fopen (file_name,"w");
  fclose (fp);
   
  // Write number of element at first line
  fp = fopen (file_name,"a");
  fprintf (fp, "Número de elementos ordenados: %d \n\n", array_size);

  // Write each report
  for(i=0; i<reports_size; i++) {
    fprintf (fp, "Método %s \n", reports[i].sortName);
    fprintf (fp, "    Tempo de execução       : %fs \n", reports[i].benchmark_time);
    fprintf (fp, "    Número de comparações   : %d \n", reports[i].iterations);
    fprintf (fp, "    Número de movimentações : %d \n", reports[i].moves);
  }
  fclose (fp);

  // Print generated report
  fp = fopen (file_name,"r");
  if (fp) {
      while ((i = getc(fp)) != EOF)
          putchar(i);
      fclose(fp);
  }
}

// Save input to file
void saveArrayToFile(int array_data[], int array_size, char* file_name) {
  FILE * fp;
  int i;

  // Clear old data
  fp = fopen (file_name,"w");
  fclose (fp);
   
  // Write number of element at first line
  fp = fopen (file_name,"a");
  fprintf (fp, "%d\r\n", array_size);

  // Write each 'array_data' element to 'file_name' file.
  for(i = 0; i < array_size;i++){
    fprintf (fp, "%d ", array_data[i]);
  }
 
  fclose (fp);
}