#ifndef _USER_H_
#define _USER_H_

struct stat;
struct pstat;
typedef uint lock_t;

// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(char*, int);
int mknod(char*, short, short);
int unlink(char*);
int fstat(int fd, struct stat*);
int link(char*, char*);
int mkdir(char*);
int chdir(char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);
int getprocs(void);
int setpri(int);
int getpinfo(struct pstat*);
void* shmem_access(int);
int shmem_count(int);
int clone(void (*)(void*), void*, void*);
int join(void**);

// user library functions (ulib.c)
int stat(char*, struct stat*);
char* strcpy(char*, char*);
void *memmove(void*, void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, char*, ...);
char* gets(char*, int max);
uint strlen(char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);

// thread library functions (threadlib.c)
int thread_create(void (*)(void*), void*);
int thread_join(void);
void lock_init(volatile lock_t*);
void lock_acquire(volatile lock_t*);
void lock_release(volatile lock_t*);

#endif // _USER_H_

