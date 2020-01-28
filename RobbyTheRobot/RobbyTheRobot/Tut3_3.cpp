#include <iostream>

int main()
{

	int input = 0;
	int total = 0;

	while (input!=-1)  
	{
		std::cout << "Enter a coursework grade or -1 to quit: " << std::endl;
		std::cin >> input;
		total = total+ input;

	}

	std::cout<< "total is :" << (total+1) << std::endl;

	return 0;
}