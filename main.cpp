#include <iostream>
#include <algorithm>
#include <ctype.h>

using namespace std;

/*
 *  PigLatin program
 */
bool isVowel(char c);
string rot(string p);
string pigLatinString(string p2);

// Checks if char c is a vowel
bool isVowel(char c) 
{
    switch (tolower(c)) 
    {
        case 'a' : 
        case 'e' : 
        case 'i' : 
        case 'o' : 
        case 'u' : 
        case 'y' : 
            return true;
        default  : 
            return false;
    }
}
// Rotates characters until the first character in string p is a vowel
// then appends "ay" to the end of the string
string rot(string p) 
{

    while (true) 
    {
        if (isVowel(p.at(0)))
            return p.append("ay");
        else
            rotate(p.begin(), p.begin() + 1, p.end());       
    }
}
// Translates p2 into piglatin and returns string
string pigLatinString(string p2) 
{
    int length = p2.length();
    bool noVowels = true;
    
    for (int i = 0; i < length; i++)
        if(isVowel(p2.at(i)))
            noVowels = false;
    
    if (isVowel(p2.at(0)))
        return p2.append("-way"); 
    else if (noVowels == true)
        return p2.append("-way"); 
    else 
    {
        p2.append("-");
        return rot(p2);
    }
}

int main() 
{
    string word;
    
    cout << "WELCOME TO RAVI AND BRYAN'S PIGLATIN PROGRAM!" << endl;
    cout << endl;
    cout << "(Type the number 2 to quit the program...)" << endl;
    cout << endl;
    
    while(true) 
    {
        cout << "Enter a word to translate to Piglatin: ";
        cin >> word;
        
        if(word == "2") 
        {
            cout << "Goodbye!" << endl;
            break;
        }    
           
        cout << pigLatinString(word) << endl;
    }

    return 0;
}

