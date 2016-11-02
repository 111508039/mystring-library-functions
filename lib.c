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

#include"mystring.h"
#include<stdlib.h>

size_t mystrlen (const char *p) {
	int count = 0;
	while(*p != '\0'){
		p++;
		count++;
	}
	return (count);
}

/* mystrcat function appends string pointed by 'q' to the string pointed by 'p' and returns
*pointer to the resulting string pointed by 'p'*/

char *mystrcat (char *p, char *q) {
        char *t = p;
        p = p + mystrlen(p);
        while(*q != '\0') {                                                                     
		*p = *q;
		p++;
		q++;             
        }               
	*p = '\0';                      
        return(t);              
}

/* mystrcpy function copies memory area pointed by 'q' to the memory area pointed by 'p'
* including terminating null '\0' byte and returns pointer to memory area pointed by 'p'*/

char *mystrcpy (char *p ,const char *q) {
	char *m = p;	
	while(*q != '\0') {
		*p = *q;
		p++;
		q++;
	}
	*p = '\0'; 
	return (m);
}

/* mystrncpy function copies at most n bytes from the memory area pointed by 'q' to the memory area
* pointed by 'p' including terminating null '\0' byte and returns pointer to memory area pointed by 'p'*/

char *mystrncpy (char *p ,const char *q, size_t n) {
	const char *l = q;
	char *m = p;
	l = l + n;	
	while((l - q) != 0) {
		*p = *q;
		p++;
		q++;
	}
	*p = '\0'; 
	return (m);
}

/* mystrrev function reverses the string pointed by 'p' and returns pointer to the reversed string*/

char *mystrrev (char *p) {
	int t, i, j;
	t = mystrlen(p) / 2;
	for(i = 0;i < t;i++){
		j = *(p + i);
		*(p + i) = *(p + (mystrlen(p) - i - 1));
		*(p + (mystrlen(p) - i - 1)) = j;
	}
	return (p);
}

/* mystrreplacce function search for the all occurances of substring pointed by 's' in the
* string pointed by 't' and replace all of them by string pointed by 'm'and this function 
* returns pointer to the resultant string obtained after replacing all substrings */

char *mystrreplacce (char *t, char *s, char *m) {
	int k, i, j, z, x, y;
	char *p, *q;
	p = t;
	q = s;
	while(*p != '\0') {
		while(*p && *q) {
			if(*p == *q) {
				p++;
				q++;
			}
			else if(q == s)
				p++;
			else
				q = s;
			if(*q == '\0') {
				k = ((p - (q - s)) - t);
		
				if(mystrlen(s) == mystrlen(m)) {
					for(i = k, j = 0;i < (k + mystrlen(s));i++, j++) {
						*(t + i) = *(m + j);
					}
				}
				
				else if(mystrlen(m) > mystrlen(s)) {
					y = mystrlen(m) - mystrlen(s);
					z = mystrlen(t);
        				p = p + y;
					for(x = 0;x < (mystrlen(t) - (k + mystrlen(s))) + 1;x++) {
						t[z + y]= t[z];
						z = z - 1;
					}
					for(i = k, j = 0;i < (k + mystrlen(m));i++, j++) {
						*(t + i) = *(m + j);
					}
			
				}
 				
				else if(mystrlen(s) > mystrlen(m)) {
         				y = mystrlen(s) - mystrlen(m);
         				z = k + mystrlen(s);
         				p = p - y;
 					for(x = 0;x < (mystrlen(t) - (k + mystrlen(s))) + 1;x++) {
          					t[z - y] = t[z];
          					z = z + 1;
 					}
					for(i = k, j = 0;i < (k + mystrlen(m));i++, j++) {
        					*(t + i) = *(m + j);            
					}
          			} 
			}       
		} q = s;
	}
	return t;
}

/* mystroccurance function returns the occurance of substring pointed by 's' in the
*string pointed by 't' or zero if no substring match is found*/

size_t mystroccurance (char *t, char *s) {
	int c = 0;
	char *p, *q;
	p = t;
	q = s;
	while(*p != '\0') {
		while(*p && *q) {
			if(*p == *q) {
				p++;
				q++;
			}
			else if(q == s)
				p++;
			else
				q = s;
			if(*q == '\0') {
      				c++;
			}
		} q = s;
	}
	return c;
}

/*if the second argument i.e character is matched with any of first
*character in the string pointed by 'p' mystrchr function will return pointer 
*to that character otherwise if no match found will return null pointer*/

