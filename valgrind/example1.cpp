#include <stdlib.h>
#include <string.h>

int main (int argc , char * argv [])
{
		char * course_name = " TI2725 -C"; // " TI2725 -C" + ’\0 ’

		char course_name_cpy1 [8];
		strcpy ( course_name_cpy1 , course_name );

		char * course_name_cpy2 = (char *) malloc ( sizeof ( char ) * 8) ;
		strcpy ( course_name_cpy2 , course_name );

		free ( course_name_cpy2 );
  	 return 0;
}