/*
Name:Surabhi Datta Mhaskar
Date:
Description:
Sample Input:
Sample Output:
 */
#include<stdio.h>
#include<string.h>
#include "mp3.h"
int main(int argc,char **argv)
{
    FILE *fp;
    if(argc > 1)
    {
	if(strcmp(argv[1],"--help") == 0)
	{
	    printf("-----------------------------------HELP MENU-------------------------------------\n1. -v -> to view mp3 file contents\n2. -e -> to edit mp3 file contens\n       2.1 -t -> to edit song title\n       2.1 -a -> to artist name\n       2.3 -A -> to edit album name\n       2.4 -y -> to edit year\n       2.5 -m -> to edit content\n       2.6 -c -> to edit comment\n----------------------------------------------------------------------------------------\n");
	}
	else if(strcmp(argv[1],"-v") == 0)
	{
	    printf("--------------------------------------------SELECTED VIEW DETAILS-----------------------------------------------\n");
	    if(strstr(argv[2],".mp3"))
	    {
		if((fp = fopen(argv[2],"r")) != NULL)
		{
		    rewind(fp);
		    char ID[3];
		    fread(ID,1,3,fp);
		    //printf("%s id",ID);
		    if((strcmp(ID,"ID3")) == 0)
		    {
			char version[2];
			fread(version,1,2,fp);
			if(version[0] == 0x03)
			{
			    if(version[1] == 0x00)
			    {
				//printf("VERSION IS 2:\n");
				view_mp3file(fp);
			    }
			    else
			    { 
				printf("VERSION IS NOT 2:\n");
			    }
			}
		    }
		    else
		    {
			printf("FILE is not ID3 file:\n");
		    }
		}
		else
		{
		    printf("FILE IS EMPTY:\n");
		}
	    }
	}
	else if((strcmp(argv[1],"-e")) == 0)
	{
	    if((fp = fopen(argv[4],"r+")) != NULL)
	    {
		if(strstr(argv[4],".mp3"))
		{
		    char ID[3];
		    fread(ID,1,3,fp);
		    printf("%s\n",ID);
		    if((strcmp(ID,"ID3")) == 0)
		    {
			char version[2];
			fread(version,1,2,fp);
			if(version[0] == 0x03)
			{
			    if(version[1] == 0x00)
			    {
				printf("VERSION IS 2:\n");
				edit_mp3(fp,argv[2],argv[3]);
			    }
			    else
			    {
				printf("NOt 2 version file\n");
			    }
			}
		    }
		    else
		    {
			printf("File is not ID3\n");
		    }
		}
		else
		{
		    printf("FILE is not .mp3 file:\n");
		}
	    }
	    else
	    {
		printf("File is empty:\n");
	    }
	}
    }
    else
    {
	printf("-----------------------------------------------------------------------------------------------------\nERROR: ./a.out : INVALID ARGUMENTS\nUSAGE :\nTO view please pass like:  ./a.out -v mp3filename\nTo edit please pass like : ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\nTo get help pass like : ./a.out --help\n------------------------------------------------------------------------------------------------\n");
    }
}

