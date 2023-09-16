using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace str1str2;

class Str2 : Str1
{
    public void Ex3()
    {
        string text = "Hello, world";
        int lastComma =text.LastIndexOf(",");
        Console.WriteLine($"Index: {lastComma}");
    }
    public int Ex8()
    {
        string text = "Helaaalo, waaorlad";
        int indexSymbol = text.IndexOf("a", 0);
        if (indexSymbol == -1) return 0;

        int counter = 1;
        int resultCounter = 0;

        for (int i = indexSymbol; i < text.Length; i++)
        {
            int nextSymbol = text.IndexOf("a", i + 1);
            if (nextSymbol == i + 1)
            {
                counter++;
            }
            else
            {
                resultCounter = Math.Max(counter, resultCounter);
                counter = 1;
                if (nextSymbol == -1)
                {
                    break;
                }
                i = nextSymbol - 1;
            }
        }
        return resultCounter;
    }
    public void Ex13()
    {
        string text = "Hello world what`s your name";
        string[] textArray = text.Split(" ");
        ShowArray(textArray);
    }
}
