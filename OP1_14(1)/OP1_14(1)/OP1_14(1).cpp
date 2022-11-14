#include <iostream>
#include <string>
using namespace std;

string print_in_column(string);

string print_in_column(string self_text) //creating a funcion for separation on 3 colums
{
    int counter = 0;  //index for separation on 3 colums
    string result_text ="";  //for the record result text

    for (int i = self_text.size(); i >= 0; i--) // function which begins at the end of
    {
        if (counter == 3) // check if the number of columns is 3
        {
            result_text = result_text + "\n"; // if the columns are equal to 3, then go to the new line
            counter = 0; //zeroing
            i++; //go back to the previous index
        }
        else
        {
            if (self_text[i] == '\0') //if the last char
            {
                result_text = result_text + self_text[i - 1] + " "; //if this symbol is the first add next char
                i--; //not to go out of range
            }
            else
            {
                result_text = result_text + self_text[i] + " "; //add symbol by index to the result text
            }
            counter += 1; //plus 1 to index
        }
    }
    return result_text;
}

int main()
{
    string text, result;

    cout << "Write your number: "; getline(cin, text);
    
    result = print_in_column(text);

    cout << print_in_column(text);

    return 0;
}
