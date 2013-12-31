/*
 * db_strerror --
 *     ANSI C strerror(3) for DB.
 */
#include <string.h>

char *
db_strerror(error)
       int error;
{
       if (error == 0)
               return ("Successful return: 0");
       if (error > 0)
               return (strerror(error));

}
