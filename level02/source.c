#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int			main(void)
{
	FILE		*fd;
	int			sz;
	char		user[100];
	char		lvl3[48];
	char		pass[112];

	bzero(user, 100);
	bzero(lvl3, 48);
	bzero(pass, 112);
	fd = fopen("/home/users/level03/.pass", "r");
	if (fd == 0)
	{
		fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
		exit(0);
	}
	sz = fread(lvl3, 1, 41, fd);
	lvl3[strcspn(lvl3, "\n")] = '\0';
	if (sz != 41)
	{
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		exit(0);
	}
	fclose(fd);
	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");
	printf("--[ Username: ");
	fgets(user, 100, stdin);
	user[strcspn(user, "\n")] = '\0';
	printf("--[ Password: ");
	fgets(pass, 100, stdin);
	pass[strcspn(pass, "\n")] = '\0';
	puts("*****************************************");
	if (strncmp(pass, lvl3, 41) == 0)
	{
		printf("Greetings, %s!\n", user);
		system("/bin/sh");
		return (0);
	}
	printf(user);
	puts(" does not have access!");
	exit(1);
}
