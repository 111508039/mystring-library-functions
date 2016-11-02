/*****************************************************************************
 *Copyright (c) maheshkumar kendre <kendremu15.it@coep.ac.in>
 *		All rights reserved. 
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *
 ****************************************************************************/

#include<stdio.h>
#include"mystring.h"
#include<string.h>
#include<errno.h>
#include<stdlib.h>

typedef struct funcptr {
	int (*p[9])();
	char *(*q[17])();
	void *(*r[8])();
	size_t (*s[4])();
}funptr;

const funptr fp = { { mystrcmp, mystrcasecmp, myffs, myffsl, myffsll, mystrncasecmp, mystrncmp, mymemcmp, mybcmp }, 
		{ mystrcpy, mystrncpy, mystrcat, mystrrev, mystrchr, mystrrchr, mystrreplacce, mystrgpbrk, mystrncat, mystrstr,
		 mystpcpy, mystrdup, mystrndup, myindex, myrindex, mystrdupa, mystrndupa }, { mymemmem, mymemset, mymemmove, mymemfrob, 
		 mimemcpy, mymemchr, mymempcpy, mymemccpy }, { mystrlen, mystroccurance, mystrspn, mystrcspn} };
		 
int hash(char *str) {
	int sum = 0;
	while(*str != '\0') 
		sum = sum + *str++;
	return sum;
}

