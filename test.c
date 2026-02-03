#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define COLOR_STR_SIZE 10
#define TERRITORY_NAMES_LENGTH 10
#define COLOR_NAMES_LENGTH 10

char const *COLOR_NAMES[] = {"Branco", "Preto", "Vermelho", "Amarelo", "Verde", "Azul", "Roxo", "Laranja", "Cinza", "Ciano"};

bool strContains(char list[][COLOR_STR_SIZE], int listSize, char* item, int itemIndex);
void sortTerritoryColors(int territoryCap);

int main() {
  srand(time(NULL));
  sortTerritoryColors(4);
  return 0;
}

void sortTerritoryColors(int territoryCap) {
  char usedColors[territoryCap][COLOR_STR_SIZE];
  
  for (int i = 0; i < territoryCap; i++) {
    char colorName[COLOR_STR_SIZE];
    do {
      // copy a random item from "COLOR_NAMES" to "colorName"
      strcpy(colorName, COLOR_NAMES[rand() % COLOR_NAMES_LENGTH]);
      // printf("%s\n", colorName);
      // check if usedColors array does not contains the sorted color already, if it doesn't it inserts it into usedColors
      
      if (!strContains(usedColors, territoryCap, colorName, i)) strcpy(usedColors[i], colorName);
    } while (strContains(usedColors, territoryCap, colorName, i)); // while usedColors already contains the sorted colorName, it will always try to get a new one which is not already on the usedColors array
  }

  for (int j = 0; j < territoryCap; j++) {
    printf("%s\n", usedColors[j]);
  }
}

// function to check if list of strings contains a certain string
bool strContains(char list[][COLOR_STR_SIZE], int listSize, char* item, int itemIndex) {
  for (int i = 0; i < listSize; i++) {
    if (i == itemIndex) continue;
    if (strcmp(list[i], item) == 0) {
     return true;
    }
  }
  
  return false;
}