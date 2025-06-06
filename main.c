#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "tad.h"

int main()
{
    int n_socios; // numero de socios

    printf("Insira o numero de socios: \n"); // usuario insere o numero de socios sobre os quais os dados serao inseridos
    scanf("%d", &n_socios);

    DADOS socios[n_socios]; // struct armazena dados sobre cada socio

    atribui_dados(socios, n_socios); // funcao que atribui os dados a cada socio

    calcula_estatisticas(socios, n_socios); // funcao que calcula o que se pede no enunciado

    socio_nota_10(socios, n_socios); // funcao que define qual eh o socio nota 10

    return 0;
}