char *mystrchr (const char *p, int c) {
	int k;
	if(*p == '\0') {
		k = *p;
		if(k == c)
			return (char *)p;
	}
	while(*p != '\0'){
		k = *p;
		if(k == c)
			return (char *)p;
		else
			p++;   
	}	
	return (NULL);
}

/* if character from the string pointed by 'q' is matched with any of the 
*character from the string pointed by 'p' then mystrgpbrk function will return pointer 
*to the first character matched otherwise if no match found will return null pointer*/

char *mystrgpbrk (const char *p, const char *q) {
	const char *s;
	s = q;
	while(*p != '\0') {
		while(*q != '\0') {
			if(*p == *q)
				return (char *)p;
			else
				q++;
		} 
		q = s;	
		p++;
	}
	return (NULL);
}

/* mystrcmp function compares the strings pointed by 't' and pointed by 's' and this funstion returns an integer  
*less than, equal to, or greater than zero if t  is found to be less than, same, or greater than s  respectively */

int mystrcmp (const char *t, const char *s){
	int i, j;
	const char *p = t;
	const char *q = s;
	while(*p != '\0' || *q != '\0'){
		if(*p == *q) {
			p++;
			q++;
		}
		else {
			i = *p;
			j = *q;
			return(i - j);
		}
		
	}
		i = *p;
		j = *q;
	return (i - j);
}

/*mystrspn function returns the no of bytes in the initial segment of the string
*pointed by 'p' which are also present in string pointed by 'q'*/	

size_t mystrspn (const char *p, const char *q) {
	const char *t = q;
	int count = 0, flag;
	while(*p != '\0') {
		flag = 0;
		while(*q != '\0') {
			if(*p == *q) {
				count++;
				flag++;
				break;
			}
			q++;
		}		
		p++;
		q = t;
		if(flag == 0)
			return count;
		
	}
	if(flag == 1)
		return count;
	return 0;		
}

/*mystrcspn function returns the no of bytes in the initial segment of the string
*pointed by 'p' which are not present in string pointed by 'q'*/	

size_t mystrcspn (const char *p, const char *q) {
	int count = 0, flag;	
	const char *t = q;
	while(*p != '\0') {
		flag = 0;
		while(*q != '\0') {
			if(*p != *q) 
				flag++;
			q++;
		}
		if(flag == (q - t)) 	
			count++;
		p++;
		if(flag < (q - t))
			return count;
		q = t;
	}
		if(flag == (q - t) || (q - t) == 0)
			return count;
	return 0;
}

/* if character c is matched with any of the character in the string pointed by 'p' then mystrrchr function
* will return pointer to last character matched otherwise if no match found will return null pointer*/ 

char *mystrrchr (const char *p, int c) {
	int k, count = 0;
	const char *q;
	while(*p != '\0') {
		k = *p;
		if(k == c){
			q = p;
			count++;
		}
			p++;
	}
	if(count == 0 && *p != '\0')
		return NULL;    	
	if(*p == '\0') {
		k = *p;
		if(k == c)
			return (char *)p;
		else
			return (char *)q;
	}	
	return (NULL);
}

/* mystrncat function works similar to mystrcat but it just appends at most n bytes of the
* string pointed by 'q' to the string pointed by 'p' */ 

char *mystrncat (char *p, char *q, size_t n) {
	int i, j;
	char *t;
	t = p;
	for(j = 0, i = mystrlen(p);j < n;i++, j++){
		*(p + i) = *(q + j);
	}
	p[i] = '\0';
	return t;
}
 
/* mymemset function will fill the first n bytes by the character c
*into the memory area pointed by the pointer 's'*/

void *mymemset (void *s, int c, size_t n) {
	int i, t;
	char k;
	char *p = s;
	k = c;
	t = c;
	if(n > mystrlen(p))
		return NULL;
	if(t >= 48 && t <= 57){
		for(i = 0;i < n;i++)
			*(p + i) = c;
	}	
	else{
		for(i = 0;i < n;i++)
			*(p + i) = k;
	}
	return (void *)p;
}

/* mimemcpy function copies n bytes from memory area pointed by 't' to memory area pointed by 's' */

void *mimemcpy (void *s, const void *t, size_t n) {
	char *p = s;
	const char *q = t;
	while(n--) {
		*p = *q;
		p++;
		q++;
	}
	return s;
}

/* mymempcpy function is nearly similar to mimemcpy it copies n byte from memory area pointed by 't'
*to memory area pointed by 's' but it returns pointe to the byte following the last written byte*/

