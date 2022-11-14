#include <iostream>
#include <string>
using namespace std;

string print_in_column(string);

string print_in_column(string self_text) //creating a funcion for separation on 3 colums
{
    int counter = 0;  //index for separation on 3 colums
    string result_text;  //for the record result text

    for (int i = self_text.size() - 1; i >= 0; i--) // function which begins at the end of
    {
        if (counter == 3) // check if the number of columns is 3
        {
            result_text = result_text + "\n"; // if the columns are equal to 3, then go to the new line
            counter = 0; //zeroing
        }
        else
        {
            result_text = result_text + self_text[i] + " "; //add symbol by index to the result text
            counter += 1; // plus 1 to index
        }
    }
    return result_text;
}

int main()
{
    string text, result;

    cout << "Write your characters via spaces: "; getline(cin, text);
    
    result = print_in_column(text);

    cout << print_in_column(text);

    return 0;
}
