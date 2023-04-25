#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 0;
	int num = 0;
	while (i < argc)
	{
		printf("------------\n");
		printf("argv:%s\n", argv[i]);
		sscanf(argv[i], "%d", &num);
		printf("num:%d\n", num);
		i++;
	}
}
