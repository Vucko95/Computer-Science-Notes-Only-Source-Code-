# Manos Tsagkias' program for computing Kullback-Liebler Divergence
# Using the Migge (2003) smoothening backoff
# see http://staff.science.uva.nl/~tsagias/?s=kullback
# updated for Python3 by Mark Keane 30-June-2014

import re, math, collections
from collections import defaultdict, deque

def tokenize(_str):

    stopwords = ['and', 'for', 'if', 'too', 'as', 'the', 'then', 'be', 'is', 'are', 'will', 'in', 'it', 'to', 'that']
    tokens = collections.defaultdict(int)
    for m in re.finditer(r"(\w+)", _str, re.UNICODE):
        m = m.group(1).lower()
        if len(m) < 2: continue
        if m in stopwords: continue
        tokens[m] += 1
    return tokens
#end of tokenize

def kldiv(_s, _t):
    if (len(_s) == 0):
        return 1e33
    if (len(_t) == 0):
        return 1e33
    ssum = 0. + sum(_s.values())
    slen = len(_s)
    tsum = 0. + sum(_t.values())
    tlen = len(_t)
    vocabdiff = set(_s.keys()).difference(set(_t.keys()))
    lenvocabdiff = len(vocabdiff)

    #print("_s: %s" % _s)
    #print("_t: %s" % _t)
    #print("%s" % vocabdiff)

    """ epsilon """
    epsilon = min(min(_s.values())/ssum, min(_t.values())/tsum) * 0.001
    
    """ gamma """
    gamma = 1 - lenvocabdiff * epsilon
    
    """ Check if distribution probabilities sum to 1"""
    sc = sum([v/ssum for v in _s.values()])  
    st = sum([v/tsum for v in _t.values()]) 
    
    if sc < 9e-6:
        print("Sum P: %e, Sum Q: %e" % (sc, st))
        print("*** ERROR: sc does not sum up to 1. Bailing out ..")
        sys.exit(2)
    if st < 9e-6:
        print("Sum P: %e, Sum Q: %e" % (sc, st))
        print("*** ERROR: st does not sum up to 1. Bailing out ..")
        sys .exit(2)

    div = 0.
    for t, v in _s.items(): 
        pts = v / ssum
        ptt = epsilon
        if t in _t:
            ptt = gamma * (_t[t] / tsum)
            
        ckl = (pts - ptt) * math.log(pts / ptt)

        div +=  ckl
    return div

#end of kldiv

d1 = """Many research publications want you to use BibTeX, which better
organizes the whole process. Suppose for concreteness your source
file is x.tex. Basically, you create a file x.bib containing the
bibliography, and run bibtex on that file."""

d2 = """In this case you must supply both a \left and a \right because the
delimiter height are made to match whatever is contained between the two commands.
But, the \left doesn't have to be an actual 'left
delimiter', that is you can use '\left)' if there were some reason
to do it."""

d3 = """Many research publications want you to use BibTeX, which better
organizes the whole process. Suppose for concreteness your source
file is x.tex.But, the \left doesn't have to be an actual 'left
delimiter', that is you can use '\left)' if there were some reason
to do it."""


print("KL-divergence between d1 and d2:", kldiv(tokenize(d1), tokenize(d2)))
print("KL-divergence between d2 and d1:", kldiv(tokenize(d2), tokenize(d1)))
print("KL-divergence between d1 and d3:", kldiv(tokenize(d1), tokenize(d3)))
print("KL-divergence between d2 and d3:", kldiv(tokenize(d2), tokenize(d3)))
