/* Given students' names along with the grade that they are in, create a roster for the school.

In the end, you should be able to:

Add a student's name to the roster for a grade
"Add Jim to grade 2."
"OK."
Get a list of all students enrolled in a grade
"Which students are in grade 2?"
"We've only got Jim just now."
Get a sorted list of all students in all students. students should sort as 1, 2, 3, etc., and students within a grade should be sorted alphabetically by name.
"Who all is enrolled in school right now?"
"Grade 1: Anna, Barb, and Charlie. Grade 2: Alex, Peter, and Zoe. Grade 3…"
Note that all our students only have one name. (It's a small town, what do you want?)
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <utility>
#include <algorithm>

using namespace std;
int convertGrade(string grd);
std::pair<string,int> parseString(string input);
void printGrade(int gradenum, vector<std::pair<string,int>> students);
void printStudents(vector<std::pair<string,int>> students);
void bubble_sort(vector<std::pair<string,int>> &students);


// TODO
// Fix printStudents function which prints all students sorted by class/alphabetically
// Fix printGrade funciton
// Add verbiage to answers that matches instructions


int main()
{
    string input;

    vector<std::pair<string,int>> students;
    
    do 
    {
        cout << "What would you like to do?" << "\n"
             << "   'Add [name] to grade __'" << "\n"
             << "   'Which students are in grade __?'" << "\n"
             << "   'Who all is enrolled in school right now?'" << "\n"
             << "   'Done'" << "\n";

        getline(cin,input);

        string command = input.substr(0,3);

        cout << "\n";
        for (int i = 0; i < 3; i++)
            command[i] = toupper(command[i]);

        cout << command << "\n";

        if (command == "ADD"){
            cout << "Add adding a student...\n\n";
            string name = parseString(input).first;
            int grade = parseString(input).second;
            // Add student to vector
            students.push_back(make_pair(name,grade));
         
        } else if (command == "WHI"){
            cout << "Checking for students...\n\n";
            string grade = input.substr(input.size()-3);
            grade = grade.substr(grade.find(' ')+1, grade.find('?')-1);
            int gradenum = convertGrade(grade);

            printGrade(gradenum, students);

        } else if (command == "WHO"){
            printStudents(students);
        }

    } while (input != "DONE");
    
    return 0;
}

// Extracts name and grade of the student from a given string
pair<string,int> parseString(string input)
{
    string tmp = input.substr(4);
    string name = tmp.substr(0,tmp.find(' ')); 
    for (unsigned int i = 0; i < name.size(); i++)
        if (i==0)
            name[i] = toupper(name[i]);
        else
            name[i] = tolower(name[i]);

    string grade = input.substr(input.size()-3);
    grade = grade.substr(grade.find(' ')+1, grade.find('.')-1);
    
    int gradenum = convertGrade(grade);

    return make_pair(name, gradenum);
}

// Returns the int of a passed string with a grade 1-12
int convertGrade(string grd)
{
    for (int i = 1; i <= 12; i++){
        string tmp = std::to_string(i);
        if (grd == tmp)
            return i;
    }

    return 0;
}


void printGrade(int gradenum, vector<std::pair<string,int>> students)
{
    
    unsigned long size = students.size();
    // Bubble sort vector
    bubble_sort(students);

    for (unsigned int i = 0; i < students.size(); i++){
        if (students[i].second == gradenum && 
            students[i+1].second == students[i].second)
            cout << students[i].first << ", ";
        
        if (students[i].second == gradenum && 
            students[i].second == students[i-1].second &&
            students[i].second > students[i+1].second)
            cout << "and " << students[i].first << " are in grade " << gradenum << ".";
    }
    // for (auto e : students)
    //     std::cout << e.first << " " << e.second << "\n";
    
    cout << endl;
}

void printStudents(vector<std::pair<string,int>> students)
{
    // Bubble sort vector
    bubble_sort(students);

    for (unsigned int i = 0; i < students.size(); i++){
        if (i == 0 || students[i-1].second != students[i].second)
            cout << "Grade " << students[i].second << ": ";

        else if (students[i-1].second == students[i+1].second)    
            cout << students[i].first << ", ";

        else if (students[i].second == students[i-1].second &&
            students[i].second > students[i+1].second)
            cout << "and " << students[i].first << ".";
    }
    // for (auto e : students)
    //     std::cout << e.first << " " << e.second << "\n";
    
    cout << endl;   
}

void bubble_sort(vector<std::pair<string,int>> &students)
{
    // Bubble sort until array is fully sorted
    bool sorted = false;
    while (sorted != true){
        bool swapped = false;

        // Sorts greater int value pairs to the left
        for (unsigned int j = 1; j < students.size(); j++)
            if (students[j].second > students[j-1].second){
                std::swap(students[j],students[j-1]);
                swapped = true;
            }


        // Sorts alphabetically pairs with the same int value
        for (unsigned int b = 1; b < students.size(); b++)
            if (students[b].second == students[b-1].second)
                if (students[b].first < students[b-1].first){
                    std::swap(students[b],students[b-1]);
                    swapped = true;
                }

        // Break loop when Bubble sorting is finished
        if (swapped == false)
            sorted = true;
    }
}