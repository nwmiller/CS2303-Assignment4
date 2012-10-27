/** file readfile.c
 *
 * @author Nathaniel Miller
 *
 * Program to demonstrate reading from files,
 * storing data into structs and arrays.
 */

#include "employee.h"

#define MAX_EMPS (2) /* the max # of employees to be read from the file */

int main() {

#ifdef DEBUG

  printf("\nNow in Debug Mode.\n\n");

#endif

  printf("Starting program readfile.\n"); /* notify user of program start */

  printf("About to read from file.\n"); /* notify user of file reading */
  
  FILE* infile; /* pointer to the file to be read from */
  int i = 0; /* loop counter for read loop */
  int j = 0; /* second loop counter for print loop */

  
  /* allocate an array with enough space to fit the number of employees read */
  Employee** readArr = calloc(MAX_EMPS, sizeof(Employee*));
  Employee** readArr2 = readArr;
  Employee** readArr3 = readArr;

  /* check if opening the file was sucessful */
  if( fopen("emptest.txt", "r") != NULL ) {
    infile = fopen("emptest.txt", "r"); /* open file if no errors occured */
    
    /* read from the file until the max # of employees has been read */
    while( i < MAX_EMPS ) {
      *(readArr++) = readFile(infile); /* read each employee & store in arr */
      i++; /* advance to next line in file to read another employee */
    } /* end while */

  } /* end if */
  
  /* if unable to open file, or errors occur, print errors to stderr */
  else {
    fprintf(stderr, "\nError: unable to open file in program readfile.\n");
    fprintf(stderr, "Error Number: %d, Information: %s, ", 
	    errno, strerror( errno ));
  } /* end else */

  fclose(infile); /* close the file now that reading is complete */

  /* print each employee struct after file reading is complete */
  while( j < MAX_EMPS ) {
    printEmployee(*(readArr2++));
    j++;
  } /* end while */
  
  printf("Ending program readfile.\n"); /* notify user of program end */

  return 0; /* indicate sucessful termination */
} /* end program main */
