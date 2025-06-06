#ifndef TAD_H_INCLUDED
#define TAD_H_INCLUDED
#define MAX 30

typedef struct { // struct de dados sobre cada socio

    int matricula;
    char nome[MAX];
    int idade;
    int grau_instrucao;
    int turno;
    int atividade;
    int frequencia;

}DADOS;

void atribui_dados();

void calcula_estatisticas();

void socio_nota_10();

#endif // TAD_H_INCLUDED

