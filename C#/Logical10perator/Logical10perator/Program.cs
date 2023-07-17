using System;

namespace Logical10perator
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Testing && .. .");
            Console.WriteLine($"1 > 0 && 4 < 5 : {1 > 0 && 4 < 5}");
            Console.WriteLine($"1 > 0 && 4 > 5 : {1 > 0 && 4 > 5}");
            Console.WriteLine($"1 == 0 && 4 > 5 : {1 == 0 && 4 > 5}");
            Console.WriteLine($"1 == 0 && 4 < 5 : {1 == 0 && 4 < 5}");

            Console.WriteLine("\nTesting || ...");
            Console.WriteLine($"1 > 0 || 4 < 5 : {1 > 0 || 4 < 5}");
            Console.WriteLine($"1 > 0 || 4 > 5 : {1 > 0 || 4 > 5}");
            Console.WriteLine($"1 == 0 || 4 > 5 : {1 == 0 || 4 > 5}");
            Console.WriteLine($"1 == 0 || 4 < 5 : {1 == 0 || 4 < 5}");

            Console.WriteLine("\nTesting ! ...");
            Console.WriteLine($"!True : {!true}");
            Console.WriteLine($"!False : {!false}");
        }
    }
}