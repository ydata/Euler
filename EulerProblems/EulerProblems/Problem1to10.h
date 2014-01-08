#include "stdafx.h"

class ProblemBase
{
public:
	virtual void Run() = 0;
};

class Problem1 : public ProblemBase
{
public:
	virtual void Run();
};

class Problem2 : public ProblemBase
{
public:
	virtual void Run();
};

class Problem3 : public ProblemBase
{
public:
	virtual void Run();
private:
  bool isPrime(__int64 n);
};

class Problem4: public ProblemBase
{
public:
  virtual void Run();
private:
  bool isPalindrome(int n);
};

