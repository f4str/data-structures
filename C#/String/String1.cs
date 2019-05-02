using System;
using System.Collections.Generic;
using System.Text;

namespace String
{
    public class String1
    {
        private readonly char[] _chars;
        public int Length { get; }
        public char this[int i]
        {
            get { return _chars[i]; }
        }

        public String1()
        {
            _chars = new char[0];
            Length = 0;
        }

        public String1(char[] chars)
        {
            _chars = chars;
            Length = chars.Length;
        }

        public String1(string str)
        {
            _chars = new char[str.Length];
            Length = _chars.Length;
            for (int i = 0; i < Length; i++)
            {
                _chars[i] = str[i];
            }
        }

        public String1 Substring(int start, int end)
        {
            if (start < 0 || end < 0 || end < start || start > Length || end > Length)
            {
                return null;
            }
            char[] chars2 = new char[end - start];
            for (int i = start, j = 0; i < end; i++, j++)
            {
                chars2[j] = _chars[i];
            }
            return new String1(chars2);
        }

        public String1 Substring(int start)
        {
            if (start < 0 || start > Length)
            {
                return null;
            }
            int end = Length - 1;
            char[] chars2 = new char[end - start];
            for (int i = start, j = 0; i < end; i++, j++)
            {
                chars2[j] = _chars[i];
            }
            return new String1(chars2);
        }

        public String1 ToLower()
        {
            char[] chars2 = new char[Length];
            for (int i = 0; i < Length; i++)
            {
                chars2[i] = char.ToLower(_chars[i]);
            }
            return new String1(chars2);
        }

        public static String1 operator +(String1 str1, String1 str2)
        {
            char[] chars = new char[str1.Length + str2.Length];
            str1._chars.CopyTo(chars, 0);
            str2._chars.CopyTo(chars, str1.Length);
            return new String1(chars);
        }

        public override string ToString()
        {
            return new string(_chars);
        }
    }
}
