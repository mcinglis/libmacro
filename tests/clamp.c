
#include <stdint.h>
#include <stdio.h>

#include "../assert.h"          // ASSERT
#include "../clamp.h"           // CLAMP


int main( void )
{
    ASSERT( CLAMP( -1, 0, 10 ) == 0,
            CLAMP( 0, 0, 10 ) == 0,
            CLAMP( 1, 0, 10 ) == 1,
            CLAMP( 9, 0, 10 ) == 9,
            CLAMP( 10, 0, 10 ) == 10,
            CLAMP( 11, 0, 10 ) == 10,
            CLAMP( 5, 5, 5 ) == 5,
            CLAMP( 5, 10, 0 ) == 10 );
    printf( "`CLAMP()` tests passed!\n" );

    ASSERT( CLAMP_TO_INTMAX( 0 ) == 0,
            CLAMP_TO_INTMAX( 1 ) == 1,
            CLAMP_TO_INTMAX( -1 ) == -1,
            CLAMP_TO_INTMAX( -12398 ) == -12398,
            CLAMP_TO_INTMAX( INTMAX_MIN ) == INTMAX_MIN,
            CLAMP_TO_INTMAX( INTMAX_MAX ) == INTMAX_MAX,
            CLAMP_TO_INTMAX( UINTMAX_MAX ) == INTMAX_MAX );
    printf( "`CLAMP_TO_INTMAX()` tests passed!\n" );
}

