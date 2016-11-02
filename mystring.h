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

#include<stddef.h>
size_t mystrlen (const char *);
char *mystrcat (char *, char *);
char *mystrcpy (char *p, const char *q);
char *mystrncpy (char *p ,const char *q, size_t n);
char *mystrrev (char *p);
char *mystrreplacce (char *t, char *s, char *m);
size_t mystroccurance (char *t, char *s);
char *mystrchr (const char *p, int c);
char *mystrgpbrk (const char *p, const char *q);
int mystrcmp (const char *t, const char *s);
size_t mystrspn (const char *p, const char *q);
size_t mystrcspn (const char *p, const char *q);
char *mystrrchr (const char *p, int c);
char *mystrncat (char *p, char *q, size_t n);
void *mymemset (void *s, int c, size_t n);
void *mimemcpy (void *s, const void *t, size_t n);
void *mymempcpy (void *s, const void *t, size_t n);
void *mymemccpy (void *p, const void *q, int c, size_t n);
int mybcmp (const void *p, const void *q, size_t n); 
char *mystrstr (const char *t, const char *s);
int mystrncmp (const char *t, const char *s, size_t n);
void *mymemmove (void *s, const void *t, size_t n);
int mymemcmp (const void *t, const void *s, size_t n);
void *mymemchr (const void *p, int c, size_t n);
char *mystpcpy (char *p , const char *q);
size_t mystrxfrm (char *p , const char *q, size_t n);
int mystrncasecmp (const char *t, const char *s, size_t n);
char *mystrtok (char *s1, const char *delimit);
void *mymemmem (void *t, size_t lent, void *s, size_t lens);
int mystrcasecmp (const char *t, const char *s);
char *mystrdup (const char *p);
char *mystrndup (const char *p, size_t n);
char *mystrdupa (const char *p);
char *mystrndupa (const char *p, size_t n); 
void *mymemfrob (void *p, size_t n);
void mybzero (void *p, size_t n);
void mybcopy (const void *p, void *q, size_t n);
int myffs (int n);
int myffsl (long int n);
int myffsll (long long int n); 
char *myindex (const char *t, int c);
char *myrindex (const char *t, int c);


