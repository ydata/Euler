#pragma once

#include "stdafx.h"
#include "Problem1to10.h"

using namespace std;

class Problem21 : public ProblemBase
{
public:
  virtual void Run();
private:
  int getDivisorSum(int n);
};

class Problem22 : public ProblemBase
{
public:
  virtual void Run();
};

class Problem24 : public ProblemBase
{
public:
  virtual void Run();
private:
  void permute();
  unsigned factorial(const unsigned n);

  vector<string> m_permutation;
  string m_data, m_one;
  vector<bool> m_flags;
};

class Problem25 : public ProblemBase
{
public:
  virtual void Run();
};
