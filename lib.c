#include"mystring.h"
#include<stdlib.h>
#include<stdio.h>
size_t mystrlen(const char *p){
	int count = 0;
	while(*p != '\0'){
		p++;
		count++;
	}
	return (count);
}


char *mystrcat(char *p, char *q) {
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


char *mystrcpy(char *p ,const char *q) {
	char *m = p;	
	while(*q != '\0') {
		*p = *q;
		p++;
		q++;
	}
	*p = '\0'; 
	return (m);
}


char *mystrncpy(char *p ,const char *q, size_t n) {
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


char *mystrrev(char *p){
	int t, i, j;
	t = mystrlen(p) / 2;
	for(i = 0;i < t;i++){
		j = *(p + i);
		*(p + i) = *(p + (mystrlen(p) - i - 1));
		*(p + (mystrlen(p) - i - 1)) = j;
	}
	return (p);
}


char *mystrreplace(char *t, char *s, char *m) {
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
					for(x = 0;x < (mystrlen(t) - (k+mystrlen(s))) + 1;x++){
						t[z + y]= t[z];
						z = z - 1;
					}
					for(i = k, j = 0;i < (k + mystrlen(m));i++, j++){
						*(t + i) = *(m + j);
					}
			
				}
 				
				else if(mystrlen(s) > mystrlen(m)){
         				y = mystrlen(s) - mystrlen(m);
         				z = k + mystrlen(s);
         				p = p - y;
 					for(x = 0;x < (mystrlen(t) - (k + mystrlen(s))) + 1;x++){
          					t[z - y] = t[z];
          					z = z + 1;
 					}
					for(i = k, j = 0;i < (k + mystrlen(m));i++, j++){
        					*(t + i) = *(m + j);            
					}
          			} 
			}       
		} q = s;
	}
	return t;
}

 


size_t mystroccurance(char *t, char *s) {
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


char *mystrchr(const char *p, int c){
	int k, n = 0;

	while(*p != '\0'){
		k = *p;
		if(k == c)
			return (char *)p;
		else
			p++;
		n++;
		if(*p == '\0') {
			k = *p;
			if(k == c)
				return (char *)p;
		}
	}	
	return 0;
}



char *mystrpbrk(const char *p, const char *q){
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
			/* as if no character in first string
			is matched with any of the character in the second string
			so i am returning null pointer here as null pointer points to nothing */
	}
	return (NULL);
}

int mystrcmp(const char *t, const char *s){
	int i, j;
	const char *p = t;
	const char *q = s;
	while(*p != '\0' || *q != '\0'){
		if(*p == *q){
			p++;
			q++;
		}
		else{
			i = *p;
			j = *q;
			return(i - j);
		}
		
	}
		i = *p;
		j = *q;
	return (i - j);
}


