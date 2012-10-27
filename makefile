all: stest emptest readfile binaryfile printbin

stest: stest.o employee.o 
	gcc -lreadline -lncurses stest.o employee.o -o stest

stest.o: stest.c employee.h
	gcc -c stest.c

employee.o: employee.c employee.h
	gcc -c employee.c

emptest: emptest.o employee.o
	gcc -lreadline -lncurses emptest.o employee.o -o emptest

emptest.o: emptest.c employee.h
	gcc -c emptest.c

readfile: readfile.o employee.o
	gcc -lreadline -lncurses readfile.o employee.o -o readfile

readfile.o: readfile.c employee.h
	gcc -c readfile.c

binaryfile: binaryfile.o employee.o
	gcc -lreadline -lncurses binaryfile.o employee.o -o binaryfile

binaryfile.o: binaryfile.c employee.h
	gcc -c binaryfile.c

printbin: printbin.o employee.o
	gcc -lreadline -lncurses printbin.o employee.o -o printbin

printbin.o: printbin.c employee.h
	gcc -c printbin.c

debug:
	gcc -g -c stest.c
	gcc -g stest.o -o stestD

debugplus:
	gcc -DDEBUG -g stest.c -c
	gcc -g stest.o -o stestDP

docs: 
	doxygen
	chmod go+r html/*
	cp -p html/* ~/public_html/assig4

clean: 
	rm *~
	rm *.o
	rm -f stest stestD stestDP
	rm -f emptest
	rm -f readfile
	rm -f binaryfile
	rm -f printbin

