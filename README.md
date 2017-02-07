UPDATE, NEW WAY TO COMPILE: tested to see if Edoras has the latest C++11 complier and it does so complie this to use it
g++ -std=c++11 file_name -o outputfilename

We need to handle:
  - File not found
  - Print address of each file line (haven't figured this out yet)
  - Printing newlines after certain amount of bits have been printed (working on this rn for the -b flag)
