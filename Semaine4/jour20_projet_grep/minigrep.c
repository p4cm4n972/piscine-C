/* minigrep.c - Programme principal */

#include "minigrep.h"

int main(int ac, char **av)
{
	t_options *opts;
	char *pattern;
	int i;

	if (ac < 3)
	{
		fprintf(stderr, "Usage: %s [options] PATTERN FILE...\n", av[0]);
		fprintf(stderr, "Options:\n");
		fprintf(stderr, "  -i  ignore case\n");
		fprintf(stderr, "  -n  line numbers\n");
		fprintf(stderr, "  -c  count only\n");
		fprintf(stderr, "  -v  invert match\n");
		return (1);
	}

	opts = parse_options(&ac, &av);
	pattern = av[1];

	for (i = 2; i < ac; i++)
		search_in_file(av[i], pattern, opts);

	free(opts);
	return (0);
}
