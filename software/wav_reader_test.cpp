/**
*   \file wav_reader_test.cpp
*
*   \author Andrew Scott -- ascott@hmc.edu
*
*   \brief Simple test file for the wav_reader class. Test outputs some
*       information from samples it returns from the wav file it reads in
*       which can then be visually inspected.
*
*/

#include "wav_reader.hpp"
#include <iostream>

using namespace std;
int main (int argc, char** argv) 
{
    if (argc != 2) {
        cout << "Incorrect parameters. Format is ./wav_reader filename.wav" << endl;
        return 1;
    }
    string filename = argv[1];
    wav_reader wav_file = wav_reader(filename);
    chrono::microseconds start = chrono::microseconds(100);
    chrono::microseconds length = chrono::microseconds(1000);
    vector<float> samples_in_range = wav_file.get_range(start, length);

    // inspect the values below to make sure they seem right (should be ~11
    // samples and can check the file itself to make sure the values are correctg)

    cout << samples_in_range.size() << endl;
    //cout << samples_in_range[0] << endl;//" " << samples_in_range[1] <<
        //  " " << samples_in_range[2] << endl;
    // for (auto i = samples_in_range.begin(); i != samples_in_range.end(); ++i)
    //     cout << *i << ' ';
    float sum = samples_in_range[0] + samples_in_range[1];
    // super cryptic valgrind error - if we remove the unsigned() cast we
    // get a memory leak
    cout << unsigned(sum) << endl;
    return 0;
}