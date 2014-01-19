#include<iostream>
#include "red_polja.h"
//#include "red_pokazivaci.h"
using namespace std;
int brojac=0;
     
void ispis(tred *red){
     tklijent pom;
     cout<<"\nPopis klijenata u redu:"<<endl;
     for(int i=0; i<brojac; i++){
             pom = FrontQ(red);
             DeQueueQ(red);
             cout<<"---------------------------"<<endl;
             cout<<"Ime i prezime: "<<pom.prez_ime<<endl;
             cout<<"Godiste: "<<pom.godiste<<endl;
             cout<<"Stanja racuna: "<<pom.stanje<<endl;
             cout<<"Transakcija: "<<pom.transakcija<<endl;
             EnQueueQ(pom, red);
             }
     cout<<"---------------------------"<<endl<<endl;
     }
     
void stariji_prednost(tred *red, tred *pom_red){
     tklijent pom;
     for(int i=0; i<brojac; i++){
             pom = FrontQ(red);
             DeQueueQ(red);
             if(pom.godiste<1945)
                EnQueueQ(pom, red);
             else{
                 EnQueueQ(pom, pom_red);
                 }
     }
     while(!IsEmptyQ(pom_red)){
             pom = FrontQ(pom_red);
             DeQueueQ(pom_red);
             EnQueueQ(pom, red);
             }
     ispis(red);
     }

void unos(tred *red){
     char jos;
     tklijent x, pom;
     do{
        cout<<"Ime i prezime: ";
        cin.ignore();
        cin.getline(x.prez_ime, 20);
        cout<<"Godiste: ";
        cin>>x.godiste;
        cout<<"Stanja racuna: ";
        cin>>x.stanje;
        cout<<"Transakcija: ";
        cin>>x.transakcija;
        EnQueueQ(x, red);
        brojac++;
        cout<<"Zelite li unijeti jos? (d/n) ";
        cin>>jos;
        }while(jos=='d');
     ispis(red);
     }

void izbacivanje(tred *red){
     tklijent pom;
     int broj = brojac;
     while(broj!=0){
             pom = FrontQ(red);
             DeQueueQ(red);
             if(pom.stanje<100&&(strcmp(pom.transakcija, "kredit")==0))
                brojac--;
             else
                 EnQueueQ(pom, red);
             broj--;
             }
     ispis(red);
     }
     
void novi_salter(tred *red){
     tklijent pom = FrontQ(red);
     DeQueueQ(red);
     if (!IsEmptyQ(red)) 
        novi_salter(red);
     EnQueueQ(pom, red);
     }

using namespace std;
int main(){
    tred *red=new tred;
    InitQ(red);
    tred *pom_red=new tred;
    InitQ(pom_red);
    int izbor;
    do{
        cout<<"==============================IZBOR============================="<<endl;
        cout<<"1. Unos klijenata u red"<<endl;
        cout<<"2. Pustanje klijenata starijih od 65 godina na pocetak red"<<endl;
        cout<<"3.|Izbacivanje klijenata iz reda koji traze kredit, \n  |a imaju manje od 100 kn na racunu"<<endl;
        cout<<"4. Zatvaranje trenutnog saltera i otvaranje novog"<<endl;
        cout<<"================================================================"<<endl;
        cout<<"Izbor: ";
        cin>>izbor;
        cout<<endl;
        switch(izbor){
                      case 1: unos(red);
                              break;
                      case 2: stariji_prednost(red, pom_red);
                              break;
                      case 3: izbacivanje(red);
                              break;
                      case 4: novi_salter(red);
                              ispis(red);
                              break;
                      case 9: break;
                      default: cout<<"Pogresan unos!"<<endl;
                      }
    }while(izbor!=9);
}
