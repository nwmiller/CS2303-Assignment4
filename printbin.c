/** File printbin.c
 *
 * @author Nathaniel Miller
 *
 * Program to read from a binary file and print
 * that data to standard output.
 */

#include "employee.h"

#define MAX (5) /* max number of employees to be read from file */

int main() {

#ifdef DEBUG

  printf("\nNow in Debug Mode.\n\n");

#endif

  printf("Starting program printbin.\n"); /* notify user of start or program */

  Employee2* read[MAX]; /* allocate an array with MAX size */
  int j = 0; /* loop counter */

  printf("About to read from file.\n"); /* notify of file reading */

  /* check if opening file was sucesseful */
  if( open("btest.txt", O_RDONLY) != -1 ) {
    int rfile = open("btest.txt", O_RDONLY); /* open the file */

    /* loop until max number of employees is reached */
    while( j < MAX ) {
      read[j] = readBin(rfile); /* read each employee from the file */
      j++; /* advance to next employee */
      
      /* check if nothing is there to read */
      if(read[j] ==  NULL) {
	break; /* end loop if nothing is there to read */
      } /* end if */
      print_read_emp(read[j]); /* print each read employee */
    } /* end while */
    if(read[j] != NULL) {
      fprintf(stderr, "Max number of employees read, excess data not read.\n");
      close(rfile); /* close the file */
    } /* end if */
    close(rfile); /* close the file */
    /* if file did not open sucessfully */
  } else {
    fprintf(stderr, "\nError: unable to open file in program stest.\n");
    fprintf(stderr, "Error Number: %d, Information: %s, ", 
	    errno, strerror( errno ));
  } /* end else */
} /* end function printbin */


    
    
