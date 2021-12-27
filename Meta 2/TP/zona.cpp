//
// Created by Rafael on 16/11/2021.
//

#include "zona.h"
#include <sstream>
#include "minaCarvao.h"
#include "minaFerro.h"
#include "bateria.h"
#include "fundicao.h"
#include "centralEletrica.h"


void Zona::defineTipo(string str) {
    tipo = move(str);
}

void Zona::definePosC(int c) {
    posC = c;
}

void Zona::definePosL(int l) {
    posL = l;
}

void Zona::defineTrab(string s) {
    int i, flag = 0;
    vector<string> aux;
    for(i = 0; i < 5; ++i){
        if(trab[i] == "-"){
            if(flag == 0){
                flag = 1;
                aux.push_back(s);
                ++i;
            }

        }
        aux.push_back(trab[i]);
    }

    trab.clear();
    trab = aux;
}

void Zona::defineEdificio(const string& s, ilha* i, int dev) {
    if(dev == 0){//e preciso meter as condições para gastar os recursos devidos
        if(s == "mnF"){
            ed = new MinaFerro(this);
            ++quant_edificio;
            return;
        }
        if(s == "mnC"){
            ed = new MinaCarvao(this);
            ++quant_edificio;
            return;
        }
        if(s == "fun"){
            ed = new Fundicao(this, i);
            ++quant_edificio;
            return;
        }
        if(s == "elec"){
            ed = new CentralEletrica(this, i);
            ++quant_edificio;
            return;
        }
        if(s == "bat"){
            ed = new Bateria(this, i);
            ++quant_edificio;
            return;
        }
    }
    if(s == "mnF"){
        ed = new MinaFerro(this);
        ++quant_edificio;
        return;
    }
    if(s == "mnC"){
        ed = new MinaCarvao(this);
        ++quant_edificio;
        return;
    }
    if(s == "fun"){
        ed = new Fundicao(this, i);
        ++quant_edificio;
        return;
    }
    if(s == "elec"){
        ed = new CentralEletrica(this, i);
        ++quant_edificio;
        return;
    }
    if(s == "bat"){
        ed = new Bateria(this, i);
        ++quant_edificio;
        return;
    }
}

void Zona::defineQuantTrab() {
    quant_trab = quant_trab + 1;
}

int Zona::obtemC() const {
    return posC;
}

int Zona::obtemL() const {
    return posL;
}

string Zona::obtemTipo(){
    return tipo;
}

string Zona::obtemTrab() const {
    ostringstream oss;
    for(const auto & i : trab)
        oss << i << " ";
    return oss.str();
}



int Zona::obtemQuant_Trab() const {
    return quant_trab;
}

string Zona::obtemEdificio() const {
    return ed->obtemTipo();
}

int Zona::obtemQuant_Edificios() const {
    return quant_edificio;
}

int Zona::obtemOnOFF() const {
    return ed->getonoff();
}

Edificio *Zona::getEd() {
    return ed;
}

void Zona::vendeEdificio() {
    ed->vende();
    delete ed;
    ed = nullptr;
    quant_edificio = 0;
}

void Zona::ligaDesligaED() {
    ed->ligaDesliga();
}
