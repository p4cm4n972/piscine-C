/*
 * ft_point.c
 * Manipulation de structures Point (x, y)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_point
{
	int x;
	int y;
}	t_point;

t_point create_point(int x, int y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return (p);
}

void print_point(t_point p)
{
	printf("(%d, %d)", p.x, p.y);
}

double distance(t_point p1, t_point p2)
{
	int dx = p2.x - p1.x;
	int dy = p2.y - p1.y;
	return (sqrt(dx * dx + dy * dy));
}

t_point translate(t_point p, int dx, int dy)
{
	p.x += dx;
	p.y += dy;
	return (p);
}

int main(void)
{
	t_point p1, p2, p3;
	double dist;

	printf("╔════════════════════════════════════════╗\n");
	printf("║        ft_point - Structures           ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	p1 = create_point(0, 0);
	p2 = create_point(3, 4);

	printf("Point 1 : ");
	print_point(p1);
	printf("\n");

	printf("Point 2 : ");
	print_point(p2);
	printf("\n");

	dist = distance(p1, p2);
	printf("Distance entre p1 et p2 : %.2f\n\n", dist);

	printf("Translation de p1 par (5, 3)\n");
	p3 = translate(p1, 5, 3);
	printf("Nouveau point : ");
	print_point(p3);
	printf("\n");

	printf("\n╔════════════════════════════════════════╗\n");
	printf("║           TESTS RÉUSSIS                ║\n");
	printf("╚════════════════════════════════════════╝\n");

	return (0);
}

/*
 * COMPILATION :
 * gcc -Wall -Wextra -Werror -g ft_point.c -o point -lm
 * ./point
 */
