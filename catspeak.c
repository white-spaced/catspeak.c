#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int countLines(char *txtFile)
{
    FILE *fp = fopen(txtFile, "r");
    if (!fp)
    {
        printf("Error opening text file");
        return -1;
    }

    int c;
    int count = 0;

    for (c = getc(fp); c != EOF; c = getc(fp)) // i have no fucking clue how this for loop works but i mean it works
    {
        if (c == '\n')
        {
            count++;
        }
    }

    fclose(fp);

    return count;
}

void printLine(int line, char *txtFile)
{
    int totalLines = countLines(txtFile);

    if (line > totalLines || line < 0)
    {
        printf("Error: requested line doesn't exist");
        return;
    }

    FILE *fp = fopen(txtFile, "r");
    if (!fp)
    {
        printf("Error opening file");
        return;
    }

    int c;
    int count = 0;

    for (c = getc(fp); c != EOF; c = getc(fp))
    {
        if (c == '\n')
        {
            count++;
        }
        if (count == line - 1)
        {
            if (c != '\n')
            { // angery never-nester sounds
                printf("%c", c);
            }
        }
    }
    fclose(fp);
}

int main(int argc, char *argv[])
{
    int color = 0;
    if (argc == 2 && strcmp(argv[1], "--color") == 0) // little did i know i would be extremely confused 5 minutes after i write this condition
    {
        color = 1;
    } else if (argc == 2 && strcmp(argv[1], "--help") == 0)
    {
        printf("makes an ascii cat say a random thing in \"$HOME/.config/catspeek/list.txt\", separated by lines\n\"--color\" for rainbow colors :3\n"); // totally didnt almost forget to add a help dialoge
        return 0;
    }
    char *noHomeFile = "/.config/catspeak/list.txt";
    char *file = getenv("HOME"); // enviornment variables...................
    strcat(file, noHomeFile);
    int items = countLines(file);
    
    srand(time(NULL));
    int line = rand() % items + 1;
    if (color == 1)
    {
        printf("\x1b[31m\(");
    } else
    {
        printf("(");
    }
    printLine(line, file);
    if (color == 1)
    { 
        printf(")\n\x1b[33m |\n\x1b[32m |  /| ､        \n\x1b[36m し(°､ ｡ 7      \n\x1b[34m    |､  ~ヽ     \n\x1b[35m    じしf_,)〳  \n\x1b[0m");
    } else
    {
        printf(")\n |\n |  /| ､        \n し(°､ ｡ 7      \n    |､  ~ヽ     \n    じしf_,)〳  \n");
    }
    
    return 0;
}
