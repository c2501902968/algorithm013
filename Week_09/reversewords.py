'''
Author: your name
Date: 2020-09-26 20:00:29
LastEditTime: 2020-09-26 20:26:03
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: /Week_09/reversewords.py
'''
# !/usr/bin/python3
# -*- encoding:utf-8 -*-
s = "a-bC-dEf-ghIj"

letters = [c for c in s if c.isalpha()]
ans = []
for c in s:
    if c.isalpha():
        ans.append(letters.pop())
    else:
        ans.append(c)
print(" ".join(ans))