void *mymempcpy (void *s, const void *t, size_t n) {
	char *p = (char *) mimemcpy (s, t, n);
	return (void *)(p + n);
}

/* mymemccpy function copies content upto n bytes from memory area pointed by 'q' to the
*memory area pointed by 'p' till the character c is not found and this function returns pointer to the 
*next character in p after c or null if c is not found in first n character of memory area pointed by 'p'*/

void *mymemccpy (void *p, const void *q, int c, size_t n) {
	if(n == 0) 
		return NULL;
	char *s = (char *)p;
	char *t = (char *)q;
	unsigned char ch = c;
	while(n--) {
		if(*t == ch)
			return (void *)(s + 1);
		*t = *s;
		t++;
		s++;
	}
	return (NULL);
}

/*mybcmp function does bitwise operation this function compares two byte sequences
*of the string pointed by 'p' and 'q' of length n each respectively if they are 
*equal and if n is zero bcmp returns zero otherwise it returns non zero value*/

int mybcmp (const void *p, const void *q, size_t n) {
     int i, j = 0;
     char *s = (char *)p;
     char *t = (char *)q;
     for(i = 0;i < n;i++) {
     	j = j | (*s ^ *t);
     	s++;
     	t++;
     }
     return j;
}

/* mystrstr function finds the first occurance of substring pointed by 's' in the string 
*pointed by 't' and this function returns pointer to the beginning of substrng founded in the
*string pointed by 't' or null if no substring match found*/

char *mystrstr (const char *t, const char *s) {
	int flag = 0;
	const char *p = t;
	const char *q = s;
	while(*p != '\0') {
		while(*p && *q) {
			if(*p == *q) {
				p++;
				q++;
			}
			else if(q == s)
				p++;
			else
				q = s;
			if(*q == '\0') {
				p = p - (q - s);
      				flag++;
				break;
			}
		} q = s;
		if(flag == 1)
			return (char *)p;
		else if(*q == 0) 
			return (char *)t;
		else 
			return 0;	
	}
	return (NULL);
}
 
/* mystrncmp function compares at most n bytes of the strings pointed by 't' and pointed by  
*'s' and this funstion returns an integer less than, equal to, or greater than zero if 't'  
*is found to be less than, same, or greater than 's'  respectively */

int mystrncmp (const char *t, const char *s, size_t n) {
	int i, j;
	const char * p = t;
	const char * q = s;
	const char *l, *m;
	l = p;
	l = l + n; 
	m = q;  
	m = m + n;
	while((l - p) != 0 || (m - q) != 0) {
		if(*p == 0 && *q == 0)
			return 0;		
		if(*p == *q){
			p++;
			q++;
		}
		else{
			i = *p;
			j = *q;
			return(i - j);
		}
		if((l - p) == 1 || (m - q) == 1) {
			i = *p;
			j = *q;
			return (i - j);
		}
	}
	return 0;
}

/* mymemmove function copies n bytes from memory area 't' to the memory area 's' and return pointer to 's'*/
	
void *mymemmove (void *s, const void *t, size_t n) {
	int i, j;
	char *p = s;
	const char *q = t;	
	if(mystrlen(p) >= mystrlen(q)) {
		for(i = 0, j = 0;j < n;i++, j++) 
			*(p+i) = *(q+j);
	}
	else {	
		for(i = 0, j = 0;j < n;i++, j++) 
			*(p+i) = *(q+j);
		p[i] = '\0';
	}
	return (void *)p;
} 

int mymemcmp (const void *t, const void *s, size_t n) {
	int i, j;
	const char * p = t;
	const char * q = s;
	const char *l, *m;
	l = p;
	l = l + n;
	m = q;  
	m = m + n; 
	while((l - p) != 0 || (m - q) != 0) {
		if(*p == 0 && *q == 0)
			return 0;		
		if(*p == *q){
			p++;
			q++;
		}
		else{
			i = *p;
			j = *q;
			return(i-j);
		}
		if((l - p) == 1 || (m - q) == 1) {
			i = *p;
			j = *q;
			return (i - j);
		}
	}
	return 0;
}

/* mymemchr function search for the first occurance of character c in the initial 
* n byte of the memory area pointed by 't' and this function returns pointer to the
* matching byte or null if character does not occur in the given memory area*/

void *mymemchr (const void *t, int c, size_t n) {
	char *p = (char *)t;
	while(n--) {
		if((unsigned char)c == *p)
			return (void *)p;
		else
			p++;
	}
	return NULL;
}

/* mystpcpy function copies string pointed by 'q' (including terminating null byte '\0') to the
*memory area pointed by 'p' and returns pointer to the end of the string pointed by 'p'*/

