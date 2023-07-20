using System;

namespace Switch
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("요일을 입력하세요(월, 화, 수, 목, 금, 토, 일) :");
            string day = Console.ReadLine();

            switch (day)
            {
                case "월":
                    Console.WriteLine("Monday");
                    break;

                case "화":
                    Console.WriteLine("Tuesday");
                    break;

                case "수":
                    Console.WriteLine("Wednesday");
                    break;

                case "목":
                    Console.WriteLine("Thursday");
                    break;

                case "금":
                    Console.WriteLine("Friday");
                    break;

                case "토":
                    Console.WriteLine("Saturday");
                    break;

                case "일":
                    Console.WriteLine("Sunday");
                    break;
            }
        }
    }
}