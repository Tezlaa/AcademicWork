using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace farming;

public class PlantGrownEventArgs: EventArgs
{
    public Plant Plant { get; }
    public PlantGrownEventArgs(Plant plant)
    {
        Plant = plant;
    }
}