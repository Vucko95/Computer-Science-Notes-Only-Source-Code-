from tkinter import * # Import tkinter
   
class FigureCanvas(Canvas):
    def __init__(self, container, figureType, filled = False, 
                 width = 100, height = 100):
        super().__init__(container, 
                         width = width, height = height)
        self.__figureType = figureType
        self.__filled = filled
        self.drawFigure()
      
    def getFigureType(self):
        return self.__figureType 
        
    def getFilled(self):
        return self.__filled 
          
    def setFigureType(self, figureType):
        self.__figureType = figureType
        self.drawFigure()
        
    def setFilled(self, filled):
        self.__filled = filled
        self.drawFigure()
                
    def drawFigure(self):
        if self.__figureType == "line":
            self.line()
        elif self.__figureType == "rectangle":    
            self.rectangle()
        elif self.__figureType == "oval":
            self.oval()
        elif self.__figureType == "arc":    
            self.arc()
        
    def line(self):
        width = int(self["width"])
        height = int(self["height"])
        self.create_line(10, 10, width - 10, height - 10)
        self.create_line(width - 10, 10, 10, height - 10)

    def rectangle(self):
        width = int(self["width"])
        height = int(self["height"])
        if self.__filled:
            self.create_rectangle(10, 10, width - 10, height - 10, 
                              fill = "red")
        else:
            self.create_rectangle(10, 10, width - 10, height - 10)
            
    def oval(self):
        width = int(self["width"])
        height = int(self["height"])
        if self.__filled:
            self.create_oval(10, 10, width - 10, height - 10, 
                             fill = "red")
        else:
            self.create_oval(10, 10, width - 10, height - 10)

    def arc(self):
        width = int(self["width"])
        height = int(self["height"])
        if self.__filled:
            self.create_arc(10, 10, width - 10, height - 10, 
                        start = 0, extent = 145, fill = "red")
        else:
            self.create_arc(10, 10, width - 10, height - 10, 
                        start = 0, extent = 145)
