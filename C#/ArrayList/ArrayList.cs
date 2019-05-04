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
			get 
			{ 
				return _data.Length; 
			} 
		}
		public T this[int i] 
		{
			get
			{
				return _data[i];
			}
			set 
			{
				_data[i] = value;
			}
		}
		
		public ArrayList() {
		}
		
		public ArrayList(T[] objects) 
		{
			foreach (T elem in objects) 
			{
				add(elem);
			}
		}
		
		public bool IsEmpty() 
		{
			return Count == 0;
		}
		
		public void Add(T e) 
		{
			EnsureCapacity();
			_data[Count++] = e;
		}
		
		public void Insert(T e, int index) 
		{
			CheckIndex(index);
			EnsureCapacity();
			
			for (int i = Count - 1; i >= index; i--) 
			{
				_data[i + 1] = _data[i];
			}
			_data[index] = e;
			size++;
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
		
		public bool RemoveAt(int index) 
		{
			CheckIndex(index);
			T elem = _data[index];
			Count--;
			for (int i = index; i < Count; i++) 
			{
				_data[i] = _data[i + 1];
			}
			_data[size] = null;
			return elem;
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
		
		private void EnsureCapacity() 
		{
			if (Count == _data.Length) 
			{
				T[] temp = T[Count * 2];
				Array.Copy(data, 0, temp, 0, size);
				data = temp;
			}
		}
		
		private void CheckIndex(int index) 
		{
			if (index < 0 || index > Count) 
			{
				throw new ArgumentOutOfRangeException("Index: " + index + ", Count: " + Count);
			}
		}
		
		public void TrimExcess()
		{
			if (Count != _data.Length) 
			{
				T[] temp = T[Count];
				Array.Copy(data, 0, temp, 0, size);
				data = temp;
			}
		}
		
		public virtual string ToString() 
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