#include <stdio.h>

int main()
{
    FILE *f_in;
    FILE *f_out;
    char s[1000];
    int k[10];
    int i, j;
    int first;

    f_in = fopen("input.txt", "r");
    f_out = fopen("output.txt", "w");

    if (f_in == NULL || f_out == NULL) {
        printf("Не получилось открыть файл\n");
        return 1;
    }


    while (fgets(s, 1000, f_in) != NULL) {
        for (i = 0; i < 10; i++) {
            k[i] = 0;


        i = 0;
        while (s[i] != '\0') {
            if (s[i] >= '0' && s[i] <= '9') {
                k[s[i] - '0']++;
            }
            i++;
        }


        first = 1;
        for (j = 0; j < 10; j++) {
            if (k[j] > 0) {
                if (first == 0) {
                    fprintf(f_out, ", ");
                }
                fprintf(f_out, "%d %d", j, k[j]);
                first = 0;
            }
        }
        fprintf(f_out, "\n");
    }

    fclose(f_in);
    fclose(f_out);
    return 0;
}
}
