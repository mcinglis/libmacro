
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


#ifndef LIBMACRO_BOUND_H
#define LIBMACRO_BOUND_H


#include <stdint.h>
#include <limits.h>

#include <libtypes/types.h>


// @public
#define MIN_BOUND( X ) \
    _Generic( ( X ), \
        bool: false, \
        char: CHAR_MIN, \
        signed char: SCHAR_MIN, \
        unsigned char: 0, \
        signed short: SHRT_MIN, \
        unsigned short: 0, \
        signed int: INT_MIN, \
        unsigned int: 0, \
        signed long: LONG_MIN, \
        unsigned long: 0, \
        signed long long: LLONG_MIN, \
        unsigned long long: 0, \
        default: INTMAX_MIN \
    )


// @public
#define MAX_BOUND( X ) \
    _Generic( ( X ), \
        bool:                   true, \
        char:                   CHAR_MAX, \
        signed char:            SCHAR_MAX, \
        unsigned char:          UCHAR_MAX, \
        signed short:           SHRT_MAX, \
        unsigned short:         USHRT_MAX, \
        signed int:             INT_MAX, \
        unsigned int:           UINT_MAX, \
        signed long:            LONG_MAX, \
        unsigned long:          ULONG_MAX, \
        signed long long:       LLONG_MAX, \
        unsigned long long:     ULLONG_MAX, \
        default:                INTMAX_MAX \
    )


#endif // ifndef LIBMACRO_BOUND_H

