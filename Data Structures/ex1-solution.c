#include <stdio.h>
#include <stdlib.h>
typedef long ElementType;
typedef struct PointerType {  
  ElementType Inf;
  struct PointerType *Next; } PointerType;

PointerType *Insert_Middle(PointerType *Pred, ElementType X) {
  PointerType *TempNode = (PointerType *)malloc(sizeof(PointerType));
  TempNode->Inf = X;
  TempNode->Next = Pred->Next;
  Pred->Next = TempNode;
  return TempNode;
}

ElementType Delete(PointerType *Pred) {
  PointerType *TempNode = Pred->Next;
  Pred->Next = Pred->Next->Next;
  ElementType X = TempNode->Inf;
  free(TempNode);
  return X;
}

PointerType *Insert_ToHead (PointerType *First, ElementType X) {
  PointerType *TempNode = (PointerType *)malloc(sizeof(PointerType));
  TempNode->Inf = X;
  TempNode->Next = First;
  First = TempNode;
  return First;
}

PointerType *Insert_ToLast (PointerType *First, ElementType X) {
  PointerType *NewNode = (PointerType *)malloc(sizeof(PointerType));
  NewNode->Inf = X;
  PointerType *TempNode = First;
  while (TempNode->Next != NULL) 
    TempNode = TempNode->Next;
  TempNode->Next = NewNode;
  return First;
}

PointerType *Delete_Head(PointerType *First) {
  PointerType *TempNode;
  TempNode = First->Next;
  free(First);
  return TempNode;
}

PointerType *Delete_Last(PointerType *First) {
  PointerType *TempNode = First;
  while (TempNode->Next->Next != NULL) 
    TempNode = TempNode->Next;
  free(TempNode->Next);
  TempNode->Next = NULL;
  return First;
}

int IsEmpty(PointerType *First) {
  return !First;
}

PointerType *MakeNull(PointerType *First) {
  while(!IsEmpty(First)) 
    First = Delete_Head(First);
  return First;
}

void Print(PointerType *First) {
  PointerType *TempNode = First;
  int count = 0;
  while (TempNode != NULL) {
    printf("%ld ", TempNode->Inf); count++;
    TempNode = TempNode->Next;
    if (count % 12 == 0) printf("\n");
  }
  printf("\n");
  return;
}

int main() {
  int rand(void);
  PointerType *S1, *S2, *S3, *V1, *V2, *V3;
  ElementType a;
  int n;
  S1 = NULL;
  // tao phan tu dau tien
  a = rand() % 100 - 50;
  S1 = Insert_ToHead(S1, a);
  printf("Nhap vao so luong phan tu n = ");
  scanf("%d", &n);
  // tao ngau nghien danh sach va dua ra man hinh
  V1 = S1;
  for (int i = 2; i <=n; i++) {
    a = rand() % 100 - 50;
    V1 = Insert_Middle(V1, a);
  }
  printf("Danh sach ban dau: \n"); Print(S1);
  printf("\n");
  V1 = S1; S2 = NULL; S3 = NULL;
  while (V1) {
    if (V1->Inf > 0) 
      if (!S2) {S2 = Insert_ToHead(S2, V1->Inf); V2 = S2;}
      else {Insert_Middle(V2, V1->Inf); V2 = V2->Next;}
    if (V1->Inf < 0) 
      if (!S3) {S3 = Insert_ToHead(S3, V1->Inf); V3 = S3;}
      else {Insert_Middle(V3, V1->Inf); V3 = V3->Next;}
    V1 = V1->Next;
  }
  printf("Danh sach so duong: \n"); Print(S2); printf("\n");
  printf("Danh sach so am: \n"); Print(S3); printf("\n");

  S1 = MakeNull(S1); S2 = MakeNull(S2); S3 = MakeNull(S3);
  return 0;
}