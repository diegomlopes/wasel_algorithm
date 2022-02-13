import java.util.Random;

public class App {
    public static final String TARGET = "METHINKS IT IS LIKE A WEASEL";
    public static final Double PROBABILITY = 0.05;
    public static final int SIZE = 100;

    public static void main(String[] a) throws InterruptedException{
        String currentSequence = generateRandomSequence();
        int generation = 0;

        System.out.println("Random sequence " + currentSequence);

        while (!currentSequence.matches(TARGET)) {
            String lastSequence = "";
            int bestScore = 0;

            for(int i = 0; i < SIZE; i++) {
                String newSequence = calculateNewSequence(currentSequence);
                int newSequenceScore = calculateScore(newSequence);

                if (newSequenceScore >= bestScore) {
                    lastSequence = newSequence;
                    bestScore = newSequenceScore;
                }
            }

            currentSequence = lastSequence;

            System.out.println("Generation " + generation + " best candidate: " + lastSequence + " score: " + bestScore);
            
            Thread.sleep(500);
            generation += 1;
        }
    }
    
    public static char newCharactere(char lastCharactere) {
        Random random = new Random();
        if(random.nextDouble() < PROBABILITY) {
            int newChar = (random.nextInt(27) + 65);

            if (newChar == 91) {
                return ' ';
            }

            return (char) newChar;
        }

        return lastCharactere;
    }

    public static String calculateNewSequence(String sequence) {
        String newSequence = "";

        for(int i = 0; i < sequence.length(); i++) {
            newSequence += newCharactere(sequence.charAt(i));
        }

        return newSequence;
    }

    public static int calculateScore(String sequence) {
        int score = 0;

        for (int i = 0; i < sequence.length(); i++) {
            if (sequence.charAt(i) == TARGET.charAt(i)) {
                score += 1;
            }
        }

        return score;
    }

    public static String generateRandomSequence() {
        String sequence = "";
        Random random = new Random();

        for (int i = 0; i < TARGET.length(); i++) {
            int newChar = random.nextInt(27) + 65;

            if (newChar == 91) {
                System.out.println("Entrou 111");
                sequence += (char) ' ';
            } else {
                sequence += (char) newChar;
            }
        }

        return  sequence;
    }
}
