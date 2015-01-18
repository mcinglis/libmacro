
#include <stdio.h>

#include "../assert.h"          // ASSERT
#include "../clamp.h"           // CLAMP


int main( void )
{
    printf( "Running tests...\n" );
    ASSERT( CLAMP( 5, 10, 20 ) == 10,
            CLAMP( 5, 20, 20 ) == 20,
            CLAMP( 5, 25, 20 ) == 20,
            CLAMP( 5, 5,  20 ) == 5,
            CLAMP( 5, 3,  20 ) == 5 );
}

