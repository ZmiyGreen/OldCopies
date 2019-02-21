using System;

namespace SchoolTest
{
    class SchoolPosition
    {
        private double _salary;
        private string _position;
        public SchoolPosition(string Position, double Salary) => (this.Position, this.Salary) = (Position, Salary);
        public double Salary
        {
            get => _salary;
            private set => _salary = Verification.Validate(in value,  100000.0, 15000.0);
        }
        public string Position
        {
            get => _position;
            set => _position = Verification.Validate(in value, 25);
        }
        public void Show() => Console.WriteLine($"{Position} {Salary}");
    }

    class Student : Person
    {
        private int _schoolClass;
        public int SchoolClass
        {
            get => _schoolClass;
            private set => _schoolClass = Verification.Validate(in value, 11, 1);
        }
        public Student(string FamilyName, string FirstName, string LastName, SelfDate BornDate, int SchoolClass) : base(FamilyName, FirstName, LastName, BornDate) =>
            (this.SchoolClass) = (SchoolClass);
        public override void Show() => Console.WriteLine($"{FamilyName} {FirstName} {LastName} {BornDate.ToString()} {SchoolClass}");
    }

    class Employee : Person
    {
        private SchoolPosition Position;
        public Employee(string FamilyName, string FirstName, string LastName, SelfDate BornDate, SchoolPosition Position) :
            base(FamilyName, FirstName, LastName, BornDate) => (this.Position) = (Position);
        public override void Show() => Console.WriteLine($"{FamilyName} {FirstName} {LastName} {BornDate.ToString()} {Position.Position} {Position.Salary}");
    }
}