#include <stdio.h>
#include <stdlib.h>

struct SNode {
  int val;
  struct SNode* next;
};

struct DNode {
  int val;
  struct DNode* next;
  struct DNode* prev;
};

//singly linked lists stuff

struct SNode* tailInsertionSinglyLinked(int val, struct SNode* pFirst){
  struct SNode* pNode = malloc(sizeof(struct SNode)), *pScan;
  pNode->val = val;
  pNode->next = NULL;
  if(pFirst == NULL){
    pFirst = pNode;
  } else {
    pScan = pFirst;
    while (pScan->next != NULL) {
      pScan = pScan->next;
    }
    pScan->next = pNode;
  }
  return pFirst;
}

void printSinglyLinked(struct SNode* pFirst){
  if(pFirst == NULL){
    printf("Empty list\n");
  } else {
    struct SNode* pScan = pFirst;
    int i = 0;
    do {
      printf("|%d|%d|->",pScan->val,i);
      pScan = pScan->next;
      i++;
    } while (pScan != NULL);
    printf("\n");
  }
}

void printSinglyLinkedRecursive(struct SNode* pScan, int n){
  if(pScan != NULL){
    printf("Element %d: %d\n",n,pScan->val);
    printSinglyLinkedRecursive(pScan->next,n+1);
  } else {
    printf("\n");
  }
}

struct SNode* headInsertionSinglyLinked(int val, struct SNode* pFirst){
  struct SNode* pNode = malloc(sizeof(struct SNode));
  pNode->val = val;
  pNode->next = NULL;
  if(pFirst == NULL){
    pFirst = pNode;
  } else {
    pNode->next = pFirst;
    pFirst = pNode;
  }
  return pFirst;
}

struct SNode* indexInsertionSinglyLinked(int index, int val, struct SNode* pFirst){
  struct SNode* pNode = malloc(sizeof(struct SNode));
  pNode->val = val;
  pNode->next = NULL;
  if(pFirst == NULL){
    pFirst = pNode;
  } else {
    struct SNode* pScan = pFirst;
    struct SNode* pPrec = NULL;
    int i = 0;
    do {
      if(i == index){
        if(pPrec != NULL){
          pPrec->next = pNode;
          pNode->next = pScan;
        } else {
          pNode->next = pFirst;
          pFirst = pNode;
        }
        break;
      }
      pPrec = pScan;
      pScan = pScan->next;
      i++;
    } while (pScan != NULL);
  }
  return pFirst;
}

struct SNode* deletElementByIndexSinglyLinked(int index, struct SNode* pFirst){
  if(pFirst == NULL){
    printf("Empty list\n");
  } else {
    struct SNode* pScan = pFirst;
    struct SNode* pPrec = NULL;
    int i = 0;
    do {
      if(i == index){
        if(pPrec != NULL){
          pPrec->next = pScan->next;
        } else {
          pFirst = pScan->next;
        }
        free(pScan);
        break;
      }
      pPrec = pScan;
      pScan = pScan->next;
      i++;
    } while (pScan != NULL);
  }
  return pFirst;
}

int getSinglyLinkedLenght(struct SNode* pFirst){
  int i = 0;
  if(pFirst != NULL){
    struct SNode* pScan = pFirst;
    do {
      pScan = pScan->next;
      i++;
    } while (pScan != NULL);
  }
  return (i==0?0:i-1);
}

//doubly linked lists stuff

struct DNode* tailInsertionDoublyLinked(int val, struct DNode* pFirst){
  struct DNode* pNode = malloc(sizeof(struct DNode)), *pScan;
  pNode->val = val;
  pNode->next = NULL;
  pNode->prev = NULL;
  if(pFirst == NULL){
    pFirst = pNode;
  } else {
    pScan = pFirst;
    while (pScan->next != NULL) {
      pScan = pScan->next;
    }
    pScan->next = pNode;
    pNode->prev = pScan;
  }
  return pFirst;
}

