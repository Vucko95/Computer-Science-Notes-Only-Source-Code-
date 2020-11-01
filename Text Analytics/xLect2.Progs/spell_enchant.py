import enchant
d = enchant.Dict('en_GB')
ans1 = d.check('bamboo')
ans2 = d.check('bambox')
print(ans1)
print(ans2)