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

void Problem6::Run() {
  __int64 sum_of_squares = 0;
  __int64 square_of_sum = 0;
  for (int i = 1; i <= 100; ++i) {
    sum_of_squares += i * i;
    square_of_sum += i;
  }
  square_of_sum *= square_of_sum;
  cout << "The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is " << square_of_sum - sum_of_squares << ".\n";
}

void Problem7::Run() {
  __int64 i = 11;
  int count = 5;
  while (count < 10001) {
    i += 2;
    while (!Problem3::isPrime(i)) {
      i += 2;
    }
    count++;
  }
  cout << "The 10 001st prime number is " << i << ".\n";
}

void Problem8::Run() {
  char* str = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
  int l = strlen(str);
  int greatest = 0;
  int i = 0;
  while (i + 4 < l) {
    vector<int> digits;
    int j = i;
    while (j < i + 5) {
      int val = str[j] - '0';
      if (val) {
        digits.push_back(val);
        j++;
      } else {
        break;
      }
    }
    if (j < i + 5) {
      i = j + 1;
      continue;
    }

    _ASSERT (digits.size() == 5);
    int product = 1;
    for (int k = 0; k < 5; ++k) {
      product *= digits[k];
      if (product > greatest) {
        greatest = product;
      }
    }
    i++;
  }
  cout << "The greatest product of five consecutive digits is " << greatest << ".\n";
}

void Problem9::Run() {
  for (int a = 3; a < 333; ++a) {
    for (int b = a+1; b < (999-a)/2; ++b) {
      int c = 1000 - a - b;
      if (a*a + b*b == c*c) {
        printf("a=%d,b=%d,c=%d,abc=%d.\n", a, b, c, a*b*c);
      }
    }
  }
}

void Problem10::Run() {
  __int64 i = 11;
  __int64 sum = 28;
  while (i < 2000000) {
    i += 2;
    while (!Problem3::isPrime(i)) {
      i += 2;
    }
    sum += i;
  }
  cout << "The sum of all the primes below two million is " << sum - i << ".\n";

}
