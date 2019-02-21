using System;

namespace SchoolTest
{
    class Program
    {
        static void Main(string[] args)
        {
             var People = new Person[5];
             People[0] = new Employee("Иванов1", "Иван1", "Алексеевич1", new SelfDate("18:9:1980"), new SchoolPosition("Учитель", 40000));
             People[1] = new Employee("Иванов2", "Иван2", "Алексеевич2", new SelfDate("18:4:1945"), new SchoolPosition("Учитель", 40000));
             People[2] = new Student ("Иванов3", "Иван3", "Алексеевич3", new SelfDate("8:5:2007"), 9);
             People[3] = new Employee("Иванов4", "Иван4", "Алексеевич4", new SelfDate("18:8:1995"), new SchoolPosition("Учитель", 40000));
             People[4] = new Student ("Иванов5", "Иван5", "Алексеевич5", new SelfDate("1:9:2004"), 11);
             foreach (var i in People)
                 i.Show();
            /*var A = DateTime.Now.Day;
            var B = DateTime.Now.Month;
            var C = DateTime.Now.Year;
            Console.WriteLine($"{A}:{B}:{C}");*/
            Console.ReadKey();
        }
    }
}
