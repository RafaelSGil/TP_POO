 //
// Created by Rafael on 21/12/2021.
//

#include "minaFerro.h"
#include <random>


MinaFerro::MinaFerro(ilha* i, int x, int y) : Edificio(i, "mnF", 10, x, y), custoSubs(10), upgradeDinheiro(15), upgradeRecurso(1), quantProd(2), probDesabar(15), quantArmazenamento(0){}

void MinaFerro::melhora() {
    if(Edificio::getNivel() <= 5){
        if(gastaRecursos("Dinheiro", upgradeDinheiro)){
            if(gastaRecursos("VigasMadeira", upgradeRecurso)){
                Edificio::incrementaNivel();
                ++quantProd;
                quantArmazenamento += 10;
            }else{
                aumentaRecursos("Dinheiro", upgradeDinheiro);
            }
        }
    }
}

int MinaFerro::desaba() {
    double val = (double)rand() / RAND_MAX;

    if(val < probDesabar){
        return 1;
    }

    return 0;
}

int MinaFerro::obtemCustoSubs() {
    return custoSubs*10;
}

void MinaFerro::produz() {
    if(!Edificio::procuraTrabalhador("M")) return;
    if(quantArmazenamento < 100){

        quantArmazenamento += quantProd;

        if(Edificio::MNT()){
            if(Edificio::ZNX()){
                aumentaRecursos("Ferro", quantProd*2+(0.1*(quantProd*2)));
                return;
            }
            aumentaRecursos("Ferro", quantProd*2);
            return;
        }

        if(Edificio::ZNX()){
            aumentaRecursos("Ferro", quantProd+(0.1*quantProd));
            return;
        }

        if(Edificio::DSR()){
            aumentaRecursos("Ferro", quantProd/2);
            return;
        }
        aumentaRecursos("Ferro", quantProd);
    }
}

MinaFerro &MinaFerro::operator=(const Edificio &outro) {
    if(this == &outro) return *this;

    Edificio::operator=(outro);

    if(typeid(this) == typeid(outro)){
        const auto* aux = dynamic_cast<const MinaFerro*>(&outro);
        custoSubs = aux->custoSubs;
        quantProd = aux->quantProd;
        upgradeDinheiro = aux->upgradeDinheiro;
        upgradeRecurso = aux->upgradeRecurso;
        probDesabar = aux->probDesabar;
        quantArmazenamento = aux->quantArmazenamento;
    }
    return *this;
}

Edificio* MinaFerro::duplica() const{
    return new MinaFerro(*this);
}


