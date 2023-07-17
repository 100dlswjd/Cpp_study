using System;

namespace NullCoalescing
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int? num = null;
            Console.WriteLine($"{num ?? 0}");

            num = 99;
            Console.WriteLine($"{num ?? 0}");

            string s = null;
            Console.WriteLine($"{s ?? "Default"}");

            s = "Specific";
            Console.WriteLine($"{s ?? "Default"}");
        }
    }
}