#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char TARGET[29] = "METHINKS IT IS LIKE A WEASEL";
double PROBABILITY = 0.05;
int SIZE = 100;

int random_int(int min_num, int max_num) {
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num) {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

double random_double() {
    return 1.0 / random_int(0, 1);
}

char new_charactere(char last_charactere) {
    if (random_double() < PROBABILITY) {
        int new_char = random_int(26, 91);

        if (new_char == 91) {
            return ' ';
        } else {
            return (char) new_char;
        }
    }

    return last_charactere;
}

char* calculate_new_sequence(char sequence[29]) {
    char* new_sequence;

    for(int i = 0; i < 29; i++) {
        new_sequence[i] = new_charactere(sequence[i]);
    }

    return new_sequence;
}

int calculate_score(char sequence[29]) {
    int score = 0;

    for(int i = 0; i < 29; i++) {
        if (sequence[i] == TARGET[i]) {
            score += 1;
        }
    }

    return score;
}

char* genereate_random_sequence() {
    char sequence[29];

    for(int i = 0; i < 29; i++) {
        int new_char = random_int(26, 91);

        if (new_char == 91) {
            sequence[i] = (char) ' ';
        } else {
            sequence[i] = new_char;
        }
    }

    return sequence;
}

int main() {
    char current_sequence[29] = genereate_random_sequence();
    int generation = 0;

    while(current_sequence != TARGET) {
        char last_sequence[29];
        int best_score = 0;

        for(int i = 0; i < SIZE; i++) {
            char* new_sequence = calculate_new_sequence(current_sequence);
            int new_sequence_score = calculate_score(new_sequence);

            if (new_sequence_score > best_score) {
                
                for(int i = 0; i < sizeof(last_sequence); i++) {
                    last_sequence[i] = new_sequence[i];
                }
                
                best_score = new_sequence_score;
            }
        }

        for(int i = 0; i < sizeof(last_sequence); i++) {
            current_sequence[i] = last_sequence[i];   
        }

        printf("Generation %d best candidates: %s score: %d", generation, last_sequence, best_score);
    }

    return 0;
}

