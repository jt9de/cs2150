//Take in a dictionary file and grid file, in that order, using command line parameters

//Read in a dictionary and store its words in a hash table. Which is implemented without using a vector of vectors or any STL hash table

//Read in a word search grid no larger than 500x500 and store it in an appropriate data structure

//Output every word of length three or greater and its location in the grid. The required output format is described below


/*
 * Filename: wordPuzzle.cpp
 * Author: Jinghui Tian
 * Date: 3.29.2020
 */

#include <iostream>
#include <fstream>
#include <string>
#include "hashTable.h"
#include "timer.h"

using namespace std;
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// Forward declarations
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);

int main(int argc, char* argv[]){
    // read in dict.
    int count;
    string word;
    ifstream file(argv[1]);
    if(file.is_open()){
        while(getline(file,word)){
            count ++;
        }
        file.close();
    }
    

    //cout << "dictionary:" << count << endl;
    
    hashTable dictionary(count);
    
    file.open(argv[1]);
    if(file.is_open()){
        while(getline(file,word)){
            dictionary.insert(word);
        }
        file.close();
        
    }else{
        cout << "hashtable creation filed.";
    }
    
    // read in grid
    int rows, cols;

    // attempt to read in the file
    bool result = readInGrid(argv[2], rows, cols);
    // if there is an error, report it
    if (!result) {
        cout << "Error reading in file!" << endl;
        return 1;
    }
    
    // find matching words
    int match = 0;
    vector<string> matching_list;
    timer t;
    t.start();
    
     for (int r = 0; r < rows; r++){
         for (int c = 0; c < cols; c++){
             for (int d = 0; d < 8; d++){
                 for (int l = 3; l <= 22; l++){
                     if (getWordInGrid(r,c,d,l,rows, cols).length() != l){
                         break;
                     }
                     if(dictionary.find(getWordInGrid(r,c,d,l,rows, cols))){
                         string finalWord = "";
                         if(d == 0){// north
                             finalWord += "N(";
                             
                         }else if (d == 1){// north-east
                             finalWord += "NE(";
                             
                         }else if (d == 2){// east
                             finalWord += "E(";
                             
                         }else if (d == 3){// south-east
                             finalWord += "SE(";
                             
                         }else if (d == 4){// south
                             finalWord += "S(";
                             
                         }else if (d == 5){// south-west
                             finalWord += "SW(";
                             
                         }else if (d == 6){// west
                             finalWord += "W(";
                             
                         }else if (d == 7){// north-west
                             finalWord += "NW(";
                             
                         }
                         finalWord += to_string(r);
                         finalWord += ",";
                         finalWord += to_string(c);
                         finalWord += "): ";
                         finalWord += getWordInGrid(r,c,d,l,rows, cols);
                         //cout << finalWord << "123" << endl;
                         match++;
                         matching_list.push_back(finalWord);
                     }
                 }
             }
         }
     }
    t.stop();
    for (int i = 0; i < matching_list.size(); i++){
        cout << matching_list[i] << endl;
    }
    cout << match << " words found" << endl;


    return 0;
    }
 




/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columns as specified in the input file;
 *             as this is a reference, it is set by the function.
 *
 */


bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    return true;
}

/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static string variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A STATIC string containing the letters in the provided direction.
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}



