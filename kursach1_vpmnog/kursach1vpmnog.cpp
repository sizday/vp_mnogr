// kursach1vpmnog.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "math.h"
#include "conio.h"

struct point {
	float x;
	float y;
	float z;
};
struct plosk {
	struct point A;
	struct point B;
	struct point C;
};

float znak(plosk L, point D)
{
	float znak;
	znak = (D.x - L.A.x)*((L.B.y - L.A.y)*(L.C.z - L.A.z) - (L.C.y - L.A.y)*(L.B.z - L.A.z));
	znak = znak - (D.y - L.A.y)*((L.B.x - L.A.x)*(L.C.z - L.A.z) - (L.B.z - L.A.z)*(L.C.x - L.A.x));
	znak = znak + (D.z - L.A.z)*((L.B.x - L.A.x)*(L.C.y - L.A.y) - (L.B.y - L.A.y)*(L.C.x - L.A.x));
	return znak;
}

void main()
{
	int n, k = 4, pr = 0, genpr = 0, pzn = 0, drk = 0, p = 0, a[10] = { 0 }, pp = 0;
	float  mzn[4] = { 0 };
	struct point masp[10];
	struct plosk L[4];
	printf("Enter number of points = ");
	scanf_s("%d", &n);
	if (n <= 3)
		printf("mnogogrannika net\n");
	else if (n == 4)
		printf("convex\n");
	else
	{
		for (int i = 0; i < n; i++)
		{
			printf("Point %d = ", i + 1);
			scanf_s("%f%f%f", &masp[i].x, &masp[i].y, &masp[i].z);
		}
		L[0].A = masp[0]; L[0].B = masp[1]; L[0].C = masp[2];
		for (int i = 3; i < n; i++)
			if (znak(L[0], masp[i]) != 0)
			{
				pp = 1;
			}
		if (pp == 0)
			printf("mnogogrannika netu\n");
		else
		{
			for (int t = 0; t < n; t++)
			{
				//printf("%f %f %f\n", masp[t].x, masp[t].y, masp[t].z); 
				for (int i = 0; i < k; i++)
					a[i] = i;
				p = k;
				if (k != n)
				{
					while (p >= 1)
					{
						for (int j = 0; j < 4; j++)
							mzn[j] = 0;
						pr = 0; drk = 0; pzn = 1;
						for (int j = 0; j < k; j++)
							if (a[j] == t)
								drk = 1;
						if (drk == 0)
						{
							/*for (int j = 0; j < k; j++)
							printf("%d ",a[j]);
							printf("\n");*/
							L[0].A = masp[a[0]]; L[0].B = masp[a[1]]; L[0].C = masp[a[2]];
							L[1].A = masp[a[0]]; L[1].B = masp[a[1]]; L[1].C = masp[a[3]];
							L[2].A = masp[a[0]]; L[2].B = masp[a[2]]; L[2].C = masp[a[3]];
							L[3].A = masp[a[1]]; L[3].B = masp[a[2]]; L[3].C = masp[a[3]];
							/*for(int j=0;j<4;j++)
							printf("znak(L[%d]),masp[a[%d]] = %f\nznak(L[%d]),masp[%d] = %f\n", j, 3-j, znak(L[j], masp[a[3-j]]), j, t, znak(L[j], masp[t]));*/
							if (((znak(L[0], masp[a[3]]) >= 0) && (znak(L[0], masp[t]) >= 0)) || ((znak(L[0], masp[a[3]]) <= 0) && (znak(L[0], masp[t]) <= 0)))
								mzn[0] = 1;
							if (((znak(L[1], masp[a[2]]) >= 0) && (znak(L[1], masp[t]) >= 0)) || ((znak(L[1], masp[a[2]]) <= 0) && (znak(L[1], masp[t]) <= 0)))
								mzn[1] = 1;
							if (((znak(L[2], masp[a[1]]) >= 0) && (znak(L[2], masp[t]) >= 0)) || ((znak(L[2], masp[a[1]]) <= 0) && (znak(L[2], masp[t]) <= 0)))
								mzn[2] = 1;
							if (((znak(L[3], masp[a[0]]) >= 0) && (znak(L[3], masp[t]) >= 0)) || ((znak(L[3], masp[a[0]]) <= 0) && (znak(L[3], masp[t]) <= 0)))
								mzn[3] = 1;
							for (int j = 0; j < 4; j++)
								if (mzn[j] != 1)
									pzn = 0;
							if (pzn == 1)
								pr = 1;
							if (znak(L[0], masp[a[3]]) == 0)
								pr = 0;
						}
						if (a[k - 1] == (n - 1))
							p = p - 1;
						else
							p = k;
						if (p >= 1)
							for (int i = k; i >= p; i--)
								a[i - 1] = a[p - 1] + i - p + 1;
						if (pr == 1)
						{
							genpr = 1;
							break;
						}
					}
				}
				//printf("%d\n", genpr);
				if (genpr == 1)
				{
					printf("not convex\n");
					break;
				}
			}
			if (genpr == 0)
				printf("convex\n");
		}
	}
	_getch();
}

