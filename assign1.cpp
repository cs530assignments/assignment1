#include <iostream> /* Library provides functions to print to the screen */
#include <fstream> /* Library provides functions to interact with files */
#include <string> /* Library provides ability to use the string type */
#include <iomanip> /* Library allows for hex printing */
#include <cstring> /* Library provides function to compare strings/chars */
#include <bitset> /* Library for printing out binary */

using namespace std;

/* 
  Determines if the given character is a valid ascii character
  by checking the printable ascii codes
*/
bool isValidASCII(char c) {
 if ((c - '0') > 31 || (c - '0') < 127) {
  return true;
 } 
 return false;
}

/* 
  Prints the valid ascii characters from the current line of the input file
*/
void printValidASCII (string str) {
  for (unsigned int i = 0; i < str.length(); i++) {
    if (isValidASCII(str[i])) {
      cout << str[i];
    } else {
      cout << ".";
    }
  }
}

/*
  Prints the hex codes for the given line of the input file
*/
void printHexSolution(char *argv[]) {
  ifstream file(argv[1]);
  string currentLine;
  int word = 0;
  while (getline(file, currentLine)) {
    for (unsigned int i = 0; i < currentLine.length(); i++) {
      if (i % 2 == 0) {
        cout << " ";
      }
      cout << hex << static_cast<int>(currentLine[i]);
    }
    cout << " ";
    printValidASCII(currentLine);
    cout << '\n';
  }
}

/*
  Prints solution when user invokes the "-b"  flag
*/
// void printBinarySolution(char *argv[]) {
//   ifstream file(argv[2]);
//   string currentLine;
//   while (getline(file, currentLine)) {
//     for (unsigned int i = 0; i < currentLine.length(); i++) {
//       if (i == 6) {
//         cout << '\n';
//       }
//       bitset<8> characterInBinary = currentLine[i];
//       cout << characterInBinary << " "; 
//     }
//     printValidASCII(currentLine);
//     cout << '\n';
//   }
// }

void printBinarySolution(char *argv[]) {
  ifstream file(argv[2]);
  string currentLine;
  string completedLine;
  while (getline(file, currentLine)) {
    for (unsigned int i = 0; i < currentLine.length(); i++) {
      if (i == 6) {
        break;
      }
      bitset<8> characterInBinary = currentLine[i];
      completedLine = completedLine + to_string(characterInBinary) + ' ';
    }
    cout << completedLine;
    printValidASCII(currentLine);
    cout << '\n';
  }
}

int main(int argc, char *argv[]) {
  if (strcmp(argv[1], "-b") == 0) {
    printBinarySolution(argv);
  } else {
    printHexSolution(argv);
  }
}
