using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VeterinaryClinic.Animals;

public class Cat : Animal
{
    public Cat(string name, int age, string description = "Cat") 
        : base(name, age, description) {}

    public override string Sound()
    {
        return "meaou neaou mew-mew!";
    }
}
