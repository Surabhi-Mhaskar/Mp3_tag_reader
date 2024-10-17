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
int edit_mp3(FILE *fp,char *argv_2,char *argv_3)
{
    unsigned int k = 0;
    unsigned char size[1] = {0};
    fseek(fp,10,SEEK_SET);
    char str[4];
    while(fread(str,1,4,fp) > 0)
    {
	//printf("%s str\n",str);
	fseek(fp,3,SEEK_CUR);
	fread(size,1,1,fp);
	//printf("%s......size",size);
	k = (int)size[0] + 2;
	//printf("size  %d",k);
	//char t[j];
	//strcpy(t,argv_3);
	//printf("%s   ....t\n",t);
        if((strcmp(argv_2,"-t") == 0) && (strcmp(str,"TIT2") == 0))
	{
	    break;
	}

	else if((strcmp(argv_2,"-a") == 0) && (strcmp(str,"TPE1") == 0))
	{
	   break;
	}

	else if((strcmp(argv_2,"-A") == 0) && (strcmp(str,"TALB") == 0))
	{
	    
	    break;
	}

	else if((strcmp(argv_2,"-y") == 0) && (strcmp(str,"TYER") == 0))
	{
	    break;
	}
	else if((strcmp(argv_2,"-m") == 0) && (strcmp(str,"TCON") == 0))
	{
	    break;
	}
	else if((strcmp(argv_2,"-c") == 0) && (strcmp(str,"COMM") == 0))
	{
	    break;
	}
	else
	{
	    fseek(fp,k,SEEK_CUR);
	}
    }
    int len = strlen(argv_3);
    printf("len  %d",len);
    if(strcmp(argv_2,"-t") == 0)
    {

	//printf("to edit title\n");
	if(len <= k)
	{
	    int s1 = k - len;
	    char buffer[10] = {'.'};
	    fwrite(argv_3,1,len,fp);
	    while(len < k)
	    {
		fwrite(buffer,1,1,fp);
		len++;
	    }
	    printf("------------------------------------------CHANGE THE TITLE--------------------------------------------------\n\n");
	    printf("TITLE                             :     %s\n",argv_3);
	    printf("----------------------------------------TITLE CHANGED SUCCESSFULLY------------------------------------------\n\n");

	}
	else
	{
	    printf("Give shorter name:\n");
	    return FAILURE;
	}
    }
    else if(strcmp(argv_2,"-a") == 0)
    {
	//printf("to edit artist\n");
	if(len <= k)
	{
	    int s1 = k - len;
	    char buffer[10] = {'.'};
	    fwrite(argv_3,1,len,fp);
	    while(len < k)
	    {
		fwrite(buffer,1,1,fp);
		len++;
	    }
	    printf("------------------------------------------CHANGE THE ARTIST--------------------------------------------------\n\n");
	    printf("ARTIST                              :     %s\n",argv_3);
	    printf("---------------------------------------ARTIST NAME CHANGED SUCCESSFULLY---------------------------------------\n\n");

	}
	else
	{
	    printf("Give shorter name\n");
	    return FAILURE;
	}
    }
    else if(strcmp(argv_2,"-A") == 0)
    {
	//printf("to edit album\n");
	if(len <= k)
	{
	    int s1 = k - len;
	    char buffer[10] = {'.'};
	    fwrite(argv_3,1,len,fp);
	    while(len < k)
	    {
		fwrite(buffer,1,1,fp);
		len++;
	    }
	    printf("------------------------------------------CHANGE THE ALBUM--------------------------------------------------\n\n");
	    printf("ALBUM                             :     %s\n",argv_3);
	    printf("---------------------------------ALBUM NAME CAHNGED SUCCESSFULLY-------------------------------------------\n\n");

	}
	else
	{
	    printf("Give shorter name\n");
	    return FAILURE;
	}
    }
    else if(strcmp(argv_2,"-y") == 0)
    {
	//printf("year\n");
	if(len <= k)
	{
	    int s1 = k - len;
	    //printf("%d s1",s1);
	    char buffer[10] = {'.'};
	    fwrite(argv_3,1,len,fp);
	    while(len < k)
	    {
		fwrite(buffer,1,1,fp);
		len++;
	    }
	    printf("------------------------------------------CHANGE THE YEAR--------------------------------------------------\n\n");
	    printf("YEAR                             :     %s\n",argv_3);
	    printf("------------------------------------CHANGED YEAR SUCCESSFULLY----------------------------------------------\n\n");

	}
	else
	{
	    printf("Give shorter name\n");
	    return FAILURE;
	}
    }
    else if(strcmp(argv_2,"-m") == 0)
    {
	//printf("music\n");
	if(len <= k)
	{
	    int s1 = k - len;
	    //printf("%d s1",s1);
	    char buffer[10] = {'.'};
	    fwrite(argv_3,1,len,fp);
	    while(len < k)
	    {
		fwrite(buffer,1,1,fp);
		len++;
	    }
	    printf("------------------------------------------CHANGE THE MUSIC--------------------------------------------------\n\n");
	    printf("MUSIC                             :     %s\n",argv_3);
	    printf("-------------------------------CHANGED MUSIC SUCCESSFULLY---------------------------------------------------\n\n");

	}
	else
	{
	    printf("Give shorter name\n");
	    return FAILURE;
	}
    }
    else if(strcmp(argv_2,"-c") == 0)
    {
	//printf("comment\n");
	if(len <= k)
	{
	    int s1 = k - len;
	    char buffer[10] = {'.'};
	    fwrite(argv_3,1,len,fp);
	    while(len < k)
	    {
		fwrite(buffer,1,1,fp);
		len++;
	    }
	    printf("------------------------------------------CHANGE THE COMMENT--------------------------------------------------\n\n");
	    printf("COMMENT                               :     %s\n",argv_3);
	    printf("----------------------------------CHANGED COMMENT SUCCESSFULLY------------------------------------------------\n\n");

	}
	else
	{
	    printf("Give shorter name\n");
	    return FAILURE;
	}
    }

}
