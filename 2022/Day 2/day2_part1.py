f = open('input.txt', 'r')
input = f.read()
# A, X: Rock; 1 point
# B, Y: Paper; 2 points
# C, Z: Scissors; 3 points
# lost round: 0 points
# draw round: 3 points
# win round: 6 points
# Paper > Rock
# Rock > Scissors
# Scissors > Paper
def calcRoundScore(p, o):
  # convert player move
  if p == "X":
    p = "A"
  elif p == "Y":
    p = "B"
  else:
    p = "C"
  
  # draw
  if p == o:
    return 3

  # check for win
  if (p == "A" and o == "C") or (p == "B" and o == "A") or (p == "C" and o == "B"):
    return 6
  
  # lost
  return 0

i = 0
score = 0
while i < len(input):
  opponent = input[i]
  player = input[i+2]
  # calculate player score
  if player == "X":
    score += 1
  elif player == "Y":
    score += 2
  else:
    score += 3
  score += calcRoundScore(player, opponent)
  i += 4

print("score: ", score)


f.close()