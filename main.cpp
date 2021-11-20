#include <iostream>
#include <stdio.h>
#include "source.h"
#include "circuit.h"

using namespace std;

int main()
{
    /*
    FILE * fich;
    int npas=1000;
    int choix;
    float t,dt=1./float(npas);
    fich=fopen("ve","wt");
    float a,b,c,d;
    source *signal; //declaration dynamique
    cout<<"Choisissez le signal a tracer : \n 1 - Sinus \n 2 - triangulaire \n 3 - rectangulaire \n 4 - echelon \n 5 - creneau\n";
    cin>>choix;
    switch(choix){
    case 1 :
        cout<<"\n Sinus choisit \n"<<"\n Entrer V0 : ";
        cin>>a;
        cout<<"\n Entrer phi : ";
        cin>>b;
        cout<<"\nEntrer periode : ";
        cin>>c;
        signal = new sinus(a,b,c);
        break;
    case 2 :
        cout<<"\n Triangulaire choisit \n"<<"\n Entrer V0 : ";
        cin>>a;
        cout<<"\n Entrer phi : ";
        cin>>b;
        cout<<"\nEntrer periode : ";
        cin>>c;
        signal = new triangulaire(a,c,b);
        break;
    case 3 :
        cout<<"\n Rectangulaire choisit \n"<<"\n Entrer V0 : ";
        cin>>a;
        cout<<"\n Entrer T : ";
        cin>>b;
        cout<<"\nEntrer phi : ";
        cin>>c;
        cout<<"\nEntrer P : ";
        cin>>d;
        signal = new rectangulaire(a,b,c,d);
        break;
    case 4 :
        cout<<"\n Echelon choisit \n"<<"\n Entrer V0 : ";
        cin>>a;
        cout<<"\n Entrer phi : ";
        cin>>b;
        signal = new step(a,b);
        break;
    case 5 :
        cout<<"\n Creneau choisit \n"<<"\n Entrer V0 : ";
        cin>>a;
        cout<<"\n Entrer phi : ";
        cin>>b;
        cout<<"\n Entrer T : ";
        cin>>c;
        signal = new creneau(c,a,b);
        break;
    default :
        cout << "\n ERREUR \n";
        break;
    }


    for(int i=0;i<npas+1;i++)
    {
    t=float(i)*3.141519265*dt;
    fprintf(fich,"%f %f \n",t,signal->Ve(t));
    }
    fclose(fich);
    //delete signal;*/

    circuit_D a(0,1.2, 10e-9, 0.1e-6, 0);
    a.choix_source();
    a.f_euler(500e-9, 1e-10);

return 0;
}
