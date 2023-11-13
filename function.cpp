#include "header.h"
#include <cstdio>

int Player(int *health, int *energy, int *count) { return *count; }

int Enemy(int *health, int *energy, int *count) { return *count; }

bool Battle(int player[], int enemy[], char choose, bool win, int* money) {
  while (true) {
  srand (time(NULL));
  printf("Что будем делать?? A - Attack. Q - escape \n");
  std::cin >> choose;
  if (choose == 'a') {
    if(player[0] <= 0) {
      printf("Вы проиграли!\n");
      return win = false;
    }
    enemy[0] -= 10;
    printf("%dHP enemy: \n", enemy[0]);
    int enemy_dmg = rand() % 55;
    player[0] -= enemy_dmg;
    printf("%dHP player: \n", player[0]);
    
    if (enemy[0] == 0) {
      printf("Вы победили!\n");
      int mns = rand() % 110;
      *money += mns;
      printf("Вы заработали %d\n", mns);
      return win = true;
    }
  }
  else if (choose == 'q') {
    int minus_money = rand() % 55;
    printf("Вы сбежали и избежали боя!\n");
    printf("Вы утратили %d монет\n", minus_money);
    return win = false;
   break;
     }
  }
  return true;
}

/*int CreateEnemy(int *health, int *energy, int *count,
  int (*pP)(int *, int *, int *)) {
    return pP(health, energy,count);
    }*/
