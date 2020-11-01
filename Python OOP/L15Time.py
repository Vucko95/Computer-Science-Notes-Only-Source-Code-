class TimeMS():
    def __init__(self,tstring):
        tt = tstring.split(':')
        self.mins = int(tt[0])
        self.secs = int(tt[1])
    
    def get_time(self):
        return(self.mins,self.secs)
    
    # generate a string representation for printing, e.g 12:09
    def __str__(self):
        ss = ":"
        if self.secs < 10:
            ss = ":0"
        ss = str(self.mins)+ss+str(self.secs)
        return ss
    
    def inc(self,ms_tuple):
        self.mins += ms_tuple[0]
        self.secs += ms_tuple[1]
        if self.secs >= 60:
            self.mins += 1
            self.secs -= 60
    
    def reset(self):
        self.mins = 0
        self.secs = 0 