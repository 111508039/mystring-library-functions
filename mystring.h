#include<stddef.h>
size_t mystrlen(const char *p);

char *mystrcat(char *p, char *q);

char *mystrcpy(char *p, const char *q);

char *mystrncpy(char *p ,const char *q, size_t n);

char *mystrrev(char *p);

char *mystrreplace(char *t, char *s, char *m);

size_t mystroccurance(char *t, char *s);

char *mystrchr(const char *p, int c);

char *mystrpbrk(const char *p, const char *q);

int mystrcmp(const char *t, const char *s);

size_t mystrspn(const char *p, const char *q);

size_t mystrcspn(const char *p, const char *q);

char *mystrrchr(const char *p, int c);

char *mystrncat(char *p, char *q, size_t n);

void *mymemset(void *s, int c, size_t n);

void *mymemcpy(void *s, const void *t, size_t n);

char *mystrstr(const char *t, const char *s);

int mystrncmp(const char *t, const char *s, size_t n);

void *mymemmove(void *s, const void *t, size_t n);

int mymemcmp(const void *t, const void *s, size_t n);

void *mymemchr(const void *p, int c, size_t n);

char *mystpcpy(char *p , const char *q);

size_t mystrxfrm(char *p , const char *q, size_t n);

int mystrncasecmp(const char *t, const char *s, size_t n);

char *mystrtok(char *s1, const char *delimit);

void *mymemmem(void *t, size_t lent, void *s, size_t lens);

int mystrcasecmp(const char *t, const char *s);

char *myindex(const char *t, int c);

char *myrindex(const char *t, int c);

char *mystrdup(const char *p);

void *mymemfrob(void *p, size_t n);

char *mystrndup(const char *p, size_t n); 

void mybzero(void *p, size_t n);

void mybcopy(const void *p, void *q, size_t n);
