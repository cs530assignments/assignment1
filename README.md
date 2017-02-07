UPDATE, NEW WAY TO COMPILE: tested to see if Edoras has the latest C++11 complier and it does so complie this to use it
g++ -std=c++11 file_name -o outputfilename

- Printing newline for binary works now
- Rethinking to grab everything character by character instead of line by line

We need to handle:
  - File not found
  - Print address of each file line (haven't figured this out yet)
  - Print newline after x characters for hex (default setting)
