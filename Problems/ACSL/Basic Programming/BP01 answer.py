apple_price = 1500
strawberry_price = 2000
banana_price = 3000

apple_count = int(input())
strawberry_count = int(input())
banana_count = int(input())

total_price = apple_count * apple_price + strawberry_count * strawberry_price + banana_count * banana_price

print(total_price)

if total_price >= 10000:
    print("True")
else:
    print("False")