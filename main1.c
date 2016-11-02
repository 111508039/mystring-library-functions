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
#include<string.h>
#include<wchar.h>
#include"mywchar.h"
#include"locale.h"
#include<errno.h>
#include<stdlib.h> 

typedef struct funptr{
	int (*p[2])();
	wchar_t *(*q[17])();
	size_t (*r[5])();
}funptr;

const funptr fp = { { mywcscmp, mywcsncmp }, { mywcscat, mywcscpy, mywcsncpy, mywcsncat, mywcsrev, mywcspbrk, mywcstr, mywcschr, 
		mywcsreplace, miwcpcpy, mywmemset, mywmemmove, mywcmemfrob, mywcmemcpy, mywcmemchr, mywcsdup, mywcrchr }, { mywcslen, 
		mywcsnlen, mywcsoccurance, mywcsspn, mywcscspn} };

int hash(char *str) {
	int sum = 0;
	while(*str != '\0') 
		sum = sum + *str++;
	return sum;
}

int main() {
	FILE *f1;
	char *q;
	wchar_t c;
	wchar_t *s, *r, *t, *p, *u;
	int l, n, z, m, a;
	f1 = fopen("test1.txt", "r");
	if(f1 == NULL) {
		printf("file cannot be opened");
		return(errno);
	}
	q = (char *)malloc(128);
	p = (wchar_t *)malloc(sizeof(wchar_t)*128);
	while(!feof(f1)) {
		setlocale(LC_ALL, "");
		fscanf(f1, "%d%s", &z, q);
		a = hash(q);
		switch(a) {
			case 882:/* mywcslen */
				free(q);
				fscanf(f1, "%ls%d\n", p, &n);
				l = fp.r[0](p);
				if(n == l)
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mywcslen code <----\n\n\tfailure because string", z);  						printf(" ---->  %ls  <---- has length ==> [ %d ] \n\n", p, l);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				break;
				
			case 992:/* mywcsnlen */ 	
				free(q);
				fscanf(f1, "%ls%d%d\n", p, &m, &n);
				l = fp.r[1](p, m);
				if(n == l)
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mywcsnlen code <----\n\n\tfailure because string", z);       						printf(" ---->  %ls  <---- has length ==> [ %d ] \n\n", p, l);	
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				break;
				
			case 895:/* mywcscpy */
				free(q);
				s = (wchar_t *)malloc(sizeof(wchar_t)*128);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%ls\n", p, s, r);
				t = fp.q[1](p, s);
				if(wcscmp(t, r) == 0)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mywcscpy code <----\n\n\tfailure because copied string", z); 						printf(" is ===>  %ls  <===\n\n", t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(s);
				free(r);
				break;	
				
			case 875:/* mywcscat */
				free(q);
				s = (wchar_t *)malloc(sizeof(wchar_t)*128);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%ls\n", p, s, r);
				t = fp.q[0](p, s);
				if(wcscmp(t, r) == 0)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
				 	printf("%d.\t\t----> Testing mywcscat code <----\n\n\tfailure because concatenated", z); 						printf(" string is ===>  %ls  <===\n\n", t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(s);
				free(r);
				break;
				
			case 896:/* mywcsrev */	
				free(q);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls\n", p, r);
				t = fp.q[4](p);
				if(wcscmp(t, r) == 0)
				 	printf("%d.----> successful... <----\n\n", z);
				else { 
				 	printf("%d.\t\t----> Testing mywcsrev code <----\n\n\tfailure because reverse string", z); 						printf(" is ===>  %ls  <===\n\n", t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(r);
				break;
				
			case 1510:/* mywcsoccurance */	
				free(q);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%d\n", p, r, &n);
				l = fp.r[2](p, r);
				if(l == n)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
				 	printf("%d.\t\t----> Testing mywcsoccurance <----\n\n\tfailure because occurance", z);    						printf(" of --> %ls <-- in --> %ls <-- is ==> [ %d ] \n\n", r, p, l);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(r);
				break;
			
			case 994:/* mywcspbrk */	
				free(q);
				s = (wchar_t *)malloc(sizeof(wchar_t)*128);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%ls\n", p, s, r);
				t = fp.q[5](p, s);
				if(t != NULL) {
					if(wcscmp(t, r) == 0)
				 		printf("%d.----> successful... <----\n\n", z);
					else {
				 		printf("%d.\t\t----> Testing mywcspbrk code <----\n\n\tfailure because output string", z); 							printf(" is ===> %ls <===\n\n", t);
					}
				}
				else {
					printf("%d.\t\t----> Testing mywcspbrk code <----\n\n\tfailure because output string", z); 						printf(" is ===> %ls <===\n\n", t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(s);
				free(r);
				break;
				
			case 793:/* mywcstr */	
				free(q);
				s = (wchar_t *)malloc(sizeof(wchar_t)*128);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%ls\n", p, s, r);
				t = fp.q[6](p, s);
				if(t != NULL) {
					if(wcscmp(t, r) == 0)
				 		printf("%d.----> successful... <----\n\n", z);
					else {
						printf("%d.\t\t----> Testing mywcstr code <----\n\n\tfailure because", z); 							printf(" resultant string is ===> %ls <===\n\n", t);
					}
				}
				else {
					printf("%d.\t\t----> Testing mywcstr code <----\n\n\tfailure because", z); 						printf(" resultant string is ===> %ls <===\n\n", t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(s);
				free(r);
				break;	
				
			case 880:/* mywcschr */	
				free(q);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				s = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%ls\n", p, s, r);
				c = *s;
				t = fp.q[7](p, c);
				if(t != NULL) {
					if(wcscmp(t, r) == 0)
				 		printf("%d.----> successful... <----\n\n", z);
					else {
						printf("%d.\t\t----> Testing mywcschr code <----\n\n\tfailure because resultant string",z); 							printf(" is ===>  %ls  <===\n\n", t);
					}
				}
				else {	
					printf("%d.\t\t----> Testing mywcschr code <----\n\n\tfailure because resultant string",z); 						printf(" is ===>  %ls  <===\n\n", t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(r);
				break;	
				
			case 1295:/* mywcsreplace */	
				free(q);
				s = (wchar_t *)malloc(sizeof(wchar_t)*128);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				u = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%ls%ls\n", p, s, u, r);
				t = fp.q[8](p, s, u);
				if(wcscmp(t, r) == 0)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
				 	printf("%d.\t\t----> Testing mywcsreplace code <----\n\n\tfailure because resultant", z); 						printf(" string is ===>  %ls  <===\n\n", t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(s);
				free(u);
				free(r);
				break;
			
			case 1107:/* mywmemmove */
				free(q);
				s = (wchar_t *)malloc(sizeof(wchar_t)*128);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%d%ls\n", p, s, &n, r);
				t = fp.q[11](p, s, n);
				if(wcscmp(t, r) == 0)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mywmemmove code <----\n\n\tfailure because resultant", z); 					printf(" string is ===>  %ls  <===\n\n", t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(s);
				free(r);
				break;
				
			case 1005:/* mywcsncpy */
				free(q);
				s = (wchar_t *)malloc(sizeof(wchar_t)*128);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%d%ls\n", p, s, &n, r);
				t = fp.q[2](p, s, n);
				if(wcscmp(t, r) == 0)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mywcsncpy code <----\n\n\tfailure because copied string", z); 						printf(" is ===>  %ls  <===\n\n", t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(s);
				free(r);
				break;
				
			case 985:/* mywcsncat */
				free(q);
				s = (wchar_t *)malloc(sizeof(wchar_t)*128);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%d%ls\n", p, s, &n, r);
				t = fp.q[3](p, s, n);
				if(wcscmp(t, r) == 0)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
				 	printf("%d.\t\t----> Testing mywcsncat code <----\n\n\tfailure because concatenated", z); 						printf(" string is ===>  %ls  <===\n\n", t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(s);
				free(r);
				break;
				
			case 1192:/* mywcmemfrob */
				free(q);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%d%ls\n", p, &n, r);
				t = fp.q[12](p, n);
				if(wcscmp(t, r) == 0)
				 	printf("%d.----> successful... <----\n\n", z);
				else { 
				 	printf("%d.\t\t----> Testing mywcmemfrob code <----\n\n\tfailure because resultant", z); 						printf(" string is ===>  %ls  <===\n\n", t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(r);
				break;
				
			case 1000:/* mywmemset */
				free(q);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				s = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%d%ls\n", p, s, &n, r);
				c = *s;
				t = fp.q[10](p, c, n);
				if(wcscmp(t, r) == 0)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mywmemset code <----\n\n\tfailure because resultant", z); 						printf(" string is ===>  %ls  <===\n\n", t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(r);
				free(s);
				break;	
				
			case 883:/* mywcscmp */
				free(q);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%d\n", p, r, &n);
				l = fp.p[0](p, r);
				if(l == n)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
					if(l > 0) {
				 		printf("%d.\t\t----> Testing mywcscmp code <----\n\n\tfailure because", z);    							printf(" string --> %ls <-- is larger than string --> %ls <--\n\n", r, p);
					}
					if(l < 0) {					
						printf("%d.\t\t----> Testing mywcscmp code <----\n\n\tfailure because", z);    							printf(" string --> %ls <-- is smaller than string --> %ls <--\n\n", r, p);
					}
					if(l == 0) {
						printf("%d.\t\t----> Testing mywcscmp code <----\n\n\tfailure because", z);    							printf(" the string --> %ls <-- and string--> %ls <-- are same\n\n", r, p);
					}
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(r);
				break;
				
			case 993:/* mywcsncmp */
				free(q);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%d%d\n", p, r, &m, &n);
				l = fp.p[1](p, r, m);
				if(l == n)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
					if(l > 0) {
				 		printf("%d.\t\t----> Testing mywcsncmp code <----\n\n\tfailure because", z);    						printf(" string --> %ls <-- is larger than string --> %ls <--\n\n", r, p);
					}
					if(l < 0) {					
						printf("%d.\t\t----> Testing mywcsncmp code <----\n\n\tfailure because", z);    						printf(" string --> %ls <-- is smaller than string --> %ls <--\n\n", r, p);
					}
					if(l == 0) {
						printf("%d.\t\t----> Testing mywcsncmp code <----\n\n\tfailure because", z);    						printf(" the string --> %ls <-- and string--> %ls <-- are same\n\n", r, p);
					}
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(r);
				break;
				
			case 900:/* mywcsspn */
				free(q);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%d\n", p, r, &n);
				l = fp.r[3](p, r);
				if(n == l)
				 	printf("%d.----> successful... <----\n\n", z);
				else { 
				 	printf("%d.\t\t----> Testing mywcsspn code <----\n\n\tfailure because output", z); 						printf(" is ===> [ %d ] <===\n\n", l);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(r);
				break;
	
			case 999:/* mywcscspn */
				free(q);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%d\n", p, r, &n);
				l = fp.r[4](p, r);
				if(n == l)
				 	printf("%d.----> successful... <----\n\n", z);
				else { 
				 	printf("%d.\t\t----> Testing mywcscspn code <----\n\n\tfailure because output", z); 						printf(" is ===> [ %d ] <===\n\n", l);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(r);
				break;
				
			case 876:/* miwcpcpy */
				free(q);
				s = (wchar_t *)malloc(sizeof(wchar_t)*128);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%ls\n", p, s, r);
				t = fp.q[9](p, s);
				if(wcscmp(t, r) == 0)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing miwcpcpy code <----\n\n\tfailure because resultant string", z); 						printf(" is ===> %ls <===\n\n", t);
				}	
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(s);
				free(r);
				break;	
				
			case 1099:/* mywcmemcpy */
				free(q);
				s = (wchar_t *)malloc(sizeof(wchar_t)*128);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%d%ls\n", p, s, &n, r);
				t = fp.q[13](p, s, n);
				if(wcscmp(t, r) == 0)
				 	printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mywcmemcpy code <----\n\n\tfailure because copied string", z); 						printf(" upto %d bytes is ===>  %ls  <===\n\n", n, t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(s);
				free(r);
				break;
			
			case 1084:/* mywcmemchr */	
				free(q);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				s = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%d%ls\n", p, s, &n, r);
				c = *s;
				t = fp.q[14](p, c, n);
				if(t != NULL) {
					if(wcscmp(t, r) == 0)
				 		printf("%d.----> successful... <----\n\n", z);
					else {
						printf("%d.\t\t----> Testing mywcmemchr code <----\n\n\tfailure because resultant",z); 							printf(" string is ===>  %ls  <===\n\n", t);
					}
				}
				else {	
					printf("%d.\t\t----> Testing mywcmemchr code <----\n\n\tfailure because resultant",z); 						printf(" string is ===>  %ls  <===\n\n", t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(r);
				break;
				
			case 892:/* mywcsdup */
				free(q);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls\n", p, r);
				t = fp.q[15](p);
				if(wcscmp(t, r) == 0)
					printf("%d.----> successful... <----\n\n", z);
				else {
					printf("%d.\t\t----> Testing mywcsdup code <----\n\n\tfailure because", z);  						printf(" duplicate string is ===> %ls <=== \n\n", t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				break;
			
			case 879:/* mywcrchr */	
				free(q);
				r = (wchar_t *)malloc(sizeof(wchar_t)*128);
				s = (wchar_t *)malloc(sizeof(wchar_t)*128);
				fscanf(f1, "%ls%ls%ls\n", p, s, r);
				c = *s;
				t = fp.q[16](p, c);
				if(t != NULL) {
					if(wcscmp(t, r) == 0)
				 		printf("%d.----> successful... <----\n\n", z);
					else {
						printf("%d.\t\t----> Testing mywcrchr code <----\n\n\tfailure because resultant string",z); 							printf(" is ===>  %ls  <===\n\n", t);
					}
				}
				else {	
					printf("%d.\t\t----> Testing mywcschr code <----\n\n\tfailure because resultant string",z); 						printf(" is ===>  %ls  <===\n\n", t);
				}
				printf("------------------------------------------------");                               					printf("------------------------------------------------\n");
				free(r);
				break;	

		}
		free(p);
		p = (wchar_t *)malloc(sizeof(wchar_t)*128);
		q = (char *)malloc(128);
	}
	fclose(f1);
	return 0;
}

