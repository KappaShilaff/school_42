#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 512
int main(int c, char **v)
{
	char *buf;
	size_t len =0;
	FILE * fd = fopen(v[1], "r");
	while (-1 != getline(&buf, &len, fd))
	 {
		 printf("%s", buf);
	 }
}
