using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VeterinaryClinic;

public class Doctor
{
    Validations _validations = new Validations();

    string _firstName
    {
        set
        {
            _validations.ValidateToNormal(value);
            _firstName = value;
        }
        get { return _firstName; }
    }
    string _lastName
    {
        set
        {
            _validations.ValidateToNormal(value);
            _lastName = value;
        }
        get { return _lastName; }

    }
    int _age
    {
        set
        {
            _validations.ValidateInt(18, 70, value);
            _age = value;
        }
        get { return _age; }
    }
    bool _busy = false;

    public Doctor(string firstName, string lastName, int age)
    {
        _firstName = firstName;
        _lastName = lastName;
        _age = age;
    }

    public string Info()
    {
        return $"Full name: {_firstName} {_lastName}. Age: {_age}. Is busy?: {_busy}";
    }

    public void ShowInfo()
    {
        Console.WriteLine(Info());
    }

    public void ChangeWorkStatus(bool status)
    {
        _busy = status;
    }

    public bool IsBusy()
    {
        return _busy;
    }
}
