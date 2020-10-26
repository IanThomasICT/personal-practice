#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <sstream>

// Random Generator
std::random_device                        entropy;
std::mt19937                    engine(entropy());
std::uniform_int_distribution<char> lett('A','Z');
std::uniform_int_distribution<int>   num(100,999);

std::string createRobot(std::vector<std::string> robots);
void listRobots(std::vector<std::string> robots);

int main()
{
    std::vector<std::string> robots;
    
    // Prompt (Create, List, Wipe)
    char input;
    std::cout << "What would you like to do?\n" 
              << "   C. Create a new robot\n"
              << "   L. List existing robots\n"
              << "   W. Wipe a robot\n"
              << "   X. Exit program\n";
    
    do {
        std::cin >> input;
        std::cin.ignore();

        input = toupper(input);

        switch(input){
            // Create Function
            case 'C': 
                robots.push_back(createRobot(robots)); 
                break;
            // List Function
            case 'L': 
                std::cout << "Generating a list of robots...\n";
                listRobots(robots); 
                break;
            // Wipe Function
            case 'W': 
                std::cout << "Which robot would you like to wipe? ";
                std::string name1;
                std::getline(std::cin,name1);
                std::cout << "Wiping " << name1 << "...\n";
                for (unsigned int i = 0; i < robots.size(); i++)
                    if (name1 == robots[i])
                        robots[i] = createRobot(robots);
                break;
                
            // default: 
            //     std::cout << "Bad input. Please try again..\n"; 
            //     break;
        }
    } while (input != 'X');

    return 0;

}

std::string createRobot(std::vector<std::string> robots)
{
    std::stringstream name;
    name << lett(engine) << lett(engine) << num(engine);
    
    // Check if name already exists
    for (auto e : robots)
        if (name.str() == e)
            createRobot(robots);

    std::cout << "Creating a new robot: " << name.str() << "\n";

    return name.str();
}

void listRobots(std::vector<std::string> robots)
{
    for (auto e : robots) 
        std::cout << e << "\n";
}