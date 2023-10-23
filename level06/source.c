#include <stdio.h>

int			auth(char *login, int pass)
{
	login[strcspn(login, "\n")] = '\0';
	if (strnlen(login, 0x20) < 5)
		return (1);
	if (ptrace(0, 0, 1, 0) == 0)
	{
		puts(".---------------------------.");
		puts("| !! TAMPERING DETECTED !!  |");
		puts("'---------------------------'");
		return (1);
	}
	txt = (char *)malloc(sizeof(strlen(argv[1])));
	key = argv[1][3] ^ 0x1337 + 0x5eeded;
	while (argv[1][i] != '\0') {
		if (argv[1][i] <= 0x1f)
			return (1);
		key = key + (argv[1][i] ^ key) % 0x539;
		i++;
	}
	return (0);
}

int			main(void)
{
	int		ret;
	char	buf[0x20];

	puts("***********************************");
	puts("*		level06		  *");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(buf, 0x20, stdin);
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", ret);
	if (auth(buf, ret) == 0)
	{
		puts("Authenticated!");
		system("/bin/sh");
		return (0);
	}
	return (1);
}
