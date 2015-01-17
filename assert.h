
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


#ifndef LIBMACRO_ASSERT_H
#define LIBMACRO_ASSERT_H


#include <assert.h>

#include <libpp/map.h>          // PP_MAP
#include <libpp/separators.h>   // PP_SEP_SEMICOLON


#ifdef NO_ASSERT
    #define ASSERT( ... )
#else

    // @public
    // Takes a variable number of scalar expressions, and `assert`s each
    // one individually. This provides better assertion error reporting than
    // techniques like `assert( e1 && e2 && ... )`.
    #define ASSERT( ... ) \
        PP_MAP( assert, PP_SEP_SEMICOLON, __VA_ARGS__ )

#endif


#endif


