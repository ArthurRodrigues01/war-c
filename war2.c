#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição constantes globais

#define NAME_STR_SIZE 30
#define COLOR_STR_SIZE 10

// Definindo a struct de territorio

struct Territory {
  char name[NAME_STR_SIZE];
  char color[COLOR_STR_SIZE];
  int numberOfTroops;
};

// Função para limpar o buffer de strings, 
// evitando que acidentalmente acabe pulando alguma pergunta do usuário
void cleanInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c !=  EOF);
}

void convertTerritory(struct Territory *converted, struct Territory *converter) {
  strcpy(converted->color, converter->color);
  converted->numberOfTroops++;

  if (converter->numberOfTroops > 1) {
    converter->numberOfTroops--;
  }
}

void attack(struct Territory* attacker, struct Territory* defender) {
  int attackerDice = rand() % 6 + 1;
  int defenderDice = rand() % 6 + 1;
  
  printf("\n---------- RESULTADO DA BATALHA ----------\n");
  printf("Atacante %s, Resultado da rolagem de dado: %d\n", attacker->name, attackerDice);
  printf("Defensor %s, Resultado da rolagem de dado: %d\n", defender->name, defenderDice);

  if (attackerDice > defenderDice) {
    printf("VITORIA DO ATACANTE! O defensor perdeu 1 tropa.\n");
    defender->numberOfTroops--;

    if (defender->numberOfTroops == 0) {
      printf("CONQUISTA! O territorio %s foi dominado pelo exercito %s!\n", defender->name, attacker->color);
      convertTerritory(defender, attacker);
    }
  } else if (attackerDice < defenderDice) {
    printf("VITORIA DO DEFENSOR! O atacante perdeu 1 tropa.\n");
    attacker->numberOfTroops--;

    if (attacker->numberOfTroops == 0) {
      printf("CONQUISTA! O territorio %s foi dominado pelo exercito %s!\n", attacker->name, defender->color);
      convertTerritory(attacker, defender);
    }
  } else {
    printf("EMPATE!\n");
  }
  

}

void checkIfGameWon(struct Territory* list, int listSize) {
  char distinctArmies[NAME_STR_SIZE][listSize];
  for (int i = 0; i < listSize; i++) {
    distinctArmies[i][0] = '\0';
  }
  // para cada valor de distincArmies
  for (int i = 0; i < listSize; i++) {
    
  }

  for (int i = 0; i < listSize; i++)
  {
    /* code */
  }
  
  
}
void freeTerritoryMemory(struct Territory* territory) {
  free(territory);
}

// Função que faz a leitura dos territórios e insere eles na lista
void fillTerritoryList(struct Territory* list, int listSize) {
  char tempName[NAME_STR_SIZE];
  char tempColor[COLOR_STR_SIZE];
  int tempNumberOfTroops;

  for (int i = 0; i < listSize; i++)
  {
    printf("=============== Insert Territorio %d ===============\n", i + 1);

    printf("Digite um nome para o territorio: ");
    fgets(tempName, sizeof(tempName), stdin);
    tempName[strlen(tempName) - 1] = '\0'; //remove o \n do final da string
    
    printf("Digite uma cor para o territorio: ");
    fgets(tempColor, sizeof(tempColor), stdin);
    tempColor[strlen(tempColor) - 1] = '\0'; // remove o \n do final da string
    
    printf("Digite o numero de tropas presentes no territorio: ");
    scanf("%d", &tempNumberOfTroops);
    cleanInputBuffer();

    // TODO: validate number of troops inserted

    strcpy(list[i].name, tempName);
    strcpy(list[i].color, tempColor);
    list[i].numberOfTroops = tempNumberOfTroops;
    
    printf("\n\n");
  }
  
}

