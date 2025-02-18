from collections import Counter
import pandas as pd

def count_inversions(arr):
    """
    Counts the number of inversions in an array.
    """
    if len(arr) <= 1:
        return arr, 0

    mid = len(arr) // 2
    left, left_inversions = count_inversions(arr[:mid])
    right, right_inversions = count_inversions(arr[mid:])
    merged, split_inversions = merge_and_count_split_inversions(left, right)

    return merged, split_inversions + left_inversions + right_inversions

def merge_and_count_split_inversions(left, right):
    """
    Merges two arrays and counts the number of split inversions.
    """
    result = []
    i = j = split_inversions = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
            split_inversions += len(left) - i

    # Append remaining elements
    result.extend(left[i:])
    result.extend(right[j:])

    return result, split_inversions

def inversions_course_codes(choices_students):
    """
    Counts the number of inversions in a list of choices and classifies
    them according to the count of inversions.
    """
    inversions = []
    for choices in choices_students:
        _, t = count_inversions(choices)
        inversions.append(t)

    # Creates a hashmap/dictionary with key as the inversion count and value
    # as the number of students that have that count, sorted by inversion count.
    count = dict(sorted(Counter(inversions).items()))
    return count

# Load the CSV file
try:
    df = pd.read_csv('course_choice.csv')
except FileNotFoundError:
    print("Error: File 'course_choice.csv' not found. Please check the file path.")
    exit()

# Extract student data
student_ids = df['Student'].tolist()
choices_students = df.drop(columns=['Student']).values.tolist()

# Count inversions and print results
for k, v in inversions_course_codes(choices_students).items():
    print(f"{v:2d} students have {k:2d} inversion count.")
