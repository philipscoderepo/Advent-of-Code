def calculatePriority(l):
  if ord(l) >= 65 and ord(l) <= 90:
    # upper case letter
    return ord(l) - 38
  else:
    # lower case letter
    return ord(l) - 96

f = open('day3_input.txt', 'r')
input = f.read()

currLine = []
currGroup = []
prioritySum = 0
lineNum = 0
for i in range(len(input)):
  # new line
  if ord(input[i]) == 10:
    lineNum += 1
    currGroup.append(currLine)
    currLine = []
    # every 3 lines starts a new group
    if ((lineNum) % 3) == 0:
      currGroup.append(currLine)
      line1 = currGroup[0]
      line2 = currGroup[1]
      line3 = currGroup[2]
      matchFound = False
      for j in range(len(line1)):
        for k in range(len(line2)):
          if line1[j] == line2[k]:
            for h in range(len(line3)):
              if line1[j] == line3[h]:
                matchFound = True
                prioritySum += calculatePriority(line1[j])
                print("Line: ", lineNum, "Letter: ", line1[j], "Score: ", prioritySum)
                break
          if matchFound:
            break
        if matchFound:
          break
      currGroup = []
  else:
    currLine.append(input[i])

print("sum: ", prioritySum)

f.close()