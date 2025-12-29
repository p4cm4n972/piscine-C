/* colors.c */

#include "minigrep.h"

void print_colored_match(const char *line, const char *pattern)
{
	const char *match;

	match = strstr(line, pattern);
	if (match)
	{
		fwrite(line, 1, match - line, stdout);
		printf(COLOR_RED"%s"COLOR_RESET, pattern);
		printf("%s", match + strlen(pattern));
	}
	else
		printf("%s", line);
}
