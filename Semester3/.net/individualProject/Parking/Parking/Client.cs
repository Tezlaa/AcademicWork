using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Parking;

public class Client
{
    public string? FirstName { get; set; }
    public string SecondName { get; set; }
    private DateTime? _BirthdayDate;
    public string BirthdayDateStr
    {
        get { return _BirthdayDate?.ToString("MMMM d, ddd, yyyy") ?? "0000 - 00 - 00"; }
        set
        {
            if (value == null) { _BirthdayDate = null; }
            else
            {
                DateTime date = DateTime.Parse(
                    value,
                    new CultureInfo(ProjectConfig.TimeZone)
                );
                ChangeBirthdayDate( date );
            }
        }
    }
    public Client(string secondName) : this(null, secondName) { }
    public Client(string firstName, string secondName) : this(firstName, secondName, null) { }

    public Client(string firstName,  string secondName, string? birthdayDate)
    {
        FirstName = firstName;
        SecondName = secondName;
        BirthdayDateStr = birthdayDate;
    }

    public void ChangeBirthdayDate(DateTime date) 
    {
        Validations.ValidateDateOnGreaterThanPresent(date);
        _BirthdayDate = date;
    }

    public string GetInfo()
    {
        return $"{FirstName} {SecondName} - {BirthdayDateStr}";
    }

    public void ShowInfo()
    {
        Console.WriteLine(GetInfo());
    }
}
