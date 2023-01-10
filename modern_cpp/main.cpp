#include<iostream>
#include<vector>

int main()
{
	std::vector<int> num_list = { 1,2,3,4,5 };
	num_list.push_back(7);

	for (int idx = 0 ;idx < num_list.size() ; idx++)
	{
		std::cout << num_list[idx] << std::endl;
	}

	for (auto num : num_list)
	{
		std::cout << num << std::endl;
	}
	return 0;
}