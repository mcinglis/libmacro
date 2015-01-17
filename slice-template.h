
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


#ifndef LIBMACRO_SLICE_H
#define LIBMACRO_SLICE_H


// Evaluates to the `LEN` elements of `XS` starting from index `FROM`.
//
//     SLICE( xs, 5, 3 )
//     >>> xs[ 5 ], xs[ 6 ], xs[ 7 ]
//
// `LEN` must be a numeric literal between 0 and {limit}.
#define SLICE( XS, FROM, LEN ) \
    PP_CONCAT( SLICE_, LEN )( XS, FROM )


{impls}


#endif


#####

def context(limit):
    impls = '#define SLICE_0(A,S)\n'
    slice_n = ('#define SLICE_{n}(A,S) \\\n'
               '    {body}\n')
    body = '(A)[(S)]'
    for i in range(1, limit+1):
        impls += slice_n.format(n=i, body=body)
        body += ', (A)[(S)+{}]'.format(i)
    return {'impls': impls}

