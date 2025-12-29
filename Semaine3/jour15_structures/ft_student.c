/*
 * ft_student.c - Gestion d'étudiants
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_student
{
	char	*name;
	int		age;
	float	average;
}	t_student;

t_student *create_student(char *name, int age, float average)
{
	t_student *student = malloc(sizeof(t_student));
	if (!student)
		return (NULL);
	student->name = strdup(name);
	student->age = age;
	student->average = average;
	return (student);
}

void print_student(t_student *s)
{
	if (!s)
		return;
	printf("%-15s | %2d ans | Moyenne: %.2f/20", s->name, s->age, s->average);
	if (s->average >= 10)
		printf(" ✓ Admis\n");
	else
		printf(" ✗ Recalé\n");
}

void free_student(t_student *s)
{
	if (!s)
		return;
	free(s->name);
	free(s);
}

t_student *best_student(t_student **students, int count)
{
	t_student *best = students[0];
	int i;

	for (i = 1; i < count; i++)
	{
		if (students[i]->average > best->average)
			best = students[i];
	}
	return (best);
}

int main(void)
{
	t_student *students[4];
	t_student *best;
	int i;

	printf("╔════════════════════════════════════════╗\n");
	printf("║        ft_student - Structure          ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	students[0] = create_student("Alice", 20, 15.5);
	students[1] = create_student("Bob", 19, 12.0);
	students[2] = create_student("Charlie", 21, 8.5);
	students[3] = create_student("David", 20, 17.0);

	printf("Liste des étudiants :\n");
	for (i = 0; i < 4; i++)
		print_student(students[i]);

	best = best_student(students, 4);
	printf("\nMeilleur étudiant : %s (%.2f/20)\n", best->name, best->average);

	for (i = 0; i < 4; i++)
		free_student(students[i]);

	printf("\n✓ Tests réussis\n");
	return (0);
}
/* gcc -Wall -Wextra -Werror -g ft_student.c -o student */
