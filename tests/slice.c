
#include <stdio.h>

#include "../slice.h"
#include "../assert.h"
#include "../nelem.h"


int main( void )
{
    int const xs[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    printf( "Testing subset slice...\n" );
    int const ws[] = { SLICE( xs, 3, 4 ) };
    ASSERT( NELEM( ws ) == 4,
            ws[ 0 ] == xs[ 3 ],
            ws[ 1 ] == xs[ 4 ],
            ws[ 2 ] == xs[ 5 ],
            ws[ 3 ] == xs[ 6 ] );
    ( void ) ws;

    printf( "Testing total slice...\n" );
    int const ys[] = { SLICE( xs, 0, 6 ) };
    ASSERT( NELEM( ys ) == 6,
            ys[ 0 ] == xs[ 0 ],
            ys[ 1 ] == xs[ 1 ],
            ys[ 2 ] == xs[ 2 ],
            ys[ 3 ] == xs[ 3 ],
            ys[ 4 ] == xs[ 4 ],
            ys[ 5 ] == xs[ 5 ] );
    ( void ) ys;

    printf( "Testing empty slice...\n" );
    int const zs[] = { 0, SLICE( xs, 2, 0 ) };
    ASSERT( NELEM( zs ) == 1 );
    ( void ) zs;

    printf( "SLICE() tests passed.\n" );
}

