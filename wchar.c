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

#include<stdlib.h>
#include"mywchar.h"

/* mywcslen function returns the length of string pointed by 'p' and it works for string in any language*/

size_t mywcslen (const wchar_t *p) {
	int count = 0;
	
	while(*p != L'\0') {
		p++;
		count++;
	}
	return (count);
}

/* mywcsnlen function works similar to mywcslen but it returns length of at most n bytes only */

size_t mywcsnlen (const wchar_t *p, size_t n) {
	int count = 0;
	while(n != 0) {
		p++;
		count++;
		n--;
	}
	return (count);
}

/* mywcscat function appends string pointed by 'q' to the string pointed by 'p' and returns
*pointer to the resulting string pointed by 'p'*/

wchar_t *mywcscat (wchar_t *p, wchar_t *q) {
        wchar_t *t = p;
        p = p + mywcslen(p);
        while(*q != L'\0') {                                                                     
		*p = *q;
		p++;
		q++;             
        }               
	*p = L'\0';                      
        return(t);              
}

/* mywcscpy function copies memory area pointed by 'q' to the memory area pointed by 'p'
* including terminating null '\0' byte and returns pointer to memory area pointed by 'p'*/

wchar_t *mywcscpy (wchar_t *p ,const wchar_t *q) {
	wchar_t *m = p;	
	while(*q != L'\0') {
		*p = *q;
		p++;
		q++;
	}
	*p = L'\0'; 
	return (m);
}

/* mywcsncpy function copies at most n bytes from the memory area pointed by 'q' to the memory area
* pointed by 'p' including terminating null '\0' byte and returns pointer to memory area pointed by 'p'*/

wchar_t *mywcsncpy (wchar_t *p ,const wchar_t *q, size_t n) {
	const wchar_t *l = q;
	wchar_t *m = p;
	l = l + n;	
	while((l - q) != 0) {
		*p = *q;
		p++;
		q++;
	}
	*p = L'\0'; 
	return (m);
}

/* mywcmemcpy function copies n bytes from memory area pointed by 't' to memory area pointed by 's' */

wchar_t *mywcmemcpy (wchar_t *p, const wchar_t *q, size_t n) {
	wchar_t *s = p;
	const wchar_t *t = q;
	while(n--) {
		*s = *t;
		s++;
		t++;
	}
	return p;
}

/* mywcsncat function works similar to mywcscat but it just appends at most n bytes of the
* string pointed by 'q' to the string pointed by 'p' */ 

wchar_t *mywcsncat (wchar_t *p, wchar_t *q, size_t n) {
	int i = 0;
	wchar_t *t = p;
	p = p + mywcslen(p);
	while(i < n-1) {
		*p = *q;
		p++;
		q++;
		i++;
	}
	p[i] = L'\0';
	return t;
}

/* mywcsrev function reverses the string pointed by 'p' and returns pointer to the reversed string*/

wchar_t *mywcsrev (wchar_t *p) {
	int t, i, j;
	t = mywcslen(p) / 2;
	for(i = 0;i < t;i++) {
		j = *(p + i);
		*(p + i) = *(p + (mywcslen(p) - i - 1));
		*(p + (mywcslen(p) - i - 1)) = j;
	}
	return (p);
}

/* mywcsoccurance function returns the occurance of substring pointed by 's' in the
*string pointed by 't' or zero if no substring match is found*/

