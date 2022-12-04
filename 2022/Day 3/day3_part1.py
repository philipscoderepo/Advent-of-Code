f = open('day3_input.txt', 'r')
input = f.read()

lineNum = 0
currLine = []
prioritySum = 0
for i in range(len(input)):
  matchFound = False
  if ord(input[i]) == 10:
    for j in range(int(len(currLine)/2)):
      for k in range(int(len(currLine)/2), len(currLine)):
        if currLine[j] == currLine[k]:
          matchFound = True
          l = currLine[j]
          if ord(l) >= 65 and ord(l) <= 90:
            # upper case letter
            prioritySum += ord(l) - 38
          else:
            # lower case letter
            prioritySum += ord(l) - 96
          print("lineNum: ", lineNum, "match: ", l, "sum: ", prioritySum)
          break
      if matchFound:
        break
    currLine.clear()
    lineNum += 1
  else:
    currLine.append(input[i])


print("sum: ", prioritySum)


f.close()