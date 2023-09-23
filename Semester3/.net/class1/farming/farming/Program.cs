using farming;

public class Program
{
    public static void Main(string[] args)
    {
        Farmer farmer = new Farmer("Bogdan", "Tishenko", "Gardener");
        
        Carrot carrot = new Carrot();
        Potato potato = new Potato();

        Farm farm = new Farm("Farm Tezla", 10, farmer);
        farm.PlantsOnGrowing.Add(carrot);
        farm.PlantsOnGrowing.Add(potato);
        farmer.AssignPlant(carrot);
        farmer.AssignPlant(potato);

        Console.ReadLine();

        Plant findPlant = farm.FindByPlantName("Carrot");
        Console.WriteLine(findPlant);
    }
}