#include "tad.h"

void atribui_dados(DADOS socios[], int n_socios){ // atribui os dados a cada socio
    int i;

    for(i = 0; i < n_socios; i++) // for que percorre de 0 a n_socios para preenchimento da struct armazenadora dos dados
    {
        do{ // do while que garante que o usuario inserirá um numero logicamente valido à questao, no caso, >0
            printf("Insira a matricula do socio %d: \n", i+1);
            scanf("%d", &socios[i].matricula); // leitura da matricula do socio i
            if(socios[i].matricula <= 0) // se o dado inserido for invalido, aparece um alerta na tela
            {
                printf("Insira uma matricula valida.\n");
            }
        }while(socios[i].matricula <= 0);
        printf("Insira o nome do socio %d: \n", i+1);
        scanf(" %s", &socios[i].nome); // leitura do nome do socio i
        do{ // do while que garante que o usuario inserirá um numero logicamente valido à questao, no caso, >0
            printf("Insira a idade do socio %d: \n", i+1);
            scanf("%d", &socios[i].idade); // leitura da idade do socio i
            if(socios[i].idade <= 0) // se o dado inserido for invalido, aparece um alerta na tela
            {
                printf("Insira uma idade valida.\n");
            }
        }while(socios[i].idade <= 0);
        do{ // do while que garante que o usuario inserirá um numero logicamente valido à questao, no caso, >=1 e <=3
            printf("Insira o grau de instrucao do socio %d: \n", i+1);
            scanf("%d", &socios[i].grau_instrucao); // leitura do grau de instrucao do socio i
            if(socios[i].grau_instrucao < 1 || socios[i].grau_instrucao > 3) // se o dado inserido for invalido, aparece um alerta na tela
            {
                printf("Insira um grau de instrucao valido.\n");
                printf("instrucoes: \n");
                printf("1 - Fundamental\n2 - Secundario\n3 - Superior\n"); // instrui o usuario na inserção do dado
            }
        }while(socios[i].grau_instrucao < 1 || socios[i].grau_instrucao > 3);
        do{ // do while que garante que o usuario inserirá um numero logicamente valido à questao, no caso, >=1 e <=3
            printf("Insira o turno do socio %d: \n", i+1);
            scanf("%d", &socios[i].turno); // leitura do turno do socio i
            if(socios[i].turno < 1 || socios[i].turno > 3) // se o dado inserido for invalido, aparece um alerta na tela
            {
                printf("Insira um turno valido.\n");
                printf("instrucoes: \n");
                printf("1 - Manha\n2 - Tarde\n3 - Noite\n"); // instrui o usuario na inserção do dado
            }
        }while(socios[i].turno < 1 || socios[i].turno > 3);
        do{ // do while que garante que o usuario inserirá um numero logicamente valido à questao, no caso, >=1 e <=6
            printf("Insira a atividade do socio %d: \n", i+1);
            scanf("%d", &socios[i].atividade); // leitura da atividade do socio i
            if(socios[i].atividade < 1 || socios[i].atividade > 6) // se o dado inserido for invalido, aparece um alerta na tela
            {
                printf("Insira uma atividade valida.\n");
                printf("instrucoes: \n");
                printf("1 - Natacao\n2 - Hidroginastica\n3 - Danca\n4 - Kung Fu\n5 - Futebol\n6 - Volei\n"); // instrui o usuario na inserção do dado
            }
        }while(socios[i].atividade < 1 || socios[i].atividade > 6);
        do{ // do while que garante que o usuario inserirá um numero logicamente valido à questao, no caso, >=0
            printf("Insira a frequencia do socio %d (por mes): \n", i+1);
            scanf("%d", &socios[i].frequencia); // leitura da frequencia do socio i
            if(socios[i].frequencia < 0) // se o dado inserido for invalido, aparece um alerta na tela
            {
                printf("Insira uma frequencia valida.\n");
            }
        }while(socios[i].frequencia < 0);
    }
}