void printDoublyLinked(struct DNode* pFirst){
  if(pFirst == NULL){
    printf("Empty list\n");
  } else {
    struct DNode* pScan = pFirst;
    int i = 0;
    do {
      printf("<-|%d|%d|->",pScan->val,i);
      pScan = pScan->next;
      i++;
    } while (pScan != NULL);
    printf("\n");
  }
}

void printDoublyLinkedRecursive(struct DNode* pScan, int n){
  if(pScan != NULL){
    printf("Element %d: %d\n",n,pScan->val);
    printDoublyLinkedRecursive(pScan->next,n+1);
  } else {
    printf("\n");
  }
}

struct DNode* headInsertionDoublyLinked(int val, struct DNode* pFirst){
  struct DNode* pNode = malloc(sizeof(struct DNode));
  pNode->val = val;
  pNode->next = NULL;
  pNode->prev = NULL;
  if(pFirst == NULL){
    pFirst = pNode;
  } else {
    pNode->next = pFirst;
    pFirst->prev = pNode;
    pFirst = pNode;
  }
  return pFirst;
}

struct DNode* indexInsertionDoublyLinked(int index, int val, struct DNode* pFirst){
  struct DNode* pNode = malloc(sizeof(struct DNode));
  pNode->val = val;
  pNode->next = NULL;
  pNode->prev = NULL;
  if(pFirst == NULL){
    pFirst = pNode;
  } else {
    struct DNode* pScan = pFirst;
    int i = 0;
    do {
      if(i == index){
        if(pScan->prev == NULL){
          pScan->prev = pNode;
          pNode->next = pScan;
          pFirst = pNode;
        } else {
          pNode->prev = pScan->prev;
          pScan->prev->next = pNode;
          pNode->next = pScan;
          pScan->prev = pNode;
        }
        break;
      }
      pScan = pScan->next;
      i++;
    } while (pScan != NULL);
  }
  return pFirst;
}

struct DNode* deletElementByIndexDoublyLinked(int index, struct DNode* pFirst){
  if(pFirst == NULL){
    printf("Empty list\n");
  } else {
    struct DNode* pScan = pFirst;
    int i = 0;
    do {
      if(i == index){
        if(pScan->prev == NULL && pScan->next != NULL){
          pScan->next->prev = NULL;
          pFirst = pScan->next;
        } else if(pScan->next == NULL && pScan->prev != NULL){
          pScan->prev->next = NULL;
        } else if(pScan->prev != NULL && pScan->next != NULL) {
          pScan->next->prev = pScan->prev;
          pScan->prev->next = pScan->next;
        } else {
          pFirst = NULL;
        }
        free(pScan);
        break;
      }
      pScan = pScan->next;
      i++;
    } while (pScan != NULL);
  }
  return pFirst;
}

int getDoublyLinkedLenght(struct DNode* pFirst){
  int i = 0;
  if(pFirst != NULL){
    struct DNode* pScan = pFirst;
    do {
      pScan = pScan->next;
      i++;
    } while (pScan != NULL);
  }
  return (i==0?0:i-1);
}

//circular singly linked lists stuff

struct SNode* tailInsertionCircularSinglyLinked(int val, struct SNode* pFirst){
  struct SNode* pNode = malloc(sizeof(struct SNode)), *pScan;
  pNode->val = val;
  if(pFirst == NULL){
    pFirst = pNode;
    pFirst->next = pFirst;
  } else {
    pScan = pFirst;
    while (pScan->next != pFirst) {
      pScan = pScan->next;
    }
      pScan->next = pNode;
    pNode->next = pFirst;
  }
  return pFirst;
}

struct SNode* headInsertionCircularSinglyLinked(int val, struct SNode* pFirst){
  struct SNode* pNode = malloc(sizeof(struct SNode)), *pScan;
  pNode->val = val;
  if(pFirst == NULL){
    pFirst = pNode;
    pFirst->next = pFirst;
  } else {
    pScan = pFirst;
    while (pScan->next != pFirst) {
      pScan = pScan->next;
    }
    pScan->next = pNode;
    pNode->next = pFirst;
    pFirst = pNode;
  }
  return pFirst;
}

