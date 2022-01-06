//
// Created by Rafael on 21/12/2021.
//

#include "minaFerro.h"
#include <random>


MinaFerro::MinaFerro(ilha* i) : Edificio(i, "mnF", 10, 0, 0), custoSubs(10), upgradeDinheiro(15), upgradeRecurso(1), quantProd(2), probDesabar(15), quantArmazenamento(100){}

void MinaFerro::melhora() {
    if(Edificio::getNivel() <= 5){
        if(gastaRecursos("Dinheiro", upgradeDinheiro)){
            if(gastaRecursos("VigaMadeira", upgradeRecurso)){
                Edificio::incrementaNivel();
                ++quantProd;
                quantArmazenamento += 10;
            }else{
                aumentaRecursos("Dinheiro", upgradeDinheiro);
            }
        }
    }
}

void MinaFerro::desaba() {//isto está mal feito
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(1,probDesabar);

    if(dist6(rng) == 1){

    }

}

int MinaFerro::obtemCustoSubs() {
    return custoSubs*10;
}

void MinaFerro::produz() {

}


