using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VeterinaryClinic.Animals;

internal class Dog : Animal
{
    public Dog(string name, int age, string description = "Dog") 
        : base(name, age, description) {}

    public override string Sound()
    {
        return "bow-vow, arf-arf!";
    }
}
