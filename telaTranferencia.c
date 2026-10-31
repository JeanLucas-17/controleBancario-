/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 31/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: TELA DAS TRANFERENCIAS BANCARIAS
*/

#include "funcoes.h"

void telaTransferencia()
{
    int i;

    gotoxy(1, 6);
    printf("-------C O N T A  O R I G E M---------+-------C O N T A  D E S T I N O--------");
    
    for (i = 7; i < 16; i++)
    {
        gotoxy(39, i);
        printf("|");
    }

    for (i = 1; i < 79; i++)
    {
        if (i == 39)
        {
            gotoxy(i, 16);
            printf("+");
            i++;
        }
        gotoxy(i, 16);
        printf("-");
    }

    gotoxy(1, 7);
    printf("Conta de Origem: ");
    gotoxy(1, 8);
    printf("Banco..........: ");
    gotoxy(1, 9);
    printf("Agencia........: ");
    gotoxy(1, 10);
    printf("Numero da Conta: ");
    gotoxy(1, 11);
    printf("Tipo da Conta..: ");
    gotoxy(1, 12);
    printf("Saldo..........: ");
    gotoxy(1, 13);
    printf("Limite.........: ");
    gotoxy(1, 14);
    printf("Saldo + Limite.: ");
    gotoxy(1, 15);
    printf("Novo Saldo.....: ");

    gotoxy(40, 7);
    printf("Conta de Destino: ");
    gotoxy(40, 8);
    printf("Banco...........: ");
    gotoxy(40, 9);
    printf("Agencia.........: ");
    gotoxy(40, 10);
    printf("Numero da Conta.: ");
    gotoxy(40, 11);
    printf("Tipo da Conta...: ");
    gotoxy(40, 12);
    printf("Saldo...........: ");
    gotoxy(40, 13);
    printf("Limite..........: ");
    gotoxy(40, 14);
    printf("Saldo + Limite..: ");
    gotoxy(40, 15);
    printf("Novo Saldo......: ");

    gotoxy(13, 17);
    printf("Valor a Ser transferido.: ");
    gotoxy(13, 18);
    printf("Data da Transferencia...: ");
}
