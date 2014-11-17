
#include <stdio.h>
#include <libtypes/types.h>

#include "../nelem.h"


int main( void )
{
    int const xs[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    printf( "NELEM( xs ) = %zu\n", NELEM( xs ) );

    char const str[] = "testing string for NELEM!";
    printf( "NELEM( str ) = %zu\n", NELEM( str ) );

    typedef struct {
        char const * foo;
        size_t bar;
        ulong baz;
    } Widget;
    Widget const ws[] = { { .foo = "yup" }, { .bar = 123, .baz = 82374 },
                          { .baz = 0 }, { .foo = "huh?", .bar = 2193 } };
    printf( "NELEM( ws ) = %zu\n", NELEM( ws ) );
}

