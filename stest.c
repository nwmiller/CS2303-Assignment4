/** File stest.c
 *
 * @author Michael Ciaraldi
 * @author Nathaniel Miller
 *
 *
 * Program to demonstrate structures,
 * raw & formated I/O, and functions which
 * operated and manipulate structs.
 */

#include "employee.h"

int main() {

#ifdef DEBUG

  printf("\nNow in Debug Mode.\n\n");

#endif

  printf("Starting program stest.\n");

  // Anybody recognize these names?
  Employee harry; // Declare a local variable (a struct).
  harry.salary = 5000;
  harry.name = strdup("Harry Palmer"); // Make a dynamic copy.
  harry.dept = strdup("N/A");

  Employee bluejay; // Declare a local variable (a struct).
  bluejay.salary = 10000;
  bluejay.name = strdup("Erik Grantby"); // Make a dynamic copy.
  bluejay.dept = strdup("N/A");

  /* create two new employees using creatEmployee */
  Employee* bobby;
  bobby = createEmployee(90000,"Bobby Kotick", "Managment");
  Employee* ian;
  ian = createEmployee(2000,"Ian Curran", "Publishing");

  /* demonstrate the userEmployee function, which prompts user data */
  Employee* emp1 = userEmployee();
  printEmployee(emp1);

  // Output the employees to stdout.
  printEmployee(&harry);
  printEmployee(&bluejay);

  /* print the two newly created employees */
  printEmployee(bobby);
  printEmployee(ian);

  // Output the employees to a file.
  printf("About to write to file.\n");

  FILE* outfile; /* pointer to file */

  /* check if opening the file was sucessful */
  if( fopen("stest.txt", "w") != NULL ) {
    outfile = fopen("stest.txt", "w"); /* open file if suecessful */
    outputEmployee(outfile, &harry);
    outputEmployee(outfile, &bluejay);

    /* include the two newly created employees */
    outEmployee(outfile, bobby);
    outEmployee(outfile, ian);
  } /* end if */

  /* if unable to open file, or error occurs, print errors to stderr */
  else {
    fprintf(stderr, "\nError: unable to open file in program stest.\n");
    fprintf(stderr, "Error Number: %d, Information: %s, ", 
	    errno, strerror( errno ));
  } /* end else */

  fclose(outfile); /* close the file */

  printf("Ending program stest.\n");
 
  return 0; /* sucessful termination */
} /* end program main */
