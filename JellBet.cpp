#include <iostream>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <string>
#include <iomanip>
 
using namespace std;




double SOF (double RT, double PU, int BA)
        {
                   double x;
                   x = 1-(PU/100);
                   double y;
                   y = pow(x, BA);
                          double r;
                          r = (RT * y - RT) / BA;
                          if (r < 0)
                          { 
                                r = r*(-1);
                                return r;
                          }
                          else 
                          {
                          return r;
                          }
        }
        
        
double STF (double RT, double DL, int BA)
       {
                   double x;
                   x = DL/100;
                   double k;
                   k = (RT * x) / BA;
                   return k;
       }
        
double SFF (double RT, double TR, double MP)   
       {
                   double x;
                   x = 1+(MP/100);
                   double y;
                   y = pow(x, TR);
                              double z;
                              z = (y * RT);
                              return z;
       }
                      
        
 
int main()
{
    
    
    double PU;
    double RT;
    int SC;
    int BA;
    double DL;
    int FS;
    int TM;
    double MP;
    double TR;
    int ST;
    int LT;
    
    
    /*
    PU: Percentage (for each subsequent bet) 
    RT: Rulle Total
    SC: System Choice
    BA: Bet Amount
    DL: Daily Limit
    FS: Forts�tt Spela
    TM: Tidsram M�nader
    MP: Monthly Percentage
    TR: Tidsram (M) R�knare
    ST: Spara Tabell
    LT: L�s Tabell
    */
    
   

for ( int c = 1; c < 2; )
      {
          
   
    
    
       
  cout<<"V\x84lkommen till HIDDEN systemet.\n";
  cout<<"Tryck Enter f\x94r att starta.\n";
  cin.get();
  //---
  cout<<"1: Detta system tar metoden";
  cout<<"\n";
  cout<<"\n";
  cout<<"2: Detta system skall anv\x84ndas, daglig limit f\x94r tillf\x84llet\n";
  cout<<"ej \x84n fastsatt.\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"3: J\x84mnf\x94r de olika metodernas resultat.\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"4: Profitabiliteringsber\x84kning.\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"5: Sparade tabeller.\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"6: Prototyp-metod.\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"V\x84lj ditt nummer: ";
  cin>> SC;
  cin.ignore();
  

  
  if ( SC == 1) {
       cout<<"Du anv\x84nder nu systemet: "<< SC <<", vilket du inte ska.\n";
       cout<<"\n";
       cout<<"\n";
       cout<<"Hur stor \x84r bankrullen?\n";
       cin>> RT;
       cin.ignore();
       cout<<"\n";
       cout<<"Hur stort \x84r varje bet procentuellt?\n";
       cin>> PU;
       cin.ignore();
       cout<<"\n";
       cout<<"Hur m\x86nga bets kommer att l\x84ggas?\n";
       cin>> BA;
       cin.ignore();
       cout<<"\n";
       
       
       cout<<"I dag kan du l\x84gga "<< SOF (RT, PU, BA) <<" kronor per bet.\n";
       
       /* TESTNING P�G�R 
       ofstream myfile;
       myfile.open ("example.txt");
       myfile << "Writing this to a file.\n";
       myfile.close();
       */
        
       cin.get();
  }
  else if ( SC ==2) {
       cout<<"Du anv\x84nder nu korrekt system: "<< SC <<"\n";
       cout<<"\n";
       cout<<"\n";
       cout<<"Hur stor \x84r bankrullen?\n";
       cout<<"\n";
       cin>> RT;
       cin.ignore();
       //cout<<"Din limit \x84r satt till 3.34 (3+(1/3)) procent\n";
       cout<<"Vad \x84r din dagliga limit?\n";
       cout<<"\n";
       //DL = 3.34;
       cin>> DL;
       cin.ignore();
       /*cin>> DL;
       cin.ignore();*/
       cout<<"Hur m\x86nga bets l\x84ggs i dag?\n";
       cout<<"\n";
       cin>> BA;
       cin.ignore();
       cout<<"Din limit f\x94r varje viktning \x84r:\n";
       cout<<"\n";
       cout<<"\n";
       
       cout<<"    1/5:    "<< STF (RT, DL, BA) * 0.6 <<" kronor.\t" << STF (RT, DL, BA) /RT *60<<" procent av rullen.\n";
       cout<<"    2/5:    "<< STF (RT, DL, BA) * 0.8 <<" kronor.\t" << STF (RT, DL, BA) /RT *80<<" procent av rullen.\n";
       cout<<"    3/5:    "<< STF (RT, DL, BA) * 1.0 <<" kronor.\t" << STF (RT, DL, BA) /RT *100<<" procent av rullen.\n";
       cout<<"    4/5:    "<< STF (RT, DL, BA) * 1.2 <<" kronor.\t" << STF (RT, DL, BA) /RT *120<<" procent av rullen.\n";
       cout<<"    5/5:    "<< STF (RT, DL, BA) * 1.4 <<" kronor.\t" << STF (RT, DL, BA) /RT *140<<" procent av rullen.\n";
       
       cin.get();
       
       cout<<"Spara tabell till:\n\n";
       cout<<"1: HIDDEN\n";
       cout<<"2: HIDDEN\n";
       cout<<"3: HIDDEN\n";
       cout<<"4: HIDDEN\n";
       
       cin>> ST;
       
       if ( ST == 1) {
            ofstream myfile;
            myfile.open ("hidden1.txt");
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 0.6 <<" kronor.\t" << STF (RT, DL, BA) /RT *60<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 0.8 <<" kronor.\t" << STF (RT, DL, BA) /RT *80<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 1.0 <<" kronor.\t" << STF (RT, DL, BA) /RT *100<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 1.2 <<" kronor.\t" << STF (RT, DL, BA) /RT *120<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 1.4 <<" kronor.\t" << STF (RT, DL, BA) /RT *140<<" procent av rullen.\n\n";
            myfile.close();
            }
            
       else if ( ST == 2){
            ofstream myfile;
            myfile.open ("hidden2.txt");
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 0.6 <<" kronor.\t" << STF (RT, DL, BA) /RT *60<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 0.8 <<" kronor.\t" << STF (RT, DL, BA) /RT *80<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 1.0 <<" kronor.\t" << STF (RT, DL, BA) /RT *100<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 1.2 <<" kronor.\t" << STF (RT, DL, BA) /RT *120<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 1.4 <<" kronor.\t" << STF (RT, DL, BA) /RT *140<<" procent av rullen.\n\n";
            myfile.close();
            }
            
       else if ( ST == 3){
            ofstream myfile;
            myfile.open ("hidden2.txt");
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 0.6 <<" kronor.\t" << STF (RT, DL, BA) /RT *60<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 0.8 <<" kronor.\t" << STF (RT, DL, BA) /RT *80<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 1.0 <<" kronor.\t" << STF (RT, DL, BA) /RT *100<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 1.2 <<" kronor.\t" << STF (RT, DL, BA) /RT *120<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 1.4 <<" kronor.\t" << STF (RT, DL, BA) /RT *140<<" procent av rullen.\n\n";
            myfile.close();
            }
            
       else if ( ST == 4){
            ofstream myfile;
            myfile.open ("hidden2.txt");
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 0.6 <<" kronor.\t" << STF (RT, DL, BA) /RT *60<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 0.8 <<" kronor.\t" << STF (RT, DL, BA) /RT *80<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 1.0 <<" kronor.\t" << STF (RT, DL, BA) /RT *100<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 1.2 <<" kronor.\t" << STF (RT, DL, BA) /RT *120<<" procent av rullen.\n";
            myfile <<"    1/5:    "<< STF (RT, DL, BA) * 1.4 <<" kronor.\t" << STF (RT, DL, BA) /RT *140<<" procent av rullen.\n\n";
            myfile.close();
            }
       
       
  }
  
  else if ( SC == 3) {
        cout<<"Rulle total?";
        cout<<"\n";
       cin>> RT;
       cin.ignore();
        cout<<"Bet i dag?";
        cout<<"\n";
       cin>> BA;
       cin.ignore();
       cout<<"Max limit per bet (typ 1)?";
        cout<<"\n";
       cin>> PU;
        cout<<"Dagens limit (typ 2)?";
        cout<<"\n";
       cin>> DL;
       cin.ignore();
        
       
       cout<<"Varje bet metod 1: "<< SOF (RT, PU, BA) <<" kronor.\n";
       cout<<"Varje bet metod 2: "<< STF (RT, DL, BA) * 1.0 <<" kronor. (" << STF (RT, DL, BA) * 0.6 <<" - "<<STF (RT, DL, BA) * 1.4 <<") viktat \n";
       cin.get();
       }
       
       else if ( SC== 4) {
            cout<<"Rulle total?";
            cout<<"\n";
            cin>> RT;
            cin.ignore();
            cout<<"\n";
            cout<<"Tidsram i m\x86nader?";
            cout<<"\n";
            cin>> TM;
            
            TR = 1;
            
            cin.ignore();
            cout<<"\n";
            cout<<"M\x86natlig profitabilitet i procent?.";
            cout<<"\n";
            cin>> MP;
            cin.ignore();
            cout<<"\n";
            
            for ( int i = 1; i <= TM; i = i + 1) {
                   
                   
                  cout<<"M\x86nad"<<i<<": "<<SFF (RT, TR, MP)<<" kronor.\n";
                  TR = TR + 1;
                  
                  
                  }
                  cout<<"\n\nDet \x84r en total \x94kning med "<<SFF (RT, TR, MP) - RT<<" kronor eller "<< (SFF (RT, TR, MP) - RT)/TR<< " i m\x86naden!";
            cin.get();
            }
            
            else if ( SC== 5){
                 
                 cout<<"\nVisa tabell f\x94r:\n\n";
                 cout<<"\thidden 1.\n";
                 cout<<"\thidden 2.\n";
                 cout<<"\thidden 3.\n";
                 cout<<"\thidden 4.\n";
                 cin>> LT;
                 
                 if ( LT == 1) {
                 
                 cout << "\n\nDagens hidden1:\n";
                 string line;
                 ifstream myfile ("hidden1.txt");
                 if (myfile.is_open())
                 {
                    while (getline (myfile,line) )
                    {
                          cout << line << '\n';
                    }
                    myfile.close();
                 }
                 
                 }
            
                 else if ( LT == 2) {
                 
                 cout << "\n\nDagens hidden2:\n";
                 string line;
                 ifstream myfile ("hidden2.txt");
                 if (myfile.is_open())
                 {
                    while (getline (myfile,line) )
                    {
                          cout << line << '\n';
                    }
                    myfile.close();
                 }
                 
                 }
                 
                 if ( LT == 3) {
                 
                 cout << "\n\nDagens hidden3:\n";
                 string line;
                 ifstream myfile ("hidden3.txt");
                 if (myfile.is_open())
                 {
                    while (getline (myfile,line) )
                    {
                          cout << line << '\n';
                    }
                    myfile.close();
                 }
                 
                 }
                 
                 if ( LT == 4) {
                 
                 cout << "\n\nDagens hidden3:\n";
                 string line;
                 ifstream myfile ("hidden4.txt");
                 if (myfile.is_open())
                 {
                    while (getline (myfile,line) )
                    {
                          cout << line << '\n';
                    }
                    myfile.close();
                 }
                 
                 }
            
                      
            }
            
            else if ( SC== 6){
                 cout << "Denna funktion �r inte tillagd \x84n!";
            }
                          
            
            
            
       else {
            cout<<"Fel kommando!\n";
            }
  
cout<<"Vill du spela igen?\n";
cout<<"      JA, skriv ""1""\n";
cout<<"      NEJ, skriv ""2""\n";
cin>> FS;
if (FS == 1) {
       c = 1;
}
else {
     c = 2;
}
 
  
}
return 1;
}

