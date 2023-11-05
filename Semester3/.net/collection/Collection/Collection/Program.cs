using Collection;


class Program
{
    static void Main(string[] args)
    {
        Collection1 collection1 = new Collection1();
        collection1.Start();

        Collection2 collection2 = new Collection2();
        collection2.Start();
    }
}

class Collection1
{
    public void Start()
    {
        FootballStats footballStats = new FootballStats();
        footballStats.AddGame("Team1", 2, "Team2", 1);
        footballStats.AddGame("Team2", 0, "Team3", 1);
        footballStats.AddGame("Team2", 1, "Team1", 1);

        footballStats.PrintStats();
        Console.WriteLine();


        FootballStats footballStatsFromFile = new FootballStats();
        string readPath = @"D:\Developments\KNU\AcademicWorkPrograming\Semester3\.net\collection\Collection\Collection\footballgames.txt";
        string writePath = @"D:\Developments\KNU\AcademicWorkPrograming\Semester3\.net\collection\Collection\Collection\stats.txt";
        footballStatsFromFile.ReadFromFile(readPath);

        footballStatsFromFile.PrintToFile(writePath);
    }
}

class Collection2
{
    public void Start()
    {
        string line1 = "({x-y-z}*[x+2y]-(z+4x));";
        string line2 = "([x-y-z}*[x+2y)-{z+4x)].";

        ValidBrackets validBrackets = new ValidBrackets();
        ResultBrackets resultLine1 = validBrackets.IsCorrect(line1);
        Console.WriteLine(resultLine1.ToString());

        ResultBrackets resultLine2 = validBrackets.IsCorrect(line2);
        Console.WriteLine(resultLine2.ToString());
    }
}