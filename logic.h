
// Copyright 2014  Malcolm Inglis <http://minglis.id.au>
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


#ifndef LIBMACRO_LOGIC_H
#define LIBMACRO_LOGIC_H


#include <libpp/intersperse.h>  // PP_INTERSPERSE
#include <libpp/separators.h>   // PP_SEP_AND, PP_SEP_OR


// @public begin


// These macros are provided more for the possibility of functional
// programming with the preprocessor - not for direct use in source code.
#define AND( X, Y )         ( ( X ) && ( Y ) )
#define OR( X, Y )          ( ( X ) || ( Y ) )
#define NAND( X, Y )        ( !AND( X, Y ) )
#define NOR( X, Y )         ( !OR( X, Y ) )

// May clarify meaning in source code:
#define IMPLIES( X, Y )     ( !( X ) || ( Y ) )

// Retains the short-circuiting behavior across variable number of arguments:
#define ALL( ... )          ( PP_INTERSPERSE( PP_SEP_AND, __VA_ARGS__ ) )
#define ANY( ... )          ( PP_INTERSPERSE( PP_SEP_OR, __VA_ARGS__ ) )
#define NONE( ... )         ( !ANY( __VA_ARGS__ ) )


// @public end


#endif

