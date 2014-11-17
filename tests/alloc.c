

#include <stdio.h>
#include <string.h>

#include "../alloc.h"      // ALLOC
#include "../assert.h"     // ASSERT


typedef struct {
    int foo;
    char const * bar;
    void * baz;
} Widget;


int main( void )
{
    printf( "Allocating int...\n" );
    int * const i = ALLOC( int, 8 );
    ASSERT( i != NULL, *i == 8 );

    printf( "Allocating Widget...\n" );
    Widget * const w = ALLOC( Widget, .foo = 0xA3, .bar = "wow" );
    ASSERT( w != NULL, w->foo == 0xA3, strcmp( w->bar, "wow" ) == 0 );

    printf( "Allocating long array...\n" );
    long * const xs = ALLOC( long[ 6 ], 383, 87, -2983 );
    ASSERT( xs != NULL, xs[ 0 ] == 383, xs[ 1 ] == 87, xs[ 2 ] == -2983,
                        xs[ 3 ] == 0,   xs[ 4 ] == 0,  xs[ 5 ] == 0 );

    FREE( i, w, xs );

    printf( "ALLOC() tests passed.\n" );
}


