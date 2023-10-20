#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void		decrypt(int n)
{
	char			cyph[] = "Q}|u`sfg~sf{3a|}";
	unsigned int	i;
	unsigned int	len;

	len = strlen(cyph);
	i = 0;
	while (i < len)
	{
		cyph[i] = cyph[i] ^ n;
		i++;
	}
	if (strncmp(cyph, "Congratulations!", 17) == 0)
		system("/bin/sh");
	else
		puts("\nInvalid Password");
}

void		test(unsigned int input, unsigned int num)
{
	unsigned int		diff;

	diff = num - input;
	switch (diff){
	case 1:
		decrypt(diff);
		return ;
	case 2:
		decrypt(diff);
		return ;
	case 3:
		decrypt(diff);
		return ;
	case 4:
		decrypt(diff);
		return ;
	case 5:
		decrypt(diff);
		return ;
	case 6:
		decrypt(diff);
		return ;
	case 7:
		decrypt(diff);
	return ;
	case 8:
		decrypt(diff);
		return ;
	case 9:
		decrypt(diff);
		return ;
	case 17:
		decrypt(diff);
		return ;
	case 18:
		decrypt(diff);
		return ;
	case 19:
		decrypt(diff);
		return ;
	case 20:
		decrypt(diff);
		return ;
	case 21:
		decrypt(diff);
		return ;
	}
	decrypt(rand());
}

int			main(void)
{
	int		ret;

	srand(time(NULL));
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &ret);
	test(ret, 0x1337d00d);
	return (0);
}
