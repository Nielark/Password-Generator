#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>

void menu(bool includNum, bool includSpecChar, bool includLowerCase, bool includUpperCase);
void generatePassword();

using namespace std;

int totalChar;
string characters;

int main()
{
    const string specialKeys = ";,:.+-*/%><=!~^&|[]{}()";     // 23 Special Characters
    const string numbers = "0123456789";                      // 10 Numbers
    const string letterLower = "abcdefghijklmnopqrstuvwxyz";  // 26 Lowercase Letters
    const string letterUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // 26 Uppercase Letters
    const int specKeySize = 23, numberSize = 10, letterLowerSize = 26, letterUpperSize =26;
    //totalChar = specKeySize + numberSize + letterLowerSize + letterUpperSize;
    //string characters = specialKeys + numbers + letterLower + letterUpper; // Concatenating the strings.
    bool includNum = false, includSpecChar = false, includLowerCase = false, includUpperCase = false;
    char choice, choiceNum, choiceSpecK, choiceLetterLow, choiceLetterUp;
    char passwordComb[4];

    while(choice != '0'){
        menu(includNum, includSpecChar, includLowerCase, includUpperCase);

        cout << "Select your choice for the combination of the password: ";
        cin >> choice;

        switch(choice){
            case '1':
                if(includNum == false){
                    includNum = true;
                }
                else{
                    includNum = false;
                }
                break;

            case '2':
                if(includSpecChar == false){
                    includSpecChar = true;
                }
                else{
                    includSpecChar = false;
                }
                break;

            case '3':
                if(includLowerCase == false){
                    includLowerCase = true;
                }
                else{
                    includLowerCase = false;
                }
                break;

            case '4':
                if(includUpperCase == false){
                    includUpperCase = true;
                }
                else{
                    includUpperCase = false;
                }
                break;
            case 'x':
                goto next;
        }
    }

    next:
    if(includNum == true){
        totalChar = numberSize;
        characters = numbers;
        generatePassword();
    }
    else if(includSpecChar == true){
        totalChar = specKeySize;
        characters = specialKeys;
        generatePassword();
    }
    else if(includLowerCase == true){
        totalChar = letterLowerSize;
        characters = letterLower;
        generatePassword();
    }
    else if(includUpperCase == true){
        totalChar = letterUpperSize;
        characters = letterUpper;
        generatePassword();
    }
}

void menu(bool includNum, bool includSpecChar, bool includLowerCase, bool includUpperCase){
    cout << "P A S S W O R D  G E N E R A T O R\n\n";
    if(includNum == false){
       cout << "[1] - Include Numbers\n";
    }
    else if(includNum == true){
        cout << "[1] - Exclude Numbers\n";
    }

    if(includSpecChar == false){
        cout << "[2] - Include Special Characters\n";
    }
    else if(includSpecChar == true){
        cout << "[2] - Exclude Special Characters\n";
    }

    if(includLowerCase == false){
        cout << "[3] - Include Lowercase Letters\n";
    }
    else if(includLowerCase == true){
        cout << "[3] - Exclude Lowercase Letters\n";
    }

    if(includUpperCase == false){
        cout << "[4] - Include Uppercase Letters\n";
    }
    else if(includUpperCase == true){
        cout << "[4] - Exclude Uppercase Letters\n";
    }
    cout << "[x] - Exit\n\n";
    cout << ">> Note: To exit the program just input 0. <<\n\n";
}

void generatePassword(){
    srand(time(0)); // Random seed.
    int passwordLen;
    string password;

    cout << "Enter the length for the password: ";
    cin >> passwordLen;
    cout << endl;

    if(passwordLen >= 8 && passwordLen != 0){
        for(int i = 0; i < passwordLen; i++){
            int randNum = 0 + (rand() % totalChar); // Random number generator from 0 up to the totalChar.
            password += characters[randNum];
        }

        cout << "Generated Password: " << password << endl;
    }
    else if(passwordLen == 0){
        return; // terminate the program.
    }
    else{
        cout << "Password length must be eight(8) characters or greater.\n";
    }
}
