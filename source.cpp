#include "source.h"
#include <cmath>
#include <iostream>


using namespace std;
#define M_PI 3.14159265358979323846


source :: source(){
    V_0 = 0;
    phi = 0;
}

periodique::periodique(){
    P=0;
}

non_periodique :: non_periodique(){
}

sinus :: sinus(){
}

sinus :: sinus(float saisie_V_0,float saisie_phi,float saisie_P){
    V_0 = saisie_V_0;
    phi = saisie_phi;
    P = saisie_P;
}

float sinus :: Ve(float t){
return V_0*sin(2*(M_PI)*t/P+phi);
}

triangulaire :: triangulaire(){
}

triangulaire :: triangulaire(float m_V_0, float m_P, float m_phi){
    V_0 = m_V_0;
    P = m_P;
    phi = m_phi;
}

float triangulaire :: Ve(float t){
    while (t >=P){
        t = t - P;
    }
    float a; //pente () utilisee pour le calcul du point Ve(0), on prends pour les calculs une pente positive)
    a = 2.*V_0/P;
    if (phi <= P/2.){
         if (t <= phi){
             return a * (phi - t);
         }
         else if (phi <= t && t <= (P/2.+phi)){
            return a*(t - phi);
         }
         else if ((P/2.+phi) <= t && t <= (P+phi)){
            return V_0 - a* (t - P/2. - phi);
         }
    }
    else{
        if (t <= (phi - P/2.)){
            return (P-phi+t)*a;
        }
        else if ((phi - (P/2.)) <= t && t <= phi){
            return V_0 -a*(t - phi + P/2.);
        }
        else if (phi <= t && t <= P){
            return a*(t - phi);
        }
    }
   return 0.0;
}

rectangulaire :: rectangulaire(){
    T = 0;
}

rectangulaire :: rectangulaire(float m_V_0, float m_T, float m_phi, float m_P){
V_0 = m_V_0;
T = m_T;
phi = m_phi;
P = m_P;
}

float rectangulaire :: Ve(float t){
while (t >= P){
    t = t - P;
}
if (t < phi) {
    return 0.0;
}
else if (t < phi + T) {
    return V_0;
}
else if  (t <= P) {
        return 0.0;
}
return 0.0;
}

creneau :: creneau(){
    T = 0;
}

creneau :: creneau(float m_V_0, float m_T, float m_phi){
    V_0 = m_V_0;
    T = m_T;
    phi = m_phi;
}

float creneau :: Ve(float t){
    if (t < phi){
        return 0;

    }
    else if ((phi < t) && (t < T + phi)){
        return V_0;
    }
    else{
        return 0.0;
    }
}

step :: step(){

}

step :: step(float m_V_0,float m_phi){
    phi = m_phi;
    V_0 = m_V_0;
}

float step :: Ve(float t){
    if  (t <= phi){
        return 0.0;
    }
    else{
        return V_0;
    }
}
