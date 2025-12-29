/* options.c */

#include "minigrep.h"

t_options *parse_options(int *ac, char ***av)
{
	t_options *opts = malloc(sizeof(t_options));
	int i = 1;

	opts->ignore_case = 0;
	opts->line_numbers = 0;
	opts->count_only = 0;
	opts->invert_match = 0;

	while (i < *ac && (*av)[i][0] == '-')
	{
		if (strcmp((*av)[i], "-i") == 0)
			opts->ignore_case = 1;
		else if (strcmp((*av)[i], "-n") == 0)
			opts->line_numbers = 1;
		else if (strcmp((*av)[i], "-c") == 0)
			opts->count_only = 1;
		else if (strcmp((*av)[i], "-v") == 0)
			opts->invert_match = 1;
		i++;
	}

	*ac -= (i - 1);
	*av += (i - 1);
	return (opts);
}
