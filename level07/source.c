#include <stdio.h>

uint32_t		get_unum()
{
	uint32_t	ret = 0;

	fflush(stdout);
	scanf("%u", ret);
	return (ret);
}

int			store_number(uint32_t *tab)
{
	int			idx = 0;
	uint32_t	ret = 0;

	printf(" Number: ");
	ret = get_unum();
	printf(" Index: ");
	idx = get_unum();
	if ((idx % 3 == 0) || (idx >> 0x18 == 0xb7))
	{
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return (0);
	}
	tab[idx] = ret;
	return (0);
}

int			read_number(uint32_t *tab)
{
	uint32_t		ret = 0;

	printf(" Index: ");
	ret = get_unum();
	ret = ret << 2;
	printf(" Number at data[%u] is %u\n", ret, tab[ret]);
	return (0);
}

int			main(int argc, char **argv, char **env)
{
	char		**av = argv;
	char		**ev = env;
	char		buf[0x14];
	uint32_t	tab[100];
	int			ret = 0;

	while (*av != 0)
	{
		memset(*av, 0, strlen(*av));
		av++;
	}
	while (*ev != 0)
	{
		memset(*ev, 0, strlen(*ev));
		ev++;
	}
	puts("----------------------------------------------------\n  Welcome to wil's crappy number storage service!   \n----------------------------------------------------\n Commands:                                          \n    store - store a number into the data storage    \n    read  - read a number from the data storage     \n    quit  - exit the program                        \n----------------------------------------------------\n   wil has reserved some storage :>                 \n----------------------------------------------------\n");
	while (1)
	{
		printf("Input command: ");
		fgets(buf, 0x14, stdin);
		buf[strlen(buf) - 1] = 0;
		if (strncmp(buf, "store", 5) == 0)
			ret = store_number(tab);
		else if (strncmp(buf, "read", 4) == 0)
			ret = read_number(tab);
		else if (strncmp(buf, "quit", 4) == 0)
			return (0);
		if (ret == 0)
			printf(" Completed %s command successfully\n", buf);
		else
			printf(" Failed to do %s command\n", buf);
		buf[0] = 0;
		buf[1] = 0;
		buf[2] = 0;
		buf[3] = 0;
		buf[4] = 0;
	}
	return (0);
}
