using VeterinaryClinic;
using VeterinaryClinic.Animals;

public class Program
{
    public static void Main(string[] args)
    {
        Clinic clinic = new Clinic("Clinic mow-mow");

        Doctor doctorAndrey = new Doctor("Andrey", "Simonov", 28);
        Doctor doctorBogdan = new Doctor("Bogdan", "Tishenko", 18);
        Doctor doctorArtem = new Doctor("Artem", "Radovskiy", 22);

        Cat cat = new Cat("Badger", 4, "White cat");
        Dog dog = new Dog("Cobra", 12, "Old Husky");
        Cow cow = new Cow("Ibex", 5, "Young cow");

        cat.Voice();
        dog.Voice();
        cow.Voice();

        clinic.HireDoctor(doctorArtem);
        clinic.HireDoctor(doctorBogdan);
        clinic.HireDoctor(doctorAndrey);

        clinic.ShowInfo();

        clinic.AddAnumal(cat, doctorBogdan);
        clinic.AddAnumal(dog, doctorAndrey);
        clinic.AddAnumal(cow, doctorArtem);
        clinic.AddAnumal(cow, doctorArtem);

        clinic.ShowInfo();

        clinic.ReturnAnimal("Badger");

        clinic.ShowInfo();
        clinic.FireDoctor(doctorBogdan);
        clinic.ShowInfo();
    }
}