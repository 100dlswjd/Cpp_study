using System;

namespace Test_01_01
{
    class MainApp
    {
        static void Main(string[] args)
        {
            Console.WriteLine("사각형의 너비를 입력하세요 ! : ");
            string width = Console.ReadLine();

            Console.WriteLine("사각형의 높이를 입력하세요 ! : ");
            string height = Console.ReadLine();

            Console.WriteLine("사각형의 넓이는 : {0}", Convert.ToInt32(width) * Convert.ToInt32(height));
        }
    }
}