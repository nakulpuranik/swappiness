# In this makefile we are accepting the input from user as a command line
# which gets stored in macro ARGS

all:
	gcc swapiness.c -o FinalExe
run:
	./FinalExe ${ARGS}
usage:
	@echo 'use as : make ARGS="CommandLine_Argument" run'
clean:
	rm FinalExe
