#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int		main(void)
{
	char	buf[0x20] = {0};
	int		status = 0;
	int		trace;
	pid_t	child = fork();
	
	if (child == 0)
	{
		prctl(1, 1);
		ptrace(0, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(buf);
	}
	else {
		wait(&status);
		if (WIFEXITED(status)) {
			if (status < 0)
			{
				puts("child is exiting...");
				return (0);
			}
			else
			{
				if ((trace = ptrace(3, child, 0x2c, 0)) == 0xb)
				{
					puts("child is exiting...");
					kill(child, 0x9);
				}
			}
			return (0);
		}
	}
	return (0);
}