// Função que imprime os territórios atuais e seus respectivos valores na tela
void printTerritoryMenu(struct Territory* list, int listSize) {
  printf("=============== MAPA DE TERRITORIOS - ESTADO ATUAL ===============\n");
  
  for (int i = 0; i < listSize; i++)
  {
    printf("%d - %s: (Exercito %s, Quantidade de Tropas: %d)\n", i + 1, list[i].name, list[i].color, list[i].numberOfTroops);
  }
}

int main() {
  // Definindo a semente aleatória que a função rand() 
  // vai utilizar para basear a sua "aleatoriadade"
  srand(time(NULL));

  // Definição de um ponteiro de territórios: "territoryList"
  struct Territory *territoryList;
  int territoryCap, attackerIndex, defenderIndex, attackerOption, defenderOption;

  printf("Digite o numero de territorios: ");
  scanf("%d", &territoryCap);
  cleanInputBuffer();
  
  // Alocando memória com calloc para o ponteiro territoryList
  territoryList = (struct Territory *) malloc(territoryCap * sizeof(struct Territory));

  if (territoryList == NULL) {
    printf("Falha na alocação de memória.");
    return 1;
  }

  armiesCount = territoryCap;
  
  //Chamando função que irá fazer o loop de inserção dos territórios
  fillTerritoryList(territoryList, territoryCap);

  do
  {
    //Chamando função que irá fazer o loop de impressão dos
    printTerritoryMenu(territoryList, territoryCap);

    printf("\n\n---------- FASE DE ATAQUE ----------\n");
    printf("Escolha o territorio atacante(1 a %d, ou 0 para sair): ",  territoryCap);
    scanf("%d", &attackerOption);
    printf("Escolha o territorio defensor(1 a %d, ou 0 para sair): ",  territoryCap);
    scanf("%d", &defenderOption);
    cleanInputBuffer();

    if (attackerOption == 0 || defenderOption == 0) {
      printf("Saindo do programa...");
    } else if (attackerOption < 0 || attackerOption > territoryCap || defenderOption < 0 || defenderOption > territoryCap) {
      printf("Por favor, digite um número válido para o território atacante e/ou defensor!");
      continue;
    } else {
      attackerIndex = attackerOption - 1;
      defenderIndex = defenderOption - 1;

      if (strcmp(territoryList[attackerIndex].color, territoryList[defenderIndex].color) == 0) {
        printf("Impossível atacar o proprio territorio!\n");
        printf("Escolha 2 territorios de exercitos distintos!\n");
        continue;
      } 
      
      attack(&territoryList[attackerIndex], &territoryList[defenderIndex]);
    }
    
  } while (attackerOption != 0 && defenderOption != 0);
  
  // attack(&territoryList[0], &territoryList[1]);
  
  // printTerritoryMenu(territoryList, territoryCap);

  // struct Territory territoryArray[MAX_TERR];

  // // Loop para ler os dados dos territórios digitados pelo usuário
  // for (int i = 0; i < MAX_TERR; i++)
  // {
  //   printf("\n\n=====================================\n\n");
    
  //   printf("Digite o nome do territorio: ");
  //   fgets(territoryArray[i].name, sizeof(territoryArray[i].name), stdin);
  //   printf("Digite a cor do exercito no territorio: ");
  //   fgets(territoryArray[i].color, sizeof(territoryArray[i].color), stdin);
  //   printf("Digite o numero de tropas no territorio: ");
  //   scanf("%d", &territoryArray[i].numberOfTroops);

  //   //Limpar buffer
  //   cleanInputBuffer();
  // }
  
  // // Loop para exibir os dados dos territórios digitados pelo usuário
  // for (int i = 0; i < MAX_TERR; i++)
  // {
  //   printf("\n\n=== Territorio %d ===\n", i + 1);

  //   printf("Nome do territorio: %s", territoryArray[i].name);
  //   printf("Cor do exercito: %s", territoryArray[i].color);
  //   printf("Numero de tropas: %d", territoryArray[i].numberOfTroops);
  // }

  return 0;
}