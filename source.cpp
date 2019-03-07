#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//Declaring the size for the array, this will be used in all arrays to make them parrell 
const int SIZE = 4;

//Function Prototypes 
void readStudents(fstream *file, string names[]);
void calcGrades(fstream *file, int gradesArray[][SIZE], int averageScore[], string letterGrades[]);
void makeResults(string names[], string letterGrades[]);

//Main Function
//This function will have the variables inside of it as well as files to read from. This will only contain the 
//functions and none of the code to make it work 
int main() {
	fstream inputFile;
	fstream gradesFile;
	inputFile.open("StudentNames.txt");
	gradesFile.open("Grades.txt");

	string names[SIZE];
	int averageScore[SIZE];
	int gradesArray[SIZE][SIZE];
	string letterGrades[SIZE];

	readStudents(&inputFile, names);
	calcGrades(&gradesFile, gradesArray, averageScore, letterGrades);
	makeResults(names, letterGrades);

	system("pause");
}


//This function will read the studentsName.txt file and place themi nto the names array
void readStudents(fstream *file, string names[]) {
	for (int i = 0; i < SIZE; i++) {
		*file >> names[i];
	}
}


//This function will read the grades.txt file and place them into the 2D array called gradesArray
//This will then move that data to the averageScore array by adding all the columns and 
//then dividing them by 3 to get the average which will then be stored in the averageScore array 
//and then that will use that number to do an if statement that will create the string grade array
void calcGrades(fstream *file, int gradesArray[][SIZE], int averageScore[], string letterGrades[]) {

	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 3; column++) {
			*file >> gradesArray[row][column];
		}
		cout << endl;

	}

	for (int row = 0; row < 4; row++)
	{
		int sum = 0;
		for (int col = 0; col < 3; col++)
			sum += gradesArray[row][col];
		int average = 0;
		average = sum / 3;
		averageScore[row] = average;
		if (average >= 90)
		{
			letterGrades[row] = 'A';
		}
		if (average >= 80 && average < 90) {
			letterGrades[row] = 'B';
		}
		if (average >= 70 && average < 80) {
			letterGrades[row] = 'C';
		}
		if (average >= 60 && average < 70) {
			letterGrades[row] = 'D';
		}
	}


}

//This array will take the information from both the name array and grades array and placed them into one file
//one part of it will print to the console, the other to a file called "newGrades"
void makeResults(string names[], string letterGrades[]) {
	ofstream outfile;
	outfile.open("newGrades.txt");
	for (int i = 0; i < 4; i++) {
		cout << names[i] << setw(5) << " " << letterGrades[i] << endl;
	}


	outfile << "Students     " << "Grades   " << endl;
	outfile << endl;
	for (int i = 0; i < 4; i++) {

		outfile << names[i] << setw(8) << " " << letterGrades[i] << endl;
	}
	outfile.close();
}



