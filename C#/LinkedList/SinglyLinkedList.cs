using System;
using System.Collections.Generic;
using Sytem.Text;

namespace LinkedList 
{
	public class SinglyLinkedList<T>
	{
		private class Node<T> 
		{
			public T Data { get; set; }
			public Node<T> Next { get; set; }
			
			public Node(T e) {
				Data = e;
				Next = null;
			}
		}
		
		private Node<T> _head;
		private Node<T> _tail;
		
		public T Head 
		{
			get { return _head?.Data; }
		}
		public T Tail 
		{
			get { return _tail?.Data; }
		}
		public int Count { get; }; 
		
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
			if (index == 0) {
			return Head;
			}
			else if (index == Count - 1) {
				return Tail;
			}
			else {
				Node<T> current = _head;
				for (int i = 0; i < index; i++) {
					current = current.Next;
				}
				return current.Data;
			}
		}
		
		public void AddFirst(T e) {
			if (Count == 0) {
				_head = new Node(e);
				_tail = _head;
			}
			else {
				Node<T> temp = new Node(e);
				temp.Next = _head;
				_head = temp;
			}
			size++;
		}
		
		public void AddLast(T e) {
			if (Count == 0) {
				_tail = new Node(e);
				_head = _tail;
			}
			else {
				Node<T> temp = new Node(e);
				_tail.Next = temp;
				_tail = temp;
			}
			size++;
		}
		
		public T RemoveFirst() {
			T data = Head;
			if (_head == _tail) {
				_head = null;
				_tail = null;
				Count = 0;
			}
			else {
				_head = _head.Next;
				Count--;
			}
			return data;
		}
		
		public T RemoveLast() {
			T data = Tail;
			if (_head == _tail) {
				_head = null;
				_tail = null;
				Count = 0;
			}
			else {
				Node<T> current = _head;
				while (current.Next != _tail) {
					current = current.Next;
				}
				current.Next = null;
				_tail = current;
				Count--;
			}
			return data;
		}
		
		public bool Contains(T e) {
			Node<T> current = _head;
			while (current != null) {
				if (current.Data.Equals(e)) {
					return true;
				}
				current = current.Next;
			}
			return false;
		}
		
		public int IndexOf(T e) {
			Node<E> current = _head;
			for (int i = 0; current != null; i++) {
				if (current.Data.Equals(e)) {
					return i;
				}
				current = current.Next;
			}
			return -1;
		}
		
		public void Insert(int index, T e) {
			if (index == 0) {
				AddFirst(e);
			}
			else if (index == Count - 1) {
				AddLast(e);
			}
			else {
				Node<T> previous = _head;
				Node<T> current = _head.Next;
				for (int i = 0; i < index; i++) {
					previous = current;
					current = current.Next;
				}
				Node<T> temp = new Node(e);
				previous.Next = temp;
				temp.Next = current;
				Count++;
			}
		}
		
		public T Erase(int index) {
			if (index == 0) {
				RemoveFirst();
			}
			else if (index == Count - 1) {
				RemoveLast();
			}
			else {
				Node<T> previous = _head;
				Node<T> current = _head.Next;
				for (int i = 0; i < index; i++) {
					previous = current;
					current = current.Next;
				}
				previous.Next = current.Next;
				Count--;
				return current.Data;
			}
		}
		
		public bool Remove(T e) {
			Node<T> previous = _head;
			Node<T> current = _head.Next;
			while (current.Next != null) {
				if (current.Data.Equals(e)) {
					previous.Next = current.Next;
					Count--;
					return true;
				}
			}
			return false;
		}
		
		public void Clear() {
			_head = null;
			_tail = null;
			Count = 0;
		}
	}
}