n = int(input())
reversed_n = 0

while n > 0:
    digit = n % 10  # 마지막 자리 숫자 추출
    reversed_n = reversed_n * 10 + digit  # 숫자를 뒤집음
    n //= 10  # 마지막 자리 숫자 제거

print(reversed_n)