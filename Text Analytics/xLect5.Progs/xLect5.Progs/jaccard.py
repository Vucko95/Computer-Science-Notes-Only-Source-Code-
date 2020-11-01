def JaccardIndex(str1, str2):
    set1 = set(str1.split())
    set2 = set(str2.split())
    ans = float(len(set1 & set2)) / len(set1 | set2)
    return round(ans, 2)

base = "roy harper album stormy"
target1 = "roy rovers comic sport"
target2 = "roy harper album flashes"
target3 = "roy green storm cock blip blop"
target4 = "roy harper album stormy"

ans1 = JaccardIndex(base, target1)
ans2 = JaccardIndex(base, target2)
ans3 = JaccardIndex(base, target3)
ans4 = JaccardIndex(base, target4)

print([ans1, ans2, ans3,ans4])



