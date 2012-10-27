/** File employee.c
 *
 * @author Michael Ciaraldi
 * @author Nathaniel Miller
 *
 * Functions which operate on employees,
 * as well as arrays of employees.
 */

#include "employee.h"

/** Takes an employee and prints out the employee
 * and all its fields.
 *
 * @param *employee The employee to be printed.
 */

void printEmployee(Employee *employee) {
  fprintf(stdout, "Employee. Name = %s , Salary = %d , Department = %s\n",
	  employee->name, employee->salary, employee->dept);
} /* end function printEmployee */


/* Takes a stream and an employee and prints out the employee
 * and adds the employee to the given file.
 *
 * @param *stream The file into which the employee will be added.
 * @param *employee The employee which will be added to the given stream.
 */

void outputEmployee(FILE *stream, Employee *employee) {
  fprintf(stream, "Employee. Name = %s , Salary = %d , Department = %s\n",
	  employee->name, employee->salary, employee->dept);
} /* end function outputEmployee */


/* Takes all the data needed for an Employee struct
 * as parameters, allocates the struct, fills in the data,
 * and finally returns a pointer to the new struct.
 *
 * @param salary The salery of the employee.
 * @param name The name of the employee.
 * @param dept The deparment the employee works in.
 *
 * @return *new_emp A pointer to the newly allocated Employee struct.
 */

Employee* createEmployee( int salary, char* name, char* dept ) {
  
  Employee* new_emp; /* define a pointer to the Employee struct */
  
  char* name_dup = strdup(name); /* duplicate the name string */
  char* dept_dup = strdup(dept); /* duplicate the department string */
  
  new_emp = (Employee*) malloc(sizeof(Employee)); /* malloc memory for struct */

  new_emp->salary = salary; /* set the salary field */
  new_emp->name = name_dup; /* set the name field */
  new_emp->dept = dept_dup; /* set the department field */

  return new_emp; /* return a pointer to the new Employee */
} /*end function createEmployee */


/** Prompots the user to enter an employee's
 * name, salary, and deparment, then allocates a
 * struct and fills it with the user enetered data.
 *
 * @return user_emp The pointer to the newly created employee.
 */

Employee* userEmployee() {
  
  char* emp_name; /* hold entered name */
  char* emp_sal; /* hold entered salary of type string */
  char* emp_dept; /* hold entered deparment */
  int emp_salary; /* hold entered salary of type int */
  
  printf("New Employee Information Entry.\n");
  emp_name = readline("Please enter Employee's name: ");
  emp_sal = readline("Please enter Employee's salary: ");
  while(stringCheck(emp_sal) == 0) {
    free(emp_sal);
    emp_sal = readline("Incorrect Input. Please try again: ");
  }
  emp_salary = atoi(emp_sal);
  emp_dept = readline("Please enter Employee's department: ");

  /* create the Employee struct with the user entered data as params */
  Employee* user_emp = createEmployee( emp_salary, emp_name, emp_dept );

  free(emp_sal); /* free the salary string */
  free(emp_name); /* free the name string */
  free(emp_dept); /* free the department string */

  return user_emp; /* return the newly allocated Employee with user data */
} /* end function userEmployee */


/* Checks if a string contains negative numbers,
 * or none digit (numeric) values.
 *
 * @param stng The string to be checked.
 *
 */

int stringCheck(char* stng) { 

  /* loop until null terminating char is reached */
  for(; *stng != '\0';) {
    
    /* check if each char is non-numeric or negative */
    if(!isdigit(*stng) || *stng < '0') {
      
      return 0; /* return 0 if invalid input is encounter */
    } /* end if */

    *(stng++); /* advance to next char in string */
  } /* end for */

  return 1; /* return 1 otherwise */
} /* end function stringCheck */


/* Takes a stream and an employee and prints out the employee
 * and adds the employee to the given file, including all fields.
 *
 * @param *stream The file into which the employee will be added.
 * @param *employee The employee which will be added to the given stream.
 */

void outEmployee(FILE *stream, Employee *employee) {
  fprintf(stream, "Employee. Name = %s , Salary = %d , Department = %s\n",
	  employee->name, employee->salary, employee->dept);
} /* end function outEmployee */

  
/** Takes an array of pointers to struct of type User
 * and de-allocates (frees) all the structs pointed to.
 *
 * @param freeArr The array of pointers to struct to be freed.
 */

void free_array(Employee** freeArr, int count ) {
 
  int i = 0; /* loop counter */
  Employee** arr_dup = freeArr; /* duplicate ptr to array of ptrs */

  /* loop until all the pointers (elements) in the array have been processed */
  while( i < count ) {
    free(&(*((Employee*)arr_dup)->name));
    free(&(*((Employee*)arr_dup)->dept));
    free(*(arr_dup++)); /* use free() to de-allocate the pointers */
    i++; /* advance to next ptr in the array */
  } /* end while */

} /* end function free_array */ 


/** Reads one employee's data from a text file,
 * in the proper format and creates an employee
 * from the read-in data.
 *
 * @param *stream The file to be read from.
 *
 * @return read_emp The employee read from the file.
 */

