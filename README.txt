Matthew Yamout cssc1002
James Hammon cssc0895
CS 530 Spring 2017
February 12th, 2017
Assignment #1, Hexdump Recreate
README.txt

FILE MANIFEST: 
assign1.cpp
Makefile
header.h




COMPILE INSTRUCTIONS: g++ -std=c++11 assign1.cpp -o xsd

OPERATING INSRUCTIONS:
To operate the program simply type in "xsd <filename>" to perform a hexdump from a given file. You may also perform a binary dump, same as a hex dump but the contents will be output in binary. Do this by typing in "xsd -b <filename>"

DESIGN DECISIONS:
We segmented the program into multiple, short lined methods to increase readability and future enhancements. This structure allows understading of the program. Another major design choice was to read the file input in binary, which helped us deal with newline characters efficiently. Following that we used a buffer array to hold sixteen characters. The size of the buffer array was dependent on if the user called for a hex or binary dump. Last but not least the final major decision in the source code was to add the length flag to the .read function in our while loops. Therefore depending on what dump the user is using the buffer is only filled with the right amount of characters.

EXTRA FEATURES/ALGORITHMS/FUNCTIONALITY:
Our group used no unrequired methods

KNOWN DEFICIENCES OR BUGS:
Our program follows the spec, as well as the 'xxd' unix command, and has exhibited no bugs

LESSONS LEARNED:
A major takeaway from the project first and foremost was the introduction to C++ that the program gave us. This was both our first times working in C++ and we had a lot to pick up quickly. Finally, how a file is read in C++ was a valuable piece of knowledge gained. When we first started working on the program we had some issues reading the characters correctly because the "newline character" was giving us a hard time.
