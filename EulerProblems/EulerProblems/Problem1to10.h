#pragma once

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
  static bool isPrime(__int64 n);
};

class Problem4: public ProblemBase
{
public:
  virtual void Run();
private:
  bool isPalindrome(int n);
};

class Problem6: public ProblemBase
{
public:
  virtual void Run();
};

class Problem7: public ProblemBase
{
public:
  virtual void Run();
};

class Problem8: public ProblemBase
{
public:
  virtual void Run();
};

class Problem9: public ProblemBase
{
public:
  virtual void Run();
};

class Problem10: public ProblemBase
{
public:
  virtual void Run();
};


