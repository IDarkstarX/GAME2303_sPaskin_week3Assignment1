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
    int grade;

    Record(string firstName, string lastName, int grade) {

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
                cout << "THE WORD IS: <" << word << ">" << endl;
                if (count == 1) {
                    tempFirstName = word;
                }
                else if (count == 2) {
                    tempLastName = word;
                }
                else {
                    tempGrade = word;
                }
                count++;
            }
            vRecords.push_back(Record(tempFirstName, tempLastName, stoi(tempGrade)));
        }
    }
    else {
        cout << "ERROR! Cannot open file!";
    }

    for (int i = 0; i < vRecords.size(); i++)
    {
        cout << vRecords[i].firstName << endl;
    }

    while (!cleanSweep) {
        for (int i = vRecords.size() - 2; i > 0; i--) {
            cout << "FOR LOOP: " << i << endl;
            foundASwap = false;

            if (vRecords[i].grade < vRecords[i + 1].grade) {


                cout << "index: " << i << endl;
                cout << "swapping " << vRecords[i].firstName << " with " << vRecords[i + 1].firstName << endl;

                foundASwap = true;

                Record temp(vRecords[i].firstName, vRecords[i].lastName, vRecords[i].grade);
                cout << "temp = " << vRecords[i].firstName << endl;

                vRecords[i] = vRecords[i + 1];
                cout << "i = " << vRecords[i].firstName << endl;

                vRecords[i + 1] = temp;
                cout << "i+1 = " << vRecords[i + 1].firstName << endl;

            }
        }
        if (!foundASwap) {
            cleanSweep = true;
        }
    }

    for (int i = 0; i < vRecords.size(); i++) {

        sumGrade += (vRecords[i].grade);

        cout << vRecords[i].firstName << " ";
        cout << vRecords[i].lastName << " ";
        cout << vRecords[i].grade << endl;


    }

    averageGrade = sumGrade / vRecords.size();
    cout << averageGrade << endl;
}