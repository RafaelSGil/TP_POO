<<<<<<< HEAD:TP/zona.h
//
// Created by Rafael on 1tt6/11/2021.
//

#ifndef TP_POO_ZONA_H
#define TP_POO_ZONA_H
#include <iostream>
#include <vector>
using namespace std;

class Zona{
public:
    Zona(string t= "-", int l = 0, int c = 0) : tipo(move(t)), quant_trab(0), posL(l), posC(c), quant_edificio(0), onoff(0){};

    void defineTipo(string str);
    void definePosL(int l);
    void definePosC(int c);
    void defineTrab(string s);
    void defineEdificio(string s);
    void defineQuantTrab();
    int obtemL() const;
    int obtemC() const;
    string obtemTrab() const;
    string obtemTipo() const;
    int obtemQuant_Trab() const;
    string obtemEdificio() const;
    int obtemQuant_Edificios() const;
    int obtemOnOFF() const;

private:
    string tipo, edificio;
    vector<string> trab;
    int quant_trab, quant_edificio, onoff;
    int posL, posC;
};

#endif //TP_POO_ZONA_H
=======
//
// Created by Rafael on 1tt6/11/2021.
//

#ifndef TP_POO_ZONA_H
#define TP_POO_ZONA_H
#include <iostream>
#include <vector>
using namespace std;

class Zona{
public:
    Zona(string t= "-", int l = 0, int c = 0) : tipo(move(t)), quant_trab(0), posL(l), posC(c), quant_edificio(0), onoff(0){};

    void defineTipo(string str);
    void definePosL(int l);
    void definePosC(int c);
    void defineTrab(string s);
    void defineEdificio(string s);
    void defineQuantTrab();
    int obtemL() const;
    int obtemC() const;
    string obtemTrab() const;
    string obtemTipo() const;
    int obtemQuant_Trab() const;
    string obtemEdificio() const;
    int obtemQuant_Edificios() const;
    int obtemOnOFF() const;

private:
    string tipo, edificio;
    vector<string> trab;
    int quant_trab, quant_edificio, onoff;
    int posL, posC;
};

#endif //TP_POO_ZONA_H
>>>>>>> main:Meta 1/TP/zona.h
