import random

TARGET = "METHINKS IT IS LIKE A WEASEL"
PROBABILITY = 0.05
SIZE = 100

def new_charactere(last_Charactere):
    if random.random() < PROBABILITY:
        char = random.randint(65,91)
        if char == 91:
            return ' '

        return chr(char)

    return last_Charactere

def calculate_new_sequence(sequence):
    newsequence = ''
    for char in sequence:
        newsequence += new_charactere(char)
    return newsequence

def calculate_score(sequence):
    score = 0
    for i in range(0,len(sequence)):
        if sequence[i] == TARGET[i]:
            score += 1
    return score

def generate_random_sequence():
    sequence = ""
    for i in range(0,len(TARGET)):
        char = random.randint(65,91)
        if char == 91:
            sequence += ' '
        else:
            sequence += chr(char)
    return sequence


current_sequence = generate_random_sequence()
generation = 0

print "Random sequence %s" % current_sequence

while current_sequence != TARGET:
    last_sequence = ""
    best_score = 0
    
    for i in range(0, SIZE):
        new_sequence = calculate_new_sequence(current_sequence)
        new_sequence_score = calculate_score(new_sequence)
        if new_sequence_score >= best_score:
            last_sequence = new_sequence
            best_score = new_sequence_score

    current_sequence = last_sequence
    print "Generation %d best candidate: %s (%d)" % (generation, last_sequence, best_score)
    generation += 1