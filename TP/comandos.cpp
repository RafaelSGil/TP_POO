//
// Created by user on 04/11/21.
//
#include <iostream>
#include <vector>
#include <sstream>
#include "geral.h"
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

bool verificaComandos(const string& com){

    vector<string> comandos = {"exec","cons","liga","des","move","vende","cont","list","next","save","load","apaga","config","debcash","debed","debskill"};

    if(find(comandos.begin(), comandos.end(), com) != comandos.end())
    {
        return true;
    }
    return false;
}


void tiraEspacos(string s, vector<string> &v){

    string temp = "";
    for(char i : s){

        if(i==' '){
            v.push_back(temp);
            temp = "";
        }
        else{
            temp.push_back(i);
        }

    }
    v.push_back(temp);

}

bool verificaTipo(const string& t){
    vector<string> tipos = {"minaferro", "minacarvao", "centraleletrica", "bateria", "fundicao", "edificio-x"};

    if(find(tipos.begin(), tipos.end(), t) != tipos.end())
    {
        return true;
    }
    return false;
}

bool verificaTrabalhador(const string& t){
    vector<string> trab = {"len", "oper", "min"};

    if(find(trab.begin(), trab.end(), t) != trab.end())
    {
        return true;
    }
    return false;
}

void comandos(ilha& a){
    string comando;
    vector<string> v;

    cout << "\nComando: " << endl;
    getline(cin, comando);

    tiraEspacos(comando, v);

    bool TF = verificaComandos(v[0]);
    if(TF){
        if(v[0] == "exec"){
            cout << "o exec esta a funcionar";
            string filename("comandos");
            vector<string> lines;
            string line;

            ifstream input_file(filename);
            if (!input_file.is_open()) {
                cerr << "Erro ao tentar abrir o ficheiro";
            }
            while (getline(input_file, line)) {
                lines.push_back(line);
            }
            for (auto &i: lines)
                cout << i << endl;

            input_file.close();

        }
        if(v[0] =="cons"){
            //codigo para o cons
            //chamar a função mudaValor e passar o v[1] para a lin, o v[2] para a col e o v[3] para t

            //bool flaglc = a.verificaLinCol(v[2], v[3]);
            //if (flaglc) {
                bool flagT = verificaTipo(v[1]);
                if (flagT) {
                    a.mudaValorEdificio(v[2], v[3], v[1]);
                }
            //}

            return;
        }
        if(v[0] == "list"){
            //codigo para o list


            return;
        }
        if(v[0] == "cont")


        //senão for nenhum dos dois é porque é um comando que ainda não fizemos o código
        return;
    }
}


