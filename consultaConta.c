/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 25/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: FUNCAO QUE CONSULTA AS CONTAS CADASTRADAS
*/

#include "funcoes.h"

void consultaConta(ListaDupla *D, int opcao)
{
    regConta conta;

    ApontConta result;
    ApontConta i;

    double saldoTot;
    double limiteTot;

    int codigo;

    int y;

    i = D->pri;

    if (i == NULL)
    {
        system("cls");

        tela();
        telaCadastrar();
        
        limpaMensagem();
        gotoxy(1, 22);
        printf("Nenhuma conta Cadastrada! Aperte ENTER: ");
        getch();
    }
    else
    {
        if (opcao == 1)
        {
            do
            {
                if (i->conteudo.status == 1)
                {
                    system("cls");

                    tela();
                    telaCadastrar();

                    conta = i->conteudo;

                    mostraConta(conta, opcao, 0);

                    limpaMensagem();
                    gotoxy(1, 22);
                    printf("Aperte ENTER: ");
                    getch();
                }

                i = i->prox;

            } while (i != NULL);

            limpaMensagem();
            gotoxy(1, 22);
            printf("Fim das contas! Aperte ENTER: ");
            getch();
        }
        else if (opcao == 2)
        {
            do
            {
                system("cls");

                tela();
                telaCadastrar();

                limpaMensagem();
                gotoxy(1, 22);
                printf("Codigo da conta / OBS (0 para sair): ");
                scanf("%d", &codigo);

                if (codigo != 0)
                {
                    result = pesquisaCodigoConta(D, codigo);

                    if (result != NULL)
                    {
                        if (result->conteudo.status == 1)
                        {
                            conta = result->conteudo;
                        
                            mostraConta(conta, opcao, 0);

                            limpaMensagem();
                            gotoxy(1, 22);
                            printf("Aperte ENTER: ");
                            getch();
                        }
                        else
                        {
                            limpaMensagem();
                            gotoxy(1, 22);
                            printf("Conta desativada! Aperte ENTER: ");
                            getch();
                        }
                    }   
                    else
                    {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Codigo nao cadastrado! Aperte ENTER: ");
                        getch();
                    }
                }
            } while(codigo != 0);
        }
        else
        {
            if (opcao == 3)
            {
                ordemCodigo(D);
            }
            else
            {
                ordemAlfabetica(D);
            }

            saldoTot = 0;
            limiteTot = 0;

            system("cls");
            tela();
            cabecalhoContas();

            i = D->pri;

            y = 6;

            do
            {
                conta = i->conteudo;

                if (conta.status == 1)
                {
                    saldoTot += conta.vl_saldo;
                    limiteTot += conta.vl_limite;

                    if (y == 21)
                    {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Aperte ENTER para proxima tela: ");
                        getch();

                        system("cls");
                        tela();

                        y = 6;

                        mostraConta(conta, opcao, y);

                        cabecalhoContas();
                    }
                    else
                    {
                        mostraConta(conta, opcao, y);
                        y++;
                    }
                }

                i = i->prox;

            } while (i != NULL);

            if (y > 19)
            {
                limpaMensagem();
                gotoxy(1, 22);
                printf("Aperte ENTER para proxima tela: ");
                getch();

                system("cls");
                tela();

                y = 6;

                cabecalhoContas();
                rodapeConta(saldoTot, limiteTot, y);
            }
            else
            {
                cabecalhoContas();
                rodapeConta(saldoTot, limiteTot, y);
            }

            limpaMensagem();
            gotoxy(1, 22);
            printf("Aperte ENTER: ");
            getch();
        }
    }
}
