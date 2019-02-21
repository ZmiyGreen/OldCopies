using System;

namespace SharpFactorial
{
    static class Factorial
    {
        public static long RecFact(int n)
        {
            if (n == 1)
                return 1;
            else
                return n * RecFact(n - 1);
        }
        public static long RFact(int n) => n == 1 ? 1 : n*RFact(n - 1);
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine($"5! = {Factorial.RFact(5)}");
            Console.ReadKey();
        }
    }
}
