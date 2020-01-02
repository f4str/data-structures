using System;
using System.Collections.Generic;
using Sytem.Text;

namespace Deque 
{
	public class Deque<T>
	{
		private class DequeNode<T> 
		{
			public T Data { get; set; }
			public DequeNode<T> Next { get; set; }
			public DequeNode<T> Previous { get; set; }
			
			public DequeNode(T e) 
			{
				Data = e;
				Next = null;
				Previous = null;
			}
		}
		
		private DequeNode<T> _front;
		private DequeNode<T> _back;
		
		public T First 
		{
			get { return _front?.Data; }
			set { Count > 0 ? _front.Data = value : AddFirst(value); }
		}
		public T Last 
		{
			get { return _back?.Data; }
			set { Count > 0 ? _back.Data = value : AddLast(value); }
		}
		public int Count { get; }
		
		public Deque() 
		{
			_front = null;
			_back = null;
			Count = 0;
		}
		
		public Deque(T[] elems) : this()
		{
			foreach (T e in elems)
			{
				AddLast(e);
			}
		}
		
		public bool IsEmpty()
		{
			return Count == 0;
		}
		
		public void AddFirst(T e) 
		{
			if (Count == 0) 
			{
				_front = new DequeNode<T>(e);
				_back = _front;
			}
			else 
			{
				DequeNode<T> temp = new DequeNode<T>(e);
				temp.Next = _front;
				_front.Previous = temp;
				_front = temp;
			}
			size++;
		}
		
		public void AddLast(T e) 
		{
			if (Count == 0) 
			{
				_back = new DequeNode<T>(e);
				_front = _back;
			}
			else 
			{
				DequeNode<T> temp = new DequeNode<T>(e);
				_back.Next = temp;
				temp.Previous = _back;
				_back = temp;
			}
			size++;
		}
		
		public T RemoveFirst() 
		{
			T data = First;
			if (_front == _back) 
			{
				Clear();
			}
			else 
			{
				_front = _front.Next;
				_front.Previous = null;
				Count--;
			}
			return data;
		}
		
		public T RemoveLast() 
		{
			T data = Last;
			if (_front == _back) 
			{
				Clear();
			}
			else 
			{
				_back = _back.Previous;
				_back.Next = null;
				Count--;
			}
			return data;
		}
		
		public bool Contains(T e) 
		{
			DequeNode<T> current = _front;
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
			_front = null;
			_back = null;
			Count = 0;
		}
	}
}
