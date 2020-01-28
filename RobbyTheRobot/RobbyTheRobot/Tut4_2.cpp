#include <iostream>

int ttl_ppl = 0,user_input = 0;
float ttl_cost = 0.0;

int main()
{
	std::cout << "Hello, please enter the age of everyone in your group one at a time, enter '-1' to end." << std::endl;

	while(std::cin >> user_input && user_input != -1)
	{
		ttl_ppl++;

		if (user_input < 16)			
		{ 
			ttl_cost += 2.5; 
		}
		
		else if (user_input >= 65)		
		{
			ttl_cost += 3.0; 
		}

		else							
		{ 
			ttl_cost += 5.0; 
		}
	}

	if (ttl_ppl >= 6) 
	{
		ttl_cost *= 0.8;
	}

	std::cout << "Your group consists of " << ttl_ppl << " people, and the total cost is: " << char(156) << ("%.2f", ttl_cost) << std::endl;
	std::cout << "Thank you for choosing us as your pool! <3" << std::endl;
}