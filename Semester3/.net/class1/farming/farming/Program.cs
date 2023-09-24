using farming;

public class Program
{
    public static void Main(string[] args)
    {
        Farmer farmer = new Farmer("Bogdan", "Tishenko", "Gardener");

        Carrot carrot = new Carrot();
        Potato potato = new Potato();

        Farm farm = new Farm("Farm Tezla", 10, farmer);
        farm.AddPlant(carrot);
        farm.AddPlant(potato);

        farmer.subscribeOnGrowing(farm, carrot);

        Console.ReadLine();

        Plant findPlant = farm.FindByPlantName("Carrot");
        Console.WriteLine(findPlant.FullName);
    }
}