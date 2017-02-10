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
    if (c  > 31 && c < 127) {
        return true;
    }
    return false;
}
/*
 Prints the address associated with the line of the file 
 */
void printStringAddr(int addr) {
    cout << setfill('0') << setw(7) << hex << addr;
    cout << ":";
}
/*
 Prints the hex codes from the given input file.
 */
void printHexString(char* str, long len) {
    for (unsigned int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            cout << " ";
        }
        cout << setfill('0') << setw(2) << hex << static_cast<int>(str[i]);
    }
    long spaces = 0;
    string s;
    if (len < 16) {
        spaces = 41 - (len*2 + len/2 + 1);
        s = string(spaces,' ');
    } else {
        s = " ";
    }
    
    cout << s;
}
/*
 Prints the valid ascii characters from the current line of the input file
 */
void printValidASCII (char* str, long len) {
    for (unsigned int i = 0; i < len; i++) {
        if (isValidASCII(str[i])) {
            cout << str[i];
        } else {
            cout << ".";
        }
    }
    cout << endl;
}
/*
 Prints the entire hexdump output if hex is requested output style
 */
void printHexSolution(char *fname) {
    ifstream file(fname, std::ios::binary);
    char currentSixteen[16];
    int addr = 0;
    long charCount;
    while (file.read(currentSixteen, 16) ) {
       charCount = file.gcount();
       printStringAddr(addr);
       printHexString(currentSixteen, charCount);
       printValidASCII(currentSixteen, charCount);
       addr+=16;
    }
    charCount = file.gcount();
    if (charCount > 0) {
        printStringAddr(addr);
        printHexString(currentSixteen, charCount);
        printValidASCII(currentSixteen, charCount);
    }
}
/*
 Prints solution when user invokes the "-b"  flag
 */
// void printBinarySolution(char *argv[]) {
//   ifstream file(argv[2], binary);
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

void printBinarySolution(char *fname) {
    ifstream file(fname, std::ios::binary);
    string currentLine;
    string validASCII;
    while (getline(file, currentLine)) {
        for (unsigned int i = 0; i < currentLine.length(); i++) {
            if (i > 0 && i % 6 == 0) {
                cout << validASCII << endl;
                validASCII = "";
            }
            bitset<8> characterInBinary = currentLine[i];
            cout << characterInBinary << ' ';
            if (isValidASCII(currentLine[i])) {
                validASCII = validASCII + currentLine[i];
            }
            if (i == currentLine.length() - 1) {
                cout << validASCII << endl;
                break;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (strcmp(argv[1], "-b") == 0) {
        printBinarySolution(argv[2]);
    } else {
        printHexSolution(argv[1]);
    }
    cin.get();
}
