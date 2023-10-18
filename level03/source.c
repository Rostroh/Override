#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void		test(int num, int dood)
{
	num = dood - num;
	if (num <= 0x15)
	{
		num *= 2;
		num += 0x80489f0;
	}
	decrypt(rand());
}

int			main(void)
{
	int		ret;
	//char	buf[0x1c];

	srand(time(NULL));
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &ret);
	test(ret, 0x1337d00d);
}
