#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int ch=0;
    FILE *src, *dest, *display;
    char dataToTransfer[50];

    src = fopen(argv[1], "r");
    dest = fopen(argv[2], "w");

    do
    {
        ch = fgetc(src);
        fputc(ch, dest);
    }while(ch != EOF);
    printf("Contents Copied!\n");

    fclose(src);
    fclose(dest);

    display = fopen(argv[1], "r");
    ch=0;

    ch = fgetc(display);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(display);
    }
    fclose(display);

    return 0;
}