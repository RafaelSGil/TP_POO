//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_MINACARVAO_H
#define TP_POO_MINACARVAO_H

#include "edificio.h"

class MinaCarvao : public Edificio{
public:
    MinaCarvao(ilha* i, int x, int y);
    MinaCarvao(const MinaCarvao& outro);

    void melhora() override;
    int desaba() override;
    int obtemCustoSubs() override;
    void produz() override;
    Edificio * duplica() const override;

    MinaCarvao& operator=(const Edificio& outro);
private:
    int custoSubs, quantProd, upgradeDinheiro, upgradeRecurso, probDesabar, quantArmazenamento;
};


#endif //TP_POO_MINACARVAO_H
