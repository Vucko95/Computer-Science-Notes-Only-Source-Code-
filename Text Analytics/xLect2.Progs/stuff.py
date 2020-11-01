import urllib.request
url = 'http://www.csi.ucd.ie/users/mark-keane'
urllib.request.urlopen(url)
<http.client.HTTPResponse object at 0x1092d1278>
raw = urllib.request.urlopen(url).read()
from bs4 import BeautifulSoup
soup = bs4.BeautifulSoup(raw)
soup2.title
soup2.body.get_text(strip=True)
soup2.findAll('a')
foo = soup2.findAll('a')
for item in foo: print(item)
