
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


#ifndef LIBMACRO_CLAMP_H
#define LIBMACRO_CLAMP_H


// @public begin


#define CLAMP( LOWER, X, UPPER ) \
    ( ( ( X ) < ( LOWER ) ) ? ( LOWER ) \
    : ( ( X ) > ( UPPER ) ) ? ( UPPER ) \
                            : ( X ) )


// @public end


#endif

