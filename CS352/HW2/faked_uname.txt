#include <sys/utsname.h>
#include <stdio.h>

int uname(struct utsname *buf);
struct utsname unameData;

int main(int argc, char *argv[])
{
	uname(&unameData);
	if(strcmp(argv[1], "--machine") == 0)
	{
		printf("%s\n", unameData.machine);
	}
	else if(strcmp(argv[1], "--operating-system") == 0)
	{
		printf("%s\n", unameData.sysname);
	}
	else if(strcmp(argv[1], "--kernel-release") == 0)
	{
		printf("%s\n", unameData.release);
	}
	return 0;
}
