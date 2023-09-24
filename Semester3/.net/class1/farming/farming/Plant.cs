using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Timers;

namespace farming;

public abstract class Plant
{
    public event EventHandler<PlantGrownEventArgs> PlantGrown;
    private System.Timers.Timer timer;

    public string ShortName { get; }
    public string FullName { get; }
    public int GrowingTime { get; }
    public bool IsNeedRegrow { get; set; }

    protected Plant(string shortName, string fullName, int growingTime, bool isNeedRegrow)
    {
        ShortName = shortName;
        FullName = fullName;
        GrowingTime = growingTime;
        IsNeedRegrow = isNeedRegrow;

        timer = new System.Timers.Timer(GrowingTime * 1000);
        timer.Stop();
    }
    public void StartGrowing()
    {
        if (!timer.Enabled)
        {
            timer.Elapsed += TimerElapsed;
            timer.Start();
        }
    }

    public void StopGrowing()
    {
        if (timer.Enabled)
        {
            timer.Stop();
            timer.Elapsed -= TimerElapsed;
        }
    }

    private void TimerElapsed(object sender, ElapsedEventArgs e)
    {
        PlantHasGrown();
    }

    protected virtual void PlantHasGrown()
    {
        PlantGrown?.Invoke(this, new PlantGrownEventArgs(this));
    }
}

public class Carrot : Plant
{
    public Carrot() : base("Carrot", "Carrot Plant", 3, true)
    {}

}

public class Potato : Plant
{
    public Potato() : base("Potato", "Potato Plant", 5, true)
    {}

}