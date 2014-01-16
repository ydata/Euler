#include "stdafx.h"
#include "Problem21to30.h"

using namespace std;

void Problem21::Run() {
  int amicable_num_sum = 0;
  for (int i = 2; i < 10000; ++i) {
    int sd1 = getDivisorSum(i);
    int sd2 = getDivisorSum(sd1);

    if ( sd1 != sd2 && i == sd2 )  amicable_num_sum += i;
  }

  cout << amicable_num_sum << endl;
}

int Problem21::getDivisorSum(int n) {
  int sum = 1;
  int upper = n / 2;
  for (int i = 2; i <= upper; ++i) {
    if (n % i == 0) sum += i;
  }
  return sum;
}

void Problem22::Run() {
  ifstream infile;
  infile.open("names.txt", ifstream::in);
  string line;
  vector<string> names;
  char seps[] = "\",\r\n\t";
  char* token;
  char* next;
  while ( getline(infile, line) ) {
    int length = line.size();
    char* ch_line = new char[length+1];
    strcpy_s(ch_line, length+1, line.c_str());  // the second para must include the null terminator
    token = strtok_s(ch_line, seps, &next);
    while (token != NULL) {
      names.push_back( string(token) );
      token = strtok_s(NULL, seps, &next);
    }
  }
  sort(names.begin(), names.end());

  int total_sum = 0;
  for (size_t i = 0; i < names.size(); ++i) {
    int sum = 0;
    for (size_t j = 0; j < names[i].size(); ++j) {
      sum += (names[i].at(j) - 'A' + 1);
    }
    total_sum += (i + 1) * sum;
  }

  cout << total_sum << endl;
}

void Problem24::Run() {
/*
  m_data = string("0123456789");
  m_flags.resize(m_data.size(), false);
  m_one = string();
  permute();
  cout << m_permutation[m_permutation.size() - 1] << endl;
*/
  unsigned n = 1000000 - 1;
  char digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8' , '9' };
  vector<char> list(digits, digits + 10);
  string result = "";

  for (unsigned i = 9; i != -1; i--) {
      unsigned f = factorial(i);
      unsigned index = n / f;
      result += list[index];
      list.erase(list.begin() + index);
      n = n % f;
  }

  cout << result << endl;
}

void Problem24::permute() {
  if (m_one.size() == m_data.size()) {
    m_permutation.push_back(m_one);
    return;
  }
  for (size_t i = 0; i < m_data.size(); ++i) {
    if (m_flags[i]) continue;
    m_one += m_data[i];
    m_flags[i] = true;
    permute();
    if (m_permutation.size() == 1000000)  return;
    m_flags[i] = false;
    m_one.erase(m_one.end()-1, m_one.end());
  }
}

unsigned Problem24::factorial(const unsigned n) {
    unsigned f = 1;
    for (unsigned i = 1; i <= n; i++)
        f *= i;
    return f;
}

void Problem25::Run() {
  double f1 = 1;
  double f2 = 1;
  int n = 2;
  int div = 0;
  while (div < 990) {
    double f3 = f1 + f2;
    f1 = f2;
    f2 = f3;
    if (f2 > 1e10) {
      f1 /= 10;
      f2 /= 10;
      div++;
    }
    n++;
  }

  cout << n << endl;
}