void calcula_estatisticas(DADOS socios[], int n_socios){ // calcula as estatisticas pedidas no enunciado da questao
    int i;
    int n_manha=0, n_tarde=0, n_noite=0; //numero de socios do turno da manha, tarde, ou noite
    int soma_fund=0, soma_sec=0, soma_sup=0; // soma das idades dos socios pelo grau de instrucao deles (fundamental, secundario ou superior)
    int n_fund=0, n_sec=0, n_sup=0; // numero de socios de acordo com o grau de instrução deles
    float media_fund=0, media_sec=0, media_sup=0; // media de idade dos socios de acordo com o grau de instrução deles
    int soma_nat=0; // numero de socios que pratica a atividade natação
    int mais_idoso=0; // idade do socio mais idoso que pratica kung fu
    char nome_mais_idoso[MAX]; // nome do socio mais idoso que pratica kung fu

    for(i = 0; i < n_socios; i++) // for que percorre de i a n_socios para calculo das proposições do problema
    {
        switch(socios[i].turno)
        {
            case 1: // se o socio i for da manha
                n_manha++; // incrementa o numero de socios da manha
                break;
            case 2: // se o socio i for da tarde
                n_tarde++; // incrementa o numero de socios da tarde
                break;
            case 3: // se o socio i for da noite
                n_noite++; // incrementa o numero de socios da noite
                break;
        }

        switch(socios[i].grau_instrucao)
        {
            case 1: // se o grau de instrução do socio i for fundamental
                soma_fund += socios[i].idade; // soma a idade do socio i com as outras dos do fundamental
                n_fund++; // incrementa o numero de socios com fundamental
                break;
            case 2: // se o grau de instrução do socio i for secundário
                soma_sec += socios[i].idade; // soma a idade do socio i com as outras dos do secundario
                n_sec++; // incrementa o numero de socios com secundário
                break;
            case 3: // se o grau de instrução do socio i for superior
                soma_sup += socios[i].idade; // soma a idade do socio i com as outras dos do superior
                n_sup++; // incrementa o numero de socios com superior
                break;
        }

        if(socios[i].atividade == 1) // se a atividade do socio i for natação
        {
            soma_nat++; // incrementa o numero de socios que praticam natação
        }

        if(socios[i].atividade == 4) // se o socio i pratica kung fu
        {
            if(mais_idoso < socios[i].idade) // se a idade do socio i for maior que a anterior
            {
                mais_idoso = socios[i].idade; // o socio i se torna o mais idoso a praticar kung fu, e aloca a idade dele na variavel 'mais_idoso'
                strcpy(nome_mais_idoso, socios[i].nome); // nome do socio i mais idoso a praticar kung fu
            }
        }
    }

    if(n_fund==0) // se o numero de socios do grau fundamental for 0
    {
        media_fund = 0; // media de idade deles eh zero (garante que nao haja indeterminação matemática)
    }
    else // se nao for 0
    {
        media_fund = (float)soma_fund/(float)n_fund; // media eh a soma das idades dos socios do fundamental dividido pelo numero de socios do fundamental
    }
    if(n_sec==0) // se o numero de socios do grau secundario for 0
    {
        media_sec = 0; // media de idade deles eh zero (garante que nao haja indeterminação matemática)
    }
    else // se nao for 0
    {
        media_sec = (float)soma_sec/(float)n_sec; // media eh a soma das idades dos socios do secundario dividido pelo numero de socios do secundario
    }
    if(n_sup==0) // se o numero de socios do grau superior for 0
    {
        media_sup = 0; // media de idade deles eh zero (garante que nao haja indeterminação matemática)
    }
    else // se nao for 0
    {
        media_sup = (float)soma_sup/(float)n_sup; // media eh a soma das idades dos socios do superior dividido pelo numero de socios do superior
    }

    printf("Total de socios do turno da manha eh: %d.\n", n_manha); // printa na tela o numero de socios do turno da manha
    printf("Total de socios do turno da tarde eh: %d.\n", n_tarde); // printa na tela o numero de socios do turno da tarde
    printf("Total de socios do turno da noite eh: %d.\n", n_noite); // printa na tela o numero de socios do turno da noite
    printf("Media de idade dos socios com grau fundamental: %.2f.\n", media_fund); // printa na tela a media de idade dos socios com funcamental
    printf("Media de idade dos socios com grau secundario: %.2f.\n", media_sec); // printa na tela a media de idade dos socios com secundario
    printf("Media de idade dos socios com grau superior: %.2f.\n", media_sup); // printa na tela a media de idade dos socios com superior
    printf("Total de socios cuja atividade eh natacao: %d.\n", soma_nat); // printa na tela o numero de socios que pratica natação

    if(mais_idoso != 0) // se o numero de socios que pratica kung fu nao for zero
    {
       printf("O socio mais idoso que pratica kung fu eh %s com %d anos. \n", nome_mais_idoso, mais_idoso); // printa na tela o nome e a idade do socio mais idoso que pratica kung fu
    }
    else // numero de socios que pratica kung fu eh zero
    {
        printf("Nao ha socios que praticam kung fu.\n"); // printa na tela que nao ha socios que praticam kung fu
    }
}

void socio_nota_10(DADOS socios[], int n_socios){ // verifica qual eh o socio nota 10, pelo seguinte criterio: melhor frequencia mensal.
    int i;
    char melhor_socio[MAX]; // nome do socio mais frequente
    int melhor_frequencia=0; // frequencia do socio mais frequente

    for(i=0; i<n_socios; i++) // for que percorre de i a n_socios para obter o socio nota 10
    {
        if(socios[i].frequencia > melhor_frequencia) // se a frequencia do socio i for maior que a anterior
        {
            melhor_frequencia = socios[i].frequencia; // a frequencia do socio i se torna a melhor frequencia
            strcpy(melhor_socio, socios[i].nome); // nome do socio i se torna o nome do socio com mais frequencia
        }
    }

    printf("O socio nota 10 eh %s com uma frequencia de %d vezes ao mes.\n", melhor_socio, melhor_frequencia); // printa na tela o nome e a frequencia do socio nota 10

}
