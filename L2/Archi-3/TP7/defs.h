#ifndef __DEFS_H
#define __DEFS_H

#define BSIZE 1024
#define NDIRECT 12
#define DIRSIZ 14

struct block
{
    char data[BSIZE];
};

struct image
{
    block* data;
    uint size;
};

struct superblock {
  uint magic;        // Must be FSMAGIC
  uint size;         // Size of file system image (blocks)
  uint nblocks;      // Number of data blocks
  uint ninodes;      // Number of inodes.
  uint nlog;         // Number of log blocks
  uint logstart;     // Block number of first log block
  uint inodestart;   // Block number of first inode block
  uint bmapstart;    // Block number of first free map block
};

struct dinode {
  short type;              // File type
  short major;             // Major device number (T_DEV only)
  short minor;             // Minor device number (T_DEV only)
  short nlink;             // Number of links to inode in file system
  uint size;               // Size of file (bytes)
  uint addrs[NDIRECT + 1]; // Data block addresses
};

struct dirent {
  ushort inum;
  char name[DIRSIZ];
};

#endif
