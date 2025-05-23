#include <fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	struct stat statbuf;
	/* turn on others-execute and turn off group-execute */
	if (stat("foo", &statbuf) < 0)
		printf("stat error for foo");

	if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_IXOTH) < 0)
		printf("chmod error for foo");

	/* set absolute mode to "rw-r--r--" */
	if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
		printf("chmod error for bar");
	
	return 0;
}