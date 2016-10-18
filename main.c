#include<stdio.h>
#include"mystring.h"
#include<string.h>
#include<errno.h>
#include<stdlib.h>
int main() {
	char *p, *arr[40];
	int n, l, m, z;
	FILE *f1;
	f1 = fopen("test.c", "r");
	if(f1 == NULL) {
		printf("file cannot be opened");
		return (errno);	
	}
	arr[0] = "mystrlen";	arr[11] = "mymemfrob";
	arr[1] = "mystrcmp";	arr[12] = "mystrcasecmp";
	arr[2] = "mystrcpy";	arr[13] = "mystrdup";
	arr[3] = "mystrstr";	arr[14] = "mystrreplace";
	arr[4] = "mystrcat";	arr[15] = "mystrndup";
	arr[5] = "mystrpbrk";	arr[16] = "mystrncasecmp";
	arr[6] = "mystrncpy";	arr[17] = "mystroccurance";
	arr[7] = "mystrspn";	arr[18] = "mystrrev";
	arr[8] = "mystrncmp";	arr[19] = "mystrcspn";		
	arr[9] = "mystpcpy";	arr[20] = "mystrchr";
	arr[10] = "mymemmem";
	p = (char *)malloc(128);
	while(!feof(f1)) {
		fscanf(f1, "%d%s", &z, p);
		if(strcmp(p, arr[20]) == 0) {
			free(p);
			char c;
			printf("hi");
			char *q = (char *)malloc(128);
			p = (char *)malloc(128);
			fscanf(f1, "%s%c%s\n", p, &c, q);
			n = c;
			char *t = mystrchr(p, n);
			if(strcmp(t, q) == 0) 
				printf("%d.operation succeed\n", z);
			else
				printf("%d.operation failed because output is --> %s\n", z, t);
			free(q);
		}
		if(strcmp(p, arr[18]) == 0) {
			free(p);
			char *q = (char *)malloc(128);
			p = (char *)malloc(128);
			fscanf(f1, "%s%s\n", p, q);
			char *t = mystrrev(p);
			if(strcmp(t, q) == 0) 
				printf("%d.operation succeed\n", z);
			else
				printf("%d.operation failed beacuse output is --> %s\n", z, t);
			free(q);
		}
		if(strcmp(p, arr[17]) == 0) {
			free(p);
			char *q;
			q = (char *)malloc(128);
			p = (char *)malloc(128);
			fscanf(f1, "%s%s%d\n", p, q, &m);
			l = mystroccurance(p, q);
			if(l == m)
				printf("%d.operation succeed\n", z);
			else
				printf("%d.operation failed because output is --> %d\n", z, l);
			free(q);
		}
		if(strcmp(p, arr[3]) == 0 || strcmp(p, arr[17]) == 0) {
			free(p);
			char *q, *s, *t;
			q = (char *)malloc(128);
			s = (char *)malloc(128);
			p = (char *)malloc(128);
			fscanf(f1, "%s%s%s\n", p, q, s);
			t = mystrstr(p, q);
			if(strcmp(t, s) == 0)
				printf("%d.operation succeed\n", z);
			else
				printf("%d.operation failed\n", z);
			free(q);
			free(s);
		}
		if(strcmp(p, arr[16]) == 0 || strcmp(p, arr[12]) == 0) {
			char *t = (char *)malloc(128);
			strcpy(t, p);
			free(p);
			char *q;
			q = (char *)malloc(128);
			p = (char *)malloc(128);
			
			if(strlen(t) == 13) {
				fscanf(f1, "%s%s%d%d\n", p, q, &n, &m);
				l = mystrncasecmp(p, q, n);
			}
			else if(strlen(t) == 12) {	
				fscanf(f1, "%s%s%d\n", p, q, &m);
				l = mystrcasecmp(p, q);
			}
			if(m == l)
				printf("%d.operation succeed\n", z);
			else
				printf("%d.operation failed because output is --> %d\n", z, m);
			free(q);
			free(t);
		}
		if(strcmp(p, arr[15]) == 0 || strcmp(p, arr[13]) == 0) {
			char *m = (char *)malloc(128);
			strcpy(m, p);
			free(p);
			char *t;
			char *q = (char *)malloc(128);
			p = (char *)malloc(128);
			if(strlen(m) == 9) {
				fscanf(f1, "%s%d%s\n", p, &n, q);
				t = mystrndup(p, n);
			}
			else {
				fscanf(f1, "%s%s\n", p, q);
				t = mystrdup(p);
			}
			if(strcmp(t, q) == 0) 
				printf("%d.operation succeed\n", z);
			else
				printf("%d.operation failed because output is --> %s\n", z, t);
			free(q);
			free(t);
			free(m);
		}
		if(strcmp(p, arr[14]) == 0) {
			free(p);
			char *q, *s, *t, *r;
			r = (char *)malloc(128);
			q = (char *)malloc(128);
			s = (char *)malloc(128);
			p = (char *)malloc(128);
			fscanf(f1, "%s%s%s%s\n", p, q, r, s);
			t = mystrreplace(p, q, r);
			if(strcmp(t, s) == 0)
				printf("%d.operation succeed\n", z);
			else
				printf("%d.operation failed because output is --> %s\n", z, t);
			free(q);
			free(s);
			free(r);
		}
		if(strcmp(p, arr[11]) == 0) {
			free(p);
			char *q, *t;
			q = (char *)malloc(128);
			p = (char *)malloc(128);
			fscanf(f1, "%s%d%s\n", p, &n, q);
			t = mymemfrob(p, n);
			if(strcmp(t, q) == 0)
			 	printf("%d.operation succeed\n", z);
			else
			 	printf("%d.operation failed because output is --> %s\n", z, t);
			free(q);
		}
		if(strcmp(p, arr[10]) == 0) {
			free(p);
			char *q, *s, *t;
			q = (char *)malloc(128);
			s = (char *)malloc(128);
			p = (char *)malloc(128);
			fscanf(f1, "%s%d%s%d%s\n", p, &l, q, &m, s);
			t = mymemmem(p, l, q, m);
			if(strcmp(t, s) == 0)
				printf("%d.operation succeed\n", z);
			else
				printf("%d.operation failed because output is --> %s\n", z, t);
			free(q);
			free(s);
		}
		if(strcmp(p, arr[9]) == 0) {
			free(p);
			char *q, *s, *t;
			q = (char *)malloc(128);
			s = (char *)malloc(128);
			p = (char *)malloc(128);
			fscanf(f1, "%s%s%s\n", p, q, s);
			t = mystpcpy(p, q);
			if(strcmp(t, s) == 0)
				printf("%d.operation succeed\n", z);
			else
				printf("%d.operation failed because output is --> %s\n", z, t);
			free(q);
			free(s);
		}
		if(strcmp(p, arr[7]) == 0 || strcmp(p, arr[19]) == 0) {
			char *t = (char *)malloc(128);
			strcpy(t, p);
			free(p);
			char *q;
			q = (char *)malloc(128);
			p = (char *)malloc(128);
			fscanf(f1, "%s%s%d\n", p, q, &n);
			if(strlen(t) == 7)
				l = mystrspn(p, q);
			else
				l = mystrcspn(p, q);
			if(n == l)
			 	printf("%d.operation succeed\n", z);
			else
			 	printf("%d.operation failed because output is --> %d\n", z, l);
			free(q);
			free(t);
		}
		if(strcmp(p, arr[6]) == 0 || strcmp(p, arr[2]) == 0) {
			char *m = (char *)malloc(128);
			strcpy(m, p);
			free(p);
			char *q, *s, *t;
			q = (char *)malloc(128);
			s = (char *)malloc(128);
			p = (char *)malloc(128);
			if(strlen(m) == 9) {
				fscanf(f1, "%s%s%d%s\n", p, q, &n, s);
				t = mystrncpy(p, q, n);
			}
			else if(strlen(m) == 8) {
				fscanf(f1, "%s%s%s\n", p, q, s);
				t = mystrcpy(p, q);
			}
			if(strcmp(t, s) == 0)
				printf("%d.operation succeed\n", z);
			else
				printf("%d.operation failed because output is --> %s\n", z, t);
			free(q);
			free(s);
			free(m);
		}
		if(strcmp(p, arr[5]) == 0) {
			free(p);
			char *s, *q, *t;
			q = (char *)malloc(128);
			s = (char *)malloc(128);
			p = (char *)malloc(128);
			fscanf(f1, "%s%s%s\n", p, q, s);
			t = mystrpbrk(p, q);
			if(strcmp(t, s) == 0)
				printf("%d.operation succeed\n", z);
			else
				printf("%d.operation failed because output is --> %s\n", z, t);
			free(s);
			free(q);
		}
		if(strcmp(p, arr[4]) == 0) {
			free(p);
			char *s, *q, *t;
			q = (char *)malloc(128);
			s = (char *)malloc(128);
			p = (char *)malloc(128);
			fscanf(f1, "%s%s%s\n", p, q, s);
			t = mystrcat(p, q);
			if(strcmp(t, s) == 0)
				printf("%d.operation succeed\n", z);
			else
				printf("%d.operation failed because output is --> %s\n", z, t);
			free(s);
			free(q);
		}
		if(strcmp(p, arr[1]) == 0 || strcmp(p, arr[8]) == 0) {
			char *t = (char *)malloc(128);
			strcpy(t, p);
			free(p);
			char *q;
			q = (char *)malloc(128);
			p = (char *)malloc(128);
			if(strlen(t) == 8) {
				fscanf(f1, "%s%s%d\n", p, q, &n);
				l = mystrcmp(p, q);
			}
			else {
				fscanf(f1, "%s%s%d%d\n", p, q, &m, &n);
				l = mystrncmp(p, q, m);
			}
			if(n == l)
				printf("%d.operation succeed\n", z);
			else
				printf("%d.operation failed because output is --> %d\n", z, l);
			free(q);
		}
		if(strcmp(p, arr[0]) == 0) {
			free(p);
			p = (char *)malloc(128);
			fscanf(f1, "%s%d\n", p, &n);
			l = mystrlen(p);
			if(n == l)
			 	printf("%d.operation succeed\n", z);
			else
			 	printf("%d.operation failed because output is --> %d\n", z, l);
		}
		free(p);
		p = (char *)malloc(128);
	}
	fclose(f1);
	return 0;
}
