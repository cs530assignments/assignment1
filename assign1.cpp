/*
  Matthew Yamout cssc1002
  James Hammon cssc0895
  CS 530 Spring 2017
  February 12th, 2017
  Assignment 1 Hexdump
  assign1.cpp
*/
#include "header.h"

using namespace std;

/*
 * Determines if the given character is a valid ascii character
 * by checking the printable ascii codes
 * */
bool isValidASCII(char c) {
    if (c  > 31 && c < 127) {
        return true;
    }
    return false;
}
/*
 * Prints the address associated with the line of the file 
 * */
void printStringAddr(int addr) {
    cout << setfill('0') << setw(7) << hex << addr;
    cout << ":";
}
/*
 * Prints the hex codes from the given input file.
 * */
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
    if (len % 2 == 0)
        cout << " ";
    } else {
        s = " ";
    }
    
    cout << " " << s;
}
/* 
 * Prints the binary octet(s) for the characters
 * from the given imput file
 * */
void printBinaryString(char* str, long len) {
    cout << " ";
    for (unsigned int i = 0; i < len; i++) {
        bitset<8> characterInBinary = str[i];
        cout << characterInBinary << " ";
    }
    long spaces = 0;
    string s;
    if (len < 6) {
        spaces = (6 - len) * 9;
        s = string(spaces, ' ');
    }
    cout << " " << s;
}
/*
 * Prints the valid ascii characters from the current set of characters
 * int the input file
 * */
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
 * Prints the entire hexdump output if hex is requested output style
 * */
void printHexSolution(char *fname) {
    ifstream file(fname, std::ios::binary);
    char currentSixteen[16];
    int addr = 0;
    long charCount;
    while (file.read(currentSixteen, 16)) {  //prints in sets of 16
       charCount = file.gcount();
       printStringAddr(addr);
       printHexString(currentSixteen, charCount);
       printValidASCII(currentSixteen, charCount);
       addr+=16;
    }
    charCount = file.gcount();
    if (charCount > 0) {  //if a set of less than 16 is left, the while loop skips it and this if catches it
        printStringAddr(addr);
        printHexString(currentSixteen, charCount);
        printValidASCII(currentSixteen, charCount);
    }
}
/*
 * Prints solution when user invokes the "-b"  flag
 * */
void printBinarySolution(char *fname) {
    ifstream file(fname, std::ios::binary);
    char currentSix[6];
    int addr = 0;
    long charCount;
    while (file.read(currentSix, 6)) {  //solution is printed in sets of 6 
        charCount = file.gcount();
        printStringAddr(addr);
        printBinaryString(currentSix, charCount);
        printValidASCII(currentSix, charCount);
        addr+=6;
    }
    charCount = file.gcount();
    if (charCount > 0) {  //if a set of less than 6 is left, the while loop skips it and this if catches it
        printStringAddr(addr);
        printBinaryString(currentSix, charCount);
        printValidASCII(currentSix, charCount);
    }
}

int main(int argc, char *argv[]) {
    if (strcmp(argv[1], "-b") == 0) {
        printBinarySolution(argv[2]);
    } else {
        printHexSolution(argv[1]);
    }
}