using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace Parking;


static public class Validations
{
    static public void ValidateToNormal(string name)
    {
        ValidateNull(name);
        ValidateFirstChar(name);
        ValidateLength(name);
    }

    static public void ValidateFirstChar(string word)
    {
        char upperFirstChar = word.ToUpper()[0];
        if (word[0] != upperFirstChar) throw new FirstCharError(word);
    }

    static public void ValidateLength(string text)
    {
        if (text.Length < 1 || text.Length > 100) throw new LengthWordError(text);
    }

    static public void ValidateNull(object? value)
    {
        if (value == null) throw new ArgumentNullException();
    }

    static public void ValidateByList(List<string> list, string value)
    {
        if (!list.Contains(value)) throw new ElementNotFound(list, value);
    }

    static public void ValidateInt(int min, int max, int value)
    {
        if ((value < min) || (value > max)) throw new ArgumentOutOfRangeException();
    }

    static public void ValidateDateOnGreaterThanPresent(DateTime date)
    {
        if (date > DateTime.Now) { throw new GreaterThanPresentError(date); }
    }
}


[Serializable]
public class FirstCharError : Exception
{
    public FirstCharError(string word)
        : base($"Invalid word. Set word from upper char {word} -> {word.ToUpper()[0] + word.Substring(1, word.Length - 1)}")
    { }
}

public class LengthWordError : Exception
{
    public LengthWordError(string word)
        : base($"{word}")
    { }
}

public class ElementNotFound : Exception
{
    public ElementNotFound(List<string> list, string element)
        : base($"Element not found in the list.")
    { }
}

public class GreaterThanPresentError : Exception
{
    public GreaterThanPresentError(DateTime? date) 
        : base($"Date: {date?.ToString("yyy, dd, MM")} greater than the present.")
    { }
}