Employee* readFile(FILE *stream) {

  /* Reading Section */

  /* Employee Name Reading */
  char j1[15]; /* stores unneeded text */
  char j2[15]; /* stores unneeded text */
  char j3[5]; /* stores unneeded text */

  char name[STRMAX]; /* store name data from text */

  /* read in data from the file piece by piece using fscanf */
  fscanf(stream, "%s", j1); /* read unneeded text */
  fscanf(stream, "%s", j2); /* read unneeded text */
  fscanf(stream, "%s", j3); /* read unneeded text */

  fscanf(stream, "%s", name); /* read name data from text */

  /* Employee Salary Reading */
  char j4[15]; /* stores unneeded text */
  char j5[15]; /* stores unneeded text */
  char j6[5]; /* stores unneeded text */

  char salary[STRMAX]; /* store salary data from text */

  /* read in data from the file piece by piece using fscanf */
  fscanf(stream, "%s", j4); /* read unneeded text */
  fscanf(stream, "%s", j5); /* read unneeded text */
  fscanf(stream, "%s", j6); /* read unneeded text */

  fscanf(stream, "%s", salary); /* read salary data from text */
  //printf("The name read: %s\n", &salary);


  /* Employee Department Reading */
  char j7[15]; /* stores unneeded text */
  char j8[15]; /* stores unneeded text */
  char j9[5]; /* stores unneeded text */

  char department[STRMAX]; /* stores department data from text */

  /* read in data from the file piece by piece using fscanf */
  fscanf(stream, "%s", j7); /* read unneeded text */
  fscanf(stream, "%s", j8); /* read unneeded text */
  fscanf(stream, "%s", j9); /* read unneeded text */

  fscanf(stream, "%s", department); /* read department data from text */
  //printf("The name read: %s\n", &department);

 
  /* Processing Section */
  int sal; /* store the read in salary data of type int */
  sal = atoi(salary); /* convert read-in salary to integer */

  Employee* read_emp; /* the employee with the data read from the file */

  read_emp = createEmployee(sal, name, department); /* create the employee */

  return read_emp; /* return the employee created with the read data */
  
} /* end function readFile */


/* Takes all the data needed for an Employee struct
 * as parameters, allocates the struct, fills in the data,
 * and finally returns a pointer to the new struct.
 *
 * @param salary The salery of the employee.
 * @param name The name of the employee.
 * @param dept The deparment the employee works in.
 *
 * @return bin_emp A pointer to the newly allocated Employee struct.
 */

Employee2* binaryEmp( int salary, char* name, char* dept ) {

  Employee2 *bin_emp; /* define a pointer to the Employee struct */
  
  bin_emp = (Employee2*) malloc(sizeof(Employee2)); /* malloc mem for struct */

  bin_emp->sal = salary; /* set the salary field */
  strcpy(bin_emp->name, name); /* set the name field */
  strcpy(bin_emp->department, dept); /* set the department field */

  return bin_emp; /* return a pointer to the new Employee */
} /*end function binaryEmp */


/** Takes an employee and prints out the employee
 * and all its fields.
 *
 * @param *employee The employee to be printed.
 */

void printBinEmp(Employee2 *employee) {
  fprintf(stdout, "Employee. Name = %s , Salary = %d , Department = %s\n",
	  employee->name, employee->sal, employee->department);
} /* end function printEmployee */ 


/** Prompots the user to enter an employee's
 * name, salary, and deparment, then allocates a
 * struct (Employee2) and  fills it with the user enetered data.
 *
 * @return ubin_emp The newly created employee.
 */

Employee2* userBinEmp() {
  
  int emp_salary = 0; /* hold entered salary of type int */
  
  printf("New Employee Information Entry.\n");
  char* emp_name = readline("Please enter Employee's name: ");
  char* emp_sal = readline("Please enter Employee's salary: ");
  while(stringCheck(emp_sal) == 0) {
    free(emp_sal);
    emp_sal = readline("Incorrect Input. Please try again: ");
  }
  emp_salary = atoi(emp_sal);
  char* emp_dept = readline("Please enter Employee's department: ");

  /* create the Employee struct with the user entered data as params */
  Employee2 *ubin_emp = binaryEmp( emp_salary, emp_name, emp_dept );

  free(emp_sal); /* free the salary string */
  free(emp_name); /* free the name string */
  free(emp_dept); /* free the department string */

  return ubin_emp; /* return the newly allocated Employee with user data */
} /* end function userEmployee */


/* Prints out an employee struct
 * to standard output (the screen).
 *
 * @param emp  The employee to be printed.
 */

void print_read_emp(Employee2* emp) {
  
  /* print out the employee struct and all its data */
  fprintf(stdout, "Employee. Name = %s, Salary = %d, Department = %s\n",
	  emp->name, emp->sal, emp->department);
} /* end function print_read_emp */


/** Stores employees in a binary file,
 * with a fixed number of bytes for each employee.
 *
 * @param int f_desc The file descriptor value.
 * @param *employee The employee struct to be written to the file
 */

void outbinaryEmp(int f_desc, Employee2 *employee) {
  
  /* write the employee's name to the file */
  write(f_desc, employee->name, CHARMAX);

  /* write the employee's salary to the file */
  int* salary = &employee->sal; /* ensure salary is of proper type */
  write(f_desc, salary, sizeof(int));

  /* write the employee's department to the file */
  write(f_desc, employee->department, STRMAX);
} /* end function outbinaryEmp */


/* Reads in an employee from a binary file,
 * and prints the employee to standard output.
 *
 * @param fdesc The file descriptor.
 *
 * @return read_emp The employee read from the file.
 */

Employee2* readBin( int fdesc ) {
  
  char* name = malloc(CHARMAX); /* allocate space for the name */
  int* salary = malloc(sizeof(int)); /* allocate space for the salary */
  char* department = malloc(STRMAX); /* allocate space for the department */

  read(fdesc, name, CHARMAX); /* read the employee's name */
  read(fdesc, salary, sizeof(int)); /* read the employee's salary */
  read(fdesc, department, STRMAX); /* read the employee's department */

  /* create the employee struct using the data read from file */
  Employee2* read_emp = binaryEmp( *salary, name, department );

  free(name); /* free the allocated name */
  free(salary); /* free the allocated salary */
  free(department); /* free the allocated department */

  return read_emp; /* return the ptr to created employee struct */
} /* end function readBinEmp */
  


