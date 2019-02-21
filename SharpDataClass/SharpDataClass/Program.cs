using System;

namespace SharpDataClass
{
    static class Give
    {
        public static uint GiveValue(uint Value, uint Border, string ErrorText)
        {
                if (Value == 0 || Value > Border)
                    throw new Exception(ErrorText);
                else
                    return Value;
        }
    }
    class Day
    {
        public uint Value { get; }
        public Day(uint Value) => this.Value = Give.GiveValue(Value, 31, "В месяце может быть не более 31 дня!");
    }
    class Month
    {
        public uint Value { get; }
        public Month(uint Value) => this.Value = Give.GiveValue(Value, 12, "В году 12 месяцев!");
    }
    class Year
    {
        public uint Value { get; }
        public Year(uint Value) => this.Value = Value;
    }

    class Date
    {
        public Day DayValue { get; }
        public Month MonthValue { get; }
        public Year YearValue { get; }
        public Date(Day DayValue, Month MonthValue, Year YearValue)
        {
            this.DayValue = DayValue;
            this.MonthValue = MonthValue;
            this.YearValue = YearValue;
        }
        public void Print() => Console.WriteLine($"{DayValue.Value}.{MonthValue.Value}.{YearValue.Value}");
    }
    class Program
    {
        static void Main(string[] args)
        {
            var D = new Date(new Day(30), new Month(8), new Year(2001));
            D.Print();
            Console.ReadKey();
        }
    }
}
