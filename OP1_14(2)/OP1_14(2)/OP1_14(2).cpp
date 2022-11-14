#include<iostream>
#include <string>
#include "color.h"

using namespace std;

void array_text(string main_text, char *word_array, string indent)
{
    int i, j=0;

    for (i = 0; i < main_text.size(); i++)
    {
        if (main_text[i] == ' ')
        {
            if (indent == "1")
                word_array[j] = '\n';
            else
                word_array[j] = ' ';
            j++;
        }
        else
        {
            word_array[j] = main_text[i];
            j++;
        }
    }
}

int main()
{
    string text, select;

    SetColor(10, 0);//Green
    cout << "--------------------FINISH LAB WORK--------------------\n\n";
    SetColor(15, 0);//White

    cout << "Write your text: ";
    SetColor(10, 0)/*green*/;
    getline(cin, text);
    
    SetColor(12, 0);//Red
    cout << "\nWrite (1) if you want to move each word to a new line: ";
    SetColor(10, 0)/*green*/;
    getline(cin, select);

    SetColor(15, 0);//White
    cout << "\n\n-------------------------RESULT------------------------\n\n";
    SetColor(10, 0);//Green

    char* word_array = new char[text.size()];

    array_text(text, word_array, select);

    for (int i = 0; i < text.size(); i++)
        cout << word_array[i];

    cout << "\n\n";

    SetColor(15, 0);//White
    return 0;
}
