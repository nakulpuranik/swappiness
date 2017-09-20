#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <linux/sysctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void validateNumberOfArguement(const int *input);
