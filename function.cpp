#include "header.h"
#include <algorithm>
#include <cstdint>
#include <random>

int Player(int *health, int *energy, int *count) { return *count; }

int Enemy(int *health, int *energy, int *count) { return *count; }

bool Battle(int player[], int enemy[], char choose, bool win) {
  while (true) {
  printf("Что будем делать??\n");
  std::cin >> choose;
  if (choose == 'a') {
    enemy[0] -= 10;
    printf("%d\n", enemy[0]);
    if (enemy[0] == 0) {
      printf("Вы победили!\n");
      return win = true;
    }
  }
  else if (choose == 'q') {
   break;
     }
  }
 
}
/*int CreateEnemy(int *health, int *energy, int *count,
  int (*pP)(int *, int *, int *)) {
    return pP(health, energy,count);
    }*/
