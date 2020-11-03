nums = [1,2,3,4,5,6,7,8,9,10]
nums1 = [int(x) for x in range(1,10)]

for x in nums:
    print(x,end=" ")

print()

# List Comprehension
numlist = [str(x) for x in nums]
print(numlist)

othernumbers = nums
othernumbers.append(11)
print(f"Othernumbers: {othernumbers}\nNumbers: {nums}\nNum range: {nums1}")



