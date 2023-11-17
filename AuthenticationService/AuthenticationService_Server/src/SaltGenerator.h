#pragma once

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

class SaltGenerator
{
public:
	SaltGenerator();

	std::string GenerateSalt();

private:
	const int saltLength = 16;
};

