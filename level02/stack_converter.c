#include <stdio.h>
#include <stdint.h>
#include <string.h>

int			isascii(char *str)
{
	int			n = 7;
	uint32_t	c = 0;
	char		buf[9];

	bzero(buf, 9);
	for (int i = 2; i < strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			c = (c << 4) + str[i] - 'A' + 0xA;
		if (str[i] >= 'a' && str[i] <= 'f')
			c = (c << 4) + str[i] - 'a' + 0xa;
		if (str[i] >= '0' && str[i] <= '9')
			c = (c << 4) + str[i] - '0';
		//printf("%x - %x\n", c, str[i]);
		if (i % 2 != 0 && i != 2)
		{
			buf[n] = c;
			c = 0;
			n--;
		}
	}
	printf("%s", buf);
	return (0);
}
/*
int			isascii(char *str)
{
	uint32_t		c = 0;

	for (int i = 2; i < 18; i++)
	{
		c = c << 8 | str[i];
		printf("%x - %x\n", c, str[i] - '0');
		if (i % 2 == 0 && i != 0)
		{
			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
				;
			else
				;//return (-1);
			c = 0;
		}
	}
	for (int i = 2; i < 16; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))
			;
		else
			return (-1);
	}
	return (0);
}*/

int			main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (isascii(argv[i]) == 0)
		{
			for (int j = 2; j < 18; j++)
				;//printf(" ");
				//printf("%c%c%c%c\n", argv[i][2], argv[i][3], argv[i][4], argv[i][5]);
		}
	}
	return (0);
}
