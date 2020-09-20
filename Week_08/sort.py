#!/use/bin/python3
#! -*- encoding: utf-8 -*-


def bubbleSort(arr):
    size = len(arr)
    for i in range(size):
        for j in range(size - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr


def selectionSort(arr):
    size = len(arr)
    for i in range(size - 1):
        minIndex = i
        for j in range(i + 1, size):
            if arr[j] < arr[minIndex]:  # 寻找最小的数
                minIndex = j  # 将最小数的索引保存
            arr[j], arr[minIndex] = arr[minIndex], arr[j]
    return arr


def insertionSort(arr):
    size = len(arr)
    for i in range(size):
        preIndex = i - 1
        current = arr[i]
        # 如果该元素（已排序）大于新元素，则将该元素移到下一个值
        # 重复步骤，直到找到已排序的元素小于或等于新的元素的位置
        while preIndex >= 0 and arr[preIndex] > current:
            arr[preIndex + 1] = arr[preIndex]
            preIndex -= 1
        # 将新元素插入到该位置后
        arr[preIndex + 1] = current
    return arr


def shellSort(arr):
    n = len(arr)
    gap = int(n / 2)

    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap = int(gap / 2)
        return arr


def mergeSort(arr):
    """ 归并排序 """
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2  # 将列表分成更小的两个列表
    # 分别对左右两个列表进行处理，分别返回两个排序好的列表
    left = mergeSort(arr[:mid])
    right = mergeSort(arr[mid:])
    # 对排序好的两个列表合并，生成一个新的排序好的列表
    return merge(left, right)


def merge(left, right):
    """ 合并两个已排序好的列表，产生一个新的已排序好的列表"""
    result = []  # 新的已排好的列表
    i = 0  # 下标
    j = 0
    # 对两个列表中的元素，两两对比
    # 将最小的元素，放到result中，并对当前列表下标加1
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result += left[i:]
    result += right[j:]
    return result


# 快速排序I
# quick_sort = lambda array: array if len(array) <= 1 else quick_sort([
#     item for item in array[1:] if item <= array[0]
# ]) + [array[0]] + quick_sort([item for item in array[1:] if item > array[0]])

# 快速排序II
# def quick_sort(arr, left, right):
#     if left < right:
#         q = partition(arr, left, right)
#         quick_sort(arr, left, q - 1)
#         quick_sort(arr, q + 1, right)
#     return arr


# def partition(arr, left, right):
#     x = arr[right]
#     i = left - 1
#     for j in range(left, right):
#         if arr[j] <= x:
#             i += 1
#             arr[i], arr[j] = arr[j], arr[i]
#     arr[i + 1], arr[right] = arr[right], arr[i + 1]
#     return i + 1
def quick_sort(arr, left, right):
    if left >= right:
        return
    stack = []
    stack.append(left)
    stack.append(right)
    while stack:
        low = stack.pop(0)
        high = stack.pop(0)
        if high - low <= 0:
            continue
        x = arr[high]
        i = low - 1
        for j in range(low, high):
            if arr[j] <= x:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        stack.extend([low, i, i + 2, high])
        return arr


# 堆排序
def heap_sort(arr):
    i, l = 0, len(arr)
    # 构造大顶堆，从非叶子节点开始倒序遍历，因此l // 2 - 1 就是最后一个非叶子节点
    for i in range(l // 2, -1, -1):
        build_heap(arr, i, l - 1)
    for j in range(l - 1, -1, -1):
        arr[0], arr[j] = arr[j], arr[0]
        build_heap(arr, 0, j - 1)
    return arr


def build_heap(arr, i, l):
    """ 构建大顶堆 """
    left, right = 2 * i + 1, 2 * i + 2
    large_index = i
    if left <= l and arr[i] < arr[left]:
        large_index = left
    if right <= l and arr[left] < arr[right]:
        large_index = right

    if large_index != i:
        arr[i], arr[large_index] = arr[large_index], arr[i]
        build_heap(arr, large_index, l)


if __name__ == "__main__":
    arr = [1, 5, 3, 2, 7, 4]
    print(arr)
    arr2 = bubbleSort(arr)
    arr3 = selectionSort(arr)
    arr4 = insertionSort(arr)
    arr5 = shellSort(arr)
    arr6 = mergeSort(arr)
    arr7 = quick_sort(arr, 0, len(arr) - 1)
    arr8 = heap_sort(arr)
    print('bubbleSort: {}'.format(arr2))
    print('selectionSort: {}'.format(arr3))
    print('insertionSort:{}'.format(arr4))
    print('shellSort:{}'.format(arr5))
    print('mergeSort{}'.format(arr6))
    print("quick_sort{}".format(arr7))
    print("heap_sort{}".format(arr8))
