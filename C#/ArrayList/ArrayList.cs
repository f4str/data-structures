using System;
using System.Collections.Generic;
using System.Text;

namespace ArrayList 
{
	public class ArrayList<T> 
	{
		public static const int INITIAL_CAPACITY = 16;
		private T[] _data = new T[INITIAL_CAPACITY];
		public int Count { get; } = 0;
		public int Capacity 
		{ 
			get { return _data.Length; } 
		}
		public T this[int i] 
		{
			get { return _data[i]; }
			set { _data[i] = value; }
		}
		
		public ArrayList() {
		}
		
		public ArrayList(T[] elems) 
		{
			foreach (T e in elems) 
			{
				Add(e);
			}
		}
		
		public bool IsEmpty() 
		{
			return Count == 0;
		}
		
		public void Add(T e) 
		{
			if (Count == _data.Length) 
			{
				T[] temp = T[Count * 2];
				Array.Copy(data, 0, temp, 0, size);
				data = temp;
			}
			_data[Count] = e;
			Count++;
		}
		
		public void Insert(T e, int index) 
		{
			if (Count == _data.Length) 
			{
				T[] temp = T[Count * 2];
				Array.Copy(data, 0, temp, 0, size);
				data = temp;
			}
			
			for (int i = Count - 1; i >= index; i--) 
			{
				_data[i + 1] = _data[i];
			}
			_data[index] = e;
			Count++;
		}
		
		public bool Contains(T e) 
		{
			foreach (T elem in _data) 
			{
				if (e.Equals(elem))
				{
					return true;
				}
			}
			return false;
		}
		
		public void Clear() 
		{
			_data = new T[INITIAL_CAPACITY];
			Count = 0;
		}
		
		public int IndexOf(T e)
		{
			for (int i = 0; i < Count; i++) 
			{
				if (e.equals(_data[i])) 
				{
					return i;
				}
			}
			return -1;
		}
		
		public T RemoveAt(int index) 
		{
			T e = _data[index];
			Count--;
			for (int i = index; i < Count; i++) 
			{
				_data[i] = _data[i + 1];
			}
			_data[size] = null;
			return e;
		}
		
		public bool Remove(T e) 
		{
			int index = IndexOf(e);
			if (index >= 0) 
			{
				RemoveAt(index);
				return true;
			}
			return false;
		}
		
		public void TrimExcess()
		{
			if (Count != _data.Length) 
			{
				T[] temp = T[Count];
				Array.Copy(_data, 0, temp, 0, Count);
				_data = temp;
			}
		}
		
		public override string ToString() 
		{
			StringBuilder sb = new StringBuilder("[");
			foreach (T e in _data) 
			{
				sb.Append(e);
				sb.Append(", ");
			}
			sb.Replace(sb.Length - 1, sb.Length, "]");
			return sb.ToString();
		}
	}
}