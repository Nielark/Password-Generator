#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0)); // Random seed.
    const string specialKeys = ";,:.+-*/%><=!~^&|[]{}()";     // 23 Special Characters
    const string numbers = "0123456789";                      // 10 Numbers
    const string letterLower = "abcdefghijklmnopqrstuvwxyz";  // 26 Lowercase Letters
    const string letterUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // 26 Uppercase Letters
    const int specKeySize = 23, numberSize = 10, letterLowerSize = 26, letterUpperSize =26;
    int totalChar, passwordLen;
    totalChar = specKeySize + numberSize + letterLowerSize + letterUpperSize;
    string characters = specialKeys + numbers + letterLower + letterUpper; // Concatenating the strings.
    string password;

    top:
    cout << "P A S S W O R D  G E N E R A T O R\n\n";
    cout << ">> Note: To exit the program just input 0. <<\n\n";
    cout << "Enter the length for the password: ";
    cin >> passwordLen;
    cout << endl;

    if(passwordLen >= 8 && passwordLen != 0){
        for(int i = 0; i < passwordLen; i++){
            int randNum = 0 + (rand() % totalChar - 1); // Random number generator from 0 up to the totalChar.
            password += characters[randNum];
        }

        cout << "Generated Password: " << password << endl;
    }
    else if(passwordLen == 0){
        return 0; // terminate the program.
    }
    else{
        cout << "Password length must be eight(8) characters or greater.\n";
    }

    cout << endl;

    system("PAUSE");
    system("CLS");
    password = ""; // Initialize back to NULL.
    goto top;
}
