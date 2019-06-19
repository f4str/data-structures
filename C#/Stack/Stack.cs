using System;
using System.Collections.Generic;
using System.Text;

namespace Stack
{
	public class StackNode<T> 
	{
		private class StackNode<T>
		{
			public T Data { get; set; }
			public StackNode<T> Next { get; set; }
			
			public StackNode(T e) 
			{
				Data = e;
				Next = null;
			}
		}
		
		private StackNode<T> _top;
		
		public int Count { get; }
		
		public Stack() 
		{
			_top = null;
			Count = 0;
		}
		
		public Stack(T[] elems) : this() 
		{
			foreach (T e in elems)
			{
				Push(e);
			}
		}
		
		public bool IsEmpty() 
		{
			return Count == 0;
		}
		
		public void Push(T e) 
		{
			if (Count == 0) 
			{
				_top = new StackNode<T>(e);
			}
			else 
			{
				StackNode<T> temp = new StackNode<T>(e);
				temp.Next = _top;
				_top = temp;
			}
			Count++;
		}
		
		public T Peek()
		{
			return _top?.Data;
		}
		
		public T Pop()
		{
			if (Count == 0) 
			{
				return null;
			}
			T data = _top.Data;
			_top = _top.Next;
			Count--;
			return data;
		}
		
		public bool Contains(T e) 
		{
			StackNode<T> current = _top;
			while (current != null)
			{
				if (current.Data.Equals(e))
				{
					return true;
				}
				current = current.Next;
			}
			return false;
		}
		
		public void Clear() 
		{
			_top = null;
			Count = 0;
		}
	}
}
