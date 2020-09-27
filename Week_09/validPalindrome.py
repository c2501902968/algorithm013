'''
Author: your name
Date: 2020-09-26 20:26:18
LastEditTime: 2020-09-26 21:04:53
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: /Week_09/validPalindrome.py
'''


def reverseOnlyLetters(S):
    size = len(S)
    for i in range(size // 2):
        if S[i] != S[size - i - 1]:

            return False
    return True


s = "abcba"
print(reverseOnlyLetters(s))