int main() {
	char *p, *t, *q, *u, *s, *r;
	int n, l, m, z, a;
	char c;
	FILE *f1;
	f1 = fopen("test.txt", "r");
	if(f1 == NULL) {
		printf("file cannot be opened");
		return (errno);	
	}
	p = (char *)malloc(128);
	while(!feof(f1)) {
		fscanf(f1, "%d%s", &z, p);
		a = hash(p);
		switch(a) {
			case 892:/* mystrchr */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				r = (char *)malloc(128);
				fscanf(f1, "%s%s%s\n", p, r, q);
				c = *r;
				t = fp.q[4](p, c);
				if(t != NULL) {
					if(strcmp(t, q) == 0) 
						printf("%d.----> successful... <----\n\n", z);
				
					else {
						printf("%d.\t\t----> Testing mystrchr code <----\n\n\tfailure because", z);          							printf(" resultant string is ===> %s <===\n\n", t);
					}
				}
				else {
					printf("%d.\t\t----> Testing mystrchr code <----\n\n\tfailure because", z);          						printf(" resultant string is ===> %s <===\n\n", t);
				}
				free(q);
				free(r);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
			
			case 1006:/* mystrrchr */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				r = (char *)malloc(128);
				fscanf(f1, "%s%s%s\n", p, r, q);
				c = *r;
				t = fp.q[5](p, c);
				if(t != NULL) {
					if(strcmp(t, q) == 0) 
						printf("%d.----> successful... <----\n\n", z);
				
					else {
						printf("%d.\t\t----> Testing mystrchr code <----\n\n\tfailure because", z);          							printf(" resultant string is ===> %s <===\n\n", t);
					}
				}
				else {
					printf("%d.\t\t----> Testing mystrchr code <----\n\n\tfailure because", z);          						printf(" resultant string is ===> %s <===\n\n", t);
				}
				free(q);
				free(r);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
		
			case 908:/* mystrrev */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s\n", p, q);
				u = (char *)malloc(128);
				strcpy(u, p);
				t = fp.q[3](p);
				if(strcmp(t, q) == 0) 
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mystrrev code <----\n\n\tfailure beacuse", z);                 						printf(" reverse of string ===> %s <=== is ===> %s <===\n\n", u, t);
				}			
				free(q);
				free(u);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
				
			case 1522:/* mystroccurance */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%d\n", p, q, &m);
				l = fp.s[1](p, q);
				if(l == m)
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mystroccurance code <----\n\n\tfailure because", z);     						printf(" occurance of string ==> %s <== in string ==> %s <== is ===> [ %d ]\n\n", q, p, l);
				}
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
				
			case 920:/* mystrstr */
				free(p);
				q = (char *)malloc(128);
				s = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%s\n", p, q, s);
				t = fp.q[9](p, q);
				if(t != NULL) {
					if(strcmp(t, s) == 0)
						printf("%d.---->successful... <----\n\n", z);
					else {
						printf("%d.\t\t----> Testing mystrstr code <----\n\n\tfailure because", z);            							printf(" resultant string is ===> %s <====\n\n", t);
					}
				}
				else {
					printf("%d.\t\t----> Testing mystrstr code <----\n\n\tfailure because", z);            						printf(" resultant string is ===> %s <====\n\n", t);
				}
				free(q);
				free(s);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
			
			case 1417:/* mystrncasecmp */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%d%d\n", p, q, &n, &m);
				l = fp.p[5](p, q, n);
				if(m == l)
					printf("%d.----> successful... <----\n\n", z);
				else {
					if(l > 0) {	
						printf("%d.\t\t----> Testing mystrncasecmp code <----\n\n\tfailure because", z);       							printf(" ==> %s <== is larger than ==> %s <== as output is ===> [ %d ]\n\n", p, q, l);
					}
					if(l < 0) {					
						printf("%d.\t\t----> Testing mystrncasecmp code <----\n\n\tfailure as",z);           							printf(" ==> %s <== is smaller than ==> %s <== as output is ===> [ %d ]\n\n", p, q, l);
					}
					if(l == 0) {
						printf("%d.\t\t----> Testing mystrncasecmp code <----\n\n\tfailure as",z);           							printf(" ==> %s <== is same as ==> %s <== as output is ===> [ %d ]\n\n", p, q, l);
					}
				}
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
				
			case 1307:/* mystrcasecmp */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%d\n", p, q, &m);
				l = fp.p[1](p, q);
				if(m == l)
					printf("%d.----> successful... <----\n\n", z);
				else {
					if(l > 0) {
						printf("%d.\t\t----> Testing mystrcasesmp code <----\n\n\tfailure because", z);        							printf(" ==> %s <== is larger than ==> %s <== as output is ===> [ %d ]\n\n", p, q, l);
					}
					if(l < 0) {					
						printf("%d.\t\t----> Testing mystrcasecmp code <----\n\n\tfailure as",z);           							printf(" ==> %s <== is smaller than ==> %s <== as output is ===> [ %d ]\n\n", p, q, l);
					}
					if(l == 0) {
						printf("%d.\t\t----> Testing mystrcasecmp code <----\n\n\tfailure as",z);           							printf(" ==> %s <== is same as ==> %s <== as output is ===> [ %d ]\n\n", p, q, l);
					}
				}
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;

			case 1014:/* mystrndup */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%d%s\n", p, &n, q);
				t = fp.q[12](p, n);
				if(strcmp(t, q) == 0) 
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mystrndup code <----\n\n\tfailure because", z);          						printf(" duplicate of ===> %s <=== upto %d byte is ===> %s <===\n\n", p, n, t);
				}
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
				
			case 904:/* mystrdup */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s\n", p, q);
				t = fp.q[11](p);
				if(strcmp(t, q) == 0) 
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mystrdup code <----\n\n\tfailure because", z);            						printf(" duplicate string is ===> %s <===\n\n", t);
				}
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
					
			case 1001:/* mystrdupa */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s\n", p, q);
				t = fp.q[15](p);
				if(strcmp(t, q) == 0) 
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mystrdupa code <----\n\n\tfailure because", z);            						printf(" duplicate string is ===> %s <===\n\n", t);
				}
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;

			case 1111:/* mystrndupa */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%d%s\n", p, &n, q);
				t = fp.q[16](p, n);
				if(strcmp(t, q) == 0) 
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mystrndupa code <----\n\n\tfailure because", z);          						printf(" duplicate of ===> %s <=== upto %d byte is ===> %s <===\n\n", p, n, t);
				}
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;

			case 1406:/* mystrreplace */
				free(p);
				r = (char *)malloc(128);
				q = (char *)malloc(128);
				s = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%s%s\n", p, q, r, s);
				t = fp.q[6](p, q, r);
				if(strcmp(t, s) == 0)
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mystrreplacce code <----\n\n\tfailure because", z);       						printf(" resultant string is ===> %s <===\n\n", t);
				}
				free(q);
				free(s);
				free(r);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
				
			case 974:/* mymemfrob */ 
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%d%s\n", p, &n, q);
				t = fp.r[3](p, n);
				if(strcmp(t, q) == 0)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
				 	printf("%d.\t\t----> Testing mymemfrob code <----\n\n\tfailure because", z);          						printf(" resultant string is ===> %s <===\n\n", t);
				}
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
				
			case 868:/* mymemmem */
				free(p);
				q = (char *)malloc(128);
				s = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%d%s%d%s\n", p, &l, q, &m, s);
				t = fp.r[0](p, l, q, m);
				if(t != NULL) {
					if(strcmp(t, s) == 0)
						printf("%d.----> successful... <----\n\n", z);
					else {
						printf("%d.\t\t----> Testing mymemmem code <----\n\n\tfailure because", z);          							printf(" resultant string is ===> %s <===\n\n", t);
					}
					
				}
				else {
					printf("%d.\t\t----> Testing mymemmem code <----\n\n\tfailure because", z);          						printf(" resultant string is ===> %s <===\n\n", t);
				}
				free(q);
				free(s);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
				
			case 905:/* mystpcpy */
				free(p);
				q = (char *)malloc(128);
				s = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%s\n", p, q, s);
				t = fp.q[10](p, q);
				if(strcmp(t, s) == 0)
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mystpcpy code <----\n\n\tfailure because", z);            						printf(" resultant string is ===> %s <===\n\n", t);
				}
				free(q);
				free(s);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
			
			case 912:/* mystrspn */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%d\n", p, q, &n);
				l = fp.s[2](p, q);
				if(n == l)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
				 	printf("%d.\t\t----> Testing mystrspn code <----\n\n\tfailure because", z);           						printf(" output is ===> [ %d ]\n\n", l);
				}
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
				
			case 1011:/* mystrcspn */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%d\n", p, q, &n);
				l = fp.s[3](p, q);
				if(n == l)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
				 	printf("%d.\t\t----> Testing mystrcspn code <----\n\n\tfailure because", z);          						printf(" output is ===> [ %d ]\n\n", l);
				}
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
				
			case 1017:/* mystrncpy */		
				free(p);
				q = (char *)malloc(128);
				s = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%d%s\n", p, q, &n, s);
				t = fp.q[1](p, q, n);
				if(strcmp(t, s) == 0)
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mystrncmp code <----\n\n\tfailure because", z);          						printf(" copied string upto %d byte is ===> %s <===\n\n", n, t);
				}
				free(q);
				free(s);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
								
			case 907:/* mystrcpy */
				free(p);
				q = (char *)malloc(128);
				s = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%s\n", p, q, s);
				t = fp.q[0](p, q);
				if(strcmp(t, s) == 0)
					printf("%d.----> successful... <----\n\n", z);	
				else {
					printf("%d.\t\t----> Testing mystrcpy code <----\n\n\tfailure because", z);             					printf(" copied string is ===> %s <===\n\n", t);
				}	
				free(q);
				free(s);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
					
			case 1109:/* mystrgpbrk */
				free(p);
				q = (char *)malloc(128);
				s = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%s\n", p, q, s);
				t = fp.q[7](p, q);
				if(t != NULL) {
					if(strcmp(t, s) == 0)
						printf("%d.----> successful... <----\n\n", z);
					else {
						printf("%d.\t\t----> Testing mystrpbrk code <----\n\n\tfailure because", z);          							printf(" resultant string is ===> %s <===\n\n", t);
					}
				}
				else {
					printf("%d.\t\t----> Testing mystrpbrk code <----\n\n\tfailure because", z);          						printf(" resultant string is ===> %s <===\n\n", t);
				}
				free(s);
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
				
			case 887:/* mystrcat */	
				free(p);
				p = (char *)malloc(128);
				q = (char *)malloc(128);
				s = (char *)malloc(128);
				fscanf(f1, "%s%s%s\n", p, q, s);
				t = fp.q[2](p, q);
				if(strcmp(t, s) == 0)
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mystrcat code <----\n\n\tfailure because", z);            						printf(" concatenated string is ===> %s <===\n\n", t);
				}	
				free(s);
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
			
			case 997:/* mystrncat */	
				free(p);
				p = (char *)malloc(128);
				q = (char *)malloc(128);
				s = (char *)malloc(128);
				fscanf(f1, "%s%s%d%s\n", p, q, &n, s);
				t = fp.q[8](p, q, n);
				if(strcmp(t, s) == 0)
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mystrncat code <----\n\n\tfailure because", z);            						printf(" concatenated string upto %d byte is ===> %s <===\n\n", n, t);
				}	
				free(s);
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
					
			case 895:/* mystrcmp */		
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%d\n", p, q, &n);
				l = fp.p[0](p, q);
				if(n == l)
					printf("%d.----> successful... <----\n\n", z);
				else {
					if(l > 0) {
						printf("%d.\t\t----> Testing mystrcmp code <----\n\n\tfailure as",z);           						printf(" ==> %s <== is larger than ==> %s <== as output is ===> [ %d ]\n\n", p, q, l);
					}
					if(l < 0) {					
						printf("%d.\t\t----> Testing mystrcmp code <----\n\n\tfailure as",z);           						printf(" ==> %s <== is smaller than ==> %s <== as output is ===> [ %d ]\n\n", p ,q, l);
					}
					if(l == 0) {
						printf("%d.\t\t----> Testing mystrncmp code <----\n\n\tfailure as",z);           							printf(" ==> %s <== is same as ==> %s <== as output is ===> [ %d ]\n\n", p, q, l);
					}
				}
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
				
			case 1005:/* mystrncmp */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%d%d\n", p, q, &m, &n);
				l = fp.p[6](p, q, m);
				if(n == l)
					printf("%d.----> successful... <----\n\n", z);
				else { 
					if(l > 0) {
						printf("%d.\t\t---> Testing mystrncmp code <---\n\n\tfailure as ==> %s <==",z,p);           							printf(" is larger than ==> %s <== upto %d bytes as output is ===> [ %d ]\n\n", q, m, l);
					}
					if(l < 0) {					
						printf("%d.\t\t---> Testing mystrncmp code <---\n\n\tfailure as ==> %s <==",z,p);           							printf(" is smaller than ==> %s <== upto %d bytes as output is ===> [ %d ]\n\n", q, m, l);
					}
					if(l == 0) {
						printf("%d.\t\t---> Testing mystrncmp code <---\n\n\tfailure as ==> %s <==",z,p);           							printf("  is same as ==> %s <== upto %d bytes as output is ===> [ %d ]\n\n", q, m, l);
					}
				}
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
					
			case 894:/* mystrlen */				
				free(p);
				p = (char *)malloc(128);
				fscanf(f1, "%s%d\n", p, &n);
				l = fp.s[0](p);
				if(n == l)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
				 	printf("%d.\t\t----> Testing mystrlen code <----\n\n\tfailure because", z);                 					        printf(" ==> %s <== has length ===> [ %d ]\n\n", p ,l);
				}
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
				
			case 988:/* mymemmove */
				free(p);
				r = (char *)malloc(128);
				q = (char *)malloc(128);
				//s = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%d%s\n", p, q, &n, r);
				t = fp.r[2](p, q, n);
				if(strcmp(t, r) == 0)
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mymemmove code <----\n\n\tfailure because", z);       						printf(" resultant string is ===> %s <===\n\n", t);
				}
				free(q);
				//free(s);
				free(r);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
			
			case 881:/* mymemset */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				r = (char *)malloc(128);
				fscanf(f1, "%s%s%d%s\n", p, r, &n, q);
				c = *r;
				t = fp.r[1](p, c, n);
				if(strcmp(t, q) == 0) 
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mymemset code <----\n\n\tfailure because", z);          						printf(" resultant string is ===> %s <===\n\n", t);
				}
				free(q);
				free(r);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
				
			case 869:/* mymemcmp */		
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%d%d\n", p, q, &m, &n);
				l = fp.p[7](p, q, m);
				if(n == l)
					printf("%d.----> successful... <----\n\n", z);
				else {
					if(l > 0) {
						printf("%d.\t\t---> Testing mymemcmp code <---\n\n\tfailure as ==> %s <==",z,p);           							printf(" is larger than ==> %s <== upto %d bytes as output is ===> [ %d ]\n\n", q, m, l);
					}
					if(l == 0) {
						printf("%d.\t\t---> Testing mymemcmp code <---\n\n\tfailure as ==> %s <==",z,p);           							printf("  is same as ==> %s <== upto %d bytes as output is ===> [ %d ]\n\n", q, m, l);
					}
					if(l < 0) {					
						printf("%d.\t\t---> Testing mymemcmp code <---\n\n\tfailure as ==> %s <==",z,p);           							printf(" is smaller than ==> %s <== upto %d bytes as output is ===> [ %d ]\n\n", q, m, l);
					}
				}
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
			
			case 866:/* mymemchr */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				r = (char *)malloc(128);
				fscanf(f1, "%s%s%d%s\n", p, r, &n, q);
				c = *r;
				t = fp.r[5](p, c, n);
				if(t != NULL) {
					if(strcmp(t, q) == 0) 
						printf("%d.----> successful... <----\n\n", z);
				
					else {
						printf("%d.\t\t----> Testing mymemchr code <----\n\n\tfailure because", z);          							printf(" resultant string is ===> %s <===\n\n", t);
					}
				}
				else {
					printf("%d.\t\t----> Testing mymemchr code <----\n\n\tfailure because", z);          						printf(" resultant string is ===> %s <===\n\n", t);
				}
				free(q);
				free(r);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
			case 766:/* myindex*/
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				r = (char *)malloc(128);
				fscanf(f1, "%s%s%s\n", p, r, q);
				c = *r;
				t = fp.q[13](p, c);
				if(t != NULL) {
					if(strcmp(t, q) == 0) 
						printf("%d.----> successful... <----\n\n", z);
				
					else {
						printf("%d.\t\t----> Testing myindex code <----\n\n\tfailure because", z);          							printf(" resultant string is ===> %s <===\n\n", t);
					}
				}
				else {
					printf("%d.\t\t----> Testing myindex code <----\n\n\tfailure because", z);          						printf(" resultant string is ===> %s <===\n\n", t);
				}
				free(q);
				free(r);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
		
			case 880:/* myrindex*/
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				r = (char *)malloc(128);
				fscanf(f1, "%s%s%s\n", p, r, q);
				c = *r;
				t = fp.q[14](p, c);
				if(t != NULL) {
					if(strcmp(t, q) == 0) 
						printf("%d.----> successful... <----\n\n", z);
				
					else {
						printf("%d.\t\t----> Testing myrindex code <----\n\n\tfailure because", z);          							printf(" resultant string is ===> %s <===\n\n", t);
					}
				}
				else {
					printf("%d.\t\t----> Testing myrindex code <----\n\n\tfailure because", z);          						printf(" resultant string is ===> %s <===\n\n", t);
				}
				free(q);
				free(r);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
				
			case 549:/* myffs */				
				free(p);
				p = (char *)malloc(128);
				fscanf(f1, "%d%d\n", &m, &n);
				l = fp.p[2](m);
				if(n == l)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
				 	printf("%d.\t\t----> Testing myffs code <----\n\n\tfailure because position", z);                 						printf(" of first least significant bit set is ===> [ %d ]\n\n", l);
				}
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
			
			case 657:/* myffsl */				
				free(p);
				long int y;
				p = (char *)malloc(128);
				fscanf(f1, "%ld%d\n", &y, &n);
				l = fp.p[3](y);
				if(n == l)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
				 	printf("%d.\t\t----> Testing myffsl code <----\n\n\tfailure because position", z);                 					        printf(" of first least significant bit set is ===> [ %d ]\n\n", l);
				}
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
			
			case 765:/* myffsll */				
				free(p);
				long long int b;
				p = (char *)malloc(128);
				fscanf(f1, "%lld%d\n", &b, &n);
				l = fp.p[4](b);
				if(n == l)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
				 	printf("%d.\t\t----> Testing myffsll code <----\n\n\tfailure because position", z);                 					        printf(" of first least significant bit set is ===> [ %d ]\n\n", l);
				}
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
				
			case 865:/* mimemcpy */		
				free(p);
				q = (char *)malloc(128);
				s = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%d%s\n", p, q, &n, s);
				t = fp.r[4](p, q, n);
				if(strcmp(t, s) == 0)
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mimemcpy code <----\n\n\tfailure because", z);          						printf(" copied string upto %d bytes is ===> %s <===\n\n", n, t);
				}
				free(q);
				free(s);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
			
			case 993:/* mymempcpy */		
				free(p);
				q = (char *)malloc(128);
				s = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%d%s\n", p, q, &n, s);
				t = fp.r[6](p, q, n);
				if(t == NULL) {
					if(strcmp(t, s) == 0)
						printf("%d.----> successful... <----\n\n", z);
					else {
						printf("%d.\t\t----> Testing mymempcpy code <----\n\n\tfailure because", z);          							printf(" copied string is ===> %s <===\n\n", t);
					}
				}
				else {
					printf("%d.\t\t----> Testing mymempcpy code <----\n\n\tfailure because", z);          						printf(" copied string is ===> %s <===\n\n", t);
				}
				free(q);
				free(s);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
			
			case 980:/* mymemccpy */		
				free(p);
				q = (char *)malloc(128);
				s = (char *)malloc(128);
				p = (char *)malloc(128);
				r = (char *)malloc(128);
				fscanf(f1, "%s%s%s%d%s\n", p, q, r, &n, s);
				c = *r;
				t = fp.r[7](p, q, c, n);
				if(t != NULL) {
					if(strcmp(t, s) == 0)
						printf("%d.----> successful... <----\n\n", z);
					else {
						printf("%d.\t\t----> Testing mymemccpy code <----\n\n\tfailure because", z);          							printf(" copied string is ===> %s <===\n\n", t);
					}
				}
				else {
					printf("%d.\t\t----> Testing mymemccpy code <----\n\n\tfailure because", z);          						printf(" copied string is ===> %s <===\n\n", t);
				}
				free(q);
				free(s);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;
			
			case 648:/* mybcmp */
				free(p);
				q = (char *)malloc(128);
				p = (char *)malloc(128);
				fscanf(f1, "%s%s%d%d\n", p, q, &m, &n);
				l = fp.p[8](p, q, m);
				if(n == l)
					printf("%d.----> successful... <----\n\n", z);
				else { 
					if(l > 0) {
						printf("%d.\t\t----> Testing mybcmp code <----\n\n\tfailure as",z);           							printf(" ==> %s <== is larger than ==> %s <== as output is ===> [ %d ]\n\n", p, q, l);
					}
					if(l < 0) {					
						printf("%d.\t\t----> Testing mybcmp code <----\n\n\tfailure as",z);           							printf(" ==> %s <== is smaller than ==> %s <== as output is ===> [ %d ]\n\n", p, q, l);
					}
					if(l == 0) {
						printf("%d.\t\t----> Testing mybcmp code <----\n\n\tfailure as",z);           							printf(" ==> %s <== is same as ==> %s <== as output is ===> [ %d ]\n\n", p, q, l);
					}
				}
				free(q);
				printf("---------------------------------------------------");                               					printf("--------------------------------------------------\n");
				break;

		}
		free(p);
		p = (char *)malloc(128);
	}
	fclose(f1);
	return 0;
}
