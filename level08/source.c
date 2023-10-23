#include <stdio.h>

int64_t log_wrapper(FILE *fd, char *str, char *file)
{
	char	buf[264];

	strcpy(buf, str);
	snprintf(buf + strlen(buf), 0xfe - strlen(buf), file);
	*(buf + strcspn(buf, "\n")) = 0;
	fprintf(buf, "LOG: %s\n", buf);
	return (0);
}

int			main(int argc, char **argv)
{
	int		file;
	FILE	*fd;
	FILE	*logs;
	char	name[104];
	char	buf;

	if (argc != 2)
		printf("Usage: %s filename\n", argv[0]);
	if (!(logs = fopen("./backups/.log", "w")))
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	log_wrapper(logs, "Starting back up: ", argv[1]);
	if (!(fd = fopen(argv[1], "r")))
	{
		printf("ERROR: Failed to open %s\n", argv[1]);
		exit(1);
	}
	strncpy(name, "./backup/", 0xb);
	strncat(name, argv[1], strlen(argv[1]) + 1);
	if (!(file = open(name, 0xc1, 0x1b0) < 0))
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
		exit(1);
	}
	while((buf = fgetc(fd)) != EOF)
		write(file, &buf, 1);
	log_wrapper(logs, "Finished back up ", argv[1]);
	fclose(fd);
	close(file);
	return (0);
}
