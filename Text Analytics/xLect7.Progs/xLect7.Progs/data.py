__author__ = 'user'

import matplotlib.pyplot as plt

'''
purified/no additives	0.082	0.045
purified/no additives	0.082	0.125
healthy	0.041	0.090
healthy	0.041	0.075
French	0.123	0.050
Bottled	0.205	0.104
refreshing	0.137	0.075
expensive	0.041	0.134
hydrating	0.041	0.060
natural source (e.g. mountain spring)	0.110	0.030
reliable	0.015	0.075

'''

lista = [0.082, 0.082, .041, .041, .123, .205, .137, .041, .041, .110, .015]
listb = [0.045, 0.125, .090, .075, .050, .104, .075, .134, .060, .030, .075]
plt.plot(lista, listb, 'ro')
plt.axis([0, .15, 0, .15])
plt.show()



