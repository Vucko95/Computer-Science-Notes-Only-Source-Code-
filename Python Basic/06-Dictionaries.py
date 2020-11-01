#!/usr/bin/python
 
__author__ = 'pythonspot.com'

words = {}
words["Hello"] = "Bonjour"
words["Yes"] = "Oui"
words["No"] = "Non"
words["Bye"] = "Au Revoir"
 
print(words)           # print key-pairs.
del words["Yes"]       # delete a key-pair.
print(words)           # print key-pairs.
words["Yes"] = "Oui!"  # add new key-pair.
print(words)           # print key-pairs.
