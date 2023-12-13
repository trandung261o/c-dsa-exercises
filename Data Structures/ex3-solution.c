#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_L 256
typedef struct Profile {
  char name[MAX_L];
  char email[MAX_L];
  struct Profile *next;
  struct Profile *prev;
} Profile;

Profile *first, *last;

Profile *makeProfile(char *name, char *email) {
  Profile *profile = (Profile *)malloc(sizeof(Profile));
  strcpy(profile->name, name);
  strcpy(profile->email, email);
  profile->next = NULL;
  profile->prev = NULL;
  return profile;
}

void initList() {
  first = NULL; last = NULL;
}

int listEmpty() {
  return first == NULL && last == NULL;
}

void printListLeft2Right() {
  for (Profile *p = first; p != NULL; p = p->next) {
    printf("%s %s\n", p->name, p->email);
  }
}

void printListRight2Left() {
  for (Profile *p = last; p != NULL; p = p->prev) {
    printf("%s %s\n", p->name, p->email);
  }
}

void insertLast(char *name, char *email) {
  Profile *profile = makeProfile(name, email);
  if (listEmpty()) {
    first = profile; last = profile;
  }
  else {
    last->next = profile; profile->prev = last;
    last = profile;
  }
}


Profile *find(char *name) {
  for (Profile *p = first; p != NULL; p = p->next) {
    if (strcmp(p->name, name) == 0) {
      return p;
    }
  }
  return NULL;
}

Profile *removeProfile(char *name) {
  if (listEmpty()) return NULL;
  Profile *profile = find(name);
  if (profile == NULL) {
    printf("not found %s\n", name);
  }else {
    Profile *right = profile->next;
    Profile *left = profile->prev;
    if (left != NULL) left->next = right;
    if (right != NULL) right->prev = left;
    if (left == NULL) first = right;
    if (right == NULL) last = left;
    free(profile);
  } 
}

void load(char *filename) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {printf("file not found\n");}
  initList();
  while (!feof(f)) {
    char name[256], email[256];
    fscanf(f, "%s%s", name, email);
    insertLast(name, email);
    printf("insert %s %s\n", name, email);
  }
  fclose(f);
}

void processFind() {
  char name[256];
  printf("enter name: ");
  scanf("%s", name);
  Profile *profile = find(name);
  if (profile == NULL) {printf("not found!\n");}
  else {
    printf("found name: %s %s\n", profile->name, profile->email);
  }
}

void processLoad() {
  char filename[256]; 
  printf("enter filename: ");
  scanf("%s", filename);
  load(filename);
}

void processStore() {
  char filename[256];
  printf("enter filename: "); scanf("%s", filename);
  FILE *f = fopen(filename, "w");
  for (Profile *p = first; p != NULL; p = p->next) {
    fprintf(f, "%s %s\n", p->name, p->email);
    if (p->next != NULL) fprintf(f, "\n");
  }
  fclose(f);
}

void processInsert() {
  char name[256], email[256];
  printf("enter name and email: "); scanf("%s%s", name, email);
  insertLast(name, email);
}

void processRemove() {
  char name[256];
  printf("enter name: "); scanf("%s", name);
  removeProfile(name);
}

void processPrintList() {
  printf("from left to right: \n"); printListLeft2Right();
  printf("from right to left: \n"); printListRight2Left();
}

void finalize() {
  Profile *p = first;
  while (p!= NULL) {
    Profile *np = p->next;
    free(p);
    p = np;
  }
}

int main() {
  initList();
  printf("cmd list:\n-Quit\n-Load\n-Print\n-Find\n-Insert\n-Remove\n-Store\n");
  while(1) {
    char cmd[256]; 
    printf("enter cmd: "); scanf("%s", cmd);
    fflush(stdin);
    if (strcmp(cmd, "Quit") == 0) break;
    else if (strcmp(cmd, "Load") == 0) processLoad();
    else if (strcmp(cmd, "Print") == 0) processPrintList();
    else if (strcmp(cmd, "Find") == 0) processFind();
    else if (strcmp(cmd, "Insert") == 0) processInsert();
    else if (strcmp(cmd, "Remove") == 0) processRemove();
    else if (strcmp(cmd, "Store") == 0) processStore();
  }
  finalize();
}
