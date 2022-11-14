#include<iostream>
#include <string>
#include "color.h"

using namespace std;

void array_text(string main_text, char *word_array, string indent)
{
    int i, j=0; // j - index for counts columns

    for (i = 0; i < main_text.size(); i++) //cycle 
    {
        if (main_text[i] == ' ') // if symbol = space, then check user selection
        {
            if (indent == "1")
                word_array[j] = '\n'; //move to a new line
            else
                word_array[j] = ' '; // add space
            j++; // move to new char in the result array
        }
        else // if symbol != space 
        {
            word_array[j] = main_text[i]; // add char by index to the result array
            j++; // move to a new char in the result array
        }
    }
}

int main()
{
    string text, select;

    SC(10, 0);//Green
    cout << "--------------------FINISH LAB WORK--------------------\n\n";
    SC(15, 0);//White

    cout << "Write your text: ";
    SC(10, 0)/*green*/;
    getline(cin, text);
    
    SC(12, 0);//Red
    cout << "\nWrite (1) if you want to move each word to a new line: ";
    SC(10, 0)/*green*/;
    getline(cin, select);

    SC(15, 0);//White
    cout << "\n\n-------------------------RESULT------------------------\n\n";
    SC(10, 0);//Green

    char* word_array = new char[text.size()];

    array_text(text, word_array, select);

    for (int i = 0; i < text.size(); i++)
        cout << word_array[i];

    cout << "\n\n";

    SC(15, 0);//White

    return 0;
}
