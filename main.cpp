#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const char allCharacters[] = ";,:.+-*/%><=!~^&|[]{}()0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char letterLower[] = "abcdefghijklmnopqrstuvwxyz";
    const char letterUppers[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char numbers[] = "0123456789";
    const char symbols[] = ";,:.+-*/%><=!~^&|[]{}()";
    int passwordLen;
    srand(time(0));

    cout << "P A S W O R D  G E N E R A T O R\n\n";

    cout << "Enter the length for the password: ";
    cin >> passwordLen;

    for(int i = 0; i < passwordLen; i++){
        int randNum = 0 + (rand() % 70);
        cout << characters[randNum];
    }

    return 0;
}
