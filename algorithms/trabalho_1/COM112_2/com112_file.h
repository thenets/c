struct report_struct
{
    char sortName[20];
    int moves;
    int iterations;
    float benchmark_time;
};
void relatorio(int array_size, char* file_name, struct report_struct reports[], int reports_size);
void saveArrayToFile(int array_data[], int array_size, char* file_name);