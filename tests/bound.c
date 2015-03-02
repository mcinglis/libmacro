
#include <stdio.h>
#include <sys/types.h>

#include "../bound.h"


int
main( void )
{

    printf( "min of `time_t`: %jd\n",
            ( intmax_t ) MIN_BOUND( ( time_t ) 0 ) );
    printf( "min of `off_t`: %jd\n",
            ( intmax_t ) MIN_BOUND( ( off_t ) 0 ) );
    printf( "min of `pid_t`: %jd\n",
            ( intmax_t ) MIN_BOUND( ( pid_t ) 0 ) );
    printf( "min of `dev_t`: %jd\n",
            ( intmax_t ) MIN_BOUND( ( dev_t ) 0 ) );
    printf( "min of `blkcnt_t`: %jd\n",
            ( intmax_t ) MIN_BOUND( ( dev_t ) 0 ) );
    printf( "min of `uid_t`: %jd\n",
            ( intmax_t ) MIN_BOUND( ( uid_t ) 0 ) );
    printf( "min of `size_t`: %jd\n",
            ( intmax_t ) MIN_BOUND( ( size_t ) 0 ) );
    printf( "min of `ssize_t`: %jd\n",
            ( intmax_t ) MIN_BOUND( ( ssize_t ) 0 ) );
    printf( "min of `intmax_t`: %jd\n",
            ( intmax_t ) MIN_BOUND( ( intmax_t ) 0 ) );
    printf( "min of `uintmax_t`: %jd\n",
            ( intmax_t ) MIN_BOUND( ( uintmax_t ) 0 ) );

    printf( "\n" );
    printf( "max of `time_t`: %ju\n",
            ( uintmax_t ) MAX_BOUND( ( time_t ) 0 ) );
    printf( "max of `off_t`: %ju\n",
            ( uintmax_t ) MAX_BOUND( ( off_t ) 0 ) );
    printf( "max of `pid_t`: %ju\n",
            ( uintmax_t ) MAX_BOUND( ( pid_t ) 0 ) );
    printf( "max of `dev_t`: %ju\n",
            ( uintmax_t ) MAX_BOUND( ( dev_t ) 0 ) );
    printf( "max of `blkcnt_t`: %ju\n",
            ( uintmax_t ) MAX_BOUND( ( dev_t ) 0 ) );
    printf( "max of `uid_t`: %ju\n",
            ( uintmax_t ) MAX_BOUND( ( uid_t ) 0 ) );
    printf( "max of `size_t`: %ju\n",
            ( uintmax_t ) MAX_BOUND( ( size_t ) 0 ) );
    printf( "max of `ssize_t`: %ju\n",
            ( uintmax_t ) MAX_BOUND( ( ssize_t ) 0 ) );
    printf( "max of `intmax_t`: %ju\n",
            ( uintmax_t ) MAX_BOUND( ( intmax_t ) 0 ) );
    printf( "max of `uintmax_t`: %ju\n",
            ( uintmax_t ) MAX_BOUND( ( uintmax_t ) 0 ) );

}

