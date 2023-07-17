using System;
using System.Collections;
using static System.Console;

namespace NullConditionalOperator
{
    internal class Program
    {
        static void Main(string[] args)
        {
            ArrayList a = null;
            a?.Add("야구"); // a?.가 null을 반환하므로 Add() 메소드는 호출되지 않음
            a?.Add("축구");
            WriteLine($"Count : {a?.Count}");
            WriteLine($"{a?[0]}");
            WriteLine($"{a?[1]}"); // a?. 가 null을 반환하므로 Count: 외에는 아무것도 출력하지 않습니다.

            a = new ArrayList(); // a는 이제 더이상 null 아닙니다.
            a?.Add("야구");
            a?.Add("축구");
            WriteLine($"Count : {a?.Count}");
            WriteLine($"{a?[0]}");
            WriteLine($"{a?[1]}");
        }
    }
}