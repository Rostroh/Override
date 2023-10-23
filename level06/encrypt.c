#include <stdio.h>

int			main(int argc, char **argv)
{
	int		key;
	int		key2;
	int		i = 0;
	char	*txt;

	if (argc == 1) {
		printf("Provide a login\n");
		return (0);
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
