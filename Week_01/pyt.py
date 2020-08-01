def plusOne(digits):
    """
        :type digits: List[int]
        :rtype: List[int]
        """
    sum = 0
    for i in range(len(digits)):
        sum = sum * 10 + digits[i]
    sum = sum + 1
    print(sum)
    l = []
    for x in str(sum):
        l.append(int(x))
    print(l)
    return l


d = [1, 2, 3]
plusOne(d)