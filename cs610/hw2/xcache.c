// Victor Maloney CS 671 Assignment 2
// October 12, 2001 
// Simple Cache device
// xcache.c (the main program file)

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include "cache.h"

int main() 
{
  CACHE_PKT *pNew;
  char sFileName[FILE_NAME_SIZE], sRealPath[FILE_NAME_SIZE];
  struct stat stInfo;
  long lSeekAddress, lBytes; //info taken in for start of file and how many bytes
  int size; //size of the file
  long lBlock, lBlockFirst, lBlockLast; //block number first block number last block number
  long lStart, lEnd;
  size_t iBytes;
  int i;
  FILE *cfptr; //File pointer to file
  char command[10]; //command ("read" or "write")
  char data[BLOCK_SIZE]; //data put into cache (used in read) 
  char content[100]; //content to read into cache (used in write)
  char c; //used for read in

  //make the cache packets and lists
  init_it();
  print_lru_list(cp_lru_head);
  
  // Prompt user for input
  printf("Please enter file name: ");
  scanf("%s", sFileName); 
  while(strcmp(sFileName,"NO_FILE") != 0) 
  {
   
    if (realpath( sFileName, sRealPath ) == NULL) 
    {
      perror( "Find the absolute path error" );
      exit( -1 );
    }
    fprintf(stdout, "Full path is %s\n", sRealPath);
    // Get status info; needed file length, etc.
    if ( stat(sRealPath, &stInfo) == -1 )
    {
     fprintf (stderr, "Could not get info on %s \n", sFileName);
     exit(-1);
    }
    else
    {
     size = stInfo.st_size;
    }
    printf("%s has size: %d bytes\n", sRealPath, size);
    printf("Please enter command: ");
    scanf("%s %ld %ld", command, &lSeekAddress, &lBytes);

    if(strcmp(command,"read") == 0)

    { //begin of read code

    if(lSeekAddress > size)
    {
     fprintf(stderr, "SeekAddress of %ld is to big \n", lSeekAddress);
     exit(-1);
    }

    if(size < (lSeekAddress + lBytes))
    {
     fprintf(stderr, "Reading to many bytes of the file \n"); 
     fprintf(stderr, "Truncating to read to just eof \n");
     lBytes = (size - lSeekAddress);
    }


    lBlockFirst = ((lSeekAddress) / BLOCK_SIZE);
    lBlockLast = ((lSeekAddress + (lBytes - 1)) / BLOCK_SIZE);

    for (lBlock = lBlockFirst; lBlock <= lBlockLast; lBlock++) 
    {
      if (get_block_for_read( sRealPath, lBlock, &pNew ) == -1) 
      {
         strcpy(pNew -> file_name, sRealPath);
         if(( cfptr = fopen (sRealPath, "r")) == NULL)
         {
           fprintf(stderr, "Could not open file %s \n", sRealPath);
         }
         else
         {
           fseek(cfptr,(lBlock * BLOCK_SIZE),SEEK_SET);
             for(i = 0; i < BLOCK_SIZE; i++)
             {
               c = getc(cfptr);
               if(c == EOF)
               {
                  i = 20;
               }
               else
               {
                  data[i] = c;
               }
             }
         }
            strcpy(pNew -> file_data, data);
            pNew -> block_size = i+1;
            fclose(cfptr);
            put_block_in_cache(sRealPath, lBlock, pNew);

            lStart = (lSeekAddress % BLOCK_SIZE);
            if(lBlock == lBlockLast)
            lEnd = ((lSeekAddress + lBytes) % BLOCK_SIZE);
            else
            lEnd = (BLOCK_SIZE);

            fprintf(stderr, "%s block %ld, %ld Bytes from disk(cache in %ld): ", sFileName, lBlock, (lEnd - lStart), pNew -> block_num);
            for (i = lStart;i<lEnd;i++)
            {
              fprintf(stderr, "%c", data[i]);
            }
            printf("\n");
            lSeekAddress = (lSeekAddress + (lEnd - lStart));
       }
      
       else
       {
          strcpy(data,pNew -> file_data);
          lStart = (lSeekAddress % BLOCK_SIZE);
          if(lBlock == lBlockLast)
          lEnd = ((lSeekAddress + lBytes) % BLOCK_SIZE);
          else
          lEnd = (BLOCK_SIZE);

          fprintf(stderr, "%s block %ld, %ld Bytes from cache(cache in %ld): ", sFileName,
 lBlock, (lEnd - lStart), pNew -> block_num);
            for (i = lStart;i<lEnd;i++)
            {
              fprintf(stderr, "%c", data[i]);
            }
            printf("\n");
            lSeekAddress = (lSeekAddress + (lEnd - lStart));
       }
     }
    }  
    else
    {  //begin of write code
      fprintf (stderr, "Have not implemented write yet/n");
    }
      printf("Please enter file name: ");
      scanf("%s", sFileName);

   }

  return 0;
}
