using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Collection;

interface ILab8DictionaryPart
{
    /// <summary>
    /// Returns dictionary with stats of teams in current moment
    /// </summary>
    public Dictionary<string, TeamResult> Stats { get; }
    /// <summary>
    /// Add to the stats results of game. Method automatically chose the winner and update Stats dictionary.
    /// </summary>
    public void AddGame(string firstTeamName, int firstTeamGoals, string secondTeamName, int secondTeamGoals);
}

class TeamResult
{
    public int NumberOfGames { get; set; }
    public int Wins { get; set; }
    public int Loses { get; set; }
    public int Draws { get; set; }
    public int SumOfPoints { get; set; }
}

class FootballStats : ILab8DictionaryPart
{
    private Dictionary<string, TeamResult> stats;

    public Dictionary<string, TeamResult> Stats
    {
        get { return stats; }
    }

    public FootballStats()
    {
        stats = new Dictionary<string, TeamResult>();
    }

    public void ReadFromFile(string path)
    {
        string readText = File.ReadAllText(path);
        foreach (string line in readText.Split('\n'))
        {
            string[] matchInfo = line.Split(';');

            if (matchInfo.Length == 4){

                string firstTeamName = matchInfo[0];
                int firstTeamGoals = int.Parse(matchInfo[1]);
                string secondTeamName = matchInfo[2];
                int secondTeamGoals = int.Parse(matchInfo[3].Split(':')[0]);

                AddGame(firstTeamName, firstTeamGoals, secondTeamName, secondTeamGoals);
            }
        }
    }

    public void AddGame(string firstTeamName, int firstTeamGoals, string secondTeamName, int secondTeamGoals)
    {
        ValidGame(firstTeamName, firstTeamGoals, secondTeamName, secondTeamGoals);

        if (!stats.ContainsKey(firstTeamName))
        {
            stats[firstTeamName] = new TeamResult();
        }
        if (!stats.ContainsKey(secondTeamName))
        {
            stats[secondTeamName] = new TeamResult();
        }

        stats[firstTeamName].NumberOfGames++;
        stats[secondTeamName].NumberOfGames++;

        if (firstTeamGoals > secondTeamGoals)
        {
            stats[firstTeamName].Wins++;
            stats[secondTeamName].Loses++;
            stats[firstTeamName].SumOfPoints += 3;
        }
        else if (firstTeamGoals < secondTeamGoals)
        {
            stats[secondTeamName].Wins++;
            stats[firstTeamName].Loses++;
            stats[secondTeamName].SumOfPoints += 3;
        }
        else
        {
            stats[firstTeamName].Draws++;
            stats[secondTeamName].Draws++;
            stats[firstTeamName].SumOfPoints++;
            stats[secondTeamName].SumOfPoints++;
        }
    }

    public void PrintStats()
    {
        foreach (var team in stats)
        {
            Console.WriteLine(
                $"Team: {team.Key} | Number of games: {team.Value.NumberOfGames} " +
                $"| Wins: {team.Value.Wins} | Draws: {team.Value.Draws} " +
                $"| Loses: {team.Value.Loses} | Points: {team.Value.SumOfPoints}"
            );
        }
    }

    public void PrintToFile(string fileName)
    {
        using (StreamWriter writer = new StreamWriter(fileName))
        {
            foreach (var team in Stats)
            {
                string line = 
                    $"Team: {team.Key} | Number of games: {team.Value.NumberOfGames} " + 
                    $"| Wins: {team.Value.Wins} | Draws: {team.Value.Draws} " + 
                    $"| Loses: {team.Value.Loses} | Points: {team.Value.SumOfPoints}";
                writer.WriteLine(line);
            }
        }
    }

    private void ValidGame(string firstTeamName, int firstTeamGoals, string secondTeamName, int secondTeamGoals)
    {
        if (firstTeamName == null || secondTeamName == null || firstTeamName == secondTeamName)
        {
            throw new Exception("Unvalid game!");
        }
    }
}