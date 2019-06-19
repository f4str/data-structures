using System;
using System.Collections.Generic;
using Sytem.Text;

namespace LinkedList 
{
	public class DoublyLinkedList<T>
	{
		private class DoublyNode<T> 
		{
			public T Data { get; set; }
			public DoublyNode<T> Next { get; set; }
			public DoublyNode<T> Previous { get; set; }
			
			public DoublyNode(T e) 
			{
				Data = e;
				Next = null;
				Previous = null;
			}
		}
		
		private DoublyNode<T> _head;
		private DoublyNode<T> _tail;
		
		public T First 
		{
			get { return _head?.Data; }
			set { Count > 0 ? _head.Data = value : AddFirst(value); }
		}
		public T Last 
		{
			get { return _tail?.Data; }
			set { Count > 0 ? _tail.Data = value : AddLast(value); }
		}
		public int Count { get; }
		
		public T this[int i] 
		{
			get { return Get(i); }
			set { Set(i, value); }
		}
		
		public DoublyLinkedList() 
		{
			_head = null;
			_tail = null;
			Count = 0;
		}
		
		public DoublyLinkedList(T[] elems) : this()
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
		
		public T Get(int index) 
		{
			if (index == 0) 
			{
				return First;
			}
			else if (index == Count - 1) 
			{
				return Last;
			}
			else 
			{
				DoublyNode<T> current = _head;
				for (int i = 0; i < index; i++) 
				{
					current = current.Next;
				}
				return current.Data;
			}
		}
		
		public T Set(int index, T e) 
		{
			if (index == 0) 
			{
				T data = First;
				First = e;
				return data;
			}
			else if (index == Count - 1) 
			{
				T data = Last;
				Last = e;
				return data;
			}
			else 
			{
				DoublyNode<T> current = _head;
				for (int i = 0; i < index; i++) 
				{
					current = current.Next;
				}
				T data = current.Data;
				current.Data = e;
				return data;
			}
		} 
		
		public void AddFirst(T e) 
		{
			if (Count == 0) 
			{
				_head = new DoublyNode<T>(e);
				_tail = _head;
			}
			else 
			{
				DoublyNode<T> temp = new DoublyNode<T>(e);
				temp.Next = _head;
				_head.Previous = temp;
				_head = temp;
			}
			size++;
		}
		
		public void AddLast(T e) 
		{
			if (Count == 0) 
			{
				_tail = new DoublyNode<T>(e);
				_head = _tail;
			}
			else 
			{
				DoublyNode<T> temp = new DoublyNode<T>(e);
				_tail.Next = temp;
				temp.Previous = _tail;
				_tail = temp;
			}
			size++;
		}
		
		public void Add(int index, T e) 
		{
			if (index == 0) 
			{
				AddFirst(e);
			}
			else if (index == Count - 1) 
			{
				AddLast(e);
			}
			else 
			{
				DoublyNode<T> current = _head;
				for (int i = 0; i <= index; i++) 
				{
					current = current.Next;
				}
				DoublyNode<T> temp = new DoublyNode<T>(e);
				current.Previous.Next = temp;
				temp.Previous = current.Previous;
				temp.Next = current;
				Count--;
			}
		}
		
		public T RemoveFirst() 
		{
			T data = First;
			if (_head == _tail) 
			{
				Clear();
			}
			else 
			{
				_head = _head.Next;
				_head.Previous = null;
				Count--;
			}
			return data;
		}
		
		public T RemoveLast() 
		{
			T data = Last;
			if (_head == _tail) 
			{
				Clear();
			}
			else 
			{
				_tail = _tail.Previous;
				_tail.Next = null;
				Count--;
			}
			return data;
		}
		
		public T Remove(int index) 
		{
			if (index == 0) 
			{
				return RemoveFirst();
			}
			else if (index == Count - 1) 
			{
				return RemoveLast();
			}
			else 
			{
				DoublyNode<T> current = _head;
				for (int i = 0; i <= index; i++) 
				{
					current = current.Next;
				}
				current.Previous.Next = current.Next;
				current.Next.Previous = current.Previous;
				Count--;
				return current.Data;
			}
		}
		
		public bool Contains(T e) 
		{
			DoublyNode<T> current = _head;
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
		
		public int IndexOf(T e) 
		{
			DoublyNode<T> current = _head;
			for (int i = 0; current != null; i++) 
			{
				if (current.Data.Equals(e)) 
				{
					return i;
				}
				current = current.Next;
			}
			return -1;
		}
		
		public bool Erase(T e) 
		{
			int index = IndexOf(e);
			if (index >= 0) 
			{
				Remove(index);
				return true;
			}
			return false;
		}
		
		public void Clear() 
		{
			_head = null;
			_tail = null;
			Count = 0;
		}
	}
}
