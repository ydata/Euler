#include "stdafx.h"
#include "Problem11to20.h"

using namespace std;

void Problem11::Run() {
  int a[20][20] = 
  {
    { 8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8 },
    { 49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0 },
    { 81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65 },
    { 52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91 },
    { 22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80 },
    { 24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50 },
    { 32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70 },
    { 67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21 },
    { 24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72 },
    { 21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95 },
    { 78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92 },
    { 16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57 },
    { 86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58 },
    { 19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40 },
    { 4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66 },
    { 88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69 },
    { 4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36 },
    { 20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16 },
    { 20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54 },
    { 1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48 }
  };

  int greatest = 0;
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 20; ++j) {
      if (i < 17) {
        int p = a[i][j] * a[i + 1][j] * a[i + 2][j] * a[i + 3][j];
        if (p > greatest) greatest = p;
      }
      if (j < 17) {
        int p = a[i][j] * a[i][j + 1] * a[i][j + 2] * a[i][j + 3];
        if (p > greatest) greatest = p;
      }
      if (i < 17 && j < 17) {
        int p1 = a[i][j] * a[i + 1][j + 1] * a[i + 2][j + 2] * a[i + 3][j + 3];
        int p2 = a[i + 3][j] * a[i + 2][j + 1] * a[i + 1][j + 2] * a[i][j + 3];
        if (p1 > greatest) greatest = p1;
        if (p2 > greatest) greatest = p2;
      }
    }
  }

  cout << "The greatest product of four adjacent numbers is " << greatest << ".\n";
}

void Problem12::Run() {
  int nDivisors = 0;
  int s = 9999;
  while (nDivisors <= 500) {
    s++;
    int n = s * (s + 1) / 2;
    nDivisors = 0;
    for (int i = 1; i <= n; ++i) {
      if (n % i == 0) nDivisors++;
    }
  }
  cout << "The value of the first triangle number to have over five hundred divisors is " << s * (s + 1) / 2 << ".\n";

/*
not efficient, refer to the solution
*/
}

void Problem13::Run() {
  __int64 a[] = {
    37107287533,
    46376937677,
    74324986199,
    91942213363,
    23067588207,
    89261670696,
    28112879812,
    44274228917,
    47451445736,
    70386486105,
    62176457141,
    64906352462,
    92575867718,
    58203565325,
    80181199384,
    35398664372,
    86515506006,
    71693888707,
    54370070576,
    53282654108,
    36123272525,
    45876576172,
    17423706905,
    81142660418,
    51934325451,
    62467221648,
    15732444386,
    55037687525,
    18336384825,
    80386287592,
    78182833757,
    16726320100,
    48403098129,
    87086987551,
    59959406895,
    69793950679,
    41052684708,
    65378607361,
    35829035317,
    94953759765,
    88902802571,
    25267680276,
    36270218540,
    24074486908,
    91430288197,
    34413065578,
    23053081172,
    11487696932,
    63783299490,
    67720186971,
    95548255300,
    76085327132,
    37774242535,
    23701913275,
    29798860272,
    18495701454,
    38298203783,
    34829543829,
    40957953066,
    29746152185,
    41698116222,
    62467957194,
    23189706772,
    86188088225,
    11306739708,
    82959174767,
    97623331044,
    42846280183,
    55121603546,
    32238195734,
    75506164965,
    62177842752,
    32924185707,
    99518671430,
    73267460800,
    76841822524,
    97142617910,
    87783646182,
    10848802521,
    71329612474,
    62184073572,
    66627891981,
    60661826293,
    85786944089,
    66024396409,
    64913982680,
    16730939319,
    94809377245,
    78639167021,
    15368713711,
    40789923115,
    44889911501,
    41503128880,
    81234880673,
    82616570773,
    22918802058,
    77158542502,
    72107838435,
    20849603980,
    53503534226
  };
  __int64 sum = 0;
  for (int i = 0; i < 100; ++i) {
    sum += a[i];
  }

  cout << sum << endl;
}

void Problem14::Run() {
  int largest_count = 1;
  int largest_num = 1;
  for (int i = 999999; i >= 499999; --i) {
    int count = 1;
    __int64 n = i;
    while (n > 1) {
      count++;
      if (n % 2 == 0) {
        n /= 2;
      } else {
        n = 3 * n + 1;
      }
    }
    if (largest_count < count) {
      largest_count = count;
      largest_num = i;
    }
  }
  cout << largest_num << ":" << largest_count << endl;
}

void Problem16::Run() {
  const int MAX_DIGITS = 1000;

  int carry = 0, temp = 0;
  int last = 0;

  vector<int> digits(MAX_DIGITS, 0);

  int sum = 0;

  digits[0] = 2; // 2^1;
  for (int n = 2; n <= 1000; n++) {
    carry = 0;

    for (int i = 0; i <= last; i++) {
      temp = digits[i] * 2  + carry;
      digits[i] = temp % 10;
      carry = temp / 10;
    }

    while (carry > 0) {
      if (last >= MAX_DIGITS) {
        throw "buffer overflow";
      }
      digits[++last] = carry % 10;
      carry /= 10;
    }

    if (n == 1000) {
      for (int i = 0; i <= last; i++) {
        sum += digits[i];
      }
    }
  }

  cout << sum << endl;
}

void Problem18::Run() {
  ifstream infile;
  infile.open("p18.txt", ifstream::in);
  vector< vector<int> > data( 15, vector<int>() );
  for (int i = 0; i < 15; ++i) {
    for (int j = 0; j <= i; ++j) {
      int val;
      infile >> val;
      data[i].push_back(val);
    }
  }
  infile.close();

  vector< vector<int> > max_sums(data);
  for (int i = 13; i >=0; --i) {
    for (int j = 0; j <= i; ++j) {
      if (max_sums[i+1][j] > max_sums[i+1][j+1]) {
        max_sums[i][j] += max_sums[i+1][j];
      } else {
        max_sums[i][j] += max_sums[i+1][j+1];
      }
    }
  }

  cout << max_sums[0][0] << endl;
}