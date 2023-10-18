#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int			main(void)
{
	puts("***********************************\n");
	puts("*            -Level00 -           *\n");
	puts("***********************************\n");
	printf("Password:");
	int		nb;

	scanf("%d", &nb);
	if (nb == 0x149c)
	{
		puts("\nAuthenticated!");
		system("/bin/sh");
	}
	else
		puts("\nInvalid Password!");
}
