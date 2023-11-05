using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Collection;

public class ValidBrackets
{
    public ResultBrackets IsCorrect(string line)
    {
        Stack<char> stack = new Stack<char>();
        Dictionary<char, char> keyValuePairs = new Dictionary<char, char>();
        keyValuePairs.Add(')', '(');
        keyValuePairs.Add(']', '[');
        keyValuePairs.Add('}', '{');

        for (int i = 0; i < line.Length; i++)
        {

            if (line[i] == '(' || line[i] == '{' || line[i] == '[')
            {
                stack.Push(line[i]);
            }
            else if (line[i] == ')' || line[i] == '}' || line[i] == ']')
            {
                char last = stack.Pop();
                Console.WriteLine(line[i]);
                Console.WriteLine(last);
                if (keyValuePairs[line[i]] != last)
                {
                    return new ResultBrackets(false, i);
                }
            }
        }
        if (stack.Count != 0 || line[line.Length - 1] == ':')
        {
            return new ResultBrackets(false, line.Length);
        }
        return new ResultBrackets(true, line.Length);
    }
}


public readonly struct ResultBrackets
{
    public ResultBrackets(bool isValid, int? unvalidIndex)
    {
        _isValid = isValid;
        _unvalidIndex = unvalidIndex;
    }

    public bool _isValid { get; init; }
    public int? _unvalidIndex { get; init;}

    public override string ToString() => $"Is valid: {_isValid}, Unvalid index: {_unvalidIndex}";
}