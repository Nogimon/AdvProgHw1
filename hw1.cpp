#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <sstream>
#include <cmath>

using namespace std;

//const int arrlen = 6;

void getinput(vector<int>& numbers)
{
	//vector<int> numbers;
	string line;
	//ifstream myfile("E:/Lehigh/Courses/Program Tech by Femister/hw1/input.txt");
	ifstream myfile("/media/zlab-1/Data/Lian/course/AdvProgHw1/input.txt");
	if (!myfile.is_open())
	{
		cout << "unable to open file" << endl;
	}
	while (getline(myfile, line))
	{
		istringstream ss(line);
		int num;
		ss >> num;
		numbers.push_back(num);
		//numbers.push_back(stoi(line));
	}

}

void getpairinput(vector<int>& numbers, vector<int>& targetnumbers)
{
	string line;
	//ifstream myfile("E:/Lehigh/Courses/Program Tech by Femister/hw1/inputpair.txt");
	ifstream myfile("/media/zlab-1/Data/Lian/course/AdvProgHw1/pairinput.txt");
	if (!myfile.is_open())
	{
		cout << "unable to open file" << endl;
	}
	while (getline(myfile, line))
	{
		istringstream ss(line);
		int num1, num2;
		ss >> num1 >> num2;
		numbers.push_back((num2));
		targetnumbers.push_back((num1));
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
	for (size_t i = 0; i < arr1.size(); i++)
	{
		dev += pow((arr1[i] - mean), 2);
		//cout << dev << endl;
	}
	dev /= arr1.size();
	dev = sqrt(dev);
	return dev;
}

float calculatet(float mean, int popmean, float dev, int size)//calculate t value
{
	float t = (mean - popmean) / (dev / sqrt(size));
	return t;
}

float calculatepairt(int sumd, int sumdsq, int size)
{
	float t;
	t = (sumd / size) / sqrt((sumdsq - pow(sumd, 2) / size) / (size * (size - 1)));
	return t;
}

int sumsquare(vector<int>& diff)
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
	cout << "For single t test" << endl;

	int popmean = 10000; //population mean
	getinput(numbers);
	while (i<numbers.size())
	{
		cout << numbers[i] << endl;
		i++;
	}
	cout << endl;

	int sum1 = accumulate(numbers.begin(), numbers.end(), 0);
	//int sum1 = sum(numbers, arrlen);
	float mean = sum1 / numbers.size();
	float dev = deviation(numbers, mean);
	float tvalue = calculatet(mean, popmean, dev, numbers.size());

	cout << "mean is" << mean << endl;
	cout << "dev is" << dev << endl;
	cout << "tvalue is" << tvalue << endl;


	cout << "\nFor paired t test" << endl;

	vector<int> pairnumbers;
	getpairinput(numbers, pairnumbers);
	while (i<numbers.size())
	{
		cout << numbers[i] << "," << pairnumbers[i] << endl;
		i++;
	}
	cout << endl;


	vector<int> diff;
	for (i = 0; i < numbers.size(); i++)
	{
		diff.push_back(abs(numbers[i] - pairnumbers[i]));
	}
	cout << diff.size() << endl;
	//cout << diff.end() << endl;
	int sumd = accumulate(diff.begin(), diff.end(), 0);
	int sumdsq = sumsquare(diff);
	float t = calculatepairt(sumd, sumdsq, diff.size());

	cout << "sumd is" << endl;
	cout << sumd << "," << sumdsq << endl;
	cout << "t value is" << t << endl;
	return 0;
}