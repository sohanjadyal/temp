#include <stdio.h>
#include <string.h>
#include <time.h>

#define d 256

int main()
{
    char txt[100], pat[100];

    printf("Enter text: ");
    scanf("%s", txt);

    printf("Enter pattern: ");
    scanf("%s", pat);

    int q = 101;

    int m = strlen(pat);
    int n = strlen(txt);

    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for(i = 0; i < m - 1; i++)
        h = (h * d) % q;
    

    for(i = 0; i < m; i++)
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;

    clock_t start = clock();

    for(i = 0; i <= n - m; i++){
        if(p == t){

            for(j = 0; j < m; j++){
                if(txt[i + j] != pat[j])
                    break;
            }

            if(j == m) 
                printf("Pattern found at %d\n", i);
        }

        if(i < n - m){
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            if(t < 0)
                t = t + q;
        }
    }

    clock_t end = clock();

    double time_taken =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time: %f sec\n", time_taken);

    return 0;
}