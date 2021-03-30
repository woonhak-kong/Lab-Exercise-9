#include <iostream>
#include <iomanip>

using namespace std;

void sortArrayToAscending(int* array, int size);
float getAverageOfArray(int* array, int size);
void printArray(int* array, int size);

int main()
{
	int size;
	int* arrayOfScores;

	do
	{
		cout << "How many scores do you want to intput? > ";
		cin >> size;

		if (size < 1)
		{
			cout << "Please Enter number over 0\n\n";
		}

	} while (size < 1);


	arrayOfScores = new int[size];

	for (int i = 0; i < size; i++)
	{
		do
		{
			cout << "Enter score of [" << i + 1 << "] : ";
			cin >> arrayOfScores[i];

			if (arrayOfScores[i] < 0)
			{
				cout << "Please Enter score more than 0\n\n";
			}

		} while (arrayOfScores[i] < 0);

	}


	cout << "< Before sorting >\n";
	printArray(arrayOfScores, size);
	cout << endl;

	sortArrayToAscending(arrayOfScores, size);

	cout << "< After sorting >\n";
	printArray(arrayOfScores, size);
	cout << endl;

	cout << "< Average of array >\n";
	cout << getAverageOfArray(arrayOfScores, size) << endl;

	return 0;
}

void sortArrayToAscending(int* array, int size)
{
	int smallest = array[0];
	int position = 0;
	int smallestPoint = 0;
	bool isFound = false;

	while (position < size - 1)
	{
		isFound = false;
		for (int i = position + 1; i < size; i++)
		{
			if (smallest > array[i])
			{
				smallest = array[i];
				smallestPoint = i;
				isFound = true;
			}

		}
		if (isFound)
		{
			array[smallestPoint] = array[position];
			array[position] = smallest;
		}
		position++;
		smallest = array[position];
	}
}

float getAverageOfArray(int* array, int size)
{
	float average = 0;
	for (int i = 0; i < size; i++)
	{
		average += array[i];
	}
	return average / size;
}

void printArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(3) << array[i] << " ";
	}
	cout << endl;

}
