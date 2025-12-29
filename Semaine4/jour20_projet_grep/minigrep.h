/* minigrep.h - Header du mini-grep */

#ifndef MINIGREP_H
# define MINIGREP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_LINE 4096

// Colors
# define COLOR_RED     "\033[1;31m"
# define COLOR_RESET   "\033[0m"

typedef struct s_options
{
	int ignore_case;
	int line_numbers;
	int count_only;
	int invert_match;
}	t_options;

// search.c
void	search_in_file(const char *filename, const char *pattern, t_options *opts);
int		match_pattern(const char *line, const char *pattern, int ignore_case);

// options.c
t_options	*parse_options(int *ac, char ***av);

// colors.c
void	print_colored_match(const char *line, const char *pattern);

#endif
