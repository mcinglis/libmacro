
#include <stdio.h>

#include "../assert.h"          // ASSERT
#include "../minmax.h"          // MIN, MAX


int main( void )
{
    printf( "Testing MIN of two values...\n" );
    ASSERT( MIN( -1, 1 ) == -1,
            MIN( 0, 1 )  == 0,
            MIN( 1, 1 )  == 1,
            MIN( 0, -1 ) == -1,
            MIN( 9182, -129 ) == -129 );

    printf( "Testing MIN of many values...\n" );
    ASSERT( MIN( 0, 1, 2 ) == 0,
            MIN( 45, 87, -1 ) == -1,
            MIN( -123, -456, -789 ) == -789 );

    printf( "Testing MAX of two values...\n" );
    ASSERT( MAX( -1, 1 ) == 1,
            MAX( 0, 1 )  == 1,
            MAX( 1, 1 )  == 1,
            MAX( 0, -1 ) == 0,
            MAX( 9182, -129 ) == 9182 );

    printf( "Testing MAX of many values...\n" );
    ASSERT( MAX( 0, 1, 2 ) == 2,
            MAX( 45, 87, -1 ) == 87,
            MAX( -123, -456, -789 ) == -123 );
}

