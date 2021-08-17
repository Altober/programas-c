
#include <stdio.h>

#define MAXC 1024   /* if you need a constant, #define one (or more) */

size_t coefficients (FILE *fp, double *a, double *b)
{
    char buf[MAXC];         /* buffer for reading each line */ 
    size_t ncoeff = 0;      /* number of coefficient pairs read */

    while (ncoeff < MAXC && fgets (buf, MAXC, fp))  /* read each line */
        /* if it contains 2 double values */
        if (sscanf (buf, "%lf %lf", &a[ncoeff], &b[ncoeff]) == 2)
            ncoeff++;       /* increment counter */

    return ncoeff;          /* return total count of pairs read */
}

int main (int argc, char **argv) {

    double a[MAXC] = {0}, b[MAXC] = {0};    /* arrays of MAXC doubles    */
    size_t n = 0;                           /* count of doubles returned */

    /* use filename provided as 1st argument (stdin by default) */
    FILE *fp = argc > 1 ? fopen (argv[1], "r") : stdin;

    if (!fp) {  /* validate file open for reading */
        perror ("file open failed");
        return 1;
    }

    if (!(n = coefficients (fp, a, b))) {   /* validate coeff pairs read */
        fputs ("error: no double values read from file.\n", stderr);
        return 1;
    }

    if (fp != stdin)   /* close file if not stdin */
        fclose (fp);

    for (size_t i = 0; i < n; i++)  /* output coefficients */
        printf ("a[%zu] : %.1f   b[%zu] : %.1f\n", i, a[i], i, b[i]);

    return 0;        
}