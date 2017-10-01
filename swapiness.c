/**
* change the current swappiness value.
*/
#include "header.h"

int _sysctl(struct __sysctl_args *args );
void currentSwappinessValue();
void changeSwappinessValue(int *swappinessValue);
void validateNumberOfArguement(const int *input);

#define SWAPPINESS_NAME_SIZE 256

int main(int argc, char *argv[]){
	
	int *inputArg;
	int arg;
	validateNumberOfArguement(&argc);
	currentSwappinessValue();
	arg = (atoi(argv[1]));
	inputArg = &arg;
	changeSwappinessValue(inputArg);
	currentSwappinessValue();	

	return 0;
}

void validateNumberOfArguement(const int *input){
	if(*input != 2)
	{
		printf("Error : Not sufficient arguments\n Passed arguments %d",*input);
	}
}

void changeSwappinessValue(int *swappinessValue){
	struct __sysctl_args args;
	int name[] = { CTL_VM };
	int ret = 0;
	char swapValue[SWAPPINESS_NAME_SIZE];
	size_t oldSwappinessLnt;

	memset(&args, 0, sizeof(struct __sysctl_args));
	args.name = name;
   	args.nlen = sizeof(name)/sizeof(name[0]);
   	args.oldval = swapValue;
   	args.oldlenp = &oldSwappinessLnt;
   	args.newval = &swappinessValue;
   	args.newlen = sizeof(swappinessValue);


	if ((syscall(SYS__sysctl, &args)) == -1) {
		perror("sysctl failed");
	}


	printf("This machines Old swap Value : %s",swapValue);
}

void currentSwappinessValue(){
	int fileDesc;
	int ret;
	char buff[512];

	bzero(buff,sizeof(buff));
	//path to the 
	strcpy(buff,"/proc/sys/vm/swappiness");
	
	fileDesc = open(buff,O_RDONLY);
	if(ret == -1){
		perror("openSysCall::\n");
		return;
	}
	//set buffer to \0
	bzero(buff,sizeof(buff));

	strcpy(buff,"Swappiness current value is \0");
	write(1,buff,sizeof(buff));		// write buffers content to the screen
	bzero(buff,sizeof(buff));		//clear the buffer with the \0
	//read the actual information form the file 
	while(( ret =read(fileDesc,buff,sizeof(buff))) != 0){
		write(1,buff,ret);
	}
	write(1,"\n",sizeof("\n"));
	close(fileDesc);
}