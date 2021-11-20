#ifndef SOURCE_H
#define SOURCE_H

class source{
protected :
    float  V_0, phi;
public:
    source();
    ~source(){};
    virtual float Ve(float t) = 0;
};

class periodique : public source{
protected:
    float P;
public:
    periodique();
    ~periodique(){};
    virtual float Ve(float t) = 0;
};

class non_periodique : public source{
public:
    non_periodique();
    ~non_periodique(){};
    virtual float Ve(float t) = 0;
};

class sinus : public periodique{
public :
    sinus();
    sinus(float saisie_V_0,float saisie_phi,float saisie_P);
    ~sinus(){};
    float Ve(float t);
};

class triangulaire : public periodique{

public :
    triangulaire();
    triangulaire(float m_V_0, float m_P, float m_phi);
    ~triangulaire(){};
    float Ve(float t);
};

class rectangulaire : public periodique{
protected :
    float T;
public :
    rectangulaire();
    rectangulaire(float m_V_0, float m_T, float m_phi, float m_P);
    ~rectangulaire(){};
    float Ve(float t);
};

class creneau : public non_periodique{
protected :
    float T;
public :
    creneau();
    creneau(float m_V_0, float m_T, float m_phi);
    ~creneau(){};
    float Ve(float t);
};

class step : public non_periodique{
public :
    step();
    step(float V_0, float phi);
    ~step(){};
    float Ve(float t);
};


#endif // SOURCE_H
