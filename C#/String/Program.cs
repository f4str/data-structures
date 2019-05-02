using System;

namespace String
{
    public class Program
    {
        public static void Main(string[] args)
        {
            char[] chars = "Hello there".ToCharArray();
            String1 str = new String1(chars);
            Console.WriteLine(str);
            Console.WriteLine(str.ToLower());
            Console.WriteLine(str.Substring(1, 5));
            Console.WriteLine(str.Substring(5));

            String1 str2 = new String1("General Kenobi".ToCharArray());
            Console.WriteLine(str + str2);
        }
    }
}
