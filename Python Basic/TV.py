class TV:
    def __init__(self):
        self.channel = 1  # Default channel is 1
        self.volumeLevel = 1  # Default volume level is 1
        self.on = False  # By default TV is off
  
    def turnOn(self):
        self.on = True
  
    def turnOff(self):
        self.on = False
  
    def getChannel(self):
        return self.channel

    def setChannel(self, channel):
        if self.on and 1 <= self.channel <= 120:
            self.channel = channel
  
    def getVolumeLevel(self):
        return self.volumeLevel

    def setVolume(self, volumeLevel):
        if self.on and \
              1 <= self.volumeLevel <= 7:
            self.volumeLevel = volumeLevel
  
    def channelUp(self):
        if self.on and self.channel < 120:
            self.channel += 1
  
    def channelDown(self):
        if self.on and self.channel > 1:
            self.channel -= 1
  
    def volumeUp(self):
        if self.on and self.volumeLevel < 7:
            self.volumeLevel += 1
  
    def volumeDown(self):
        if self.on and self.volumeLevel > 1:
            self.volumeLevel -= 1
