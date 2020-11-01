__author__ = 'mark keane'

def tester():
    print("this is my test...")
    run_this()
    print("end")

def run_this():
    print("this is the run this bit...")
    print(__author__)

tester()

x = -(-(-(-2))) == -2
y = 19 % 4
val = (not True) or True
print(val)

def check(name):
    if name == "Mark":
        print("hurray")

check("Mark")