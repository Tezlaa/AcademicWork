using Parking.Enum;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace Parking;

public class Order
{
    string carNumber;
    CarTypeRate rateByCarType;
    DateTime parkingTime;

    public Order(string carNumber, string rateByCarType, DateTime parkingTime)
    {
        this.carNumber = carNumber;
        this.rateByCarType = CarTypeRate;
        this.parkingTime = parkingTime;
    }
}
