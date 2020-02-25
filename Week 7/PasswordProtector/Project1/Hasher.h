#pragma once
#include <String>

class Hasher
{
public:
	Hasher();
	~Hasher();

	bool checkUsername(std::string);
	bool checkPassword(int);
	int hashDecoder(std::string);

private:

	
	int hashValues[26];
	int userPos;

	int hashedPasswords[5] = { 48,64,65,45,58 };

	char hashableCharacters[26] = { 'a','b','c','d','e','f','g',
								'h','i','j','k','l','m','n',
								'o','p','q','r','s','t','u',
								'v','w','x','y','z' };
	

	std::string usernames[5] = { "test1", "jamie_99", 
								"BillyBob", "Bigrobby", 
								"jemimaHethelstein" };
};