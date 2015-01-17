
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


#ifndef LIBREQUIRE_REQUIRE_H
#define LIBREQUIRE_REQUIRE_H


#include <libpp/map.h>          // PP_MAP
#include <libpp/separators.h>   // PP_SEP_SEMICOLON
#include <libtypes/types.h>     // noreturn, uint


#ifdef NO_REQUIRE
    #define REQUIRE( ... )
#else

    // @public
    // Checks that all of the given scalar expressions at non-zero. If any
    // are zero, the first zero expression is printed to stderr with the
    // function, file, and line it was made on. Then, execution is
    // `abort()`ed.
    #define REQUIRE( ... ) \
        PP_MAP( REQUIRE1, PP_SEP_SEMICOLON, __VA_ARGS__ )

    #define REQUIRE1( X ) \
        ( ( void )( ( X ) \
                 || ( require_fail( #X, __func__, __FILE__, __LINE__ ), 0 ) ) )

#endif


noreturn
void
require_fail( char const * expr,
              char const * func,
              char const * file,
              uint line );


#endif


