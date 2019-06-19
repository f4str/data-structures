class StackNode:
    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:
    def __init__(self, elems = None):
        self._top = None
        self._length = 0
        if elems:
            for e in elems:
                self.push(e)
    
    def __len__(self):
        return self._length
    
    def __contains__(self, e):
        return self.contains(e)
    
    def empty(self):
        return self._length == 0
    
    def push(self, e):
        if self._length == 0:
            self._top = StackNode(e)
        else:
            temp = StackNode(e)
            temp.next = self._top
            self._top = temp
        self._length += 1
    
    def peek(self):
        if self._top == None:
            return None
        return self._top.data
    
    def pop(self):
        if self._length == 0:
            return None
        data = self._top.data
        self._top = self._top.next
        self._length -= 1
        return data
    
    def contains(self, e):
        current = self._top
        while current:
            if current.data == e:
                return True
            current = current.next
        return False
    
    def clear(self):
        self._top = None
        self._length = 0
