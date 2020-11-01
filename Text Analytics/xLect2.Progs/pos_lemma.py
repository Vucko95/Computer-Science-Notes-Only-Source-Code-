import nltk

text = nltk.word_tokenize('John Doe ran the U.S., he\'ll do anything for I.B.M.' )

text_with_pos = nltk.pos_tag(text)
print(text_with_pos)
ne_chunks = nltk.ne_chunk(text_with_pos, binary=True)
print(ne_chunks)
