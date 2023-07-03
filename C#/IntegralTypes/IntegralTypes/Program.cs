// See https://aka.ms/new-console-template for more information

using System.Runtime.InteropServices;

namespace IntegralTypes
{    class MainApp
    {
        /*
        static void Main(string[] args)
        {
            sbyte a = -10;
            byte b = 40;

            Console.WriteLine($"a={a}, b={b}");

            short c = -30000;
            ushort d = 60000;
            Console.WriteLine($"c = {c}, d = {d}");

            int e = -10_000_000; // 0이 7개
            int f = 300_000_000; // 0이 8개
            Console.WriteLine($"e = {e}, f = {f}");

            long g = -500_000_000_000;
            ulong h = 2_000_000_000_000_000_000;
            Console.WriteLine($"g = {g}, h = {h}");
        }
        */
        /*
        static void Main(string[] args)
        {
            byte a = 240; // 10진수
            Console.WriteLine($"a = {a}");

            byte b = 0b1111_0000; // 2진수
            Console.WriteLine($"b = {b}");

            byte c = 0XF0; // 16진수
            Console.WriteLine($"c = {c}");

            uint d = 0x1234_abcd; // 16진수
            Console.WriteLine($"d = {d}");
        }
        */
        // SignedUnsigned
        /*
        static void Main(string[] args)
        {
            byte a = 255;
            sbyte b = (sbyte)a;

            Console.WriteLine(a);
            Console.WriteLine(b);
        }
        */
        /*
        static void Main(string[] args)
        {
            uint a = uint.MaxValue;
            Console.WriteLine(a);
            a = a + 1;
            Console.WriteLine(a);
        }
        */
        static void Main(string[] args)
        {
            float a = 3.1415_9265_3589_7932_3846_2643_3832_79f;
            Console.WriteLine(a);

            double b = 3.1415_9265_3589_7932_3846_2643_3832_79;
            Console.WriteLine(b);

            decimal c = 3.1415_9265_3589_7932_3846_2643_3832_79m;
            Console.WriteLine(c);

        }
    }
}