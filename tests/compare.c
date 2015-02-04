
#include <stdio.h>

#include "../assert.h"          // ASSERT
#include "../compare.h"         // COMPARE


int main( void )
{
    printf( "Running tests...\n" );
    ASSERT( COMPARE( 12, 34 ) == -1,
            COMPARE( 47, 42 ) == 1,
            COMPARE( 0, 0 ) == 0,
            COMPARE( -1, -1 ) == 0,
            COMPARE( 1, 2 ) == -1,
            COMPARE( 1.5, 1.25 ) == 1 );
}

