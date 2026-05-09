#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
int compare_by_area (const void* a, const void* b) {
    const triangle* ia = (const struct triangle *)a;
    const triangle* ib = (const struct triangle *)b;

    // compute area
    double p_1 = (ia->a + ia->b + ia->c) / 2.0;
    double p_2 = (ib->a + ib->b + ib->c) / 2.0;

    double p1_a = p_1 - ia->a;
    double p1_b = p_1 - ia->b;
    double p1_c = p_1 - ia->c; 

    double p2_a = p_2 - ib->a;
    double p2_b = p_2 - ib->b;
    double p2_c = p_2 - ib->c;

    double t1_area = sqrt(p_1 * p1_a * p1_b * p1_c);
    double t2_area = sqrt(p_2 * p2_a * p2_b * p2_c);

    if (t1_area < t2_area) return -1;
    if (t1_area > t2_area) return 1;
    return 0;
}

void sort_by_area(triangle* tr, int n) {
    qsort(tr, n, sizeof(triangle), compare_by_area);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}