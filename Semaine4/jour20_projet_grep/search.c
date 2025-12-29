/* search.c */

#include "minigrep.h"
#include <ctype.h>

int match_pattern(const char *line, const char *pattern, int ignore_case)
{
	if (ignore_case)
		return (strcasestr(line, pattern) != NULL);
	return (strstr(line, pattern) != NULL);
}

void search_in_file(const char *filename, const char *pattern, t_options *opts)
{
	FILE *file;
	char line[MAX_LINE];
	int line_num = 0, count = 0;

	file = fopen(filename, "r");
	if (!file)
	{
		perror(filename);
		return;
	}

	while (fgets(line, MAX_LINE, file))
	{
		line_num++;
		int match = match_pattern(line, pattern, opts->ignore_case);

		if (opts->invert_match)
			match = !match;

		if (match)
		{
			count++;
			if (!opts->count_only)
			{
				if (opts->line_numbers)
					printf("%d:", line_num);
				print_colored_match(line, pattern);
			}
		}
	}

	if (opts->count_only)
		printf("%s: %d\n", filename, count);

	fclose(file);
}
