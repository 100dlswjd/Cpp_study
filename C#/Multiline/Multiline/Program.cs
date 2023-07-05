namespace Multiline
{
    class MainApp
    {
        static void Main(string[] args)
        {
            string a = """
                여러줄을 표시합니다.
                두번째줄
                세번째줄
                """;
            Console.WriteLine(a);
        }
    }
}