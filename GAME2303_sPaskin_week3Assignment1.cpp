// GAME2303_sPaskin_week3Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

class Record {
public:
    string firstName;
    string lastName;
    string grade;

    Record(string firstName, string lastName, string grade) {

        this->firstName = firstName;
        this->lastName = lastName;
        this->grade = grade;
    }
};

int main() //cout << "\n";
{
    ifstream myfile("students\\students.txt");

    string tempFirstName;
    string tempLastName;
    string tempGrade;

    string toSplit;

    int count = 1;
    int sumGrade = 0;
    int averageGrade = 0;

    vector<Record> vRecords;

    bool cleanSweep = false;
    bool foundASwap = false;
    
    if (myfile.is_open()) {

        while (getline(myfile, toSplit))
        {
            count = 1;

            istringstream ss(toSplit);

            string word;

            while (ss >> word)
            {
                if (count == 1) {
                    tempFirstName = word;
                } else if (count == 2) {
                    tempLastName = word;
                } else {
                    tempGrade = word;
                }
                count++;
            }
            vRecords.push_back(Record(tempFirstName, tempLastName, tempGrade));
        }
    } else {
        cout << "ERROR! Cannot open file!";
    }
    
    while (!cleanSweep) {
        for (int i = 0; i < vRecords.size(); i++) {
            foundASwap = false;

            if (i != 0 && vRecords[i-1].grade > vRecords[i].grade) {

                foundASwap = true;

                Record temp(vRecords[i-1].firstName, vRecords[i-1].lastName, vRecords[i-1].grade);

                vRecords[i-1] = vRecords[i];
                vRecords[i] = temp;

            }
        }
        if (!foundASwap) {
            cleanSweep = true;
        }
    }

    for (int i = 0; i < vRecords.size(); i++) {

        sumGrade += stoi(vRecords[i].grade);

        cout << vRecords[i].firstName << " ";
        cout << vRecords[i].lastName << " ";
        cout << vRecords[i].grade << endl;

        
    }

    averageGrade = sumGrade / vRecords.size();
    cout << averageGrade << endl;
}