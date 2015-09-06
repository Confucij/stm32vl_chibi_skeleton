#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "stm32f10x.h"

int _read_r (struct _reent *r, int file, char * ptr, int len){
  errno = EINVAL;
  return -1;
}
/***************************************************************************/
int _lseek_r (struct _reent *r, int file, int ptr, int dir){
  return 0;
}
/***************************************************************************/
static inline void put_char(char c){
    while (ITM->PORT[0].u32 == 0){;}
    ITM->PORT[0].u8 = (uint8_t) c;
//    asm (
//    "mov r0, #0x03\n"   /* SYS_WRITEC */
//    "mov r1, %[msg]\n"
//    "bkpt #0xAB\n"
//    : [msg] "r" (&c)
//    : "r0", "r1"
//    );
}

int _write_r (struct _reent *r, int file, char * ptr, int len){  
  /* For example, output string by UART */
  for(int index=0; index<len; index++) {
    put_char(ptr[index]);
  }     
  return len;
}
/***************************************************************************/
int _close_r (struct _reent *r, int file)
{
  return 0;
}
/***************************************************************************/

caddr_t _sbrk_r (struct _reent *r, int incr){
    return NULL;
}
/***************************************************************************/
int _fstat_r (struct _reent *r, int file, struct stat * st){

  return 0;
}
/***************************************************************************/
int _isatty_r(struct _reent *r, int fd){
  return 1;
}

//int _getpid(){
//        return 1;
//}

void _exit(int i)
{
//      printf("Program exit with code %d", i);
        i = i;
        while (1);
}

//int _kill(int pid, int sig){
//        (void)pid;
//        (void)sig;
//        errno = EINVAL;
//        return (-1);
//}

