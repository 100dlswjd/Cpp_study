using System;
using static System.Console;

namespace Hello
{
    class MainApp
    {
        static void Main(string[] args)
        {
            if(args.Length == 0) 
            {
                Console.WriteLine("사용법 : Hello.exe <이름>");
                return;
            }
            WriteLine("Hello, {0}", args[0]);
        }
        
        static void Test_1(string[] args)
        {
            Console.WriteLine("여러분, 안녕하세요?");
            Console.WriteLine("반갑습니다!");
        }

        static void Test_2(string[] args)
        {

        }
    }

   
}


