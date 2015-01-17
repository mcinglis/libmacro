
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


#ifndef LIBMACRO_MINMAX_H
#define LIBMACRO_MINMAX_H


#include <libpp/foldr.h>        // PP_FOLDR


// @public begin


// Returns the minimum value of the two given scalars.
#define MIN2( X, Y ) \
    (((X)<(Y))?(X):(Y))

// Returns the minimum value of the `n` given scalars.
#define MIN( ... ) \
    PP_FOLDR( MIN2, __VA_ARGS__ )


// Returns the maximum value of the two given scalars.
#define MAX2( X, Y ) \
    (((X)>(Y))?(X):(Y))

// Returns the maximum value of the `n` given scalars.
#define MAX( ... ) \
    PP_FOLDR( MAX2, __VA_ARGS__ )


// @public end


#endif

