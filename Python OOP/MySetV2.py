class MySet:
    def __init__(self, members):
        self._members = {}
        for cand in members:
            self.add(cand)
    
    def clear(self):
        self._members = {}
    
    def add(self,cand):
        if not cand in self._members:
                self._members[cand]="DVal"
    
    def member(self, mem):
        if mem in self._members: return True
        return False 
    
    def remove(self,mem):
        del self._members[mem]
    
    def union(self,s):
        su = MySet(self._members.keys())
        for el in s._members.keys():
            su.add(el)
        return su
    
    def intersection(self,s):
        si = MySet([])
        for el in self._members.keys():
            if el in s._members.keys(): 
                si.add(el)
        return si

    def print(self):
        mems = self._members
        print('V2{',end='')
        i = 0
        for el in mems.keys():
            print(el,end='')
            if i != len(mems)-1:    #don't print a comma after final element
                print(', ',end='')
            i += 1
        print('}')
    
    def mem_list(self):    
        mems = self._members
        return list(mems.keys())