size_t mywcsoccurance (wchar_t *t, wchar_t *s) {
	int c = 0;
	wchar_t *p, *q;
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

/* if character from the string pointed by 'q' is matched with any of the 
*character from the string pointed by 'p' then mywcspbrk function will return pointer 
*to the first character matched otherwise if no match found will return null pointer*/

wchar_t *mywcspbrk (const wchar_t *p, const wchar_t *q) {
	const wchar_t *s;
	s = q;
	while(*p != '\0') {
		while(*q != '\0') {
			if(*p == *q)
				return (wchar_t *)p;
			else
				q++;
		}
		q = s;	
		p++;
	}
	return (NULL);
}

/* mywcsdup function return pointer to a new string which is duplicate of the string
*pointed by 'p'or null if insufficient memory was available*/

wchar_t *mywcsdup (const wchar_t *p) {
	wchar_t *q;
	int l;
	l = mywcslen(p) + 1;
	q = (wchar_t *) malloc(sizeof(wchar_t)*l);
	if(!(q = (wchar_t *) malloc(sizeof(wchar_t)*l)))
		return NULL;
	mywcscpy(q, p);
	return q;
}

/* mywcstr function finds the first occurance of substring pointed by 's' in the string 
*pointed by 't' and this function returns pointer to the beginning of substrng founded in the
*string pointed by 't' or null if no substring match found*/

wchar_t *mywcstr (const wchar_t *t, const wchar_t *s) {
	int flag = 0;
	const wchar_t *p = t;
	const wchar_t *q = s;
	while(*p != L'\0') {
		while(*p && *q) {
			if(*p == *q) {
				p++;
				q++;
			}
			else if(q == s)
				p++;
			else
				q = s;
			if(*q == L'\0') {
				p = p - (q - s);
      				flag++;
				break;
			}
		} q = s;
		if(flag == 1)
			return (wchar_t *)p;
		else if(*q == 0) 
			return (wchar_t *)t;
		else 
			return 0;	
	}
	return (NULL);
}

/* mywcmemchr function search for the first occurance of character c in the initial 
* n byte of the memory area pointed by 't' and this function returns pointer to the
* matching byte or null if character does not occur in the given memory area*/

wchar_t *mywcmemchr (const wchar_t *t, wchar_t c, size_t n) {
	wchar_t *p = (wchar_t *)t;
	while(n--) {
		if((wchar_t)c == *p)
			return p;
		else
			p++;
	}
	return NULL;
}

/* if the second argument i.e character is matched with any of first
*character in the string pointed by 'p' mywcschr function will return pointer 
*to that character otherwise if no match found will return null pointer*/

wchar_t *mywcschr (const wchar_t *p, wchar_t c) {
	int n = 0;
	wchar_t k;
	while(*p != L'\0') {
		k = *p;
		if(k == c)
			return (wchar_t *)p;
		else
			p++;
		n++;
		if(*p == L'\0') {
			k = *p;
			if(k == c)
				return (wchar_t *)p;
		}
	}	
	return (NULL);
}

/* if character c is matched with any of the character in the string
*pointed by 'p' then mywcsrchr function will return pointer to last 
*character matched otherwise if no match found will return null pointer*/ 

wchar_t *mywcrchr (const wchar_t *p, wchar_t c) {
	int count = 0;
	wchar_t k;
	const wchar_t *q;
	while(*p != L'\0') {
		k = *p;
		if(k == c) {
			q = p;
			count++;
		}
			p++;
	}
	if(count == 0 && *p != L'\0')
		return (NULL); 
	if(*p == L'\0') {
		k = *p;
		if(k == c)
			return (wchar_t *)p;
		else
			return (wchar_t *)q;
	}	
	return (NULL);
}

/* mywcsspn function returns the no of bytes in the initial segment of the string
*pointed by 'p' which are also present in string pointed by 'q'*/	

size_t mywcsspn (const wchar_t *p, const wchar_t *q) {
	const wchar_t *t = q;
	int count = 0, flag;
	while(*p != L'\0') {
		flag = 0;
		while(*q != L'\0') {
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

/* mywcscspn function returns the no of bytes in the initial segment of the string
*pointed by 'p' which are not present in string pointed by 'q'*/	

size_t mywcscspn (const wchar_t *p, const wchar_t *q) {
	int count = 0, flag;	
	const wchar_t *t = q;
	while(*p != L'\0') {
		flag = 0;
		while(*q != L'\0') {
			if(*p != *q) {
				flag++;
			}
			q++;
		}
		if(flag == (q - t)) {
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

/* mywcsreplacce function search for the all occurances of substring pointed by 's' in the
* string pointed by 't' and replace all of them by string pointed by 'm'and this function 
* returns pointer to the resultant string obtained after replacing all substrings */

wchar_t *mywcsreplace (wchar_t *t, wchar_t *s, wchar_t *m) {
	int k, i, j, z, x, y;
	wchar_t *p, *q;
	p = t;
	q = s;
	while(*p != L'\0') {
		while(*p && *q) {
			if(*p == *q) {
				p++;
				q++;
			}
			else if(q == s)
				p++;
			else
				q = s;
			if(*q == L'\0') {
				k = ((p - (q - s)) - t);
		
				if(mywcslen(s) == mywcslen(m)) {
					for(i = k, j = 0;i < (k + mywcslen(s));i++, j++) {
						*(t + i) = *(m + j);
					}
				}
				
				else if(mywcslen(m) > mywcslen(s)) {
					y = mywcslen(m) - mywcslen(s);
					z = mywcslen(t);
        				p = p + y;
					for(x = 0;x < (mywcslen(t) - (k + mywcslen(s))) + 1;x++) {
						t[z + y]= t[z];
						z = z - 1;
					}
					for(i = k, j = 0;i < (k + mywcslen(m));i++, j++) {
						*(t + i) = *(m + j);
					}
			
				}
 				
				else if(mywcslen(s) > mywcslen(m)) {
         				y = mywcslen(s) - mywcslen(m);
         				z = k + mywcslen(s);
         				p = p - y;
 					for(x = 0;x < (mywcslen(t) - (k + mywcslen(s))) + 1;x++) {
          					t[z - y] = t[z];
          					z = z + 1;
 					}
					for(i = k, j = 0;i < (k + mywcslen(m));i++, j++) {
        					*(t + i) = *(m + j);            
					}
          			} 
			}       
		} q = s;
	}
	return t;
}

/* mywcspcpy function copies string pointed by 'q' (including terminating null byte '\0') to the
*memory area pointed by 'p' and returns pointer to the end of the string pointed by 'p'*/

wchar_t *miwcpcpy (wchar_t *p , const wchar_t *q) {
	const wchar_t *t = q;
	while( *t != L'\0') {
		*p = *t;
		p++;
		t++;
	}
	*p = L'\0';
	return p;
}

/* mywmemset function will fill the first n bytes by the character c
*into the memory area pointed by the pointer 's'*/

wchar_t *mywmemset (wchar_t *s, wchar_t c, size_t n) {
	int i, t;
	wchar_t k;
	wchar_t *p = s;
	k = c;
	t = c;
	if(n > mywcslen(p))
		return NULL;
	if(t >= 48 && t <= 57){
		for(i = 0;i < n;i++) {
			*(p + i) = c;
		}
	}	
	else{
		for(i = 0;i < n;i++) {
			*(p + i) = k;
		}
	}
	return (wchar_t *)p;
}

/* mywmemmove function copies n bytes from memory area 't' to the memory area 's' and return pointer to 's'*/

wchar_t *mywmemmove (wchar_t *s, const wchar_t *t, size_t n) {
	int i, j;
	wchar_t *p = s;
	const wchar_t *q = t;	
	if(mywcslen(p) >= mywcslen(q)) {
		for(i = 0, j = 0;j < n;i++, j++) {
			*(p + i) = *(q + j);
		}
	}
	else{	
		for(i = 0, j = 0;j < n;i++, j++) {
			*(p + i) = *(q + j);
		}
		p[i] = L'\0';
	}
	return (wchar_t *)p;
} 

/* mywcscmp function compares the strings pointed by 't' and pointed by 's' and this funstion returns an integer  
*less than, equal to, or greater than zero if t  is found to be less than, same, or greater than s  respectively */

int mywcscmp (const wchar_t *t, const wchar_t *s) {
	int i, j;
	const wchar_t *p = t;
	const wchar_t *q = s;
	while(*p != L'\0' || *q != L'\0') {
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

/* mywcsncmp function compares the strings pointed by 't' and pointed by 's' and this funstion  
*returns an integer less than, equal to, or greater than zero if t  is found to be
*less than, same, or greater than s  respectively */

int mywcsncmp (const wchar_t *t, const wchar_t *s, size_t n) {
	int i, j;
	const wchar_t *p = t;
	const wchar_t *q = s;
	const wchar_t *l, *m;
	l = p;
	l = l + n;
	m = q;  
	m = m + n;
	while((l - p) != 0 || (m - q) != 0) {
		if(*p == 0 && *q == 0)
			return 0;		
		if(*p == *q) {
			p++;
			q++;
		}
		else {
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

/* mywcmemfrob function encrypts first n bytes of the memory area pointed by 'p' by exclusive-oRing 
*each character with number '42' and it returns pointer to the encrypted memory area*/

wchar_t *mywcmemfrob (wchar_t *p, size_t n) {
	wchar_t *s = p;
	while(n > 0) {
		*s ^= 42;
		s++;
		n--;
	}
	return p;
}

