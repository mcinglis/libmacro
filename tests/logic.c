
#include <stdio.h>
#include <libtypes/types.h>

#include "../logic.h"

int main( void )
{
    printf( "AND( true, false ) = %d\n", AND( true, false ) );
    printf( "OR( 0, 9283 ) = %d\n", OR( 0, 9283 ) );
    printf( "NAND( OR( 0, false ), 76 ) = %d\n", NAND( OR( 0, false ), 76 ) );
    printf( "NOR( 0, true ) = %d\n", NOR( 982, 37 ) );
    printf( "IMPLIES( -23 < 0, 87 > -22 ) = %d\n",
            IMPLIES( -23 < 0, 87 > -22 ) );

    printf( "ALL( false, false, false, true ) = %d\n",
            ALL( false, false, false, true ) );
    printf( "ANY( false, false, false, true ) = %d\n",
            ANY( false, false, false, true ) );
    printf( "NONE( false, false, false, true ) = %d\n",
            NONE( false, false, false, true ) );

    printf( "ALL( false, false, false, false ) = %d\n",
            ALL( false, false, false, false ) );
    printf( "ANY( false, false, false, false ) = %d\n",
            ANY( false, false, false, false ) );
    printf( "NONE( false, false, false, false ) = %d\n",
            NONE( false, false, false, false ) );

    printf( "ALL( true, true, true, true ) = %d\n",
            ALL( true, true, true, true ) );
    printf( "ANY( true, true, true, true ) = %d\n",
            ANY( true, true, true, true ) );
    printf( "NONE( true, true, true, true ) = %d\n",
            NONE( true, true, true, true ) );
}

