#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

const int arrlen = 6;

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

int sum(int *arr1, int size) // calculate sum
{
	int summ = 0;
	for (int i = 0; i < size; i++)
	{
		summ += arr1[i];
	}
	return summ;
}

float deviation(int *arr1, int size, int mean) //calculate deviation
{
	float dev = 0;
	for (int i = 0; i < size; i++)
	{
		dev += pow((arr1[i] - mean), 2);
		cout << dev << endl;
	}
	dev /= size;
	dev = sqrt(dev);
	return dev;
}

float calculatet(int mean, int popmean, float dev, int size)//calculate t value
{
	float t = (mean - popmean) / (dev / sqrt(size - 1));
	return t;
}

int main()
{
	cout << "hello xiaojijiang" << endl;

	int *numbers;
	int i = 0;
	int popmean = 10000; //population mean
	int size = 0; //number of samples
	int mean; // sample mean

	numbers = getinput();
	
	while (i<arrlen)
	{
		cout << numbers[i];
		i++;
	}
	cout << endl;
	

	size = arrlen;
	//int sum = accumulate(numbers.begin(), numbers.end(), 0);
	int sum1 = sum(numbers, arrlen);
	mean = sum1 / size;
	float dev = deviation(numbers, arrlen, mean);
	float tvalue = calculatet(mean, popmean, dev, size);

	cout << "mean is";
	cout << mean << endl;
	cout << "dev is";
	cout << dev << endl;
	cout << "tvalue is";
	cout << tvalue << endl;

	system("PAUSE");
	delete numbers;
	return 0;
}