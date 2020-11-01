def isPalindrome(s):
    return isPalindromeHelper(s, 0, len(s) - 1)

def isPalindromeHelper(s, low, high):
    if high <= low: # Base case
      return True
    elif s[low] != s[high]: # Base case
      return False
    else:
      return isPalindromeHelper(s, low + 1, high - 1)

def main():
    print("Is moon a palindrome?", isPalindrome("moon"))
    print("Is noon a palindrome?", isPalindrome("noon"))
    print("Is a a palindrome?", isPalindrome("a"))
    print("Is aba a palindrome?", isPalindrome("aba"))
    print("Is ab a palindrome?", isPalindrome("ab"))

main() # Call the main function
