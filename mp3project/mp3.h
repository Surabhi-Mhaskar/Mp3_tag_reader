#include<stdio.h>
#include<stdlib.h>

#define FAILURE 0
#define SUCCESS 1

typedef struct
{
    char album_name[100];
    char artist_name[100];
    char year[4];
    char music[100];
    char title[100];
    char comment[100];
}mp3;


int view_mp3file(FILE *fp);
int edit_mp3(FILE *fp,char *argv_2,char *argv_3);
