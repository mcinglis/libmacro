
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


#ifndef LIBMACRO_DEBUG_H
#define LIBMACRO_DEBUG_H


#include <stdio.h>

#include <libpp/concat.h>


#ifdef NDEBUG
    #define DEBUG( ... )
#else

    // @public
    // Takes a literal format string and a variable number of arguments (up
    // to 32) corresponding to the directives in the given format string, and
    // prints the formatted message to stderr prefixed with the function,
    // file and line the originating `DEBUG` statement was made.
    //
    // If called with a single literal string, then this prints that string
    // without requiring any formatting arguments.
    #define DEBUG( ... ) \
        PP_CONCAT( DEBUG_, DEBUG_COUNT( __VA_ARGS__ ) )( __VA_ARGS__ )

    #define DEBUG_COUNT( ... ) \
        DEBUG_COUNT_( __VA_ARGS__, \
                      M, M, \
                      M, M, M, M, M, M, M, M, M, M, \
                      M, M, M, M, M, M, M, M, M, M, \
                      M, M, M, M, M, M, M, M, M, M, \
                      1, vararg when given 1 )

    #define DEBUG_COUNT_( _33,_32,_31, \
                          _30,_29,_28,_27,_26,_25,_24,_23,_22,_21, \
                          _20,_19,_18,_17,_16,_15,_14,_13,_12,_11, \
                          _10,_09,_08,_07,_06,_05,_04,_03,_02,_01, \
                          X, ... ) X

    #define DEBUG_1( str ) \
        fprintf( stderr, "[DEBUG] %s (%s:%d): " str "\n", \
                         __func__, __FILE__, __LINE__ )

    #define DEBUG_M( fmt, ... ) \
        fprintf( stderr, "[DEBUG] %s (%s:%d): " fmt "\n", \
                         __func__, __FILE__, __LINE__, __VA_ARGS__ )

#endif


#endif

