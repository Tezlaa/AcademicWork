using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace farming;

public class Farmer : Validations
{
    public event EventHandler<PlantGrownEventArgs> PlantGrown;

    Farm _subscribeFarm;
    Plant _subscribePlant;

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

    public void subscribeOnGrowing(Farm farm, Plant plant)
    {
        _subscribeFarm = farm;

        _subscribePlant = farm.PlantsOnGrowing.Find(growingPlant => growingPlant == plant);
        ValidateNull(_subscribePlant);

        _subscribePlant.PlantGrown += HandlePlantGrown;
    }

    public void unsubscribeOnGrowing()
    {
        _subscribePlant.PlantGrown -= HandlePlantGrown;
    }

    public void HandlePlantGrown(object sender, PlantGrownEventArgs e)
    {
        _subscribeFarm.DeletePlant(e.Plant);

        Console.WriteLine($"\nPlant is grown! \n{Specialzation} {FirstName} {LastName} harvested the {e.Plant.FullName}");
        if (e.Plant.IsNeedRegrow)
        {
            _subscribeFarm.AddPlant(e.Plant);
            Console.WriteLine("Planting a new one...");
        }

        PlantGrown?.Invoke(this, e);
    }
}