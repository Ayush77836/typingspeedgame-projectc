#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char sentences[5][100] = {
        "I can do this all day.",
        "Mistakes are proof that you are trying.",
        "C programming is powerful and fast.",
        "Gojo vs Sukuna will Shatter the Internet.",
        "Practice makes a man perfect."
    };

    char input[200];
    int choice;
    clock_t start, end;
    double time_taken, wpm;
    int correct = 0, total = 0, i;

    printf("=========== TYPING SPEED GAME ===========\n");
    printf("Choose a sentence number (1-5): ");
    scanf("%d", &choice);
    getchar();  

    if (choice < 1 || choice > 5) {
        printf("Invalid choice!\n");
        return 0;
    }

    printf("\nYour sentence to type:\n");
    printf("%s\n\n", sentences[choice - 1]);
    printf("Press ENTER when you are ready to start typing...");
    getchar();

    printf("\nStart typing below:\n");

    start = clock();  
    fgets(input, sizeof(input), stdin);
    end = clock();    

    
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
        input[len - 1] = '\0';

    
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    
    for (i = 0; i < strlen(sentences[choice - 1]); i++) {
        if (input[i] == sentences[choice - 1][i])
            correct++;
        total++;
    }

    double accuracy = ((double)correct / total) * 100.0;

    
    double minutes = time_taken / 60.0;
    wpm = ((double)strlen(input) / 5.0) / minutes;

    printf("\n************* RESULTS *************\n");
    printf("Time Taken   : %.2f seconds\n", time_taken);
    printf("Typed Chars  : %d\n", (int)strlen(input));
    printf("Correct Chars: %d\n", correct);
    printf("Accuracy     : %.2f%%\n", accuracy);
    printf("Typing Speed : %.2f WPM\n", wpm);

    printf("*************************************\n");
    printf("Original : %s\n", sentences[choice - 1]);
    printf("You typed: %s\n", input);

    return 0;
}