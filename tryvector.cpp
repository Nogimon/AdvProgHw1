#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void getinput(std::vector<int>& numbers)
{
	//vector<int> numbers;
	string line;
	ifstream myfile("E:/Lehigh/Courses/Program Tech by Femister/hw1/input.txt");
	if (!myfile.is_open())
	{
		cout << "unable to open file" << endl;
	}
	while (getline(myfile, line))
	{
		numbers.push_back(stoi(line));
	}

}

int main()
{
	vector<int> numbers;
	getinput(numbers);
	int i = 0;
	while (i < numbers.size())
	{
		cout << numbers[i] << endl;
		i++;
	}
	cout << endl;
	system("PAUSE");
	return 0;

}