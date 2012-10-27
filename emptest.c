/** File emptest.c
 *
 * @author Nathaniel Miller
 *
 *
 * Program to demonstrate structures, arrays of pointers,
 * dynamic memory allocation, as well as raw & formated I/O.
 */

#include "employee.h"

int main() {

#ifdef DEBUG

  printf("\nNow in Debug Mode.\n\n");

#endif

  printf("Starting program emptest.\n");
  
  int i = 0; /* loop counter */
  char* ent; /* store the # of entries, type char */
  int entries; /* store the number of employee entries needed */

  /* read the user input and store into local var */
  ent = readline("Number of employee entries needed: ");
  entries = atoi(ent); /* convert the string into an integer */
  
  /* allocate an array of pointers to Employees with appropriate size */
  Employee** emp = calloc(entries, sizeof(Employee*));
  Employee** emp2 = emp;
  Employee** emp3 = emp;
  Employee** emp4 = emp;
  
  /* fill the array with ptrs to Employee structs until # entries is reached */
  while( i < entries ) {
    *(emp2++) = userEmployee();
    i++;
  } /* end while */

  
  int j = 0; /* loop counter */

  /* print each struct in the array */
  while( j < entries ) {
    printEmployee(*(emp3++));
    j++;
  } /* end while */


  /* output the employees to a file */
  printf("About to write to file.\n");

  int k = 0; /* loop counter */

  FILE* ofile;

  /* check if opening the file was sucessful */
  if( fopen("emptest.txt", "w") != NULL ) {
    ofile = fopen("emptest.txt", "w"); /* open file if suecessful */
    
    /* out each employee to the file */
    while( k < entries ) {
      outEmployee(ofile, *(emp4++));
      k++;
    } /* end while */

  } /* end if */

  /* if unable to open file, or error occurs, print errors to stderr */
  else {
    fprintf(stderr, "\nError: unable to open file in program stest.\n");
    fprintf(stderr, "Error Number: %d, Information: %s, ", 
	    errno, strerror( errno ));
  } /* end else */

  fclose(ofile); /* close the file */

  free_array(emp, entries);

  printf("Ending program emptest.\n");
 
  return 0; /* sucessful termination */
} /* end function main */


  
