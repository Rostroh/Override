#include <stdio.h>

void		main(void)
{
	char	buf[0x64];

	fgets(buf, 0x64, stdin);
	for (int i = 0; i < strlen(buf); i++)
	{
		if (buf[i] > '@' && buf[i] <= 'Z')
			buf[i] += 0x20;
	}
	printf(buf);
}
