//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_MINAFERRO_H
#define TP_POO_MINAFERRO_H

#include "edificio.h"

class MinaFerro: public Edificio{
public:
    MinaFerro(ilha* i);

    void melhora();
    void desaba();
    string obtemTipo() override;
    void vende() override;
    int obtemCusto() override;
    int obtemCustoSubs() override;
private:
    string tipo;
    int custoConst, custoSubs, nivel, quantProd, upgradeDinheiro, upgradeRecurso, quantArmazenamento, probDesabar;

};


#endif //TP_POO_MINAFERRO_H