/*
Name:Surabhi Datta Mhaskar
Date:
Description:
Sample Input:
Sample Output:
*/
#include<stdio.h>
#include<string.h>
#include"mp3.h"
int view_mp3file(FILE *fp)
{
    printf("\n");
    printf("----------------------------------------------------------------------------------------------------------------\n-----------------------------------MP3 TAG READER AND EDITOR FOR ID3v2-------------------------------------------\n----------------------------------------------------------------------------------------------------------------\n");
    unsigned int j = 0;
    unsigned char size[1] = {0};
    fseek(fp,10,SEEK_SET);
    while(!feof(fp))
    {
	char str[4];
	fread(str,1,4,fp);
        //printf("->%s",str);
        //printf("TIT2 is for title of the album\n");
	fseek(fp,3,SEEK_CUR);
        fread(size,1,1,fp);
        j = (int)size[0] + 2;
        //printf("%d size\n",j);
        char t[j];
        fread(t,1,j,fp);
	if((strcmp(str,"TIT2")) == 0)
	{
	    printf("TITLE                   :                ");
	    int i = 0;
	    while( i < j)
	    {
		if(t[i] != '.')
		{
		    printf("%c",t[i]);
		}
                i++;
            }
            t[i] = '\0';
	    printf("\n");
	   
        }
	else if((strcmp(str,"TPE1")) == 0)
	{
	    printf("ARTIST                  :                ");
	    int i = 0;
	    while(i < j)
	    {
		if(t[i] != '.')
		{
		    printf("%c",t[i]);
		}
	        i++;
	    }
	    t[i] = '\0';
	    printf("\n");
	}
        else if((strcmp(str,"TALB")) == 0)
        {
	    printf("ALBUM                   :                ");
	    int i = 0;
	    while(i < j)
	    {
		if(t[i] != '.')
		{
		    printf("%c",t[i]);
		}
		i++;
	    }
	    t[i] = '\0';
	    printf("\n");
	}
        else if((strcmp(str,"TYER")) == 0)
        {
	    printf("YEAR                    :                ");
	    int i = 0;                                                                                                                                              while(i < j)
	    {
		if(t[i] != '.')
		{
		    printf("%c",t[i]);
		}
                i++;
            }
            t[i] = '\0';
	    printf("\n");
	}
        else if((strcmp(str,"TCON")) == 0)
	{
	    printf("MUSIC                   :                ");
	    int i = 0;                                                                                                                                              while(i < j)
            {
		if(t[i] != '.')
		{
		    printf("%c",t[i]);
		}
                i++;
           }
           t[i] = '\0';
	   printf("\n");
	}
	else if((strcmp(str,"COMM")) == 0)
        {                                                                                                                                                             printf("COMMENT                 :                ");
              int i = 0;                                                                                                                                              while(i < j)                                                                                                                                            {
		  if(t[i] != '.')
		  {
		      printf("%c",t[i]);
		  }
                  i++;                                                                                                                                                }
              t[i] = '\0';
	      printf("\n");
        }
	

    }
    printf("----------------------------------------------------------------------------------------------------------------\n-------------------------------------------DISPLAYED DETAILS SUCCESSFULLY-------------------------------------------\n");

        	

}

