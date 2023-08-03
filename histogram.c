#include <stdio.h>

#define MAX_WORD_LENGTH 10

/* prints a histogram chart of the frequency of word lengths */
int main() {
  int c, wordLength = 0;
  int range[MAX_WORD_LENGTH] = {0};

  while ((c = getchar()) != EOF) {
    if ((c == ' ' || c == '\t' || c == '\n') && wordLength > 0) {
      if (wordLength <= MAX_WORD_LENGTH) {
        ++range[wordLength - 1];
      } else {
        // group all words 10 characters or greater.
        ++range[MAX_WORD_LENGTH - 1];
      }

      wordLength = 0;
    } else {
      ++wordLength;
    }
  }

  printf("--- word length frequency ---\n");
  for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
    if (i < MAX_WORD_LENGTH - 1) {
      printf("%3d: ", i + 1);
    } else {
      printf("%3d+: ", MAX_WORD_LENGTH);
    }

    for (int j = 0; j < range[i]; ++j) {
      printf("-");
    }

    printf("\n");
  }

  return 0;
}
