using System;
using System.Collections.Generic;
using System.Text;

namespace Queue
{
	public class Queue<T> 
	{
		private class QueueNode<T> 
		{
			public T Data { get; set; }
			public QueueNode<T> { get; set; }
			
			public QueueNode(T e)
			{
				Data = e;
				Next = null;
			}
		}
		
		private QueueNode<T> _front;
		private QueueNode<T> _back;
		
		public int Count { get; }
		
		public Queue() 
		{
			_front = null;
			_back = null;
			Count = 0;
		}
		
		public Queue(T[] elems) : this() 
		{
			foreach	(T e in elems)
			{
				Enqueue(e);
			}
		}
		
		public bool IsEmpty() 
		{
			return Count == 0;
		}
		
		public void Enqueue(T e)
		{
			if (Count == 0)
			{
				_back = new QueueNode<T>(e);
				_front = _back;
			}
			else 
			{
				QueueNode<T> temp = new QueueNode<T>(e);
				_back.Next = temp;
				_back = temp;
			}
			Count++;
		}
		
		public T Peek() 
		{
			return _front?.Data;
		}
		
		public T Dequeue() 
		{
			T data = Peek();
			if (_front == _back) 
			{
				Clear();
			}
			else 
			{
				_front = _front.Next;
				Count--;
			}
			return data;
		}
		
		public bool Contains(T e)
		{
			QueueNode<T> current = _front;
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