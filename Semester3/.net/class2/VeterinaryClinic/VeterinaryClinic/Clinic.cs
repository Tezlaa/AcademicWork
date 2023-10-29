using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using VeterinaryClinic.Animals;

namespace VeterinaryClinic;

public class Clinic
{
    Validations _validations = new Validations();
    List<Doctor> Doctors { get; }
    Dictionary<Animal, Doctor> Treatment { get; }

    string _clinicName
    {
        set
        {
            _validations.ValidateToNormal(value);
            _clinicName = value;
        }
        get { return _clinicName; }
    }

    public Clinic(string clinicName)
    {
        Doctors = new List<Doctor>();
        Treatment = new Dictionary<Animal, Doctor>();
        _clinicName = clinicName;
    }

    public void HireDoctor(Doctor doctor)
    {
        _validations.ValidateNull(doctor);
        if (!Doctors.Exists(_doctor => _doctor == doctor))
        {
            Doctors.Add(doctor);
        }
    }

    public void FireDoctor(Doctor doctor)
    {
        _validations.ValidateNull(doctor);
        if (Doctors.Exists(_doctor => _doctor == doctor))
        {
            Doctors.Remove(doctor);
        }
    }

    public void AddAnumal(Animal anumal, Doctor doctor) 
    {
        try
        {
            if (!CanAddAnumalToClinic())
            {
                Console.WriteLine("Can`t add new animal. Come back again soon!");
            }

            ChangeEmployment(doctor);
            Treatment[anumal] = doctor;
        }
        catch (ArgumentNullException ex)
        {
            Console.WriteLine(ex);
        }
        catch (DoctorBusy ex)
        {
            Console.WriteLine(ex);
        }
        
    }

    public Animal ReturnAnimal(string animalName)
    {
        try
        {
            Animal animal = FoundByName(animalName);
            Doctor doctor = Treatment[animal];
            doctor.ChangeWorkStatus(false);
            Treatment.Remove(animal);

            return animal;
        }
        catch (ArgumentNullException ex)
        {
            Console.WriteLine(ex);
        }
        throw new ArgumentNullException($"Animal {animalName} not found");
    }

    private Animal FoundByName(string name)
    {
        List<Animal> animals = new List<Animal>(Treatment.Keys);
        var foundAnimal = animals.Find(animal => animal.GetName() == name);
        _validations.ValidateNull(foundAnimal);

        return foundAnimal;
    }

    private bool CanAddAnumalToClinic()
    {
        int availableDoctors = Doctors.Count(doctor => !doctor.IsBusy());
        
        if (availableDoctors < availableDoctors + 1)
        {
            return false;
        }
        return true;
    }

    private void ChangeEmployment(Doctor doctor)
    {
        foreach (Doctor availableDoctor in Doctors)
        {
            if (availableDoctor == doctor)
            {
                if (availableDoctor.IsBusy())
                {
                    throw new DoctorBusy(doctor);
                }
                availableDoctor.ChangeWorkStatus(true);
                return;
            }
        }
        throw new ArgumentNullException($"Doctor not found");
    }
}
