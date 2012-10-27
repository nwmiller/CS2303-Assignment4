/* File employee.h
 *
 * @author Michael Ciaraldi
 * @author Nathaniel Miller
 *
 * Holds Employee struct definition.
 * Functions which operate on Employee structs.
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <curses.h>
#include <term.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


/* define an employee structure */
struct _Employee {
  int salary; // Monthly salary in UK pounds sterling
  char *name; // Pointer to character string holding name of employee.
              // MUST be dynamically allocated from the heap.
  char *dept; /* pointer to character string holding the employee's
		 department name, allocated dynamically from heap */
};

typedef struct _Employee Employee; // For convenience

#define CHARMAX (50)
#define STRMAX (50)

/* define second employee structure, without pointers */
struct _Employee2 {
  int sal; /* salary of employee */
  char name[CHARMAX]; /* name of employee, stored in array */
  char department[STRMAX]; /* dept of employee, stored in array */
};

typedef struct _Employee2 Employee2; /* typedef for ease */


/* function prototypes */

void printEmployee(Employee *employee);

void outputEmployee(FILE *stream, Employee *employee);

Employee* createEmployee(int salary, char* name, char* dept);

Employee* userEmployeee();

int stringCheck(char* stng);

void outEmployee(FILE *stream, Employee *employee);

void free_array(Employee** freeArr, int count);

Employee* readFile(FILE *stream); 

Employee2* binaryEmp( int salary, char* name, char* dept );

void printBinEmp(Employee2 *employee);

Employee2* userBinEmp();

void print_read_emp(Employee2* emp);

void outbinaryEmp(int f_desc, Employee2 *employee);

Employee2* readEmp(int fdesc);


#endif

