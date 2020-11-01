__author__ = 'user'

import nltk.metrics
import distance

#  transposition flag allows transpositions edits (e.g., “ab” -> “ba”),

s1 = 'dr mark keane'
s2 = 'mr mark bean'

s3 = 'rain'
s4 = 'shine'

s5 = 'mr rowan atkinson'
s6 = 'mr bean'

ans = nltk.metrics.distance.edit_distance(s1, s2, transpositions=False)
print(ans)

ans = nltk.metrics.distance.edit_distance(s3, s4, transpositions=False)
print(ans)

ans = nltk.metrics.distance.edit_distance(s5, s6, transpositions=False)
print(ans)

ans = distance.levenshtein(s1, s2)
print(ans)

ans = distance.levenshtein(s3, s4)
print(ans)

ans = distance.levenshtein(s5, s6)
print(ans)
