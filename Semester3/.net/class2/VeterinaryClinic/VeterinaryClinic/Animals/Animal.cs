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
    string _name;
    string _description;
    int _age;

    public string Name
    {
        get { return _name; }
        set
        {
            _validations.ValidateToNormal(value);
            _validations.ValidateByList(availableName, value);
            _name = value;
        }
    }

    public string Description
    {
        get { return _description; }
        set
        {
            _validations.ValidateToNormal(value);
            _description = value;
        }
    }

    public int Age
    {
        get { return _age; }
        set
        {
            _validations.ValidateNull(value);
            _age = value;
        }
    }

    protected Animal(string name, int age, string description)
    {
        Name = name;
        Age = age;
        Description = description;
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
}
