
// Copyright 2015  Malcolm Inglis <http://minglis.id.au>
//
// This file is part of Libmacro.
//
// Libmacro is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the
// Free Software Foundation, either version 3 of the License, or (at your
// option) any later version.
//
// Libmacro is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
// License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with Libmacro. If not, see <https://gnu.org/licenses/>.


#ifndef LIBMACRO_ALLOC_H
#define LIBMACRO_ALLOC_H


#include <stdlib.h>             // free

#include <libtypes/types.h>     // size_t


// @public
// Takes a type name, and allocates and returns a copy of a compound
// literal of that type, containing the variable arguments as fields.
// This can be used for allocating a primitive value, struct value, or
// an array:
//
//      int * const x = ALLOC( int, 8 );
//      Widget * const w = ALLOC( Widget, .foo = 0xA3, .bar = "wow" );
//      long * const xs = ALLOC( long[ 5 ], 42, 13, 18 );
//
// Note that the unspecified struct fields and array elements will be
// zeroed.
#define ALLOC( TYPE, ... ) \
    malloc_copy( sizeof ( TYPE ), &( TYPE ){ __VA_ARGS__ } )


// Allocates `size` bytes, copies `size` bytes from `source` into that
// memory, and returns a pointer to that memory. Returns `NULL` if
// `size == 0` or if the memory allocation failed. If `source == NULL`,
// nothing is copied, so this acts just like `malloc( size )`.
void * malloc_copy( size_t size, void const * source );


// @public
// Takes a variable number of pointers to allocated memory, and `free()`s
// each one individually.
#define FREE( ... ) \
    PP_MAP( free, PP_SEP_SEMICOLON, __VA_ARGS__ )


#endif

