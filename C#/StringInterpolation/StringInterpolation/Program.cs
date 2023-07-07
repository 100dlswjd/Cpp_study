using static System.Console;

namespace StringInterpolation
{
    class MainApp
    {
        static void Main(string[] args)
        {
            string name = "김튼튼";
            int age = 23;
            WriteLine($"{name,-10}, {age:D3}");

            name = "박날씬";
            age = 30;
            WriteLine($"{name}, {age}");

            name = "이비실";
            age = 17;
            WriteLine($"{name}, {(age > 20 ? "성인" : "미성년자")}");
        }
    }
}