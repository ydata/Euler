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