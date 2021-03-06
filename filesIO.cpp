#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	char fileName[12];
	ifstream fin;
	ofstream fout;
	string firstName, lastName, smartPerson, highest;
	double score, sum = 0.0, avg, highestAvgScore = -1;
	double highScore;

	cout << "Enter input file: ";
	cin >> fileName;
	
	fin.open(fileName);
	fout.open("results.txt");

	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);


	if(fin.fail())
	{
		cout << "Error, input file failed to open\n";
		exit(1);
	}
	if(fout.fail())
	{
		cout << "Error, output file failed to open\n";
		exit(1);
	}
	
	fout << endl;

	while(fin >> firstName >> lastName)
	{
		int counter = 0;

		sum = 0;

		for(counter = 0; counter < 6; counter++)
		{
			fout.precision(1);

			if(fin >> score)
			{
				if(counter == 0)
					fout << setw(10) << left << firstName << setw(10) << left << lastName;
				sum += score;
				fout << setw(7) << score << setw(7);
			}
		}
		avg = sum / counter;

		if(highestAvgScore < avg)
		{
			highestAvgScore = avg;
			smartPerson = firstName + " " + lastName;
		}
		if(avg != 0) {
			fout.precision(2);
			fout << avg << endl;
			}
	}


	fout << "\nHighest Average Score: " << smartPerson << endl;

	fin.close();
	fout.close();

	return 0;
}


