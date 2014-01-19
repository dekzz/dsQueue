#include<iostream>
using namespace std;

struct tklijent {
       char prez_ime[20];
       int godiste;
       float stanje;
       char transakcija[15];
       }klijent;
       
struct tred {
       tklijent polje[15];
       int front, rear;
       }red;

int AddOne(int n) {
    return ((n+1)%15);
}
  
void InitQ(tred *red) {
     red->front=0;
     red->rear=14;
     }

bool IsEmptyQ(tred *red) {
     if(AddOne(red->rear)==red->front)
       return true;
     else
         return false ;
     }

tklijent FrontQ(tred *red) {
         return red->polje[red->front];
         }
         
void EnQueueQ(tklijent x, tred *red) {
     red->rear=AddOne(red->rear);
     red->polje[red->rear]=x;
     }

void DeQueueQ(tred *red) {
     red->front=AddOne(red->front);
     }
