using System;

namespace IncDecOperator
{
    class MainApp
    {
        static void Main(string[] args)
        {
            int a = 10;
            Console.WriteLine(a++);
            Console.WriteLine(++a);

            Console.WriteLine(a--);
            Console.WriteLine(--a);

            string result = "123" + "456";
            Console.WriteLine(result);
            result = "Hello" + " " + "World";
            Console.WriteLine(result);
        }
    }
}