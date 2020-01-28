#include <iostream>

int main()
{
	int ttl_cost = 0, item_amount = 0, lowest_cost = 0, second_lowest = 0, user_input;

	std::cout << "Please insert the cost of each of your item one at a time in descending order." << std::endl;

	for (int i = 0; i < 6; i++)
	{
		user_input = 0;
		std::cin >> user_input;
		ttl_cost += user_input;

		if (i == 0)
		{
			lowest_cost = user_input;	
		}

		else if (user_input < lowest_cost)
		{	
			second_lowest = lowest_cost;
			lowest_cost = user_input;
		}
	}

	std::cout << "Discount: " << (lowest_cost + second_lowest) << std::endl;
	std::cout << "Total Cost (With Discount): " << (ttl_cost - (lowest_cost + second_lowest)) << std::endl;

}