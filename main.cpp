#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>

void menu(bool includNum, bool includSpecChar, bool includLowerCase, bool includUpperCase);
void generatePassword(bool regenPassword);
void clean();

using namespace std;

int totalChar, passwordLen;
string characters;

int main()
{
    const string specialKeys = ";,:.+-*/%><=!~^&|[]{}()";     // 23 Special Characters
    const string numbers = "0123456789";                      // 10 Numbers
    const string letterLower = "abcdefghijklmnopqrstuvwxyz";  // 26 Lowercase Letters
    const string letterUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // 26 Uppercase Letters
    const int specKeySize = 23, numberSize = 10, letterLowerSize = 26, letterUpperSize =26;
    bool includNum = false, includSpecChar = false, includLowerCase = false, includUpperCase = false;
    bool regenPassword = false;
    char choice, genAgain;

    enterChoice:
    while(true){
        menu(includNum, includSpecChar, includLowerCase, includUpperCase); // Display the choices.

        // Selection of password combination starts.
        cout << "Enter your choice for the combination of the password: ";
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

            case '5':
                goto next;
                break;

            case '0':
                return 0;
                break;

            default:
                cout << "Invalid Input\n";
                clean();
                goto enterChoice;
        }
        system("CLS");
    }

    next:
    // Conditions for the selected password combination.
    if(includNum == true && includSpecChar == false && includLowerCase == false && includUpperCase == false){
        totalChar = numberSize;
        characters = numbers;
        generatePassword(regenPassword);
    }
    else if(includNum == false && includSpecChar == true && includLowerCase == false && includUpperCase == false){
        totalChar = specKeySize;
        characters = specialKeys;
        generatePassword(regenPassword);
    }
    else if(includNum == false && includSpecChar == false && includLowerCase == true && includUpperCase == false){
        totalChar = letterLowerSize;
        characters = letterLower;
        generatePassword(regenPassword);
    }
    else if(includNum == false && includSpecChar == false && includLowerCase == false && includUpperCase == true){
        totalChar = letterUpperSize;
        characters = letterUpper;
        generatePassword(regenPassword);
    }
    else if(includNum == true && includSpecChar == true && includLowerCase == false && includUpperCase == false){
        totalChar = numberSize + specKeySize;  // Adding the sized of selected characters.
        characters = numbers + specialKeys;    // Concatenating the selected char for password combination.
        generatePassword(regenPassword);
    }
    else if(includNum == true && includSpecChar == false && includLowerCase == true && includUpperCase == false){
        totalChar = numberSize + letterLowerSize;
        characters = numbers + letterLower;
        generatePassword(regenPassword);
    }
    else if(includNum == true && includSpecChar == false && includLowerCase == false && includUpperCase == true){
        totalChar = numberSize + letterUpperSize;
        characters = numbers + letterUpper;
        generatePassword(regenPassword);
    }
    else if(includNum == false && includSpecChar == true && includLowerCase == true && includUpperCase == false){
        totalChar = specKeySize + letterLowerSize;
        characters = specialKeys + letterLower;
        generatePassword(regenPassword);
    }
    else if(includNum == false && includSpecChar == false && includLowerCase == true && includUpperCase == true){
        totalChar = letterLowerSize + letterUpperSize;
        characters = letterLower + letterUpper;
        generatePassword(regenPassword);
    }
    else if(includNum == true && includSpecChar == true && includLowerCase == true && includUpperCase == false){
        totalChar = numberSize + specKeySize + letterLowerSize;
        characters = numbers + specialKeys + letterLower;
        generatePassword(regenPassword);
    }
    else if(includNum == true && includSpecChar == true && includLowerCase == false && includUpperCase == true){
        totalChar = numberSize + specKeySize + letterUpperSize;
        characters = numbers + specialKeys + letterUpper;
        generatePassword(regenPassword);
    }
    else if(includNum == true && includSpecChar == false && includLowerCase == true && includUpperCase == true){
        totalChar = numberSize + letterLowerSize + letterUpperSize;
        characters = numbers + letterLower + letterUpper;
        generatePassword(regenPassword);
    }
    else if(includNum == false && includSpecChar == true && includLowerCase == true && includUpperCase == true){
        totalChar = specKeySize + letterLowerSize + letterUpperSize;
        characters = specialKeys + letterLower + letterUpper;
        generatePassword(regenPassword);
    }
    else if(includNum == true && includSpecChar == true && includLowerCase == true && includUpperCase == true){
        totalChar = numberSize + specKeySize + letterLowerSize + letterUpperSize;
        characters = numbers + specialKeys + letterLower + letterUpper;
        generatePassword(regenPassword);
    }

    generateAgain:
    cout << "\nGenerate Again? [Y or N]?: ";
    cin >> genAgain;

    if(genAgain == 'Y' || genAgain == 'y'){          // To regenerate a new password combination.
        regenPassword = true;
        generatePassword(regenPassword);
        goto generateAgain;
    }
    else if(genAgain == 'N' || genAgain == 'n'){    // Go back to the menu.
        totalChar = 0;
        includNum = false;
        includSpecChar = false;
        includLowerCase = false;
        includUpperCase = false;
        regenPassword = false;
        system("CLS");
        goto enterChoice;
    }
    else{
        cout << "Invalid Input\n";
        clean();
        goto generateAgain;
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
    cout << "[5] - Next\n";
    cout << "[0] - EXIT\n\n";
    cout << "=====================================\n\n";
}

void generatePassword(bool regenPassword){
    srand(time(0)); // Random seed.
    string password;

    // Generate Password.
    if(regenPassword == false){
        enterPasswordLen:
        cout << "\nEnter the length for the password: ";
        cin >> passwordLen;
        cout << endl;

        if(passwordLen >= 8){
            for(int i = 0; i < passwordLen; i++){
                int randNum = 0 + (rand() % totalChar); // Random number generator from 0 up to the totalChar.
                password += characters[randNum];
            }

            cout << "Generated Password: " << password << endl;
        }
        else{
            cout << "Password length must be eight(8) characters or greater.\n";
            clean();
            goto enterPasswordLen;
        }
    }
    // Regenerate Password.
    else{
        for(int i = 0; i < passwordLen; i++){
            int randNum = 0 + (rand() % totalChar); // Random number generator from 0 up to the totalChar.
            password += characters[randNum];
        }

        cout << "Regenerated Password: " << password << endl;
        regenPassword = false;
    }

    password = "";
}

void clean(){
    system("PAUSE");
    system("CLS");
}
