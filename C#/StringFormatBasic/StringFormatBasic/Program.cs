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
        }
    }
}