#####O(n^3)

# # Function to find a triplet with a given sum in an array
# def find3Numbers(arr, sum):
#     n = len(arr)

#     # Fix the first element as arr[i]
#     for i in range(n - 2):

#         # Fix the second element as arr[j]
#         for j in range(i + 1, n - 1):

#             # Now look for the third number
#             for k in range(j + 1, n):

#                 if arr[i] + arr[j] + arr[k] == sum:

#                     # Triplet is found; print the triplet elements
#                     print(f"Triplet is {arr[i]}, {arr[j]}, {arr[k]}")
#                     return True

#     # If no triplet is found, return false
#     return False


# # Driver code
# arr = [1, 4, 45, 6, 10, 8]
# sum = 22

# find3Numbers(arr, sum)



##### O(n^3)

# Function to find a triplet with a given sum in an array
# def find3Numbers(arr, sum):
#     n = len(arr)
    
#     # Fix the first element as arr[i]
#     for i in range(n - 2):
      
#         # Create a set to store potential second elements
#         # that complement the desired sum
#         s = set()

#         # Calculate the current sum needed to reach the
#         # target sum
#         curr_sum = sum - arr[i]

#         # Iterate through the subarray arr[i+1..n-1] to find
#         # a pair with the required sum
#         for j in range(i + 1, n):
          
#             # Calculate the required value for the second
#             # element
#             required_value = curr_sum - arr[j]

#             # Check if the required value is present in the
#             # set
#             if required_value in s:
              
#                 # Triplet is found; print the triplet elements
#                 print(f"Triplet is {arr[i]}, {arr[j]}, {required_value}")
#                 return True

#             # Add the current element to the set for future
#             # complement checks
#             s.add(arr[j])

#     # If no triplet is found, return false
#     return False

# # Driver code
# arr = [1, 4, 45, 6, 10, 8]
# sum = 22

# find3Numbers(arr, sum)


##### O(n^2)

# Function to find a triplet with a given sum in an array
def find3Numbers(arr, sum):
    n = len(arr)
    
    # Fix the first element as arr[i]
    for i in range(n - 2):
      
        # Create a set to store potential second elements
        # that complement the desired sum
        s = set()

        # Calculate the current sum needed to reach the
        # target sum
        curr_sum = sum - arr[i]

        # Iterate through the subarray arr[i+1..n-1] to find
        # a pair with the required sum
        for j in range(i + 1, n):
          
            # Calculate the required value for the second
            # element
            required_value = curr_sum - arr[j]

            # Check if the required value is present in the
            # set
            if required_value in s:
              
                # Triplet is found; print the triplet elements
                print(f"Triplet is {arr[i]}, {arr[j]}, {required_value}")
                return True

            # Add the current element to the set for future
            # complement checks
            s.add(arr[j])

    # If no triplet is found, return false
    return False

# Driver code
arr = [1, 4, 45, 6, 10, 8]
sum = 22

find3Numbers(arr, sum)


