/** File binaryfile.c
 *
 * @author Nathaniel Miller
 *
 * Program to demonstrate writing
 * to binary files using low level I/O.
 */

#include "employee.h"

int main() {

#ifdef DEBUG

  printf("\nNow in Debug Mode.\n\n");

#endif

  printf("Starting program binaryfile.\n"); /* notify user of program start */
  
  int k = 0; /* loop counter */
  int ent; /* hold number of entries */
  char* entries = readline("Number of entries needed: "); /* prompt # of entries */
  ent = atoi(entries); /* convert user entered string to integer for use later */

  Employee2** emp = calloc(ent, sizeof(Employee2*)); /* allocate array of ptrs */

  /* loop until the number of entries has been reached */
  while( k < ent) {
    emp[k] = userBinEmp(); /* fill the array with user entered employees */
    k++; /* advance to next element in the array */
  } /* end while */

  /* output the employees to a file */
  printf("About to write to file.\n");
  
  int j = 0; /* second loop counter */

  /* check if opening the file was sucessful */
  if( open("btest.txt", O_WRONLY | O_CREAT) != -1 ) {
    int outfile = open("btest.txt", O_WRONLY | O_CREAT); /* open file */

    /* loop until number of entries has been reached */
    while( j < ent ) {
      outbinaryEmp(outfile, emp[j]); /* write each employee entry to the file */
      j++; /* advance to next entry in the array */
    } /* end while */

    close(outfile); /* close the file */

  } /* end if */

  /* if unable to open file, or error occurs, print errors to stderr */
  else {
    fprintf(stderr, "\nError: unable to open file in program binaryfile.\n");
    fprintf(stderr, "Error Number: %d, Information: %s, ", 
	    errno, strerror( errno ));
  } /* end else */


  printf("Ending program stest.\n");
 
  return 0; /* sucessful termination */
} /* end program main */
