using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace farming;

public class Farm : Validations
{

    private int _plantsLimit;
    public int PlantsLimit => _plantsLimit;
    public List<Plant> PlantsOnGrowing { get; }
    public Farmer? Farmer { get; private set; }

    string _name;
    public string Name {
        get
        {
            return _name;
        }
        set
        {
            ValidateName(value); _name = value;
        }
    }

    public Farm() : this("Farm"){ }
    public Farm(string name) : this(name, 20) { }
    public Farm(string name, int limit) : this(name, limit, null) { }
    public Farm(string name, int limit, Farmer? farmer)
    {
        _plantsLimit = limit;
        PlantsOnGrowing = new List<Plant>(20);
        Farmer = farmer;
        Name = name;
    }

    public bool AddPlant(Plant plant)
    {
        if (PlantsOnGrowing.Count == PlantsLimit)
        {
            return false;
        }

        PlantsOnGrowing.Add(plant);
        plant.StartGrowing();

        return true;
    }

    public bool DeletePlant(Plant plant)
    {
        plant.StopGrowing();
        return PlantsOnGrowing.Remove(plant);
    }

    public Plant? FindByPlantName(string name)
    {
        string validateName = name.Trim();
        var foundPlant = PlantsOnGrowing.Find(
            plant => plant.FullName == validateName || plant.ShortName == validateName
        );

        if (foundPlant == null) return null;
        else return foundPlant;
    }

    public void ChangeFermer(Farmer? farmer)
    {
        ValidateNull(farmer);
        Farmer = farmer;
    }
}

