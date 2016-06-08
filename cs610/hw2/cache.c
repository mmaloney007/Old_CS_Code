//Victor Maloney
//CS 671 HW 2
//Partially Working

#include "cache.h"
#include <stdio.h>
#include <stdlib.h>

// initialization function
// creates a single linked list of CACHE_PKT structures
// except for the links, all fields are zeroed

void init_it() 
{
  int i, j;
  CACHE_PKT *pCurrent, *pNew;

  for (i = 0; i < CACHE_SIZE; i++)
  {
    // allocate memory for a structure
    if ((pNew = (CACHE_PKT *) malloc( sizeof(CACHE_PKT) )) == NULL) 
    {
      perror( "Error allocating memory" );
      exit( 1 );
    }

    //Next -- initialize the fields in cache packet.
    pNew -> block_size = BLOCK_SIZE;
    pNew -> block_num = i;
    pNew -> c_free_next = NULL;
    pNew -> c_lru_next = NULL;

    // if this is the first packet, set free list pointer to it
    if (i == 0) 
    {
       cp_free_list = pNew;
       cp_lru_head = pNew;
       pCurrent = pNew;
       pCurrent -> c_lru_prev = NULL;
    }
   // if not, add the packet at the end of the list
    else 
    {
      pCurrent -> c_lru_next = pNew;
      pNew -> c_lru_prev = pCurrent;
      pCurrent -> c_free_next = pNew;
      pCurrent = pNew;
      cp_lru_tail = pNew;
    }
  }
}

CACHE_PKT* get_cache_free()
{
  CACHE_PKT *tmp;

  if(cp_free_list == NULL)
  {
     return NULL;
  }
  else
  {
   tmp = cp_free_list;
   cp_free_list = cp_free_list -> c_free_next;
   return tmp;
  }
  fprintf(stderr, "In get cache_free()\n");
}

//this gets a clock for read in

int get_block_for_read(char *p_file_name, long block_num, CACHE_PKT **p_p_cache_pkt)
{
   int num1;
   CACHE_PKT *tmp,*temp;

   num1 = hash(p_file_name, block_num);

   if(hash_table[num1] == NULL)
   {

      tmp = get_cache_free();
      
      if(tmp == NULL)
      {
         tmp = cp_lru_head;

         if (tmp -> dirty_bit == 1)
         {
            write_block(tmp);
         }
         cp_lru_head = (tmp -> c_lru_next);
         cp_lru_head -> c_lru_prev = NULL;
         cp_lru_tail -> c_lru_next = tmp;
         tmp -> c_lru_prev = cp_lru_tail;
         tmp -> c_lru_next = NULL;
         cp_lru_tail = tmp;
     }
     else
     {
       if(tmp == cp_lru_head)
       {
         cp_lru_head = tmp -> c_lru_next;
       }
     }
    
    *p_p_cache_pkt = tmp;
  }
  else
  {

     temp = hash_table[num1];

     while(temp -> file_name != p_file_name && temp -> c_hash_next != NULL)
     {
         temp = temp -> c_hash_next;
     }
     if(strcmp(temp -> file_name, p_file_name) == 0)
     {
        if(temp == cp_lru_head)
        {
           cp_lru_head = (cp_lru_head -> c_lru_next);
           cp_lru_head -> c_lru_prev = NULL;
           cp_lru_tail -> c_lru_next = temp;
           temp -> c_lru_prev = cp_lru_tail;
           cp_lru_tail = temp;
           temp -> c_lru_next = NULL;
        }
        else
        {
          if(temp -> c_lru_prev != NULL)
          {
            (temp -> c_lru_prev) -> c_lru_next = temp -> c_lru_next;
          }
          if(temp -> c_lru_next != NULL)
          {
            (temp -> c_lru_next) -> c_lru_prev = temp -> c_lru_prev;
          }
          cp_lru_tail -> c_lru_next = temp;
          temp -> c_lru_prev = cp_lru_tail;
          temp -> c_lru_next = NULL;
          cp_lru_tail = temp;
        }
        *p_p_cache_pkt = temp;
        
        return 0;
     }
     else
     { 
         tmp = cp_lru_head;

         if (tmp -> dirty_bit == 1)
         {
             write_block(tmp);
         }
         cp_lru_head = cp_lru_head -> c_lru_next;
         cp_lru_head -> c_lru_prev = NULL;
         cp_lru_tail -> c_lru_next = tmp;
         tmp -> c_lru_prev = cp_lru_tail;
         tmp -> c_lru_next = NULL;
         cp_lru_tail = tmp;

         *p_p_cache_pkt = tmp;
     }   
     
  }
  return -1;
}

//This function "writes" a block to disk

void write_block(CACHE_PKT *p_cache_pkt)
{
    fprintf(stderr, "The block %x of block size %x that belongs to %s and contains data %sis now being written to disk...", p_cache_pkt -> block_num, p_cache_pkt -> block_size, p_cache_pkt -> file_name, p_cache_pkt -> file_data);
}

//This inserts a cache packet into the cache

void put_block_in_cache(char *p_file_name,long block_num,CACHE_PKT *p_cache_pkt)
{
   CACHE_PKT *tmp;
   int num1;
   
   num1 = hash(p_file_name,block_num);
 
   if(hash_table[num1] == NULL)
   {
     tmp = p_cache_pkt;
     tmp -> c_hash_next = NULL;
     tmp -> c_hash_prev = NULL;
     cp_lru_tail -> c_lru_next = tmp;
     cp_lru_tail = tmp;
     tmp -> c_lru_next = NULL;
     hash_table[num1] = tmp;
   }

   else
   {
     tmp = hash_table[num1];
     while(tmp -> c_hash_next != NULL)
     {
        tmp = tmp -> c_hash_next;
     }

     tmp -> c_hash_next = p_cache_pkt;
     p_cache_pkt -> c_hash_next = NULL;
     p_cache_pkt -> c_hash_prev = tmp; 
     cp_lru_tail -> c_lru_next = p_cache_pkt;
     cp_lru_tail = p_cache_pkt;
     cp_lru_tail -> c_lru_next = NULL;
   }
}

// hash function; the hash key is the length of the absolute path
// multiplied with the block number
int hash( char *sFileName, long lBlockNum ) 
{
  size_t iPathLength;
  long iHashKey;

  iPathLength = strlen( sFileName );
  iHashKey = (long)iPathLength * (lBlockNum + 1);
  return( iHashKey % HASH_SIZE );
}     

//print the lru list

void print_lru_list(CACHE_PKT *pkt)
{
   long num;
  
   while(pkt != NULL)
   {

      num = pkt -> block_num;
      if(strcmp(pkt -> file_name,"\0") == NULL)
      {
         fprintf(stderr, "%ld(NULL)->", num);
      }
      else
      {
         fprintf(stderr, "%ld(%s:%ld-%ld)->", num, pkt -> file_name, (num * 20), (((num + 1) * 20) - 1));
      }
      pkt = pkt -> c_lru_next;
    }
    fprintf(stderr, "End of List\n");
}
