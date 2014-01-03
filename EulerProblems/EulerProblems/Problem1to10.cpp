#include "stdafx.h"
#include "Problem1to10.h"

void Problem1::Run(){
	printf("Problem 1:\n");

	int max = 1000 - 1;
	int n3 = max / 3;
	int n5 = max / 5;
	int n15 = max / 15;

	int sum3 = 3 * n3 * (n3 + 1) / 2;
	int sum5 = 5 * n5 * (n5 + 1) / 2;
	int sum15 = 15 * n15 * (n15 + 1) / 2;

	printf("The sum is %d.\n", sum3 + sum5 - sum15);
}

void Problem2::Run(){
	printf("Problem 2:\n");

	int limit = 4e6;
	int a1 = 1;
	int a2 = 1;
	int a3 = a1 + a2;
	int sum = 0;
	printf("Fibonacci numbers: %d,%d,%d", a1, a2, a3);
	while (a3 <= limit){
		/* if ((a2 % 2) == 0){
			sum += a2;
		}*/
		sum += a3;
		a1 = a2 + a3;
		a2 = a3 + a1;
		a3 = a1 + a2;
		printf(",%d,%d,%d", a1, a2, a3);
	}

	printf("\nThe sum is %d.\n", sum);

/*There is another beautiful structure hidden beneath this problem:
If we only write the even numbers:
2 8 34 144...
it seems that they obey the following recursive relation: E(n)=4*E(n-1)+E(n-2).
F(n) = F(n-1) + F(n-2)
= F(n-2)+F(n-3)+F(n-2)=2 F(n-2) + F(n-3)
= 2(F(n-3)+F(n-4))+F(n-3))=3 F(n-3) + 2 F(n-4)
= 3 F(n-3) + F(n-4) + F(n-5) + F(n-6)
= 4 F(n-3) + F(n-6)
*/
}