#include <iostream>
#include <sstream>
#include <string>

int main()
{

    // M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1

    // Prompt for date
    std::string date; 
    std::cout << "Enter a date: ";
    std::getline(std::cin,date);
    std::stringstream ss;

    int dsize = date.size();

    std::stringstream date1;
    std::stringstream date10;
    std::stringstream date100;
    std::stringstream date1000;

    // Isolate each base of the string date
    if (dsize == 4){
        date1 << date.substr(3);
        date10 << date.substr(2);
        date100 << date.substr(1);
        date1000 << date.substr(0);
    } else if (dsize == 3){
        date10 << date.substr(2);
        date100 <<date.substr(1);
        date1000 << date.substr(0);
    } else if (dsize == 2){
        date100 << date.substr(1);
        date1000 << date.substr(0);        
    } else if (dsize == 1)
        date1000 << date.substr(0);  
    
    // Convert the string bases to the integers 
    int x1; date1 >> x1;
    int x10; date10 >> x10;
    int x100; date100 >> x100;
    int x1000; date1000 >> x1000;

    switch(dsize){
        case 4:
            for (int i = 0; i < (x1000/1000); i++)
                    ss << "M";
        case 3:
            if (x100/100 == 9)
                ss << "CM";
            else if (x100 >= 500 && x100 < 900){
                ss << 'D';
                for (int i = 0; i < (x100 % 500)/100; i++)
                    ss << "C";
            }
            else if (x100/100 == 4) ss << "CD";
            else if (x100 < 400)
                for (int i = 0; i < (x100 % 500)/100; i++)
                    ss << "C";

        case 2:
            if (x10/10 == 9)
                ss << "XC";
            else if (x10 >= 50 && x10 < 90){
                ss << 'L';
                for (int i = 0; i < (x10 % 50)/10; i++)
                    ss << "X";
            }
            else if (x10/10 == 4) ss << "XL";
            else if (x10 < 40)
                for (int i = 0; i < (x10 % 50)/10; i++)
                    ss << "X";

        case 1:
            if (x1 == 9)
                ss << "IX";
            else if (x1 >= 5 && x1 < 9){
                ss << 'V';
                for (int i = 0; i < x1 % 5; i++)
                    ss << "I";
            }
            else if (x1 == 4) ss << "IV";
            else if (x1 < 4)
                for (int i = 0; i < x1 % 5; i++)
                    ss << "I";
    }                 

    std::cout << ss.str() << "\n";


}