import nltk
from nltk.corpus import names
import random

def gender_features(word):
    return {'last_letter': word[-1]}
# gender_features('Shrek') = {'last_letter': 'k'}

male_names = [(name, 'male') for name in names.words('male.txt')]
female_names = [(name, 'female') for name in names.words('female.txt')]
labeled_names = male_names + female_names
random.shuffle(labeled_names)
featuresets = [(gender_features(n), gender) for (n, gender) in labeled_names]
#entries are    ({'last_letter': 'g'}, 'male')
train_set, test_set = featuresets[500:], featuresets[:500]

classifier = nltk.NaiveBayesClassifier.train(train_set)

ans1 = classifier.classify(gender_features('Mark'))
ans2 = classifier.classify(gender_features('Precilla'))

print("Mark is:", ans1)
print("Precilla is:", ans2)

# classifier.show_most_informative_features(5)
# print(nltk.classify.accuracy(classifier, test_set))





