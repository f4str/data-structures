using System;
using System.Collections.Generic;
using Sytem.Text;

namespace LinkedList 
{
	public class SinglyLinkedList<T>
	{
		private class SinglyNode<T> 
		{
			public T Data { get; set; }
			public SinglyNode<T> Next { get; set; }
			
			public SinglyNode(T e) 
			{
				Data = e;
				Next = null;
			}
		}
		
		private SinglyNode<T> _head;
		private SinglyNode<T> _tail;
		
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
		
		public SinglyLinkedList() 
		{
			_head = null;
			_tail = null;
			Count = 0;
		}
		
		public SinglyLinkedList(T[] elems) : this()
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
			else {
				SinglyNode<T> current = _head;
				for (int i = 0; i < index; i++) 
				{
					current = current.Next;
				}
				return current.Data;
			}
		}
		
		public T Set(int index, T e) 
		{
			if (index == 0) {
				T data = First;
				First = e;
				return data;
			}
			else if (index == Count - 1) 
			{
				T data = First;
				Last = e;
				return data;
			}
			else 
			{
				SinglyNode<T> current = _head;
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
				_head = new SinglyNode<T>(e);
				_tail = _head;
			}
			else 
			{
				SinglyNode<T> temp = new SinglyNode<T>(e);
				temp.Next = _head;
				_head = temp;
			}
			size++;
		}
		
		public void AddLast(T e) 
		{
			if (Count == 0) 
			{
				_tail = new SinglyNode<T>(e);
				_head = _tail;
			}
			else 
			{
				SinglyNode<T> temp = new SinglyNode<T>(e);
				_tail.Next = temp;
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
				SinglyNode<T> previous = _head;
				SinglyNode<T> current = _head.Next;
				for (int i = 0; i < index; i++) 
				{
					previous = current;
					current = current.Next;
				}
				SinglyNode<T> temp = new SinglyNode<T>(e);
				previous.Next = temp;
				temp.Next = current;
				Count++;
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
				SinglyNode<T> current = _head;
				while (current.Next != _tail) 
				{
					current = current.Next;
				}
				current.Next = null;
				_tail = current;
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
				SinglyNode<T> previous = _head;
				SinglyNode<T> current = _head.Next;
				for (int i = 0; i < index; i++) 
				{
					previous = current;
					current = current.Next;
				}
				previous.Next = current.Next;
				Count--;
				return current.Data;
			}
		}
		
		public bool Contains(T e) 
		{
			SinglyNode<T> current = _head;
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
			SinglyNode<T> current = _head;
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
