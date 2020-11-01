import Rational

# Create and initialize two rational numbers r1 and r2.
r1 = Rational.Rational(4, 2)
r2 = Rational.Rational(2, 3)

# Display results
print(r1, "+", r2, "=", r1 + r2)
print(r1, "-", r2, "=", r1 - r2)
print(r1, "*", r2, "=", r1 * r2)
print(r1, "/", r2, "=", r1 / r2)

print(r1, ">", r2, "is", r1 > r2)
print(r1, ">=", r2, "is", r1 >= r2)
print(r1, "<", r2, "is", r1 < r2)
print(r1, "<=", r2, "is", r1 <= r2)
print(r1, "==", r2, "is", r1 == r2)
print(r1, "!=", r2, "is", r1 != r2)

print("int(r2) is", int(r2))
print("float(r2) is", float(r2))

print("r2[0] is", r2[0])
print("r2[1] is", r2[1])