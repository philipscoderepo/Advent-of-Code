f = open('input.txt', 'r')
input = f.read()
# A: Rock; 1 point
# B: Paper; 2 points
# C: Scissors; 3 points
# lost round: 0 points
# draw round: 3 points
# win round: 6 points
# X means you need to lose
# Y means you need to draw
# Z means you need to win
def findLose(o):
  # opp played rock
  if o == "A":
    # play scissors
    return 3
  # opp played paper
  elif o == "B":
    # play rock
    return 1
  # opp played scissors
  else:
    # play paper
    return 2

def findDraw(o):
  # opp played rock
  if o == "A":
    return 1
  # opp played paper
  elif o == "B":
    return 2
  # opp played scissors
  else:
    return 3

def findWin(o):
  # opp played rock
  if o == "A":
    # play paper
    return 2
  # opp played paper
  elif o == "B":
    # play scissors
    return 3
  # opp played scissors
  else:
    # play rock
    return 1

i = 0
score = 0
while i < len(input):
  opponent = input[i]
  outcome = input[i+2]

  if outcome == "X":
    score += 0
    score += findLose(opponent)
  elif outcome == "Y":
    score += 3
    score += findDraw(opponent)
  else:
    score += 6
    score += findWin(opponent)

  i += 4

print("score: ", score)


f.close()