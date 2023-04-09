#include<iostream>
#include <string>
#include "color.h"

using namespace std;

void array_text(string main_text, string *word_array)
{
    int i, j=0; // j - index for counts word in the result array 

    for (i = 0; i < main_text.size(); i++) //cycle 
    {
        if (main_text[i] == ' ') // if symbol
        {
            j++; // move to new word in the array
        }
        else // if symbol != space 
        {
            word_array[j] += main_text[i]; // add char by index to the result array
        }
    }
}

int count_word_in_text(string main_text) //check count word in text 
{
    int result_counter = 0;
    for (int i = 0; i < main_text.size(); i++)
    {
        if (main_text[i] == ' ')
        {
            result_counter += 1;
        }
    }
    if (main_text[main_text.size()] != ' ') // to correct where the last char is a space
    {
        result_counter += 1;
    }

    return result_counter;
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

    if (select == "1") // check user selection
        select = "\n"; //replacement on new line
    else
        select = ' '; //replacement on space

    SC(15, 0);//White
    cout << "\n\n-------------------------RESULT------------------------\n\n";
    SC(10, 0);//Green

    int count_word = count_word_in_text(text); 

    string* word_array = new string[count_word];

    array_text(text, word_array);

    for (int i = 0; i < count_word; i++)
        cout << word_array[i] + select;

    cout << "\n\n";

    SC(15, 0);//White

    return 0;
}
