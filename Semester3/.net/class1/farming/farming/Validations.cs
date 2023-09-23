using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace farming;

public class Validations
{
    public void ValidateName(string name)
    {
        ValidateNull(name);
        ValidateFirstChar(name);
        ValidateLengthWord(name);
    }

    public void ValidateFirstChar(string word)
    {
        char upperFirstChar = word.ToUpper()[0];
        if (word[0] != upperFirstChar) throw new FirstCharError(word);
    }
    
    public void ValidateLengthWord(string word)
    {
        if (word.Length < 3) throw new LengthWordError(word);
    }

    public void ValidateNull(object value)
    {
        if (value == null) throw new ArgumentNullException();
    }
}

[Serializable]
public class FirstCharError : Exception
{
    public FirstCharError(string word) 
        : base($"Invalid word. Set word from upper char {word} -> {word.ToUpper()[0] + word.Substring(1, word.Length - 1)}")
    {}
}

public class LengthWordError : Exception 
{
    public LengthWordError(string word)
        : base($"{word}")
    {}
}


