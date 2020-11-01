import nltk

text = nltk.word_tokenize('The fish who jumped over the man is happy, the man who was fishing in the stream'  )

text_with_pos = nltk.pos_tag(text)
print(text_with_pos)

def convert_tags(tag):
        if tag == 'vbd' or tag == 'vbg' or tag == 'vbz':
                return 'v'
        else:
                return 'n'

wnl = nltk.WordNetLemmatizer()

for item in text_with_pos:
        new_tag = convert_tags(item[1].lower())
        print([item[0],new_tag])
        out = wnl.lemmatize(item[0], new_tag)
        print(out)