void printCircularSinglyLinked(struct SNode* pFirst){
  if(pFirst == NULL){
    printf("Empty list\n");
  } else {
    struct SNode* pScan = pFirst;
    int i = 0;
    do {
      printf("|%d|%d|->",pScan->val,i);
      pScan = pScan->next;
      i++;
    } while (pScan != pFirst);
    printf("\n");
  }
}

void printCircularSinglyLinkedRecursive(struct SNode* pScan, struct SNode* pFirst, int n){
  if(pScan->next != pFirst){
    printf("Element %d: %d\n",n,pScan->val);
    printCircularSinglyLinkedRecursive(pScan->next,pFirst,n+1);
  } else {
    printf("\n");
  }
}

struct SNode* deletElementByIndexCircularSinglyLinked(int index, struct SNode* pFirst){
  if(pFirst == NULL){
    printf("Empty list\n");
  } else {
    struct SNode* pScan = pFirst;
    struct SNode* ppScan = NULL;
    struct SNode* pPrec = NULL;
    int i = 0;
    do {
      if(i == index){
        if(pPrec != NULL){
          pPrec->next = pScan->next;
        } else {
          ppScan = pScan;
          do {
            ppScan = ppScan->next;
          } while (ppScan->next != pFirst);
          ppScan->next = pScan->next;
          if(pScan == pScan->next)
            pFirst = NULL;
          else
            pFirst = pScan->next;
        }
        break;
      }
      pPrec = pScan;
      pScan = pScan->next;
      i++;
    } while (pScan != pFirst);
  }
  return pFirst;
}

struct SNode* indexInsertionCircularSinglyLinked(int index, int val, struct SNode* pFirst){
  struct SNode* pNode = malloc(sizeof(struct SNode));
  pNode->val = val;
  if(pFirst == NULL){
    pFirst = pNode;
    pFirst->next = pFirst;
  } else {
    struct SNode* pScan = pFirst;
    struct SNode* ppScan = NULL;
    struct SNode* pPrec = NULL;
    int i = 0;
    do {
      if(i == index){
        if(pPrec != NULL){
          pPrec->next = pNode;
          pNode->next = pScan;
        } else {
          ppScan = pScan;
          do {
            ppScan = ppScan->next;
          } while (ppScan->next != pFirst);
          ppScan->next = pNode;
          pNode->next = pScan;
          pFirst = pNode;
        }
        break;
      }
      pPrec = pScan;
      pScan = pScan->next;
      i++;
    } while (pScan != NULL);
  }
  return pFirst;
}

int getCircularSinglyLinkedLenght(struct SNode* pFirst){
  int i = 0;
  if(pFirst != NULL){
    struct SNode* pScan = pFirst;
    do {
      pScan = pScan->next;
      i++;
    } while (pScan != pFirst);
  }
  return (i==0?0:i-1);
}

