#%% Change working directory from the workspace root to the ipynb file location. Turn this addition off with the DataScience.changeDirOnImportExport setting
import os
try:
	os.chdir(os.path.join(os.getcwd(), 'ucd.python/ipython'))
	print(os.getcwd())
except:
	pass
#%% [markdown]
# ## Python Basics
#%% [markdown]
# ### Variables in Python
#%% [markdown]
# **Variable**: A container in memory, which has a unique name or identifier, where you can store information.
# Start using the variable by assigning it a value, where the *=* symbol denotes *assignment*. 

#%%
x = 100

#%% [markdown]
# Python has a number of variable naming rules:
# * Can contain both letters and numbers, but must begin with a letter.
# * Can contain the underscore character. 
# * Must not clash with reserved keywords.
#%% [markdown]
# We can display the value in a variable using the *print* function - note the use of parentheses.

#%%
print(x)

#%% [markdown]
# Each variable also has a *type*, indicating the nature of the value that it stores.

#%%
type(x)


#%%
type("UCD")

#%% [markdown]
# Numeric data can be *integers* (whole numbers) or *floats* (real values):

#%%
a = 3
b = -125
fx = 0.432
fy = -24.23

#%% [markdown]
# *Boolean* values can be indicated by *True* or *False* - case sensitive! Can alternatively we can use '1' and '0'

#%%
answer = True
test_value = False

#%% [markdown]
# A *string* value containing text is enclosed within either single quotes or double quotes - make sure you end with the same character: 

#%%
some_text = "hello world"
moredata = 'university college dublin, ireland'

#%% [markdown]
# We also use a special value *None* to indicate a variable containing an empty or "null" value:

#%%
current_value = None

#%% [markdown]
# ### Operators and Expressions
#%% [markdown]
# Python can be used as a simple calculator. It supports all basic mathematical operators, such as +, -, *, /
#%% [markdown]
# We can use combinations of these operators and values to create *expressions*, which are the building blocks of Python code.

#%%
a = 4 * 3 + 2
a


#%%
b = a - 2
b

#%% [markdown]
# We can also use operators to perform assignment and an operation on the same variable. Note that these lines include *comments* - everything from # onwards is ignored.

#%%
a += 2   # add 2 to the value currently in a and assign it back to a
b -= 1   # subtract 1 from the value currently in b and assign it back to b

#%% [markdown]
# Parentheses can be used to control the *order* in which operators are applied:

#%%
4 + 10 / 2  # Division will normally be applied first


#%%
(4 + 10)/2  # Use parenthesis to apply addition first, then division

#%% [markdown]
# There are also other operators, such as %,// and ** (modulo, floor division and ‘to the power’)

#%%
3**2

#%% [markdown]
# ### Boolean Expressions
#%% [markdown]
# Any value or variable in Python can be tested for a 'truth value'. These will yield a value of True or False, depending on what we are testing - e.g. equality, inequality, greater/less than

#%%
x = 75 # don't confuse assignment with equality!


#%%
x == 75 # test for equality


#%%
x == 100 # test for equality


#%%
x != 100 # test for inequality


#%%
x < 1000 # less than


#%%
x > 0 # greater than

#%% [markdown]
# Python contains boolean operators to create more complex boolean expressions:
# * *not x*: returns False if x is True, returns True if x is False
# * *x and y*: if both x and y are True then return True, otherwise False
# * *x or y*: if either x or y are True then return True, otherwise False

#%%
True and True


#%%
True and False


#%%
True or False


#%%
not True


#%%
x > 0 and x < 100


