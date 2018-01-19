#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int znak,i,j, niz[3][8];
    char ime[50];
    FILE *pf;

    printf ("ime fajla je:");
    gets(ime);
    pf=fopen(ime,"r");

    if (pf==NULL) {
        printf("ne valja ime %s\n", ime);
    }
    i=0;
    j=0;
    while ((znak=fgetc(pf))!=EOF)
    {
    if ((znak!='\n')) {
        niz[i][j]=znak;
        j++;
    }
    else {
        niz[i][j]=znak;
        i++;
        j=0;
    }
    //    putchar (znak);
    }
    fclose(pf);
    printf("vrednost elementa prvog reda druge kolone je %c ", niz[0][0]);

   int rows = sizeof(niz)/sizeof (niz[0]);
   int columns = sizeof(niz[0])/sizeof (niz[0][0])-1;
    printf("rows %d, columns %d", rows, columns);

    pf=fopen("D:\\C\\trpaj.txt","w");
if(pf==NULL) {
    printf("Cannot open file.\n");
}
    i=0;
    j=0;
    for (i;i<rows;i++){
        for (j;j<columns;j++){
         fputc(niz[i][j], pf);
        }
        fputc('\n', pf);
        j=0;
    }
    fclose(pf);
    return EXIT_SUCCESS;

}
