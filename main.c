/* This Is A Simple App To Write Down What You Have Learned From Your Day */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int args, char *argv[])
{
    int fd;
    if((fd = open("/home/omar/computer/projects/todayInSentence/notes.txt", O_RDWR|O_APPEND|O_CREAT, 0600)) == -1)
        perror("open");

    if(args == 2)
    {
        if(write(fd, argv[1], strlen(argv[1])) == -1)
            perror("write");
        if(write(fd, "\n", 1) == -1)
            perror("write");
    }
    else if (args > 2)
    {
        printf("Man Put Sentence In Quotes!\n");
        return 1;
    }
    else
    {
        printf("Man We Need Sentence!\n");
        return 1;
    }

    return 0;
}