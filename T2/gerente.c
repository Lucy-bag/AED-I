#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <windows.h>

int main()
{
    bool pass = false, pause = false;
    int menu, i, opcao; // variaveis de menu
    int quantidade;

    int cpf[12], d1 = 0, d2 = 0; // variaveis de cpf
    char cpfchar[12];

    int notas[] = {500, 150, 50, 20, 10, 5, 2, 1}; // variaveis de saque
    int a01, a02, a03, a04, a05, a06;
    int saque, qnt_saque[8], total = 0;
    int max_notas[8], maximo[8];
    max_notas[0] = 100, maximo[0] = 100;

    for (i = 1; i < 8; i++)
        max_notas[i] = max_notas[i - 1] * 2;// alocando as notas mais rapidamente por serem o dobro uma da outra
    for (i = 0; i < 8; i++)
        total += notas[i] * max_notas[i]; // valor maximo do caixa

    do
    {
        do
        {
            printf("\n|----------------|\n");
            printf("| MENU PRINCIPAL | ");
            printf("\n|----------------|\n\n");
            printf(" 1 - Saque\n");
            printf(" 2 - Gerente\n");
            printf(" 3 - Finalizar\n --> ");
            scanf("%d", &menu);
            if ((menu < 1 || menu > 3))
            {
                system("cls");
                printf("\n|OPCAO INVALIDA|\n    escolha\nentre as opcoes!\n");
            }

        } while (menu < 1 || menu > 3);

        switch (menu)
        {
        case 1:
           
            i = 0;
            do {
                if (total != 0) {
                    printf("\n------------------------\n");
                    printf("Para cancelar (DIGITE 0)");
                    printf("\n------------------------\n");
                    do {
                        printf("\n Insira o valor do\n saque desejado: ");
                        scanf("%d", &saque);

                        if (saque < 0)
                        {
                            system("cls"); 
                            printf("\n------------------------\n");
                            printf("Para cancelar (DIGITE 0)");
                            printf("\n------------------------\n");
                            printf("\n   /~~~~~~~~~~~~~~~~\\\n  / |VALOR INVALIDO| \\\n /~~~~~~~~~~~~~~~~~~~~\\");
                            printf("\n\n Valor abaixo de zero! \n");
                        }
                        else if (saque > total)
                        {
                            system("cls");
                            printf("\n------------------------\n");
                            printf("Para cancelar (DIGITE 0)");
                            printf("\n------------------------\n");
                            printf("\n   /~~~~~~~~~~~~~~~~\\\n  / |VALOR INVALIDO| \\\n /~~~~~~~~~~~~~~~~~~~~\\");
                            printf("\n\n Valor acima do limite\n disponivel no caixa!");
                            printf("\n LIMITE ATUAL: %d REAIS\n", total);
                        }
                    } while (saque < 0 || saque > total);
                    if (saque == 0) {
                        printf("\nRetornando ao menu");
                        usleep(400000);
                        for(int k=0; k<3 ;k++){
                        printf(" .");
                        usleep(400000);
                        }
                        break;
                    }
        
                    total -= saque, d1 = saque;
                    system("cls");
                    printf("\n----------------------------------------\n\n");
                    printf("Para o valor de %d reais, Foram sacadas: \n", saque);
                    for (i = 0; i < 8; i++)
                    {
                        qnt_saque[i] = d1 / notas[i];
                        d1 %= notas[i];

                        if (qnt_saque[i] > max_notas[i])
                        {
                            d1 += (qnt_saque[i] - max_notas[i]) * notas[i];
                            qnt_saque[i] = max_notas[i];
                            max_notas[i] = 0;
                        } else
                            max_notas[i] -= qnt_saque[i];

                        switch (i) {
                        case 0:
                            if (qnt_saque[i] != 0)
                                printf("\n|  %d | -> Nota(s) de quinhentos reais", qnt_saque[i]);
                            break;
                        case 1:
                            if (qnt_saque[i] != 0)
                                printf("\n|  %d | -> Nota(s) de cento e cinquenta reais", qnt_saque[i]);
                            break;
                        case 2:
                            if (qnt_saque[i] != 0)
                                printf("\n|  %d | -> Nota(s) de cinquenta reais", qnt_saque[i]);
                            break;
                        case 3:
                            if (qnt_saque[i] != 0)
                                printf("\n|  %d | -> Nota(s) de vinte reais", qnt_saque[i]);
                            break;
                        case 4:
                            if (qnt_saque[i] != 0)
                                printf("\n|  %d | -> nota(s) de dez reais", qnt_saque[i]);
                            break;
                        case 5:
                            if (qnt_saque[i] != 0)
                                printf("\n|  %d | -> nota(s) de cinco reais", qnt_saque[i]);
                            break;
                        case 6:
                            if (qnt_saque[i] != 0)
                                printf("\n|  %d | -> nota(s) de dois reais", qnt_saque[i]);
                            break;
                        case 7:
                            if (qnt_saque[i] != 0)
                                printf("\n|  %d | -> nota(s) de um reais", qnt_saque[i]);
                            break;
                        }
                    }
                    printf("\n\nsaque total: \nR$ ");
                    a06 = (saque % 1000000) / 100000;
                    a05 = (saque % 100000) / 10000;
                    a04 = (saque % 10000) / 1000;
                    a03 = (saque % 1000) / 100;
                    a02 = (saque % 100) / 10;
                    a01 = (saque % 10);

                    if (a06 == 1)
                    {

                        if (a05 == 0 && a04 == 0)
                            printf("CEM ");
                        else
                            printf("CENTO E ");
                    }
                    if (a05 == 1)
                    {
                        if (a04 == 0)
                            printf("DEZ ");
                        else if (a04 == 1)
                            printf("ONZE ");
                        else if (a04 == 2)
                            printf("DOZE ");
                        else if (a04 == 3)
                            printf("TREZE ");
                        else if (a04 == 4)
                            printf("QUATORZE ");
                        else if (a04 == 5)
                            printf("QUINZE ");
                        else if (a04 == 6)
                            printf("DEZESSEIS ");
                        else if (a04 == 7)
                            printf("DEZESSETE ");
                        else if (a04 == 8)
                            printf("DEZOITO ");
                        else if (a04 == 9)
                            printf("DEZENOVE ");
                    }
                    else if (a05 == 2)
                        printf("VINTE ");
                    else if (a05 == 3)
                        printf("TRINTA ");
                    else if (a05 == 4)
                        printf("QUARENTA ");
                    else if (a05 == 5)
                        printf("CINQUENTA ");
                    else if (a05 == 6)
                        printf("SESSENTA ");
                    else if (a05 == 7)
                        printf("SETENTA ");
                    else if (a05 == 8)
                        printf("OITENTA ");
                    else if (a05 == 9)
                        printf("NOVENTA ");

                    if ((a05 != 1 && a05 != 0) && a04 != 0)
                        printf("E ");

                    if (a05 != 1)
                    {
                        if (a04 == 1 && a05 != 0)
                            printf("UM ");
                        else if (a04 == 2)
                            printf("DOIS ");
                        else if (a04 == 3)
                            printf("TRES ");
                        else if (a04 == 4)
                            printf("QUATRO ");
                        else if (a04 == 5)
                            printf("CINCO ");
                        else if (a04 == 6)
                            printf("SEIS ");
                        else if (a04 == 7)
                            printf("SETE ");
                        else if (a04 == 8)
                            printf("OITO ");
                        else if (a04 == 9)
                            printf("NOVE ");
                    }
                    if (a04 != 0 || a05 != 0 || a06 != 0) {
                        if ((a03!=0 && a02==0 && a01==0))
                            printf("MIL E ");
                        else if (a03!=0 || (a03==0 && a02==0 && a01==0))
                            printf("MIL ");
                        else if (a03==0 )
                            printf("MIL E ");
                    }
                    if (a03 == 1)
                    {
                        if (a02 == 0 && a01 == 0)
                            printf("CEM ");
                        else
                            printf("CENTO ");
                    }
                    if (a03 == 2)
                        printf("DUZENTOS ");
                    else if (a03 == 3)
                        printf("TREZENTOS ");
                    else if (a03 == 4)
                        printf("QUATROCENTOS ");
                    else if (a03 == 5)
                        printf("QUINHENTOS ");
                    else if (a03 == 6)
                        printf("SEISCENTOS ");
                    else if (a03 == 7)
                        printf("SETECENTOS ");
                    else if (a03 == 8)
                        printf("OITOCENTOS ");
                    else if (a03 == 9)
                        printf("NOVECENTOS ");
                    if (a03 != 0 && !(a02 == 0 && a01 == 0))
                        printf("E ");

                    if (a02 == 1) {
                        if (a01 == 0)
                            printf("DEZ ");
                        else if (a01 == 1)
                            printf("ONZE ");
                        else if (a01 == 2)
                            printf("DOZE");
                        else if (a01 == 3)
                            printf("TREZE ");
                        else if (a01 == 4)
                            printf("QUATORZE ");
                        else if (a01 == 5)
                            printf("QUINZE");
                        else if (a01 == 6)
                            printf("DEZESSEIS ");
                        else if (a01 == 7)
                            printf("DEZESSETE ");
                        else if (a01 == 8)
                            printf("DEZOITO ");
                        else if (a01 == 9)
                            printf("DEZENOVE ");
                    }
                    else if (a02 == 2)
                        printf("VINTE ");
                    else if (a02 == 3)
                        printf("TRINTA ");
                    else if (a02 == 4)
                        printf("QUARENTA ");
                    else if (a02 == 5)
                        printf("CINQUENTA ");
                    else if (a02 == 6)
                        printf("SESSENTA ");
                    else if (a02 == 7)
                        printf("SETENTA ");
                    else if (a02 == 8)
                        printf("OITENTA ");
                    else if (a02 == 9)
                        printf("NOVENTA ");


                    if (a02 != 1)
                    {
                        
                        if ((a02 != 0 &&  a01 != 0) && (a04 != 0 || a05 != 0 || a06 != 0))
                            printf("E ");
                        if (a01 == 1)
                            printf("UM ");
                        else if (a01 == 2)
                            printf("DOIS ");
                        else if (a01 == 3)
                            printf("TRES ");
                        else if (a01 == 4)
                            printf("QUATRO ");
                        else if (a01 == 5)
                            printf("CINCO ");
                        else if (a01 == 6)
                            printf("SEIS ");
                        else if (a01 == 7)
                            printf("SETE ");
                        else if (a01 == 8)
                            printf("OITO ");
                        else if (a01 == 9)
                            printf("NOVE ");
                    }
                    printf("\n\n----------------------------------------\n");

                    do {
                        printf("\n\nPara voltar ao menu (DIGITE 0)");
                        printf("\nPara Sacar novamente (DIGITE 1)");
                        printf("\nEscolha uma opcao acima: ");
                        scanf("%d", &i);
                        if ((i < 0 || i > 1))
                        {
                            system("cls");
                            printf("     |OPCAO INVALIDA|");
                        }
                    } while (i < 0 || i > 1);
                    system("cls");
                } else 
                {
                    printf("-->  CAIXA VAZIO!!! <--\n\n");
                    printf(" Retornando ao menu"), i = 0;
                    usleep(400000);
                    for(int k=0; k<3 ;k++){
                    printf(" .");
                    usleep(400000);
                    }
                }
            } while (i);
            break;

        case 2:
            do {
                system("cls");
                printf("\n|----------------|\n");
                printf("|  MENU GERENTE  | ");
                printf("\n|----------------|\n\n");
                printf(" 1 - Valor Total Sacado\n");
                printf(" 2 - Saldo Existente\n");
                printf(" 3 - Cedulas Existentes\n");
                printf(" 4 - Abastecer Caixa\n");
                printf(" 5 - Voltar ao menu principal\n --> ");
                scanf("%d", &menu);
                system("cls");
                
                // valor do saldo existente
                // valor total sacado
                if (menu==1)
                {
                    saque = (173600-total);
                    printf("*------------------------------*\n\n");
                    printf("Valor total sacado: R$ %d \n\nRetirado do caixa:\n", saque);
                } else if (menu==2) {
                    saque = total;
                    printf("*-------------------------------*\n\n");
                    printf("Valor do saldo existente: R$ %d \n\nRestando no caixa:\n", saque);
                }
                if ((menu==1 || menu==2)) 
                {
                    if (saque!=0) {
                        a06 = (saque % 1000000) / 100000;
                        a05 = (saque % 100000) / 10000;
                        a04 = (saque % 10000) / 1000;
                        a03 = (saque % 1000) / 100;
                        a02 = (saque % 100) / 10;
                        a01 = (saque % 10);
                        if (a06 == 1)
                        {
                            if (a05 == 0 && a04 == 0)
                                printf("CEM ");
                            else
                                printf("CENTO E ");
                        }
                        if (a05 == 1)
                        {
                            if (a04 == 0)
                                printf("DEZ ");
                            else if (a04 == 1)
                                printf("ONZE ");
                            else if (a04 == 2)
                                printf("DOZE ");
                            else if (a04 == 3)
                                printf("TREZE ");
                            else if (a04 == 4)
                                printf("QUATORZE ");
                            else if (a04 == 5)
                                printf("QUINZE ");
                            else if (a04 == 6)
                                printf("DEZESSEIS ");
                            else if (a04 == 7)
                                printf("DEZESSETE ");
                            else if (a04 == 8)
                                printf("DEZOITO ");
                            else if (a04 == 9)
                                printf("DEZENOVE ");
                        }
                        else if (a05 == 2)
                            printf("VINTE ");
                        else if (a05 == 3)
                            printf("TRINTA ");
                        else if (a05 == 4)
                            printf("QUARENTA ");
                        else if (a05 == 5)
                            printf("CINQUENTA ");
                        else if (a05 == 6)
                            printf("SESSENTA ");
                        else if (a05 == 7)
                            printf("SETENTA ");
                        else if (a05 == 8)
                            printf("OITENTA ");
                        else if (a05 == 9)
                            printf("NOVENTA ");

                        if ((a05 != 1 && a05 != 0) && a04 != 0)
                            printf("E ");

                        if (a05 != 1)
                        {
                            if (a04 == 1 && a05 != 0)
                                printf("UM ");
                            else if (a04 == 2)
                                printf("DOIS ");
                            else if (a04 == 3)
                                printf("TRES ");
                            else if (a04 == 4)
                                printf("QUATRO ");
                            else if (a04 == 5)
                                printf("CINCO ");
                            else if (a04 == 6)
                                printf("SEIS ");
                            else if (a04 == 7)
                                printf("SETE ");
                            else if (a04 == 8)
                                printf("OITO ");
                            else if (a04 == 9)
                                printf("NOVE ");
                        }
                        if (a04 != 0 || a05 != 0 || a06 != 0) {
                            if ((a03!=0 && a02==0 && a01==0))
                                printf("MIL E ");
                            else if (a03!=0 || (a03==0 && a02==0 && a01==0))
                                printf("MIL ");
                            else if (a03==0 )
                                printf("MIL E ");
                        }
                        if (a03 == 1)
                        {
                            if (a02 == 0 && a01 == 0)
                                printf("CEM ");
                            else
                                printf("CENTO ");
                        }
                        if (a03 == 2)
                            printf("DUZENTOS ");
                        else if (a03 == 3)
                            printf("TREZENTOS ");
                        else if (a03 == 4)
                            printf("QUATROCENTOS ");
                        else if (a03 == 5)
                            printf("QUINHENTOS ");
                        else if (a03 == 6)
                            printf("SEISCENTOS ");
                        else if (a03 == 7)
                            printf("SETECENTOS ");
                        else if (a03 == 8)
                            printf("OITOCENTOS ");
                        else if (a03 == 9)
                            printf("NOVECENTOS ");
                        if (a03 != 0 && !(a02 == 0 && a01 == 0))
                            printf("E ");

                        if (a02 == 1) {
                            if (a01 == 0)
                                printf("DEZ ");
                            else if (a01 == 1)
                                printf("ONZE ");
                            else if (a01 == 2)
                                printf("DOZE");
                            else if (a01 == 3)
                                printf("TREZE ");
                            else if (a01 == 4)
                                printf("QUATORZE ");
                            else if (a01 == 5)
                                printf("QUINZE");
                            else if (a01 == 6)
                                printf("DEZESSEIS ");
                            else if (a01 == 7)
                                printf("DEZESSETE ");
                            else if (a01 == 8)
                                printf("DEZOITO ");
                            else if (a01 == 9)
                                printf("DEZENOVE ");
                        }
                        else if (a02 == 2)
                            printf("VINTE ");
                        else if (a02 == 3)
                            printf("TRINTA ");
                        else if (a02 == 4)
                            printf("QUARENTA ");
                        else if (a02 == 5)
                            printf("CINQUENTA ");
                        else if (a02 == 6)
                            printf("SESSENTA ");
                        else if (a02 == 7)
                            printf("SETENTA ");
                        else if (a02 == 8)
                            printf("OITENTA ");
                        else if (a02 == 9)
                            printf("NOVENTA ");

                        if (a02 != 0 && a02 != 1 && a01 != 0)
                            printf("E ");
                        if (a02 != 1)
                        {
                            if (a01 == 1)
                                printf("UM ");
                            else if (a01 == 2)
                                printf("DOIS ");
                            else if (a01 == 3)
                                printf("TRES ");
                            else if (a01 == 4)
                                printf("QUATRO ");
                            else if (a01 == 5)
                                printf("CINCO ");
                            else if (a01 == 6)
                                printf("SEIS ");
                            else if (a01 == 7)
                                printf("SETE ");
                            else if (a01 == 8)
                                printf("OITO ");
                            else if (a01 == 9)
                                printf("NOVE ");
                        }
                        printf("Reais");
                    } else
                        printf("ZERO Reais");
                        
                    printf("\n\n*-------------------------------*\n");
                    system("pause");
                }
                switch (menu) {
                case 3:
                    // quantidade de cedulas existentes
                    system("cls");
                    printf("*--------------------------------------------*\n\n");
                    for (i=0; i<8; i++) {
                        printf("( %d ) ", max_notas[i]);
                        if (max_notas[i]!=0) {
                            a06 = (max_notas[i] % 1000000) / 100000;
                            a05 = (max_notas[i] % 100000) / 10000;
                            a04 = (max_notas[i] % 10000) / 1000;
                            a03 = (max_notas[i] % 1000) / 100;
                            a02 = (max_notas[i] % 100) / 10;
                            a01 = (max_notas[i] % 10);

                            if (a05 == 1)
                            {
                                if (a04 == 0)
                                    printf("DEZ ");
                                else if (a04 == 1)
                                    printf("ONZE ");
                                else if (a04 == 2)
                                    printf("DOZE ");
                                else if (a04 == 3)
                                    printf("TREZE ");
                                else if (a04 == 4)
                                    printf("QUATORZE ");
                                else if (a04 == 5)
                                    printf("QUINZE ");
                                else if (a04 == 6)
                                    printf("DEZESSEIS ");
                                else if (a04 == 7)
                                    printf("DEZESSETE ");
                                else if (a04 == 8)
                                    printf("DEZOITO ");
                                else if (a04 == 9)
                                    printf("DEZENOVE ");
                            }
                            else if (a05 == 2)
                                printf("VINTE ");
                            else if (a05 == 3)
                                printf("TRINTA ");
                            else if (a05 == 4)
                                printf("QUARENTA ");
                            else if (a05 == 5)
                                printf("CINQUENTA ");
                            else if (a05 == 6)
                                printf("SESSENTA ");
                            else if (a05 == 7)
                                printf("SETENTA ");
                            else if (a05 == 8)
                                printf("OITENTA ");
                            else if (a05 == 9)
                                printf("NOVENTA ");

                            if ((a05 != 1 && a05 != 0) && a04 != 0)
                                printf("E ");

                            if (a05 != 1)
                            {
                                if (a04 == 1 && a05 != 0)
                                    printf("UM ");
                                else if (a04 == 2)
                                    printf("DOIS ");
                                else if (a04 == 3)
                                    printf("TRES ");
                                else if (a04 == 4)
                                    printf("QUATRO ");
                                else if (a04 == 5)
                                    printf("CINCO ");
                                else if (a04 == 6)
                                    printf("SEIS ");
                                else if (a04 == 7)
                                    printf("SETE ");
                                else if (a04 == 8)
                                    printf("OITO ");
                                else if (a04 == 9)
                                    printf("NOVE ");
                            }
                            if (a04 != 0 || a05 != 0 || a06 != 0) {
                                if ((a03!=0 && a02==0 && a01==0))
                                    printf("MIL E ");
                                else if (a03!=0 || (a03==0 && a02==0 && a01==0))
                                    printf("MIL ");
                                else if (a03==0 )
                                    printf("MIL E ");
                            }
                            if (a03 == 1)
                            {
                                if (a02 == 0 && a01 == 0)
                                    printf("CEM ");
                                else
                                    printf("CENTO ");
                            }
                            if (a03 == 2)
                                printf("DUZENTOS ");
                            else if (a03 == 3)
                                printf("TREZENTOS ");
                            else if (a03 == 4)
                                printf("QUATROCENTOS ");
                            else if (a03 == 5)
                                printf("QUINHENTOS ");
                            else if (a03 == 6)
                                printf("SEISCENTOS ");
                            else if (a03 == 7)
                                printf("SETECENTOS ");
                            else if (a03 == 8)
                                printf("OITOCENTOS ");
                            else if (a03 == 9)
                                printf("NOVECENTOS ");
                            if (a03 != 0 && !(a02 == 0 && a01 == 0))
                                printf("E ");

                            if (a02 == 1) {
                                if (a01 == 0)
                                    printf("DEZ ");
                                else if (a01 == 1)
                                    printf("ONZE ");
                                else if (a01 == 2)
                                    printf("DOZE");
                                else if (a01 == 3)
                                    printf("TREZE ");
                                else if (a01 == 4)
                                    printf("QUATORZE ");
                                else if (a01 == 5)
                                    printf("QUINZE");
                                else if (a01 == 6)
                                    printf("DEZESSEIS ");
                                else if (a01 == 7)
                                    printf("DEZESSETE ");
                                else if (a01 == 8)
                                    printf("DEZOITO ");
                                else if (a01 == 9)
                                    printf("DEZENOVE ");
                            }
                            else if (a02 == 2)
                                printf("VINTE ");
                            else if (a02 == 3)
                                printf("TRINTA ");
                            else if (a02 == 4)
                                printf("QUARENTA ");
                            else if (a02 == 5)
                                printf("CINQUENTA ");
                            else if (a02 == 6)
                                printf("SESSENTA ");
                            else if (a02 == 7)
                                printf("SETENTA ");
                            else if (a02 == 8)
                                printf("OITENTA ");
                            else if (a02 == 9)
                                printf("NOVENTA ");

                            if (a02 != 0 && a02 != 1 && a01 != 0)
                                printf("E ");
                            if (a02 != 1)
                            {
                                if (a01 == 1)
                                    printf("UM ");
                                else if (a01 == 2)
                                    printf("DOIS ");
                                else if (a01 == 3)
                                    printf("TRES ");
                                else if (a01 == 4)
                                    printf("QUATRO ");
                                else if (a01 == 5)
                                    printf("CINCO ");
                                else if (a01 == 6)
                                    printf("SEIS ");
                                else if (a01 == 7)
                                    printf("SETE ");
                                else if (a01 == 8)
                                    printf("OITO ");
                                else if (a01 == 9)
                                    printf("NOVE ");
                            }
                        } else
                            printf("ZERO ");
                        printf(" Cedulas de %d \n", max_notas[i], notas[i]);
                    }                    
                    printf("*--------------------------------------------*\n\n");
                    system("pause");
                    break;
                case 4:
                    do{
                        do {
                        printf("*---------------------------*\n\n");
                        printf(" 500 - Cedulas de 500 \n");
                        printf(" 150 - Cedula de 150 \n");
                        printf(" 50 - Cedulas de 50 \n");
                        printf(" 10 - Cedulas de 10 \n");
                        printf(" 5 - Cedulas de 5 \n");
                        printf(" 2 - Cedulas de 2 \n");
                        printf(" 1 - Cedulas de 1 \n");
                        printf(" 0 - Voltar ao menu gerente\n\n" );
                        printf("*---------------------------*\n\n --> ");
                        scanf("%d", &i);
                        system("cls");
                        if (i!=500 && i!=150 && i!=50 && i!=10 && i!=5 && i!=3 && i!=2 && i!=1 && i!= 0)
                            printf("   | OPCAO INVALIDA |   \n\n"), i=-1;
                        
                        } while(i==(-1));
                        if (i==0)
                            break;
                        
                        if (i==500)
                            i=0;
                        if (i==150)
                            i=1;
                        if (i==50)
                            i=2;
                        if (i==20)
                            i=3;
                        if (i==10)
                            i=4;
                        if (i==5)
                            i=5;
                        if (i==2)
                            i=6;
                        if (i==1)
                            i=7;
                        do {
                            printf("\nquantas notas de %d quer abastecer?\n--> ", notas[i]);
                            scanf("%d", &quantidade);
                            if (quantidade < 0) {
                                system("cls");
                                printf("            | VALOR INVALIDO |\n");
                                printf("Valor digitado NAO pode ser menor que zero!!\n");
                            } else if ((max_notas[i] + quantidade) > (100*pow(2, i)) ){
                                system("cls");
                                printf("            | VALOR INVALIDO |\n");
                                printf("Valor digitado maior que o limite de cedulas!!\n");
                            }
                        } while (quantidade < 0 ||  ((max_notas[i] + quantidade) > (100*pow(2, i)) ));
                        if (quantidade!=0)                
                            printf("\nForam armazenadas %d cedulas de %d\n", quantidade, notas[i]);
                        else
                            printf("\nNao houve nenhuma cedula armazenada\n");

                        max_notas[i] += quantidade;
                        printf("Cedulas totais de %d : ( %d )\n\n", notas[i], max_notas[i]);
                        system("pause");
                        system("cls");
                    } while(i==0);
                    break;
                case 5:

                    printf(" Retornando ao menu"), i = 0;
                    usleep(300000);
                    for(int k=0; k<3 ;k++){
                    printf(" .");
                    usleep(300000);
                    }
                    break;
                }
            } while (menu!=5);
            break;
            
        case 3:
            system("cls");
            printf("Finalizando programa");
            usleep(300000);
            for(int k=0; k<3 ;k++){
            printf(" .");
            usleep(300000);
            }
            return 0;
        }
        system("cls");
    } while (1);

    return 0;
}