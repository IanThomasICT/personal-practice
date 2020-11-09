#include <iostream>
// cool is cool -> 12

int cstringLength(char []);

int main()
{
  char cstring[1000];  // capacity = 1000
  std::cout << "Enter your string: ";
  std::cin.getline(cstring, 1000);
  std::cout << cstring << " is your string.\n";

  int length = cstringLength(cstring);
  
  // Reverse entire cstring
  for (int i = 0; i < (length / 2); i++)
  {
    char a = cstring[i], b = cstring[length - (i+1)];
    // swap values
    cstring[i] = b;
    cstring[length - (i+1)] = a;
  }


  return 0;
}

// Find string length
int cstringLength(char cstring[])
{
  int length = 0;
  for(int i = 0; cstring[i] != '\0'; i++)
    length++;
  return length;
}
