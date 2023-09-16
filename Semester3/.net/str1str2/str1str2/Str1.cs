using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace str1str2;

class Str1
{
    public void Ex2()
    {
        string text = "Hello world";
        text = "begin" + text + "end";
        Console.WriteLine(text);
        Console.WriteLine($"Length: {text.Length}");
    }
    public void Ex7()
    {
        string[] wordArray = {"Hello", "World", "What`s", "Your", "Name" };
        string[] wordArrayNew = wordArray.Select(word => word + "!").ToArray();
        ShowArray(wordArrayNew);
    }
    public void Ex12()
    {
        string text = "H!ello!World";
        string[] arraySplitBySymbol = text.Split("!");
        Console.WriteLine(arraySplitBySymbol[1]);
    }

    public void ShowArray(string[] array)
    {
        foreach(string word in array)
        {
            Console.WriteLine(word);
        }
    }

}
