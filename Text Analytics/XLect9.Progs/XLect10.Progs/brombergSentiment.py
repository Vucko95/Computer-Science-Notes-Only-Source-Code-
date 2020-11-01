# http://andybromberg.com/sentiment-analysis-python/
# Andy Bromberg's Simple Sentiment Analysis System
# Uses data from Pang & Lee (2005)
# Uses a Naive Bayes Classifier Train the System
#  NB Updated 2016 for package changes around scores

import re, math, collections, itertools, sys, os
import nltk, nltk.classify.util, nltk.metrics
from nltk.classify import NaiveBayesClassifier
from nltk.metrics import BigramAssocMeasures, scores
from nltk.probability import FreqDist, ConditionalFreqDist

__location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))


def evaluate_features(feature_select):
    #reading pre-labeled input and splitting into lines
    negSentences = open(os.path.join(__location__, 'rt-polarity-neg.txt'), 'r', encoding='utf8')
    posSentences = open(os.path.join(__location__, 'rt-polarity-pos.txt'), 'r', encoding='utf8')
    negSentences = re.split(r'\n', negSentences.read())
    posSentences = re.split(r'\n', posSentences.read())
    
    posFeatures = []
    negFeatures = []
    # breaks up the sentences into lists of individual words
    # creates instance structures for classifier
    for i in posSentences:
        posWords = re.findall(r"[\w']+|[.,!?;]", i)
        posWords = [feature_select(posWords), 'pos']
        posFeatures.append(posWords)
    for i in negSentences:
        negWords = re.findall(r"[\w']+|[.,!?;]", i)
        negWords = [feature_select(negWords), 'neg']
        negFeatures.append(negWords)
        
    posCutoff = int(math.floor(len(posFeatures)*3/4))
    negCutoff = int(math.floor(len(negFeatures)*3/4))
    trainFeatures = posFeatures[:posCutoff] + negFeatures[:negCutoff]
    testFeatures = posFeatures[posCutoff:] + negFeatures[negCutoff:]
    
    #Runs the classifier on the testFeatures
    classifier = NaiveBayesClassifier.train(trainFeatures)
    
    #Sets up labels to look at output
    referenceSets = collections.defaultdict(set)
    testSets = collections.defaultdict(set)
    for i, (features, label) in enumerate(testFeatures): # enumerate adds number-count to each item
        referenceSets[label].add(i)               # recorded polarity for these test sentences
        predicted = classifier.classify(features) # classifiers' proposed polarity for tests
        testSets[predicted].add(i)

    #Outputs
    print('train on %s instances, test on %s instances'% (len(trainFeatures), len(testFeatures)))
    print('accuracy:', nltk.classify.util.accuracy(classifier, testFeatures))
    print('pos precision:', scores.precision(referenceSets['pos'], testSets['pos']))
    print('pos recall:', scores.recall(referenceSets['pos'], testSets['pos']))
    print('neg precision:', scores.precision(referenceSets['neg'], testSets['neg']))
    print('neg recall:', scores.recall(referenceSets['neg'], testSets['neg']))
    classifier.show_most_informative_features(10)

def make_full_dict(words):
    return dict([(word, True) for word in words])

print('using all words as features')
evaluate_features(make_full_dict)
