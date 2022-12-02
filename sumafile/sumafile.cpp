#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<fstream> //file IO support
#include<cstdlib> //support for exit()
const int SIZE= 60;

int main()
{
	using namespace std;
	char filename[SIZE];
	ifstream infile;//object for handing file input
	cout << "Enter a name fo data file:\n";
	cin.getline(filename, SIZE);
	infile.open(filename);
	if (!infile.is_open())
	{
		cout << "can not open the file" << filename << endl;
		cout << "³ÌÐòÍ£Ö¹ÔËÐÐ" << endl;
		exit(EXIT_FAILURE);
	}
	double value;
	double sum = 0;
	int count = 0;    //number of items read
	infile >> value;//get first callue
	while (infile.good())
	{
		++count;//one more  item read
		sum += value;//calc running total
		infile >> value; //get next value
	}
	if (infile.eof())
	{
		cout << "end of file reached" << endl;
	}
	else if (infile.fail())
	{
		cout << "input terminated by data mismatch.\n";
	}
	else
	{
		cout << "input terminated for unknow reason.\n";
	}
	if (count == 0)
	{
		cout << "no data proceed.\n";
	}
	else
	{
		cout << "Item read:" << count << endl;
		cout << "sum:" << sum << endl;
		cout << "average:" << sum / count << endl;
	}
	infile.close();
	return 0;
}