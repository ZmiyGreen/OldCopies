using System;

namespace SchoolTest
{
    static class Verification
    {
        public static int Validate(in int Value, in int MaxBorder, in int MinBorder) => Value >= MinBorder && Value <= MaxBorder ? Value : MinBorder;
        public static double Validate(in double Value, in double MaxBorder, in double MinBorder) => Value >= MinBorder && Value <= MaxBorder ? Value : MinBorder;
        public static string Validate(in string Str, in int MaxBorder) => Str.Length <= MaxBorder? Str : Str.Substring(0, MaxBorder);
    }
    class SelfDate
    {
        private int _day;
        private int _month;
        private int _year;
        public SelfDate(int Day, int Month, int Year) => (this.Day, this.Month, this.Year) = (Day, Month, Year);
        public SelfDate() => (this.Day, this.Month, this.Year) = (0, 0, 0);
        public SelfDate(string StrDate)
        {
            var Str = StrDate.Split(':');
            (Day, Month, Year) = (int.Parse(Str[0]), int.Parse(Str[1]), int.Parse(Str[2]));
        }
        public int Day
        {
            get => _day;
            set => _day = Verification.Validate(in value, 31, 1);
        }
        public int Month
        {
            get => _month;
            set => _month = Verification.Validate(in value, 12, 1);
        }
        public int Year
        {
            get => _year;
            set => _year = Verification.Validate(in value, 2100, 1900);
        }
        /// <summary>
        /// Вывод в консоль в формате дд:мм:гггг
        /// </summary>
        public void Show() => Console.WriteLine($"{Day,2}:{Month,2 }:{Year}");
        public override string ToString() => $"{Day}:{Month}:{Year}";
    }
    class Person
    {
        private string _firstName;
        private string _lastName;
        private string _familyName;
        protected SelfDate BornDate;
        public string FirstName
        {
            get => _firstName;
            private set => _firstName = Verification.Validate(in value, 15);
        }
        public string LastName
        {
            get => _lastName;
            private set => _lastName = Verification.Validate(in value, 15);
        }
        public string FamilyName
        {
            get => _familyName;
            private set => _familyName = Verification.Validate(in value, 15);
        }
        public Person(string FamilyName, string FirstName, string LastName, SelfDate BornDate) => (this.FamilyName, this.FirstName, this.LastName, this.BornDate) =
            (FamilyName, FirstName, LastName, BornDate);
        public virtual void Show() => Console.WriteLine($"{FamilyName} {FirstName} {LastName} {BornDate.ToString()}");
    }
}