#include <ctime>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <cstring>
using namespace std;

/*
struct stat {
    mode_t st_mode;   //protection mode
    ino_t st_ino;   //inode number
    dev_t st_dev;   //identifier of device containing file
    nlink_t st_nlink;   //reference count of hard links
    uid_t st_uid;   //user identifier of owner
    gid_t st_gid;   //group identifier of owner
    off_t st_size;   //total file size in bytes
    struct timespec st_atim;   //time of last access
    struct timespec st_mtim;   //time of last modification
    struct timespec st_ctim;   //time of last status change
    blksize_t st_blksize;   //preferred block size for file system I/O
    blkcnt_t st_blocks;   //number of blocks allocated
};
*/

int main(int argc, char* argv[]) {
    if(argc != 2){
        cout << "Please specify filename as '. /a.out filename'" << endl;
        return 1;
    }
struct stat buf;
     if(stat(argv[1],&buf) != 0){
         cout << "Failed to get file statistics " << endl;
         return 1;
     }
     cout << "Device Identifier:  " <<  buf.st_dev << endl;
     cout << "Inode number: " << buf.st_ino << endl;
     cout << "Protection mode: " << oct <<  buf.st_mode << endl;
     cout << "Number of hard links:" << dec <<  buf.st_nlink << endl;
     cout << "User Identifier: " << getpwuid(buf.st_uid) -> pw_name << endl;
     cout << "Group Identifier: " << getgrgid(buf.st_gid) -> gr_name << endl;
     cout << "Total File Size in bytes: " << buf.st_size << endl;
     cout << "Block size for IO: " << buf.st_blksize << endl;
     cout << "Number of blocks allocated: " << buf.st_blocks << endl;
     cout << "Time of last access: " << ctime(&buf.st_atime) << endl;
     cout << "Time of last modification: " << ctime(&buf.st_mtime) << endl;
     cout << "Time of last status change: " << ctime(&buf.st_ctime) << endl;
     return 0;
}