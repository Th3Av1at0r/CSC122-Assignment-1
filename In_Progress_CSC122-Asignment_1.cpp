//***************************************************************************
//
// Avi Schmookler
// H00846758
// CSC122 W01
//
// I certify that this is my own work and where appropriate an extension
// of the starter code provided for the assignment.
//
//***************************************************************************

// adds includes (generic use includes mostly)
using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <sstream>


struct file
{
    int id;
    string last;
    string first;
    string address;
    string city;
    string state;
    string zipcode;
};

string get_data_file_name(string data_file_name)
{
    cout << "Enter the data file name: ";
    cin >> data_file_name;

    return data_file_name;
}

string get_merge_file_name(string merge_file_name)
{
    cout << "Enter the merge file name: ";
    cin >> merge_file_name;

    return merge_file_name;
}

vector<string> split_at_commas(const string& row)
{
    vector<string> res;
    istringstream buf(row);
    string s;
    while (getline(buf, s, ','))
        res.push_back(s);
    return res;
}

void create_letter(string data_file_name, string merge_file_name)
{
    fstream data_file;
    fstream merge_file;
    fstream new_file;

    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word;

    data_file.open(data_file_name);

    if (data_file.is_open())  //checking whether the file is open
    {
        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(data_file, line);

        // used for breaking words
        istringstream infile(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(infile, word, ','))
        {
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
        int i = 0;
        while (i <= row.size() - 1)
        {
            cout << row[i];
            i += 1;
        }
    }
    else
    {
        cout << "File A Failed to open.";
        exit(1);
    }

    merge_file.open(merge_file_name, ios::in);

    if (merge_file.is_open())  //checking whether the file is open
    {
        while (getline(merge_file, line)) { //read data from file object and put it into string.
            ofstream new_file("CCCCCCCCCCCCCCCCCCCCHHHHHHHHHHHHHHHHHHHHHHHAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAANNNNNNNNNNNNNNGGGGGGGGGGGGGGGGGGEEEEEEEEEEEEEEEEEEEEEE.txt");
            if (new_file.is_open())
            {
                new_file << line << "\n"; //imprint the data of the string
            }
            else
            {
                cout << "File C Failed to open.";
                exit(1);
            }
            new_file.close();
        }
    }
    else
    {
        cout << "File B Failed to open.";
        exit(1);
    }
    data_file.close(); //close the file object.
    merge_file.close(); //close the file object.
}

//plays main
int main()
{
    //Header and colour change
    system("color 0a");
    cout << "\tAvi Schmookler\n\tDate: 6/14/2023" << endl;
    cout << setw(19) << "Assignment#: 1\n\t";
    cout << "\"Assignment_1_Files_For_Contractors\"\n\tObjectives: Create a program that asks for information to be filled into two "
        << "seperate files and combine them when the file names are brought up for the final message.\n\n";

    // let's you read the header for a sec
    this_thread::sleep_for(std::chrono::milliseconds(3000));

    system("CLS");

    string data_file_name;
    string merge_file_name;

    data_file_name = get_data_file_name(data_file_name);
    merge_file_name = get_merge_file_name(merge_file_name);

    create_letter(data_file_name, merge_file_name);

    return 0;
}
