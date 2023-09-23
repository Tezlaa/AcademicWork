using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace farming;

public class Farmer : Validations
{
    private Plant currentPlant;
    public event EventHandler<PlantGrownEventArgs> PlantGrown;

    string _firstName;
    string _lastName;
    string _specialzation;

    public string FirstName
    {
        get
        {
            return _firstName;
        }
        set
        {
            ValidateName(value); _firstName = value;
        }
    }
    public string LastName
    {
        get
        {
            return _lastName;
        }
        set
        {
            ValidateName(value); _lastName = value;
        }
    }
    public string Specialzation
    {
        get
        {
            return _specialzation;
        }
        set
        {
            ValidateName(value); _specialzation = value;
        }
    }

    public Farmer(string firstName, string lastName, string specialzation)
    {
        FirstName = firstName;
        LastName = lastName;
        Specialzation = specialzation;
    }

    public void AssignPlant(Plant plant)
    {
        if (currentPlant != null)
        {
            currentPlant.PlantGrown -= HandlePlantGrown;
            currentPlant.StopGrowing();
        }

        currentPlant = plant;
        currentPlant.PlantGrown += HandlePlantGrown;
        currentPlant.StartGrowing();
    }
    public void HandlePlantGrown(object sender, PlantGrownEventArgs e)
    {
        Console.WriteLine($"\nPlant is grown! \n{Specialzation} {FirstName} {LastName} harvested the {e.Plant.FullName}");
        if (e.Plant.IsNeedRegrow)
        {
            Console.WriteLine("Planting a new one...");
        }

        PlantGrown?.Invoke(this, e);
    }
}