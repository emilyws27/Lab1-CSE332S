/*
Lab1.cpp
Emily Sheehan, e.sheehan@wustl.edu

Lab1.cpp contains the definitions for three functions: parse_file, usage_message, and main.
The file executes the project's intended purpose: reading in text from a file, interpreting whether it is a string or numerical value, and then displaying the file's identified strings and then integers.
*/

#include "Header.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

fstream fileStream;

int parse_file(vector<string>& v, char* t) {
    /*
    * opens and reads contents of file, piece by piece, and adds them to vector.
    *
    * Parameters-
    * vector<string>& v: vector v that holds the contents of file t
    * char* t: c-style string that refers to the name of the file to be opened
    *
    * Returns-
    * SuccessValue: a value of 0,2, or 3 depending on whether function is able to open program and execute properly
    */
    fileStream.open(t);                                     //opens file with given t
    if (fileStream.fail()) {
        return FILEERROR;
    }
    string file_contents;
    while ((fileStream >> file_contents))                   // right shift operator,
    {
        try 
        {
             v.push_back(file_contents);
             file_contents = "";
         }
         catch (const std::ios_base::failure& fail)
         { 
             std::cout << fail.what() << '\n';
             return EXTRACTIONERROR;
         }
    }
    fileStream.close();
    return SUCCESS;
}
int usage_message(char* name) {
    /*
    * displays a message summarizing how to run the program
    *
    * Parameters-
    * char* name: c-style string that refers to the name of the program (argv[0])
    *
    * Returns-
    * WRONG_ARGS: if wrong num of args given in command line
    */

    cout << "This program, " << name << ", reads in the contents of a file, for example test1.txt, and parses it into strings and integers. It first identifies strings that consist" <<
        "of integers only and adds them to a vector of integers. Then, it prints all of the non - integer strings line-by-line, and then prints out the converted integers. A command line example" <<
        "would be: Lab1.cpp ../text1.txt" << endl;
    return WRONG_ARGS;
}
int main(int argc, char* argv[])
{
    /*
    * responsible for starting the execution and termination of this program. Displays results of parse_file line by line to console.
    *
    * Parameters-
    * int argc: number of parameters given in command line
    * char* argv[]: array of arguments
    *
    * Returns-
    * SuccessValue: either 0 or 1 depending on whether program operates correctly.
    */

    if (argc != EXPECTEDARGS)                                                                           //wrong num of args given in command line
    {
        char* program = argv[PROGRAMNAME];
        return usage_message(program);
    }

    char* file_name = argv[INPUTFILENAME];
    vector<string> vals;
    int t = parse_file(vals, file_name);
    vector<int> nums;

    for (unsigned int i = 0; i < vals.size(); i++) {
        bool has_only_digits = (vals[i].find_first_not_of("0123456789") == std::string::npos);         //checks if the characters at the position in the vector are only digit

        if (has_only_digits) {
            int num;
            string str = vals[i];

            num = std::stoi(str);                                                                       //converts string to int

            nums.push_back(num);                                                                        //vector of num
        }
        else                                                                                            //if not a numerical value, displays string to console
        {
            cout << vals[i] << endl;
        }
    }
    for (int num : nums) {                                                                              //prints numerical values to console following display of non-nums
        cout << num << endl;
    }
    return SUCCESS;
}