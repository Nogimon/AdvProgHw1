#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <sstream>
#include <cmath>

using namespace std;

int getinput(vector<int>& numbers)//get input of single sample t test from txt
{
	string line;
	ifstream myfile("./input.txt");
	if (!myfile.is_open())
	{
		cout << "unable to open file" << endl;
		return 0;
	}
	while (getline(myfile, line))
	{
		istringstream ss(line);
		int num;
		ss >> num;
		numbers.push_back(num);
	}
	return 1;
}

int getpairinput(vector<int>& numbers, vector<int>& targetnumbers)//get input of pair test from txt
{
	string line;
	ifstream myfile("./pairinput.txt");
	if (!myfile.is_open())
	{
		cout << "\nunable to open file" << endl;
		return 0;
	}
	while (getline(myfile, line))
	{
		istringstream ss(line);
		int num1, num2;
		ss >> num1 >> num2;
		numbers.push_back((num2));
		targetnumbers.push_back((num1));
	}
	return 1;
}

float deviation(vector<int>& arr1, float mean) //calculate deviation
{
	float dev = 0;
	for (size_t i = 0; i < arr1.size(); i++)
	{
		dev += pow((arr1[i] - mean), 2);
	}
	dev /= arr1.size();
	dev = sqrt(dev);
	return dev;
}

float calculatet(float mean, int popmean, float dev, int size)//calculate single t value
{
	float t;
	if (size > 30)
	{
		t = (mean - popmean) / (dev / sqrt(size));
	}
	else
	{
		t = (mean - popmean) / (dev / sqrt(size - 1));
	}
	return t;
}

float calculatepairt(int sumd, int sumdsq, int size)//calculate pair t value
{
	float t = (sumd / size) / sqrt((sumdsq - pow(sumd, 2) / size) / (size * (size - 1)));
	return t;
}

int sumsquare(vector<int>& diff)//summation over square of input array
{
	int sumdsq = 0;
	for (size_t i = 0; i < diff.size(); i++)
	{
		sumdsq += pow(diff[i], 2);
	}
	return sumdsq;
}

int main()
{
	vector<int> numbers;
	size_t i = 0;

	//For simple single t test
	if (getinput(numbers))
	{
		cout << "For simple single t test" << endl;
		int popmean = 10000; //population mean
		int sum1 = accumulate(numbers.begin(), numbers.end(), 0);
		float mean = sum1 / numbers.size();
		float dev = deviation(numbers, mean);
		float t1 = calculatet(mean, popmean, dev, numbers.size());
		//cout << "mean is" << mean << endl;
		//cout << "dev is" << dev << endl;
		cout << "t value is" << t1 << endl;
	}
	else
	{
		cout << "Simple single t test failed" << endl;
	}
	
	//For paired t test
	vector<int> pairnumbers;
	vector<int> numbers1;
	if (getpairinput(numbers1, pairnumbers))
	{
		cout << "\nFor paired t test" << endl;
		vector<int> diff;
		for (i = 0; i < numbers1.size(); i++)
		{
			diff.push_back((numbers1[i] - pairnumbers[i]));
		}
		//cout << diff.size() << endl;
		int sumd = accumulate(diff.begin(), diff.end(), 0);
		int sumdsq = sumsquare(diff);
		float t2 = calculatepairt(sumd, sumdsq, diff.size());
		//cout << "sumd is" << endl;
		//cout << sumd << "," << sumdsq << endl;
		cout << "t value is" << t2 << endl;
	}
	else
	{
		cout << "paired t test failed" << endl;
	}
	return 0;
}