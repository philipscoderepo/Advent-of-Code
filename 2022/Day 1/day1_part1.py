
f = open('day1_input.txt', 'r')
input = f.read()

max = 0
sum = 0
currNum = 0
i = 0
while i < len(input):
  char = input[i]
  # 10 for new line character
  if ord(char) == 10:
    sum += currNum
    if (i+1) < len(input) and ord(input[i+1]) == 10:
      if max < sum:
        max = sum
      sum = 0
    currNum = 0
  else:
    currNum *= 10
    currNum += ord(input[i]) - 48
  i += 1

if max < sum:
  max = sum

print(max)
f.close()