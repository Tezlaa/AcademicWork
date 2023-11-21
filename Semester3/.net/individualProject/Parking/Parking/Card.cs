using Parking.Enum;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Parking;

public class Card
{
    Client client;
    ParkingRate rate;
    double amount;
    List<Order> orders;
    List<Parked> ParkedCars;
}
