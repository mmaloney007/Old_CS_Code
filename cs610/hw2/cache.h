//Victor Maloney
//CS 671
//Cache.h

#define CACHE_PKT      struct cache_pkt
#define HASH_SIZE      50
#define CACHE_SIZE     15
#define FILE_NAME_SIZE 80
#define BLOCK_SIZE     20

CACHE_PKT
{
   CACHE_PKT  *c_hash_next;  
   CACHE_PKT  *c_hash_prev;  
   CACHE_PKT  *c_free_next;  
   CACHE_PKT  *c_lru_next;
   CACHE_PKT  *c_lru_prev;
   long       block_num;
   long       block_size;
   int        dirty_bit;
   char       file_name[FILE_NAME_SIZE];
   char       file_data[BLOCK_SIZE];
};

CACHE_PKT  *hash_table[HASH_SIZE];
CACHE_PKT  *cp_free_list;
CACHE_PKT  *cp_lru_head;
CACHE_PKT  *cp_lru_tail;

//create a free list and initalize everything to zero
void init_it();

//gets a free cache packet

CACHE_PKT * get_cache_free();

//this geta a cache packet for read
int get_block_for_read(char *p_file_name, long block_num, CACHE_PKT **p_p_cache_pkt);

//this writes a block from the cache packet

void write_block(CACHE_PKT *p_cache_pkt);

//this puts a cache block into the cache

void put_block_in_cache(char *p_file_name,long block_num,CACHE_PKT *p_cache_pkt);

// hash function; the hash key is the length of the absolute path
// multiplied with the block number
int hash( char *sFileName, long lBlockNum );

//print what happened

void print_lru_list(CACHE_PKT *pkt);

//print 
void print_d(CACHE_PKT *pkt, long block, int s_byte); 
void print_c(CACHE_PKT *pkt, long block, int s_byte); 
