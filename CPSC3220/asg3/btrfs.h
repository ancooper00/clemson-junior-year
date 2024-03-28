
#include <stdio.h>
#include <string.h>
#include <ctype.h>


/* defined sizes and limits */

#define N_DIRECTORY_ENTRIES 16
//increased suze of file system to 512 blocks
#define N_BLOCKS 512

#define BLOCK_SIZE 128
#define BLOCK_SIZE_AS_POWER_OF_2 7
//changed total number of bytes and max file size based on new system size 
#define N_BYTES (512*128)
#define MAX_FILE_SIZE (512*128)
//changed filename length to be 16 bytes instead of 9
#define FILENAME_LENGTH 16

#define FIRST_VALID_FD 1
#define FIRST_VALID_BLOCK 4


/* directory entry status */

#define UNUSED 0
#define CLOSED 1
#define OPEN 2


/* special case block index values */

#define FREE 0
#define LAST_BLOCK 1


/* logical values */

#define TRUE 1
#define FALSE 0


/* storage for file system */

char storage[N_BYTES];


/* struct declarations and pointers */

struct file_block{
  char bytes[BLOCK_SIZE];
};

struct directory_entry{
  unsigned char status;
  unsigned short first_block;
  unsigned short size;
  unsigned short byte_offset;
  char name[FILENAME_LENGTH + 1];
  //added permissions to directory entry
  unsigned char readPermission;
  unsigned char writePermission;
  unsigned char executePermission;
  //is file encrypted bit
  unsigned char encrypted;
};

struct file_block *blocks;
struct directory_entry *directory;
unsigned char *file_allocation_table;


/* public interface */

void btrfs_init();

void btrfs_list_blocks();

void btrfs_list_directory();

unsigned int btrfs_create( char *name );

unsigned int btrfs_exists( char *name );

unsigned int btrfs_open(   char *name );

unsigned int btrfs_size(   unsigned int file_descriptor );

unsigned int btrfs_seek(   unsigned int file_descriptor,
                         unsigned int offset );

unsigned int btrfs_read(   unsigned int file_descriptor,
                         char *buffer,
                         unsigned int byte_count );

unsigned int btrfs_write(  unsigned int file_descriptor,
                         char *buffer,
                         unsigned int byte_count );

unsigned int btrfs_close(  unsigned int file_descriptor );

unsigned int btrfs_delete( unsigned int file_descriptor );


/* helper functions */

unsigned int btrfs_check_fd_in_range( unsigned int fd );
unsigned int btrfs_check_block_in_range( unsigned int b );
unsigned int btrfs_check_file_is_open( unsigned int fd );
unsigned int btrfs_check_valid_name( char *name );
unsigned int btrfs_size( unsigned int file_descriptor );
unsigned int btrfs_new_directory_entry();
unsigned int btrfs_map_name_to_fd( char *name );
unsigned int btrfs_new_block();