size_t mystrspn(const char *p, const char *q) {
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


size_t mystrcspn(const char *p, const char *q) {
	int count = 0, flag;	
	const char *t = q;
	while(*p != '\0') {
		flag = 0;
		while(*q != '\0') {
			if(*p != *q) {
				flag++;
			}
			q++;
		}
		if(flag == (q - t)){
			count++;
		}
		p++;
		if(flag < (q - t))
			return count;
		q=t;
	}
		if(flag == (q - t) || (q - t) == 0)
			return count;
	return 0;
}


char *mystrrchr(const char *p, int c){
	int k, count = 0;
	const char *q;
	while(*p != '\0'){
		k = *p;
		if(k == c){
			q = p;
			count++;
		}
			p++;
	}
	if(count == 0 && *p != '\0')
		return 0;/* if no character c is matched with any of the character
			in the string pointed by p then function will return
			null pointer*/ 
	if(*p == '\0'){
		k = *p;
		if(k == c)
			return (char *)p;
		else
			return (char *)q;
	}	
	return (NULL);
}

 
char *mystrncat(char *p, char *q, size_t n){
	int i, j;
	char *t;
	t = p;
	for(j = 0, i = mystrlen(p);j < n;i++, j++){
		*(p + i) = *(q + j);
	}
	p[i] = '\0';
	return t;
}


void *mymemset(void *s, int c, size_t n){
	int i, t;
	char k;
	char *p = s;
	k = c;
	t = c;
	if(n > mystrlen(p))
		return 0;
	if(t >= 48 && t <= 57){
		for(i = 0;i < n;i++){
			*(p + i) = c;
		}
	}	
	else{
		for(i = 0;i < n;i++){
			*(p + i) = k;
		}
	}
	return (void *)p;
}


void *mymemcpy(void *s, const void *t, size_t n) {
	int i, j;
	char *p = s;
	const char *q = t;	
	if(mystrlen(p) >= mystrlen(q)) {
		for(i = 0, j = 0;j < n;i++, j++) {
			*(p + i) = *(q + j);
		}
	}
	else{
		for(i = 0, j = 0;j < n;i++, j++) {
			*(p + i) = *(q + j);
		}
		p[i] = '\0';
	}
	return (void *)p;
}


char *mystrstr(const char *t, const char *s) {
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


int mystrncmp(const char *t, const char *s, size_t n) {
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
	

void *mymemmove(void *s, const void *t, size_t n) {
	int i, j;
	char *p = s;
	const char *q = t;	
	if(mystrlen(p) >= mystrlen(q)) {
		for(i = 0, j = 0;j < n;i++, j++) {
			*(p+i) = *(q+j);
		}
	}
	else{	
		for(i = 0, j = 0;j < n;i++, j++) {
			*(p+i) = *(q+j);
		}
		p[i] = '\0';
	}
	return (void *)p;
} 


int mymemcmp(const void *t, const void *s, size_t n) {
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
 

void *mymemchr(const void *t, int c, size_t n) {
	int k, i = 0;
	const char *p = t;
	const char *q = t;
	while((*p != *(q + n)) || i < n){
		k=*p;
		if(k == c)
			return (void *)p;
		else
			p++;
		i++;
	}
	return 0;
}

char *mystpcpy(char *p , const char *q) {
	const char *t = q;
	while( *t != '\0') {
		*p = *t;
		p++;
		t++;
	}
	*p = '\0';
	return p;
}


size_t mystrxfrm(char *p , const char *q, size_t n) {
	int i, j, count = 0;
	while(*q != '\0'){	
		if(mystrlen(p) >= mystrlen(q)) {
			for(i = 0, j = 0;j < n;i++, j++) {
				*(p+i) = *(q+j);
			}
		}
		else{
			for(i = 0, j = 0;j < n;i++, j++) {
				*(p+i) = *(q+j);
			}
			p[i] = '\0';
		}
		q++;
		count++;
	}
	return (count);
}
	

int mystrncasecmp(const char *t, const char *s, size_t n){
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

char *mystrtok(char *p, const char *delim) {
	static char *q;
        char *m;

	if ( p == NULL ) {
		p = q;
	        if (*p == '\0')      
			return NULL;
	
	} 
		m = p;
 	        p = mystrpbrk(p, delim);
		if(p != (NULL)) {
		       *p = '\0';
			q = p + 1;
		}
		else {
			if(p == (NULL)){
				q = myindex(m, '\0');
				return m;
			}
			else
				return NULL;
		}		
		return m;
}

void *mymemmem(void *t, size_t lent, void *s, size_t lens) {
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
			return 0;	
	}
	return (NULL);
}


int mystrcasecmp(const char *t, const char *s){
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
				i=i-32;
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

char *myindex(const char *t, int c){
	int k, n = 0;

	while(*t != '\0'){
		k = *t;
		if(k == c)
			return (char *) t;
		else
			t++;
		n++;
		if(*t == '\0') {
			k = *t;
			if(k == c)
				return (char *) t;
		}
	}	
	return (NULL);
}

char *myrindex(const char *t, int c){
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

char *mystrdup(const char *p) {
	char *q;
	int l;
	l = mystrlen(p) + 1;
	q = (char *) malloc(sizeof(char)*l);
	if(!(q = (char *) malloc(sizeof(char)*l)))
		return NULL;
	mystrcpy(q, p);
	return q;
}

char *mystrndup(const char *p, size_t n) {
	char *q;
	q = (char *) malloc(sizeof(char)*n);
	if(!(q = (char *) malloc(sizeof(char)*n)))
		return NULL;
	mystrncpy(q, p, n);
	return q;
}

void *mymemfrob(void *p, size_t n) {
	char *s = (char *) p;
	while(n > 0){
		*s ^= 42;
		s++;
		n--;
	}
	return p;
}

void mybzero(void *p, size_t n) {
	register char *t = (char *) p;
	while(n != 0) {
		*t = 0;
		t++;
		n--;
	}
}

void mybcopy(const void *p, void *q, size_t n) {
	char *t = q;
	const char *s = p;
	while(n != 0) {
		*t = *s;
		t++;
		s++;
		n--;
	}
}			
