#include "circuit.h"
//#include "source.h"
#include <cmath>
#include <stdio.h>
#include <iostream>

using namespace std;

void circuit :: choix_source(){
    int choix;
    float a, b, c, d;
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
        signal = new creneau(a, c, b);
        break;
    default :
        cout << "\n ERREUR \n";
        break;
}
}

circuit_A :: circuit_A(){
    C = 0;
    R = 0;
}

circuit_A :: circuit_A(float saisie_Vs_init, float saisie_R, float saisie_C){
    C = saisie_C;
    R = saisie_R;
    Vs_init = saisie_Vs_init;
}

float circuit_A :: f_prim(){
    return (Ve - Vs)/(R*C);
}

void ordre_1 :: f_euler(float t,float pas){
    FILE * fich_vs;
    fich_vs=fopen("vs","wt");
    float t_int = 0;
    while (t_int < t){
        Ve = signal->Ve(t_int);
        if (t_int == 0){
            Vs = Vs_init;
        }
        Vs = Vs + pas*f_prim();
        t_int = t_int + pas;
        fprintf(fich_vs,"%e %f %f \n",t_int,Vs,Ve);
}
fclose(fich_vs);
}

circuit_B :: circuit_B(){
}

circuit_B :: circuit_B(float saisie_Vs_init, float saisie_R1, float saisie_R2, float saisie_C){
    Vs_init = saisie_Vs_init;
    R1 = saisie_R1;
    R2 = saisie_R2;
    C = saisie_C;
    Vbe = 0.6;
}

float circuit_B :: f_prim(){
    if (Ve > Vbe){
    return -(1/(R1*C)+1/(R2*C))*Vs+ (Ve - Vbe)/(R1*C);
    }
    else{
        return -Vs/(R2*C);
    }
}

void ordre_2 :: f_euler(float t,float s_pas){
    pas = s_pas;
    FILE * fich_vs;
    fich_vs=fopen("vs","wt");
    float t_int = 0;
    while (t_int < t){
        Ve_buff = Ve;
        Ve = signal->Ve(t_int);
        if (t_int == 0){
            Vs = Vs_init;
        }
        Vs = Vs + pas*Vs_prim;
        Vs_prim = Vs_prim + pas*f_second();
        t_int = t_int + pas;
        fprintf(fich_vs,"%e %f %f \n",t_int,Vs,Ve);
}
fclose(fich_vs);
}

circuit_C :: circuit_C(){
}

circuit_C :: circuit_C(float saisie_Vs_init, float saisie_R, float saisie_L, float saisie_C,float saisie_Vs_prim){
    Vs_init = saisie_Vs_init;
    R = saisie_R;
    L = saisie_L;
    C = saisie_C;
    Vs_prim = saisie_Vs_prim;
    Ve_buff = 0;
}

float circuit_C :: f_second(){
    return -R/L*Vs_prim+(Ve - Vs)/(L*C);
}

circuit_D :: circuit_D(){
}

circuit_D :: circuit_D(float saisie_Vs_init, float saisie_R, float saisie_L, float saisie_C,float saisie_Vs_prim){
    Vs_init = saisie_Vs_init;
    R = saisie_R;
    L = saisie_L;
    C = saisie_C;
    Vs_prim = saisie_Vs_prim;
    Ve_buff = 0;
}

float circuit_D :: f_second(){
    return ((Ve-Ve_buff)/pas-Vs_prim)/(R*C)-Vs/(L*C);
}

