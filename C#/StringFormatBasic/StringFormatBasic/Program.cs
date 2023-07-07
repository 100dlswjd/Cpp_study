using static System.Console;

namespace StringFormatBasic
{
    class MainApp
    {
        static void Main(string[] args)
        {
            string fmt = "{0, -20}{1,-15}{2,30}";

            WriteLine(fmt, "Publisher", "Author", "Title");
            WriteLine(fmt, "marvel", "Stan Lee", "Iron Man");
            WriteLine(fmt, "Hanbit", "Sanghyun Park", "This is C#");
            WriteLine(fmt, "Prentice Hall", "K&R", "The C Programming Language");

            // {0:D} 10진수로 표시
            WriteLine("{0:D}", 255);
            WriteLine("{0:D}", 0xFF);

            // {0:X} 16진수로 표시
            WriteLine("{0:X}", 255);
            WriteLine("{0:X}", 0xFF);

            // {0:N} 콤마(,)로 묶어 표현한수
            WriteLine("{0:N}", 123456789);

            // {0:F} 고정 소수점
            WriteLine("고정 소수점 : {0:F}", 123.45);

            // {0:E} 지수
            WriteLine("지수 : {0:E}", 123.456789);
        }
    }
}