using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VeterinaryClinic;

public class Validations
{
    public void ValidateToNormal(string name)
    {
        ValidateNull(name);
        ValidateFirstChar(name);
        ValidateLength(name);
    }

    public void ValidateFirstChar(string word)
    {
        char upperFirstChar = word.ToUpper()[0];
        if (word[0] != upperFirstChar) throw new FirstCharError(word);
    }

    public void ValidateLength(string text)
    {
        if (text.Length < 1 || text.Length > 100) throw new LengthWordError(text);
    }

    public void ValidateNull(object? value)
    {
        if (value == null) throw new ArgumentNullException();
    }

    public void ValidateByList(List<string> list, string value) 
    {
        if (!list.Contains(value)) throw new ElementNotFound(list, value);
    }
    
    public void ValidateInt(int min, int max, int value)
    {
        if ((value < min) || (value > max)) throw new ArgumentOutOfRangeException();
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
        : base($"Element: {element} not found in the list: {String.Join(", ", list)}")
    { }
}

public class DoctorBusy : Exception
{
    public DoctorBusy(Doctor doctor)
        : base($"Doctor {doctor.Info()} is not available now! Come back again soon!")
    { }
}
