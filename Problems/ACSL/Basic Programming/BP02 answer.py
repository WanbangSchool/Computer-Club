korean = int(input())
english = int(input())
math = int(input())

average = (korean + english + math) / 3

if average >= 60 and korean >= 40 and english >= 40 and math >= 40:
    print("Pass")
else:
    print("Fail")