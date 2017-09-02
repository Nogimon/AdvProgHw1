#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

//const int arrlen = 6;

void getinput(vector<int>& numbers)
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

void getpairinput(vector<int>& numbers, vector<int>& targetnumbers)
{
	string line;
	ifstream myfile("E:/Lehigh/Courses/Program Tech by Femister/hw1/input.txt");
	if (!myfile.is_open())
	{
		cout << "unable to open file" << endl;
	}
	while (getline(myfile, line, ' '))
	{
		numbers.push_back(stoi(line));
	}
}

/*
int *getinput() //generate input
{
	int *input = new int[arrlen];
	int inputtemp[6] = { 11300,9890,10400,9900,10545,12334 };
	int i=0;
	ifstream myfile("E:/Lehigh/Courses/Program Tech by Femister/hw1/input.txt");
	string temp;
	if (!myfile.is_open())
	{
		cout << "unable to open file" << endl;
	}
	while (getline(myfile, temp))
	{
		input[i] = stoi(temp);
		i++;
	}
	return input;
}
*/

int sum(int *arr1, int size) // calculate sum
{
	int summ = 0;
	for (int i = 0; i < size; i++)
	{
		summ += arr1[i];
	}
	return summ;
}

float deviation(vector<int>& arr1, float mean) //calculate deviation
{
	float dev = 0;
	for (int i = 0; i < arr1.size(); i++)
	{
		dev += pow((arr1[i] - mean), 2);
		//cout << dev << endl;
	}
	dev /= arr1.size();
	dev = sqrt(dev);
	return dev;
}

float calculatet(int mean, int popmean, float dev, int size)//calculate t value
{
	float t = (mean - popmean) / (dev / sqrt(size));
	return t;
}

int main()
{
	cout << "hello xiaojijiang" << endl;

	vector<int> numbers;
	vector<int> pairnumbers;
	int i = 0;
	int popmean = 10000; //population mean

	getinput(numbers);	
	while (i<numbers.size())
	{
		cout << numbers[i];
		cout << ",";
		cout << pairnumbers[i] << endl;
		i++;
	}
	cout << endl;
	
	int sum1 = accumulate(numbers.begin(), numbers.end(), 0);
	//int sum1 = sum(numbers, arrlen);
	float mean = sum1 / numbers.size();
	float dev = deviation(numbers, mean);
	float tvalue = calculatet(mean, popmean, dev, numbers.size());

	cout << "mean is";
	cout << mean << endl;
	cout << "dev is";
	cout << dev << endl;
	cout << "tvalue is";
	cout << tvalue << endl;

	system("PAUSE");
	//delete numbers;
	return 0;
}