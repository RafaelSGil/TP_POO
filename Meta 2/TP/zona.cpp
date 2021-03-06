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
#include "serracao.h"
#include "edificiox.h"
#include "operario.h"
#include "lenhador.h"
#include "mineiro.h"


string Zona::defineTrab(string s, int dia, ilha* il) {
    if(s == "O"){
        Trabalhador *o = new Operario(dia, this);
        if(!il->gastaRecursos("Dinheiro", o->obtemCusto()))
            return "nao tem recursos";

        if(il->getContratou() == 0){
            il->setContratou();
        }
        workers.push_back(o->duplica());
        ++quant_trab;
    }
    if(s == "L"){
        Trabalhador *o = new Lenhador(dia, this);
        if(!il->gastaRecursos("Dinheiro", o->obtemCusto()))
            return "nao tem recursos";

        if(il->getContratou() == 0){
            il->setContratou();
        }
        workers.push_back(o->duplica());
        ++quant_trab;
    }
    if(s == "M"){
        Trabalhador *o = new Mineiro(dia, this);
        if(!il->gastaRecursos("Dinheiro", o->obtemCusto()))
            return "nao tem recursos";

        if(il->getContratou() == 0){
            il->setContratou();
        }
        workers.push_back(o->duplica());
        ++quant_trab;
    }

    int i, flag = 0;
    vector<string> aux;
    for(i = 0; i < 5; ++i){
        if(trab[i] == "-"){
            if(flag == 0){
                flag = 1;
                aux.push_back(s);
                continue;
            }

        }
        aux.push_back(trab[i]);
    }

    trab.clear();
    trab = aux;

    return "contratacao sucedida";
}

string Zona::defineEdificio(const string& s, ilha* i, int dev) {
    if(dev == 0){
        if(s == "mnF"){
            Edificio* m = new MinaFerro(i, posL, posC);
            if(i->gastaRecursos("VigasMadeira", m->obtemCustoDinheiro()) || i->gastaRecursos("Dinheiro", m->obtemCustoSubs())){
                ed = m->duplica();
                ++quant_edificio;
                return "construi uma mina de ferro";
            }
        }
        if(s == "mnC"){
            auto* m = new MinaCarvao(i, posL, posC);
            if(i->gastaRecursos("VigasMadeira", m->obtemCustoDinheiro()) || i->gastaRecursos("Dinheiro", m->obtemCustoSubs())){
                ed = m->duplica();
                ++quant_edificio;
                return "construi uma mina de carvao";
            }
        }
        if(s == "fun"){
            auto* m = new Fundicao(i, posL, posC);
            if(i->gastaRecursos("Dinheiro", m->obtemCustoDinheiro())){
                ed = m->duplica();
                ++quant_edificio;
                return "construi uma fundicao";
            }
        }
        if(s == "elec"){
            auto* m = new CentralEletrica(i, posL, posC);
            if(i->gastaRecursos("Dinheiro", m->obtemCustoDinheiro())){
                ed = m->duplica();
                ++quant_edificio;
                return "construi uma central eletrica";
            }
        }
        if(s == "bat"){
            auto* m = new Bateria(i);
            if(i->gastaRecursos("Dinheiro", m->obtemCustoDinheiro())){
                ed = m->duplica();
                ++quant_edificio;
                return "construi uma bateria";
            }
        }
        if(s == "ser"){
            auto* m = new Serracao(i);
            if(i->gastaRecursos("Dinheiro", m->obtemCustoDinheiro())){
                ed = m->duplica();
                ++quant_edificio;
                return "construi uma serracao";
            }
        }
        if(s == "edX"){
            Edificio* m = new Edificiox(i, posC, posL);
            if(i->gastaRecursos("Dinheiro", m->obtemCustoDinheiro())){
                ed = m->duplica();
                ++quant_edificio;
                return "construi um edificio-x";
            }
        }
    }else{
        if(s == "mnF"){
            ed = new MinaFerro(i, posL, posC);
            ++quant_edificio;
            return "construi uma mina de ferro";
        }
        if(s == "mnC"){
            ed = new MinaCarvao(i, posL, posC);
            ++quant_edificio;
            return "construi uma mina de carvao";
        }
        if(s == "fun"){
            ed = new Fundicao(i, posL, posC);
            ++quant_edificio;
            return "construi uma fundicao";
        }
        if(s == "elec"){
            ed = new CentralEletrica(i, posL, posC);
            ++quant_edificio;
            return "construi uma central eletrica";
        }
        if(s == "bat"){
            ed = new Bateria(i);
            ++quant_edificio;
            return "construi uma bateria";
        }
        if(s == "ser"){
            ed = new Serracao(i);
            ++quant_edificio;
            return "construi uma serracao";
        }
        if(s == "edX"){
            ed = new Edificiox(i, posL, posC);
            ++quant_edificio;
            return "construi um edificio-x";
        }
    }

    return "nao tem recursos";

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

Edificio *Zona::getEd() const{
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

string Zona::obtemWorkers() const {
    ostringstream oss;
    for(const auto & i : workers)
        oss << i->obtemTipo() << " : " << i->obtemID() << " | ";
    return oss.str();
}

void Zona::verificaDespedimento() {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->pedeDemissao() == 1){
            if((*it)->obtemTipo() == "L"){
                if((*it)->vidaBoa() != 0){
                    continue;
                }
            }

            vector<string>::reverse_iterator i;
            for(i = trab.rbegin(); i < trab.rend(); ++i){
                if((*i) == (*it)->obtemTipo()){
                    trab.erase((i+1).base());
                    trab.emplace_back("-");
                }
            }

            --quant_trab;
            delete (*it);
            it = workers.erase(it);
            continue;
        }
        ++it;
    }
}

