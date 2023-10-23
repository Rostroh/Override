#include <stdio.h>

typedef struct		s_setup {
	char			msg[140];
	char			usr[40];
	int				len;
}					t_setup;

void		secret_backdoor(void)
{
	char	buf[0x80]

	fgets(buf, 0x80, stdin);
	system(buf);
}

void		set_msg(t_setup com)
{
	char		buf[0x400];

	memset(buf, 0, 0x400);
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(buf, 0x400, stdin);
	strncpy(com.msg, buf, com.len);
}

int			set_username(t_setup com)
{
	int			i;
	char		buf[0x80];

	puts(">: Enter your username");
	printf(">>: ");
	fgets(buf, 0x80, stdin);
	while (i <= 0x28)
	{
		if (buf == 0)
			break;
		com.usr[i] = buf[i];
		i++;
	}
	printf(">: Welcome, %s", com.usr);
	return (0);
}

void		handle_msg(void)
{
	t_setup		com;

	bzero(com.usr, 0x28);
	com.len = 0x8c;
	set_username(com);
	set_msg(com);
	puts(">: Msg sent!");
}

int			main(void)
{
	puts("--------------------------------------------\n\
|   ~Welcome to l33t-m$n ~    v1337        |\n\
--------------------------------------------"
	handle_msg();
	return (0);
}
