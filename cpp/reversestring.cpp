// Supplemental Instruction

// Pair Programming 

#include <iostream>
#include <string>

using namespace std;

// fucntion 
// reverseSubStr(a, b, &str);
// this is nice
// reverseSubStr(0, 3, &str);
// siht is nice

void reverseSubStr(int, int, string&);

int main()
{
  cout << "Please enter your string: ";
  string input;
  getline(cin,input);

  cout << input << endl;
  
  int s = 0, e = 0;
  
  // Reverses the spelling of each word
  // I.e. "this is great" becomes "siht si taerg"
  for (int i = 0; i < input.length(); i++)
  {
    // start & middle words
     
    if (input[i] == ' ')
      reverseSubStr(s, i - 1, input);
    else if (input[i - 1] == ' ' && input[i] != ' ') 
      s = i;  

    // last word
    if (i == input.length() - 1 && input[i] != ' ')
      reverseSubStr(s, i, input);
  }

  // Reverses the reveresed-spelled string to switch the order of the words
  // I.e. "siht si taerg" becomes "great is this"
  reverseSubStr(0, input.length() - 1, input);
  cout << input << endl;

  return 0;
}

void reverseSubStr(int start, int end, string& inputString)
{
  // uses swap(x,y) function to swap two index values in a string

  while (start <= end)
    swap(inputString[start++],inputString[end--]);
  
}