#include <stdio.h>

char * ft_rev_print( const char *str )
{
    const char *p = str;

    while ( *p ) ++p;

    while ( p != str ) putchar( *--p );  // substitute the call of putchar for write( 1, *--p, 1 )

    putchar( '\n' );  // substitute the call of putchar for write( 1, "\n", 1 )

    return ( char * )str;
}

int main(void) 
{
    ft_rev_print( "I do not fear computers. I fear the lack of them - Isaac Asimov" );

    return 0;
}