char *mystpcpy (char *p , const char *q) {
	const char *t = q;
	while( *t != '\0') {
		*p = *t;
		p++;
		t++;
	}
	*p = '\0';
	return p;
}

size_t mystrxfrm (char *p , const char *q, size_t n) {
	int i, j, count = 0;
	while(*q != '\0'){	
		if(mystrlen(p) >= mystrlen(q)) {
			for(i = 0, j = 0;j < n;i++, j++) 
				*(p+i) = *(q+j);
		}
		else{
			for(i = 0, j = 0;j < n;i++, j++)
				*(p+i) = *(q+j);
			p[i] = '\0';
		}
		q++;
		count++;
	}
	return (count);
}

/* mystrncasecmp function compares at most n bytes of the strings pointed by 't' and 's' ignoring the case
*of characters and it returns an integer less than, equal to, or greater than zero if t  is found to be
*less than, same, or greater than s  respectively */
	
int mystrncasecmp (const char *t, const char *s, size_t n) {
	int i, j;
	const char *p = t;
	const char *q = s;
	const char *l, *m;
	l = p;
	l = l + n;
	m = q;  
	m = m + n; 
	while((l - p) != 0 || (m - q) != 0) {
		i = *p;
		j = *q;
		if(*p == 0 && *q == 0)
			return 0;
		if((i - j) == 32 || (i - j) == -32 || (i - j) == 0){
			p++;
			q++;
		}
		else{
			if((i <= 122 && i >= 97) && (j <= 90 && j >= 65))
				i=i-32;
			if((i <= 90 && i >= 65) && (j <= 122 && j >= 97))
				j = j - 32;
			if((i <= 90 && i >= 65) && *q == 0)
				i = i + 32;
			if((j <= 90 && j >= 65) && *p == 0) 
				j = j + 32;			
			return(i - j);
			if((l - p) == 1 || (m - q) == 1) {
				if((i - j) == 32 || (i - j) == -32 || i == j) {					
					return 0;
				}
				else
					return(i - j);
			}	
			
		}

	}
	if((i - j) == 32 || (i - j) == -32 || i == j) 					
		return 0;
	return (i - j);
}

/* mystrtok function breaks the string pointed by 'p' into the sequence of zero or more non empty
*tokens by comparing with each byte from string pointed by 'm' and this function return
*a pointer to the next token or null if no more tokens are remained*/

char *mystrtok (char *p, const char *s) {
	static char *q;
        char *m;
	if ( p == NULL ) {
		p = q;
	        if (*p == '\0')      
			return NULL;
	} 
	m = p;
 	p = mystrgpbrk(p, s);
	if(p != (NULL)) {
		*p = '\0';
		q = p + 1;
	}
	else {
		if(p == (NULL)) {
			q = myindex(m, '\0');
			return m;
		}
		else
			return NULL;
	}		
	return m;
}

/* mymemmem function find the start of occurance of substring pointed by 's' of length lens
*in the memory area pointed by 't' of length lent and this function returns pointer
*to the beginning of the substring or null if substring match is found*/

void *mymemmem (void *t, size_t lent, void *s, size_t lens) {
	int flag = 0;
	char *p = t;
	char *q = s;
	char *m = s;
	*(p+lent) = '\0';
	*(q+lens) = '\0'; 
	while(*p != '\0') {
		while(*p && *q) {
			if(*p == *q) {
				p++;
				q++;
			}
			else if(q == m)
				p++;
			else
				q = m;
			if(*q == '\0') {
				p = p - (q - m);
      				flag++;
				break;
			}
		} q = m;
		if(flag == 1)
			return (void *)p;
		else if(*q == 0) 
			return (void *)t;
		else 
			return NULL;	
	}
	return (NULL);
}

int mystrcasecmp (const char *t, const char *s) {
	int i, j;
	const char *p = t;
	const char *q = s;
	while(*p != '\0' || *q != '\0'){
		i = *p;
		j = *q;
		if(*p == 0 && *q == 0)
			return 0;
		if((i - j) == 32 || (i - j) == -32 || (i - j) == 0){
			p++;
			q++;
		}
		else{
			if((i <= 122 && i >= 97) && (j <= 90 && j >= 65))
				i = i - 32;
			if((i <= 90 && i >= 65) && (j <= 122 && j >= 97))
				j = j - 32;
			if((i <= 90 && i >= 65) && *q == 0)
				i = i + 32;
			if((j <= 90 && j >= 65) && *p == 0) 
				j = j + 32;				
			return(i - j);
		}
		
	}
		i = *p;
		j = *q;
	return (i - j);
}

