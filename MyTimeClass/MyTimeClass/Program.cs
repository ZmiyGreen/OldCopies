using System;
using System.Threading;

namespace MyTimeClass
{
    class Time : IComparable<Time>
    {
        public int Hour { get; private set; }
        public int Minute { get; private set; }
        public int Second { get; private set; }
        public Time(int Hour, int Minute, int Second) => SetTime(Hour, Minute, Second);
        public Time() => SetTime(0, 0, 0);
        public Time(int Hour) => SetTime(Hour, 0, 0);
        public Time(int Hour, int Minute) => SetTime(Hour, Minute, 0);
        private void SetTime(int hour, int minute, int second)
        {
            if ((hour >= 0 && hour <= 23) && (minute >= 0 && minute <= 59) && (second >= 0 && second <= 59))
            {
                Hour = hour;
                Minute = minute;
                Second = second;
            }
            else
                throw new Exception("Недопустимое значение!");
        }
        /// <summary>
        /// Вернуть время в секундах
        /// </summary>
        public int SecondFormat
        {
            get => (Hour * 60 * 60) + (Minute * 60) + Second;
        }
        public int CompareTo(Time Other) => SecondFormat.CompareTo(Other.SecondFormat);
        public void Show() => Console.WriteLine($"{Hour,2}:{Minute,2}:{Second,2}");
        public static Time operator+(Time Self, Time Other)
        {
            var Result = new Time
            {
                Hour = Self.Hour + Other.Hour,
                Minute = Self.Minute + Other.Minute,
                Second = Self.Second + Other.Second
            };
            if (Result.Second >= 60)
            {
                Result.Second -= 60;
                Result.Minute++;
            }
            if(Result.Minute >= 60)
            {
                Result.Minute -= 60;
                Result.Hour += 1;
            }
            return Result;
        }
    }
    /// <summary>
    /// Класс для ввода целочисленных числе и вычисления факториала
    /// </summary>
    static class MyMath
    {
        /// <summary>
        /// Факториал числа
        /// </summary>
        /// <param name="n">Целое число, для которого будет вычислен факториал</param>
        /// <returns>Факториал числа</returns>
        public static int Fact(int n) => n == 1 ? 1 : n * Fact(n - 1);
        /// <summary>
        /// Считывание целочисленных чисел из консоли
        /// </summary>
        /// <param name="Text">Приглашение к вводу</param>
        /// <returns>Целое число, введенное с клавиатуры</returns>
        public static int Input(string Text = "")
        {
            while(true)
            {
                Console.Write(Text);
                if (int.TryParse(Console.ReadLine(), out int result))
                    return result;
                else
                    Text = "Недопустимый ввод! Введите число: ";
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            /*var T1 = new Time(3,7,2);
            var T2 = new Time(5,9,9);
            T1.Show();
            T2.Show();
            T1 += T2;
            T1.Show();*/
            /*var A = Math.Pow(5, 3);
            int n = MyMath.Input("Введите число: ");
            Console.WriteLine($"{n}! = {MyMath.Fact(n)}");*/
            string Str = "!!Привет!!";
            Str = Str.Substring(2, Str.Length-(2+2));
            Console.WriteLine(Str);
            Console.ReadKey();
        }
    }
}
