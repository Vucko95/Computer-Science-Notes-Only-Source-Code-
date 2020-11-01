#!/usr/bin/env python
 
__author__ = 'pythonspot.com'

class Human:
 
  def __init__(self):
    self.name = 'Guido'
    self.head = self.Head()
    self.brain = self.Brain()
 
  class Head:
    def talk(self):
      return 'talking...'
 
  class Brain:
    def think(self):
      return 'thinking...'
 
if __name__ == '__main__':
  guido = Human()
  print(guido.name)
  print(guido.head.talk())
  print(guido.brain.think())
