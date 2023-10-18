#include <strings.h>
#include <stdio.h>

char	a_user_name[256];

int		verif_user_name(void)
{
	puts("verifying username....\n");
	return (strncmp(a_user_name, "dat_will", 0x7));
}

int		verif_user_pass(char *pass)
{
	return (strncmp(pass, "admin", 0x5));
}

int		main(void)
{
	int		ret;
	char	pass[80];

	bzero(pass, 0x10);
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 0x100, stdin);
	if (verif_user_name() != 0)
	{
		puts("nope, incorrect username...\n");
		return (1);
	}
	puts("Enter Password: ");
	fgets(pass, 0x64, stdin);
	ret = verif_user_pass(pass);
	if (ret == 0)
	{
		puts("nope, incorrect password...\n");
		return (1);
	}
	return (0);
}
