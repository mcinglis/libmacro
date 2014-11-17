
#include "../require.h"


int main( void )
{
    REQUIRE( "these", "requirements", "are", "truthy" );
    REQUIRE( "just", "like this", 21938 * 3 > 12 );
    REQUIRE( 1, 1, 1, 1, 1, 1, 1, 1, 1 );
    // But this is falsy:
    REQUIRE( 123, "falsy incoming" == NULL, 456 );
}


