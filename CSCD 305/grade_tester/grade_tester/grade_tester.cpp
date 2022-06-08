// grade_tester.cpp : This file contains the 'main' function. Program execution begins and ends there. 
//Author: Pedro Hernandez
//Compiler: Visual Studio 2019

#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    float grade = 0, sum = 0, max = 0, min = 100;
    int student;

    cout << "Welcome to the Student Score Application" << endl;
    cout << "Please enter the number of students: ";

    while (!(cin >> student) || (student <= 0) || (cin.get() != '\n')) {
            cout << "Please enter a valid number of students: ";
            cin.clear();
            cin.ignore(1000, '\n');
    }

    
    cout << "there are " << student << " students." << endl;

    while (count < student) { // checks that it ask x scores based on x input.

        for (int i = 0; i < student; i++) { // this label the individual student's score
            cout << "Enter score for student " << i+1 << ": " << endl;
            
            while (!(cin >> grade) || (grade < 0) || (grade > 100) ||(cin.get() != '\n')) { // check for errors
                cerr << "Enter a valid score: " << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }

            float curr = grade; //this varable and if statements finds the min and max

            if (curr > max)
                max = curr;
            if (curr < min)
                min = curr;
            /*if (student == 0)   this prototype checks that if there are no students,
                float min = 0;    min is set to 0*/
            sum += grade; // used to find average.
            count++;
        }
    }
    cout << "Average score is: " << sum / count << endl;
    cout << "Minimum score is: " << min << endl;
    cout << "Maximum score is: " << max << endl;
}
