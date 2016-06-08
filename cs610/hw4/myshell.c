//Victor Maloney CS 610 Homework #4
//November 19, 2001
//A Simple Shell That works on pipes and redirections
//I can't seem to get it exactly write on making new files on redirections
//It seems to add a space in there for some reason.

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int makeargv(char * s, char * delimiters, char *** argvp); //this should make the arguements out of the s
int parsefile(char * inbuf, char delimiter, char ** v); //parse the command lines and look for a delimeter
int redirect(char * infile, char * outfile); //this function should take care of all the redirections
void executecmdline(char * command); //execute a command line
int connectpipeline(char * cmd, int frontfd[], int backfd[]); //pipe do the pipes and check for redirections

int main(int argc, char ** argv)
{
	char input[256];
        int child;

	fprintf(stdout, "Welcome to Vic Shell 0.1 ! \n");

        while(1)
        {
		fprintf(stdout, "vsh 0.1 > ");
                if(fgets(input, 255, stdin) == NULL)
                  break;
                if(*(input + strlen(input) - 1) == '\n')
		  *(input + strlen(input) - 1) = 0;
		if(strcmp(input, "exit") == 0)
		  break;
                else
		{
			if((child = fork()) == 0) 
			{
				executecmdline(input);
				exit(1);
			}
			else if(child > 0)
				wait(NULL);
		}
	}

	return 0;
}

//These should handle redirection
int redirect(char * infile, char * outfile)
{
	int infd;
	int outfd;

	if (infile != NULL) //This redirect to infilename
	{
		if ((infd = open(infile, 0)) == -1)
			return -1;
		if(dup2(infd, 0) == -1) 
		{
			close(infd);
			return -1;
		}
		close(infd);
	}
	if (outfile != NULL) //this redirects to outfile
	{
		if((outfd = creat(outfile, 0644)) == -1)
			return -1;
		if(dup2(outfd, 1) == -1)
		{
			close(outfd);
			return -1;
		}
		close(outfd);
	}

	return 0;
}


void executecmdline(char * command)
{
   char **chargv;
   int child;
   char *cmd;
   char *nextcmd;
   int frontfd[2];
   int backfd[2];

   frontfd[0] = -1;
   frontfd[1] = -1;
   backfd[0] = -1;
   backfd[1] = -1;

   child = 0;
   if ((nextcmd = command) == NULL)
      exit(1);

   for ( ; ; )
   {
      cmd = nextcmd;
      if (cmd == NULL)
        break;
      if ((nextcmd = strchr(nextcmd, '|')) == NULL)
      { 
         backfd[1] = -1;
         child = 0;    
      }
      else
      {
         *nextcmd = '\0';       
         nextcmd++;
         if (pipe(backfd) == -1)
         {
            exit(1);
         }
         else if ((child = fork()) == -1) {
            exit(1);
         }
      }
      if (child == 0)
      {
         if (connectpipeline(cmd, frontfd, backfd) == -1)
         {
            exit(1);
         }
         else if (makeargv(cmd, " ", &chargv) > 0)
         {
            if (execvp(chargv[0], chargv) == -1)
                fprintf( stderr, "bad command or file name\n");
         }
         exit(1);
      }
      close(frontfd[0]);
      close(frontfd[1]);
      frontfd[0] = backfd[0];
      frontfd[1] = backfd[1];
   }  
   close(backfd[0]);
   close(backfd[1]);
   exit(1);
}

//seperate the commands
int parsefile(char *s, char delimiter, char **v)
{
   char *p;
   char *q;
   int offset;
   int error = 0;

   *v = NULL;
   if ((p = strchr(s, delimiter)) != NULL)  
   {
       if ((q = (char *)malloc(strlen(p + 1) + 1)) == NULL)
       {
           error = -1;
       }
       else 
       {
           strcpy(q, p + 1);
           if ((*v = strtok(q, "><|")) == NULL)
           {
              error = -1;
           }
           offset = strlen(q);
           strcpy(p, p + offset + 1);
       }
   }
   return error;
}

//Connect the approiate pipe lines and check for indirections
int connectpipeline(char *command, int frontfd[], int backfd[])
{
   int error = 0;
   char *infile;
   char *outfile;

   if (parsefile(command, '<' , &infile) == -1)
   {
      error = -1;
   }
   else if (infile != NULL && frontfd[0] != -1)
   {
      error = -1; 
   }
   else if (parsefile(command, '>' , &outfile) == -1)
   {
      error = -1;
   }
   else if (outfile != NULL && backfd[1] != -1)
   {
      error = -1;
   }
   else if (redirect(infile, outfile) == -1)
   {
      error = -1;
   }
   else 
   {
      if (frontfd[0] != -1) 
      {
         if (dup2(frontfd[0], 0) == -1)
         {
            error = -1;
         }
       }
       if (backfd[1] != -1) 
       {
          if (dup2(backfd[1], 1) == -1)
          {
             error = -1;
          }
       }
   }

   close (frontfd[0]);
   close (frontfd[1]);
   close (backfd[0]);
   close (backfd[1]);
   return error;
}

//This should make the arguements to pass to execvp's second arguements
int makeargv(char * s, char * delimiters, char *** argvp)
{
   char *t;
   char *snew;
   int numtokens;
   int i;
   snew = s + strspn(s, delimiters);
                              /* create space for a copy of snew in t */
   if ((t = calloc(strlen(snew) + 1, sizeof(char))) == NULL)  //create space for a copy of the new s in t
   {
      *argvp = NULL;
      numtokens = -1;
   } 
   else //count the number of tokens in the new s
   { 
      strcpy(t, snew);
      if (strtok(t, delimiters) == NULL)
      {
         numtokens = 0;
      }
      else
      {
         for (numtokens = 1; strtok(NULL, delimiters) != NULL; numtokens++);
      }
      if ((*argvp = calloc(numtokens + 1, sizeof(char *))) == NULL) 
      {
         free(t);
         numtokens = -1;
      } 
        else 
        {            // put pointers to arguements in the array 
         if (numtokens > 0) 
         {
            strcpy(t, snew);
            **argvp = strtok(t, delimiters);
            for (i = 1; i < numtokens + 1; i++)
            {
               *((*argvp) + i) = strtok(NULL, delimiters);
            }
         } 
         else
         {
           **argvp = NULL;
           free(t);
         }
      }
   }

   return numtokens;
}