/* myindex function returns pointer to the first occurance of character c in the string
*pointed by 't' or null if no character match found*/

char *myindex (const char *t, int c) {
	int k;

	while(*t != '\0'){
		k = *t;
		if(k == c)
			return (char *) t;
		else
			t++;
		if(*t == '\0') {
			k = *t;
			if(k == c)
				return (char *) t;
		}
	}	
	return (NULL);
}

/* myrindex function returns pointer to the last occurance of character c in the string
*pointed by 't' or null if no character match found*/

char *myrindex (const char *t, int c) {
	int k, count = 0;
	const char *q;
	while(*t != '\0'){
		k = *t;
		if(k == c){
			q = t;
			count++;
		}
			t++;
	}
	if(count == 0 && *t != '\0')
		return 0;
	if(*t == '\0'){
		k=*t;
		if(k == c)
			return (char *) t;
		else
			return (char *) q;
	}	
	return (NULL);
}

/* mystrdup function return pointer to a new string which is duplicate of the string
*pointed by 'p'or null if insufficient memory was available*/

char *mystrdup (const char *p) {
	char *q;
	size_t l;
	l = mystrlen(p) + 1;
	q = (char *) malloc(sizeof(char)*l);
	if(!(q = (char *) malloc(sizeof(char)*l)))
		return NULL;
	mystrcpy(q, p);
	return q;
}

/* mystrndup function works in similar fashion as mystrdup but copies at most n bytes */

char *mystrndup (const char *p, size_t n) {
	char *q;
	q = (char *) malloc(sizeof(char)*n);
	if(!(q = (char *) malloc(sizeof(char)*n)))
		return NULL;
	mystrncpy(q, p, n);
	return q;
}

/* mystrdupa function is similar to mystrdup it just uses alloca(3) function instead
*of malloc(3) to allocate the memory */

char *mystrdupa (const char *p) {
	char *q;
	size_t l;
	l = mystrlen(p) + 1;
	q = (char *) alloca(sizeof(char)*l);
	if(!(q = (char *) alloca(sizeof(char)*l)))
		return NULL;
	mimemcpy(q, p, l);
	return q;
}
 /* mystrndupa works similar to mystrdupa but it copies at most n bytes */
 
char *mystrndupa (const char *p, size_t n) {
	char *q;
	q = (char *) alloca(sizeof(char)*n);
	if(!(q = (char *) alloca(sizeof(char)*n)))
		return NULL;
	mystrncpy(q, p, n);
	return q;
}

/* mymemfrob function encrypts first n bytes of the memory area pointed by 'p' by exclusive-oRing 
*each character with number '42' and it returns pointer to the encrypted memory area*/

void *mymemfrob (void *p, size_t n) {
	char *s = (char *) p;
	while(n > 0){
		*s ^= 42;
		s++;
		n--;
	}
	return p;
}

/* mybzero function sets first n bytes of memory area pointed by 'p' to zero (bytes containing '\0') */

void mybzero (void *p, size_t n) {
	register char *t = (char *) p;
	while(n != 0) {
		*t = 0;
		t++;
		n--;
	}
}

/* mybcopy function copies n bytes from memory area pointed by 'p' to the memory area pointed by 'q'*/

void mybcopy (const void *p, void *q, size_t n) {
	char *t = q;
	const char *s = p;
	while(n != 0) {
		*t = *s;
		t++;
		s++;
		n--;
	}
}

/* myffs function returns the position of first (least significant) bit set in the
* word 'n'or zero if no bits are set in the word 'n'  
*least significant bit position is 1 and most significant bit position is 32 or 64*/

int myffs (int n) {
	int k, l;
	if (n == 0)
		return 0;
	l = k = 1;
	while((n & k) == 0) {
		k = k << 1;
		l = l + 1;
	}
	return l;		
}

/* myffsl function works in similar fashion as myffs works but it takes different argument which is 'long int'*/

int myffsl (long int n) {
	int k, l;
	if(n == 0)
		return 0;
	l = k = 1;
	while((k & n) == 0) {
		k = k << 1;
		l = l + 1;
	}
	return l;
}

/* myffsll function works in similar fashion as myffs works but it takes different argument which is 'long long int'*/
			
int myffsll (long long int n) {
	int k, l;
	if(n == 0)
		return 0;
	l = k = 1;
	while((k & n) == 0) {
		k = k << 1;
		l = l + 1;
	}
	return l;
}

