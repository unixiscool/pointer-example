#include "header.h"
int Player(int *health, int *energy, int *count, int* player_D) { return (*health, *energy, *count, *player_D); }

int Enemy(int *health, int *energy, int *count) {return (*health, *energy, *count);  }

void Menu(int player[], int enemy[], char choose1, bool win, int* money, char choose, bool (*tmp)(int* , int* , char, bool, int* )) {
  while (true) {
    printf("Что будем делать?\n"
	   "1.Battle ");
    std::cin >> choose;
    if(choose = '1') {
      tmp(player, enemy, choose1, win, money);
    }
  }
}
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

int CreateEnemy(int *health, int *energy, int *count,
  int (*pP)(int *, int *, int *)) {
    return pP(health, energy,count);   
}
