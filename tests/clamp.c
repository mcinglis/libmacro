
#include <stdio.h>

#include "../assert.h"          // ASSERT
#include "../clamp.h"           // CLAMP


int main( void )
{
    printf( "Running tests...\n" );
    ASSERT( CLAMP( -1, 0, 10 ) == 0,
            CLAMP( 0, 0, 10 ) == 0,
            CLAMP( 1, 0, 10 ) == 1,
            CLAMP( 9, 0, 10 ) == 9,
            CLAMP( 10, 0, 10 ) == 10,
            CLAMP( 11, 0, 10 ) == 10,
            CLAMP( 5, 5, 5 ) == 5,
            CLAMP( 5, 10, 0 ) == 10 );
}