void Zona::trataTrabalhadores() {
    auto it = workers.begin();
    while(it != workers.end()){
        (*it)->aumentaDias();
        (*it)->movimenta();

        if((*it)->obtemTipo() == "L"){
            (*it)->vidaBoa();
        }

        ++it;
    }
}

void Zona::trataEdificios() {
    ed->produz();
    if(ed->desaba() == 1){
        delete ed;
        ed = nullptr;
        --quant_edificio;
    }
}

bool Zona::procuraTrab(string t) {
    auto  it = trab.begin();
    while (it != trab.end()){
        if((*it) == t){
            return true;
        }
        ++it;
    }
    return false;
}
bool Zona::apagaTrabID(string id) {
    vector<string>::reverse_iterator i;
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == id){
            if(quant_trab <= 5){
                for(i = trab.rbegin(); i < trab.rend(); ++i){
                    if((*i) == (*it)->obtemTipo()){
                        trab.erase((i+1).base()); 
                        trab.emplace_back("-");
                        break;
                    }
                }
            }
            delete *it;
            workers.erase(it);
            --quant_trab;
            return true;
        }
        ++it;
    }
    return false;
}

int Zona::contaTrab(string t) {
    int i = 0;
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemTipo() == t){
            ++i;
        }
        ++it;
    }
    return i;
}

void Zona::trata(ilha& i) {

}

string Zona::obtemTipo(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->obtemTipo();
        }

        ++it;
    }
    return "-";
}

int Zona::obtemCusto(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->obtemCusto();
        }
        ++it;
    }
    return 0;
}

double Zona::obtemProb(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->obtemProb();
        }
        ++it;
    }
    return 0;
}

int Zona::obtemDiasSim(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->obtemDiasSim();
        }
        ++it;
    }
    return 0;
}

int Zona::pedeDemissao(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->pedeDemissao();
        }
        ++it;
    }
    return 0;
}

int Zona::obtemIDT(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->ID();
        }
        ++it;
    }
    return 0;
}

int Zona::obtemDescanso(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->obtemDescanso();
        }
        ++it;
    }
    return 0;
}

int Zona::obtemDID(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->obtemDID();
        }
        ++it;
    }
    return 0;
}

bool Zona::procuraTrab(string t, int a) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return true;
        }
        ++it;
    }
    return false;
}

void Zona::destroiED() {
    delete ed;
    ed = nullptr;
    --quant_edificio;
}

void Zona::apagaTodosTrab() {
    if(workers.empty()) return;
    auto it = workers.begin();
    while (it != workers.end()){
        delete *it;
        it = workers.erase(it);
    }

    workers.clear();

    trab.clear();

    for (int i = 0; i < 5; ++i) {
        trab.emplace_back("-");
    }
    quant_trab = 0;
}

int Zona::getNArvores() const {
    return -1;
}

double Zona::obtemRedProd() {
    return 0;
}

bool Zona::previneDespedimento() {
    if(tipo == "pas"){
        return true;
    }
    return false;
}

int Zona::obtemMovTrab(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->obtemMovim();
        }
        ++it;
    }
    return -1;
}

Trabalhador *Zona::moveTrab(string t) {
    Trabalhador* aux = nullptr;
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            --quant_trab;
            aux = *it;
            workers.erase(it);
            break;
        }
        ++it;
    }

    vector<string>::reverse_iterator it_t;
    it_t = trab.rbegin();
    while (it_t != trab.rend()){
        if((*it_t) == aux->obtemTipo()){
            trab.erase((it_t+1).base());
            trab.emplace_back("-");
            break;
        }
        ++it_t;
    }

    return aux;
}

void Zona::recebeTrab(Trabalhador* auxt) {
    auxt->redefineZona(this);
    workers.push_back(auxt);

    int i, flag = 0;
    vector<string> aux;
    for(i = 0; i < 5; ++i){
        if(trab[i] == "-"){
            if(flag == 0){
                flag = 1;
                aux.push_back(auxt->obtemTipo());
                continue;
            }

        }
        aux.push_back(trab[i]);
    }

    trab.clear();
    trab = aux;
    ++quant_trab;

}

Zona &Zona::atribui(const Zona &outro) {
    if(this == &outro) return *this;

    auto it1 = workers.begin();
    while (it1 != workers.end()){
        delete (*it1);
        ++it1;
    }
    workers.clear();

    trab.clear();

    auto it2 = outro.workers.begin();
    while(it2 != outro.workers.end()){
        workers.push_back((*it2)->duplica());
        ++it2;
    }

    auto it3 = outro.trab.begin();
    while (it3 != outro.trab.end()){
        trab.push_back((*it3));
        ++it3;
    }

    delete ed;
    ed = nullptr;

    if (outro.getEd() != nullptr){
        ed = outro.ed->duplica();
    }

    quant_edificio = outro.quant_edificio;
    quant_trab = outro.quant_edificio;
    posC = outro.posC;
    posL = outro.posL;

    return *this;
}

Zona *Zona::duplica() const {
    return nullptr;
}

void Zona::upgradeED() {
    ed->melhora();
}

double Zona::getAumentoProbDem() const {
    return 0;
}

int Zona::getNivel() const {
    return ed->getNivel();
}
