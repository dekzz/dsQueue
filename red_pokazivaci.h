#include<iostream>
using namespace std;

struct tklijent {
       char prez_ime[20];
       int godiste;
       float stanje;
       char transakcija[15];
       }klijent;
       
struct element {
       tklijent podaci;
       element *sljedeci;
       };

struct tred {
       element *front, *rear;
       }red;

void InitQ(tred *red) {
     element *novi=new element;
     red->front=novi;
     red->rear=novi;
     novi->sljedeci=NULL;
     }

bool IsEmptyQ(tred *red) {
     if(red->rear == red->front)
        return true;
     else
         return false;
     }

tklijent FrontQ(tred *red) {
         return red->front->sljedeci->podaci;
         }
         
void EnQueueQ(tklijent x, tred *red) {
     element *novi=new element;
     novi->podaci=x;
     novi->sljedeci=NULL;
     red->rear->sljedeci=novi;
     red->rear=novi;
     }

void DeQueueQ(tred *red) {
     element *brisi;
     brisi = red->front;
     red->front = red->front->sljedeci;
     delete brisi; 
     }
