using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VeterinaryClinic.Animals;

public abstract class Animal
{
    Validations _validations = new Validations();
    List<string> availableName = new List<string>()
    {
        "Badger", "Giraffe", "Cobra", "Hawk", "Deer", "Ibex", "Jaguar",
    };

    string _name 
    {
        set
        {
            _validations.ValidateToNormal(value);
            _validations.ValidateByList(availableName, value);
            _name = value;
        }
        get { return _name; }
    }
    string _description
    {
        set
        {
            _validations.ValidateToNormal(value);
            _description = value;
        }
        get { return _description; }
    }
    int _age
    {
        set
        {
            _validations.ValidateNull(value);
            _age = value;
        }
        get { return _age; }
    }

    protected Animal(string name, int age, string description)
    {
        _name = name;
        _description = description;
        _age = age;
    }

    protected Animal(string name, int age) : this(name, age, "Empty") {}

    public abstract string Sound(); 

    public void CheckTag()
    {
        Console.WriteLine($"Name: {_name}\nAnimal description: {_description}\nAge: {_age}");
    }

    public void Voice()
    {
        Console.WriteLine(Sound());
    }

    public string GetName()
    {
        return _name;
    }

}
