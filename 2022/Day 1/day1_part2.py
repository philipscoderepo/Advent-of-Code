
f = open('day1_input.txt', 'r')
input = f.read()

max1 = 0
max2 = 0
max3 = 0
sum = 0
currNum = 0
i = 0
while i < len(input):
  char = input[i]
  # 10 for new line character
  if ord(char) == 10:
    sum += currNum
    if (i+1) < len(input) and ord(input[i+1]) == 10:
      if max1 < sum:
        max3 = max2
        max2 = max1
        max1 = sum
      
      if max2 < sum and sum < max1:
        max3 = max2
        max2 = sum
        
      if max3 < sum and sum < max2:
        max3 = sum

      sum = 0
    currNum = 0
  else:
    currNum *= 10
    currNum += ord(input[i]) - 48
  i += 1

print("max1: ", max1)
print("max2: ", max2)
print("max3: ", max3)
print("total: ", max1 + max2 + max3)
f.close()