int main(){

int exit = 0;
  int opz,val,idx,lim,sExit,dExit,csExit;
  struct SNode* sNode = NULL; //singly linked list head
  struct DNode* dNode = NULL; //doubly linked list head
  struct SNode* csNode = NULL; //circular singly linked list head
  do {
    printf("\nSelect the operation:\n1) Singly linked list\n2) Doubly linked list\n3) Circular singly linked list\n4) Exit\n");
    scanf("%d",&opz);
    if(opz == 1){
      sExit = 0;
      do {
        printf("\nSingly linked list\nSelect the operation:\n1) Add element to the tail\n2) Add element to the head\n3) Add element by index\n4) Textual print\n5) Graphical print\n6) Delete element\n7) Back\n");
        scanf("%d",&opz);
        if(opz == 1){
          printf("Insert value: ");
          scanf("%d",&val);
          sNode = tailInsertionSinglyLinked(val,sNode);
        } else if(opz == 2){
          printf("Insert value: ");
          scanf("%d",&val);
          sNode = headInsertionSinglyLinked(val,sNode);
        } else if(opz == 3){
          printf("Insert value: ");
          scanf("%d",&val);
          lim = getSinglyLinkedLenght(sNode);
          printf("Insert index (0 - %d): ",lim);
          scanf("%d",&idx);
          sNode = indexInsertionSinglyLinked(idx,val,sNode);
        } else if(opz == 4){
          printSinglyLinkedRecursive(sNode,0);
        } else if(opz == 5){
          printSinglyLinked(sNode);
        } else if(opz == 6){
          lim = getSinglyLinkedLenght(sNode);
          printf("Insert index (0 - %d): ",lim);
          scanf("%d",&val);
          deletElementByIndexSinglyLinked(idx,sNode);
        } else if(opz == 7){
          sExit = 1;
        } else {
          printf("Error\n");
        }
      } while (sExit == 0);
    } else if(opz == 2){
      dExit = 0;
      do {
        printf("\nDoubly linked list\nSelect the operation:\n1) Add element to the tail\n2) Add element to the head\n3) Add element by index\n4) Textual print\n5) Graphical print\n6) Delete element\n7) Back\n");
        scanf("%d",&opz);
        if(opz == 1){
          printf("Insert value: ");
          scanf("%d",&val);
          dNode = tailInsertionDoublyLinked(val,dNode);
        } else if(opz == 2){
          printf("Insert value: ");
          scanf("%d",&val);
          dNode = headInsertionDoublyLinked(val,dNode);
        } else if(opz == 3){
          printf("Insert value: ");
          scanf("%d",&val);
          lim = getDoublyLinkedLenght(dNode);
          printf("Insert index (0 - %d): ",lim);
          scanf("%d",&idx);
          dNode = indexInsertionDoublyLinked(idx,val,dNode);
        } else if(opz == 4){
          printDoublyLinkedRecursive(dNode,0);
        } else if(opz == 5){
          printDoublyLinked(dNode);
        } else if(opz == 6){
          lim = getDoublyLinkedLenght(dNode);
          printf("Insert index (0 - %d): ",lim);
          scanf("%d",&val);
          deletElementByIndexDoublyLinked(idx,dNode);
        } else if(opz == 7){
          dExit = 1;
        } else {
          printf("Error\n");
        }
      } while (dExit == 0);
    } else if(opz == 3){
      csExit = 0;
      do {
        printf("\nCircular singly linked list\nSelect the operation:\n1) Add element to the tail\n2) Add element to the head\n3) Add element by index\n4) Textual print\n5) Graphical print\n6) Delete element\n7) Back\n");
        scanf("%d",&opz);
        if(opz == 1){
          printf("Insert value: ");
          scanf("%d",&val);
          csNode = tailInsertionCircularSinglyLinked(val,csNode);
        } else if(opz == 2){
          printf("Insert value: ");
          scanf("%d",&val);
          csNode = headInsertionCircularSinglyLinked(val,csNode);
        } else if(opz == 3){
          printf("Insert value: ");
          scanf("%d",&val);
          lim = getCircularSinglyLinkedLenght(csNode);
          printf("Insert index (0 - %d): ",lim);
          scanf("%d",&idx);
          csNode = indexInsertionCircularSinglyLinked(idx,val,csNode);
        } else if(opz == 4){
          printCircularSinglyLinkedRecursive(csNode,csNode,0);
        } else if(opz == 5){
          printCircularSinglyLinked(csNode);
        } else if(opz == 6){
          lim = getCircularSinglyLinkedLenght(csNode);
          printf("Insert index (0 - %d): ",lim);
          scanf("%d",&val);
          deletElementByIndexCircularSinglyLinked(idx,csNode);
        } else if(opz == 7){
          csExit = 1;
        } else {
          printf("Error\n");
        }
      } while (csExit == 0);
    } else if(opz == 4){
      exit = 1;
    } else {
      printf("Error\n");
    }
  } while (exit == 0);

  return 0;
}
