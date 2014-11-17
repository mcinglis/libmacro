
#include "../debug.h"


int main( void )
{
    DEBUG( "debugging, la di da" );
    DEBUG( "more debugging with \n a linebreak!" );
    DEBUG( "formatting, oooh: %d %s %g", 390, "test", 99.73 );
    DEBUG( "all the printf formatting modifiers available: %20s", "see?" );
}

