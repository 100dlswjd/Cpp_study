using System;

namespace Switch2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            object obj = null;

            string s = Console.ReadLine();

            if (int.TryParse(s, out int out_i))
            {
                obj = out_i;
            }
            else if (float.TryParse(s, out float out_f))
            {
                obj = out_f;
            }
            else
            {
                obj = s;
            }

            switch (obj)
            {
                case int:
                    Console.WriteLine($"{(int)obj}는 int 형식입니다.");
                    break;
                case float:
                    Console.WriteLine($"{(float)obj}는 float 형식입니다.");
                    break;
                default:
                    Console.WriteLine($"{obj}(은)는 모르는 형식입니다.");
                    break;
            }
            
        }
    }
}