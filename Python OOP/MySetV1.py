class MySet:
    def __init__(self, members):
        self._members = []
        for cand in members:
            self.add(cand)
  
    def clear(self):
        self._members = []
    
    def add(self,cand):
        if not cand in self._members:
                self._members.append(cand)
    
    def member(self, mem):
        for el in self._members:
            if el == mem: return True
        return False 

    def remove(self,mem):
        self._members.remove(mem)
    
    def union(self,s):
        su = MySet(self._members)
        for el in s._members:
            su.add(el)
        return su
    
    def intersection(self,s):
        si = MySet([])
        for el in self._members:
            if el in s._members: 
                si.add(el)
        return si
    
    def print(self):
        mems = self._members
        print('V1{',end='')
        for i in range(len(mems)):
            print(mems[i],end='')
            if i != len(mems)-1:    #don't print a comma after final element
                print(', ',end='')
        print('}')
        
    def mem_list(self):    
        return self._members