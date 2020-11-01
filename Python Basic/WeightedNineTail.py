from WeightedNineTailModel import WeightedNineTailModel
from NineTailModel import getIndex
from NineTailModel import getNode
from NineTailModel import printNode

def main():
    # Prompt the user to enter nine coins H's and T's
    initialNode = \
        input("Enter an initial nine coin H's and T's: ").strip()

    # Create the NineTaileModel
    model = WeightedNineTailModel()
    path = model.getShortestPath(getIndex(initialNode))

    print("The steps to flip the coins are ")
    for i in range(len(path)):
        printNode(getNode(path[i]))  
        
    print("The number of flips is " + 
        str(model.getNumberOfFlipsFrom(getIndex(initialNode))))
    
main()