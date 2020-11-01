import urllib.request
input = urllib.request.urlopen('http://www.yahoo.com/index.html')
print(input.read())