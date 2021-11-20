#include "source.h"

class circuit{
protected :
    float Vs_init;
    float Vs;
    float Ve;
    source *signal;
public :
    circuit(){
    Vs_init = 0;Vs = 0; Ve = 0;};
    ~circuit(){};
    virtual float f_prim() = 0;
    virtual void f_euler(float t, float pas) = 0;
    virtual float f_second() = 0;
    void choix_source();
};

class ordre_1 : public circuit{
public:
    void f_euler(float t, float pas);
    virtual float f_prim() = 0;
    float f_second(){return 0;};
    ordre_1(){};

};

class ordre_2 : public circuit{
protected :
    float pas, Vs_prim, Ve_buff;
public:
    virtual float f_prim(){return 0;};
    virtual float f_second() = 0;
    void f_euler(float t, float s_pas);
    ordre_2(){};
};


class circuit_A : public ordre_1{
protected :
    float R, C;
public :
    circuit_A();
    circuit_A(float saisie_Vs_init, float saisie_R, float saisie_C);
    float f_prim();
};


class circuit_B : public ordre_1{
private :
    float Vbe;
protected :
    float R1, R2, C;

public :
    circuit_B();
    circuit_B(float saisie_Vs_init, float saisie_R1, float saisie_R2, float saisie_C);
    float f_prim();
};

class circuit_C : public ordre_2{
protected :
    float R, L, C;
public :
    circuit_C();
    circuit_C(float saisie_Vs_init, float saisie_R, float saisie_L, float saisie_C,float saisie_Vs_prim);
    float f_second();
    float f_prim(){return 0;};
    //void f_euler(float t, float pas);
};


class circuit_D : public ordre_2{
protected :
    float R, L, C;
public :
    circuit_D();
    circuit_D(float saisie_Vs_init, float saisie_R, float saisie_L, float saisie_C,float saisie_Vs_prim);
    float f_second();
    float f_prim(){return 0;};
    //void f_euler(float t, float pas);
};



/*
class circuit_B : public circuit{
private :
    float Vbe;
protected :
    float R1, R2, C;

public :
    circuit_B();
    circuit_B(float saisie_Vs_init, float saisie_R1, float saisie_R2, float saisie_C);
    float f_prim();
    void f_euler(float t, float pas);
};

class circuit_C : public circuit{
protected :
    float R, L, C, Vs_prim;
public :
    circuit_C();
    circuit_C(float saisie_Vs_init, float saisie_R, float saisie_L, float saisie_C,float saisie_Vs_prim);
    float f_second();
    float f_prim(){return 0;};
    void f_euler(float t, float pas);
};


class circuit_D : public circuit{
protected :
    float R, L, C, Vs_prim, Ve_prim;
public :
    circuit_D();
    circuit_D(float saisie_Vs_init, float saisie_R, float saisie_L, float saisie_C,float saisie_Vs_prim);
    float f_second();
    float f_prim(){return 0;};
    void f_euler(float t, float pas);
};*/
