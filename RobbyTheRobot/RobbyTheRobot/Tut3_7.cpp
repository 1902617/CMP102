#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
	srand(time(0));

	int roll = 0, roll_Counter, input, run_counter = 0, ttl_roll_ctr=0;

	do
	{
		input = 0;
		roll_Counter = 0;
		roll = rand() % 6 + 1;

		while (roll != 6 && roll > 0)
		{
			
			roll_Counter++;
			std::cout<<"Roll #"<< roll_Counter << ": " << roll << std::endl;
			roll = rand() % 6 + 1;
		}

		std::cout << "Amount of Rolls: "<< roll_Counter << std::endl;
		std::cout << "Enter a possitive number to run again, and 0 to exit." << std::endl;
		std::cin >> input;
		ttl_roll_ctr += roll_Counter;
		run_counter++; //Number of 6's
		
	} while (input != 0 && input > 0);

	std::cout << "The average number of rolls needed to get a 6: " << (ttl_roll_ctr / run_counter) << std::endl;
	std::cout << "Based on " << run_counter << " runs." << std::endl;

	return 0;
}