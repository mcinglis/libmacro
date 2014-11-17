
#include <libtypes/types.h>
#include "../assert.h"

int main( void )
{
    ASSERT( 1, true, 2938, -12938 );
    ASSERT( "this is non null" );
    ASSERT( &( int ){ 5 } );
    ASSERT( 1 == 1, 2398 > 298731, "should never get here" == NULL );
    // This kills the process.
}

