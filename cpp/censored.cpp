#include <iostream>
#include <string>

using std::endl;
using std::cout;

void uncensorString(std::string& str1, std::string str2);

int main()
{
    std::string first_str = "*PP*RC*S*";
    std::string second_str = "UEAE";
    uncensorString(first_str, second_str);

    cout << first_str << endl;

    return 0;
}

void uncensorString(std::string& str1, std::string str2)
{
    int j = 0;
    for (unsigned int i = 0; i < str1.length(); ++i){
        if (str1[i] == '*'){
            str1[i] = str2[j++];
        }
    }
}