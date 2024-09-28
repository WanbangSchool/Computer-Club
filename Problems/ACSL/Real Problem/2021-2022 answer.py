
def fibonacci_clock(colors):
    fibonacci = [1, 1, 2, 3, 5]
    hours = 0
    minutes = 0
    for i, color in enumerate(colors):
        if color == 'R': 
            hours += fibonacci[i]
        elif color == 'G':  
            minutes += fibonacci[i]
        elif color == 'B': 
            hours += fibonacci[i]
            minutes += fibonacci[i]
    minutes *= 5
    if minutes == 60:
        minutes = 0
        hours += 1
    if hours >= 12:
        hours -= 12
    return f"{hours:02}:{minutes:02}"

test_cases = []

for _ in range(5):
    line = input().split()  
    test_cases.append(line)

for case in test_cases:
    print(fibonacci_clock(case))
