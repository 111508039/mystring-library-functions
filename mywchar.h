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

#include"stddef.h"
size_t mywcslen (const wchar_t *);
size_t mywcsnlen (const wchar_t *p, size_t n);
wchar_t *mywcscat (wchar_t *p, wchar_t *q);
wchar_t *mywcscpy (wchar_t *p ,const wchar_t *q);
wchar_t *mywcsncpy (wchar_t *p ,const wchar_t *q, size_t n);
wchar_t *mywcmemcpy (wchar_t *p, const wchar_t *q, size_t n);
wchar_t *mywcsncat (wchar_t *p, wchar_t *q, size_t n);
wchar_t *mywcsrev (wchar_t *p);
size_t mywcsoccurance (wchar_t *t, wchar_t *s);
wchar_t *mywcspbrk (const wchar_t *p, const wchar_t *q);
wchar_t *mywcsdup (const wchar_t *p);
wchar_t *mywcstr (const wchar_t *t, const wchar_t *s);
wchar_t *mywcmemchr (const wchar_t *t, wchar_t c, size_t n);
wchar_t *mywcrchr (const wchar_t *p, wchar_t c);
wchar_t *mywcschr (const wchar_t *p, wchar_t c);
size_t mywcsspn (const wchar_t *p, const wchar_t *q);
size_t mywcscspn (const wchar_t *p, const wchar_t *q);
wchar_t *mywcsreplace (wchar_t *t, wchar_t *s, wchar_t *m);
wchar_t *miwcpcpy (wchar_t *p , const wchar_t *q);
wchar_t *mywmemset (wchar_t *s, wchar_t c, size_t n);
wchar_t *mywmemmove (wchar_t *s, const wchar_t *t, size_t n);
int mywcscmp (const wchar_t *t, const wchar_t *s);
int mywcsncmp (const wchar_t *t, const wchar_t *s, size_t n);
wchar_t *mywcmemfrob (wchar_t *p, size_t n);
