#include "stdafx.h"
#include "Problem1to10.h"

using namespace std;

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

	int limit = (int)4e6;
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

bool Problem3::isPrime(__int64 n){
  __int64 s = (__int64)sqrt((double)n);
  for (__int64 i = 2; i <= s; ++i){
    if (n % i == 0) return false;
  }

  return true;
}

void Problem3::Run(){
  __int64 n = 600851475143;
  __int64 s = (__int64)sqrt((double)n);
  if (s % 2 == 0) s--;

  /*
  for (__int64 i = s; i > 1; i -= 2){
    if ( (n % i == 0) && (isPrime(i)) ){
      cout << "The largest prime factor is " << i << ".\n";
      return;
    }
  }
  cout << "The largest prime factor is itself " << n << ".\n";
  */

  // a better solution
  __int64 last_factor = 1;
  if (n % 2 == 0){
    while(n % 2 == 0){
      n /= 2;
    }
    last_factor = 2;
  }
  __int64 factor = 3;
  while (n > 1 && factor <= s){
    if (n % factor == 0)
    {
      while (n % factor == 0){
        n /= factor;
      }
      last_factor = factor;
    }
    factor += 2;
  }
  if (last_factor == 1){
    last_factor = n;
  }
  cout << "The largest prime factor is " << last_factor << ".\n";
}

bool Problem4::isPalindrome(int n){
  vector<int> numbers;
  while (n > 0){
    numbers.push_back(n % 10);
    n /= 10;
  }
  int i = 0;
  int j = numbers.size() - 1;
  while (i < j){
    if (numbers[i] != numbers[j]) return false;
    i++;
    j--;
  }
  return true;
}

void Problem4::Run(){
  int max_pal = 0;
  for (int i = 100; i < 1000; ++i){
    for (int j = 100; j < 1000; ++j){
      int n = i * j;
      if (isPalindrome(n) && n > max_pal) {
        max_pal = n;
      }
    }
  }
  cout << "The largest palindrome made from the product of two 3-digit numbers is " << max_pal << ".\n";
}

/* Problem 5:
We know that N must
be divisible by each of the primes, p[i], less than or equal to k. But what determines the
exponent, a[i], in the prime factorisation of N is the greatest perfect power of p[i] that
is less than or equal to k. For example, as 2^4 = 16 and 2^5 = 32, we know that a[1]
= 4 as no other numbers, 2 ¡Ü j ¡Ü 20, can contain more than four repeated factors of 2.
Similarly 3^2 = 9 and 3^3 = 27, so a[2] = 2. And for p[i] ¡Ý 5, a[i] = 1.
*/

