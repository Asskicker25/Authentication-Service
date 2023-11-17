#include "SaltGenerator.h"

SaltGenerator::SaltGenerator()
{
}

std::string SaltGenerator::GenerateSalt()
{
	const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    srand(static_cast<unsigned int>(time(nullptr)));

    std::string salt;

    for (int i = 0; i < saltLength; ++i) 
    {
        salt += charset[rand() % (sizeof(charset) - 1)];
    }

    return salt;
}
