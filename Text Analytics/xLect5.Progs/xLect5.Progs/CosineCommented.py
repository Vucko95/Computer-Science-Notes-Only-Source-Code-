__author__ = 'user'
# bits from http://stackoverflow.com/questions/15173225/how-to-calculate-cosine-similarity-given-2-sentence-strings-python
# load_docs, process_docs and compute_vector by MK
import math
from collections import Counter

vector_dict = {}                                       #Dict that will hold tf-idf matrix

#Just loads in all the documents
def load_docs():
 print("Loading docs...")
 doc1=('d1', 'LSI tutorials and fast tracks')
 doc2=('d2', 'books on semantic analysis')
 doc3=('d3', 'learning latent semantic indexing')
 doc4=('d4', 'advances in structures and advances in indexing')
 doc5=('d5', 'analysis of latent structures')
 return [doc1, doc2,doc3,doc4,doc5]

#Computes TF for words in each doc, DF for all features in all docs; finally whole Tf-IDF matrix
def process_docs(all_dcs):
 stop_words = [ 'of', 'and', 'on','in' ]
 all_words = []                                         #list to collect all unique words in each docs
 counts_dict = {}                                       #dict to collect doc data, word-counts and word-lists
 for doc in all_dcs:
    words = [x.lower() for x in doc[1].split() if x not in stop_words]
    words_counted = Counter(words)                      #counts words in a doc
    unique_words = list(words_counted.keys())           #list of the unique words in the doc
    counts_dict[doc[0]] = words_counted                 #make dict entry {'d1' : {'a': 1, 'b':6}}
    all_words = all_words + unique_words                #collect all unique words from each doc; bit hacky
 n = len(counts_dict)                                   #number of documents is no of entries in dict
 df_counts = Counter(all_words)                         #DF of all unique words from each doc, counted
 compute_vector_len(counts_dict, n, df_counts)          #computes TF-IDF for all words in all docs


#computes TF-IDF for all words in all docs
def compute_vector_len(doc_dict, no, df_counts):
  global vector_dict
  for doc_name in doc_dict:                              #for each doc
    doc_words = doc_dict[doc_name].keys()                #get all the unique words in the doc
    wd_tfidf_scores = {}
    for wd in list(set(doc_words)):                      #for each word in the doc
        wds_cts = doc_dict[doc_name]                     #get the word-counts-dict for the doc
        wd_tf_idf = wds_cts[wd] * math.log(no / df_counts[wd], 10)   #compute TF-IDF
        wd_tfidf_scores[wd] = round(wd_tf_idf, 4)        #store Tf-IDf scores with word
    vector_dict[doc_name] = wd_tfidf_scores              #store all Tf-IDf scores for words with doc_name


def get_cosine(text1, text2):
     vec1 = vector_dict[text1]
     vec2 = vector_dict[text2]
     intersection = set(vec1.keys()) & set(vec2.keys())
     #NB strictly, this is not really correct, needs vector of all features with zeros
     numerator = sum([vec1[x] * vec2[x] for x in intersection])
     sum1 = sum([vec1[x]**2 for x in vec1.keys()])
     sum2 = sum([vec2[x]**2 for x in vec2.keys()])
     denominator = math.sqrt(sum1) * math.sqrt(sum2)
     if not denominator:
        return 0.0
     else:
        return round(float(numerator) / denominator, 3)



#RUN THE DEFINED FNS

all_docs = load_docs()
process_docs(all_docs)
vector_dict['q'] = {'semantic' : 1, 'latent' : 1, 'indexing' : 1}

for keys,values in vector_dict.items(): print(keys, values)

text1 = 'd3'
text2 = 'q'
cosine = get_cosine(text1, text2)
print('Cosine:', cosine)
