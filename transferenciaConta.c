/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 31/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: TRANSFERENCIA ENTRE CONTAS BANCARIAS
*/

#include "funcoes.h"

void transferenciaConta(ListaDupla*D, ListaSimples *S)
{
    ApontConta resultDestino;
    ApontConta resultOrigem;
    regConta contaDestino;
    regConta contaOrigem;

    regMovimentacao mov;
    ApontMov p;

    double novoSaldoOr;
    double novoSaldoDe;

    int codigo;

    do
    {
        system("cls");
        tela();
        telaTransferencia();

        limpaMensagem();

        gotoxy(1, 22);
        printf("OBS (0 para sair): ");

        gotoxy(19, 7);
        scanf("%d", &contaOrigem.codigo_conta);

        if (contaOrigem.codigo_conta != 0 && contaOrigem.codigo_conta > 0)
        {
            limpaMensagem();

            resultOrigem = pesquisaCodigoConta(D, contaOrigem.codigo_conta);

            if (resultOrigem != NULL)
            {
                contaOrigem = resultOrigem->conteudo;

                gotoxy(19, 8);
                printf(contaOrigem.banco);

                gotoxy(19, 9);
                printf(contaOrigem.agencia);

                gotoxy(19, 10);
                printf(contaOrigem.numero_conta);

                gotoxy(19, 11);
                printf(contaOrigem.tipo_conta);

                gotoxy(19, 12);
                printf("R$ %.2f", contaOrigem.vl_saldo);

                gotoxy(19, 13);
                printf("R$ %.2f", contaOrigem.vl_limite);

                gotoxy(19, 14);
                printf("R$ %.2f", contaOrigem.vl_saldo + contaOrigem.vl_limite);

                do
                {
                    gotoxy(59, 7);
                    printf("                    ");

                    gotoxy(59, 7);
                    scanf("%d", &contaDestino.codigo_conta);

                    resultDestino = pesquisaCodigoConta(D, contaDestino.codigo_conta);

                    if (resultDestino == NULL)
                    {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Codigo nao Cadastrado! Aperte ENTER: ");
                        getch();
                    }
                    else if (contaOrigem.codigo_conta == contaDestino.codigo_conta)
                    {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Codigo sao iguais! Aperter ENTER: ");
                        getch();
                    }

                    limpaMensagem();

                } while (resultDestino == NULL || contaOrigem.codigo_conta == contaDestino.codigo_conta);

                contaDestino = resultDestino->conteudo;

                gotoxy(59, 8);
                printf(contaDestino.banco);

                gotoxy(59, 9);
                printf(contaDestino.agencia);

                gotoxy(59, 10);
                printf(contaDestino.numero_conta);

                gotoxy(59, 11);
                printf(contaDestino.tipo_conta);

                gotoxy(59, 12);
                printf("R$ %.2f", contaDestino.vl_saldo);

                gotoxy(59, 13);
                printf("R$ %.2f", contaDestino.vl_limite);

                gotoxy(59, 14);
                printf("R$ %.2f", contaDestino.vl_saldo + contaDestino.vl_limite);

                do
                {
                    gotoxy(39, 17);
                    printf("                                     ");
                    gotoxy(39, 17);
                    scanf("%lf", &mov.vl_movimento);

                    if (mov.vl_movimento > (contaOrigem.vl_saldo + contaOrigem.vl_limite) || mov.vl_movimento < 1)
                    {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Valor Invalido ou Saldo Insuficiente! Aperte ENTER: ");
                        getch();
                    }

                    limpaMensagem();

                } while (mov.vl_movimento > (contaOrigem.vl_saldo + contaOrigem.vl_limite) || mov.vl_movimento < 1);

                novoSaldoOr = contaOrigem.vl_saldo - mov.vl_movimento;
                novoSaldoDe = contaDestino.vl_saldo + mov.vl_movimento;

                resultOrigem->conteudo.vl_saldo = novoSaldoOr;
                resultDestino->conteudo.vl_saldo = novoSaldoDe;

                gotoxy(19, 15);
                printf("R$ %.2f", novoSaldoOr);

                gotoxy(59, 15);
                printf("R$ %.2f", novoSaldoDe);

                gotoxy(39, 18);
                scanf("%s", &mov.dt_movimento);
                
                mov.sequencial++;
                strcpy(mov.tp_movimento, "Transferencia Entre Contas");
                mov.codigo_conta = contaOrigem.codigo_conta;
                strcpy(mov.ds_favorecido, contaDestino.banco);
                mov.vl_saldo = contaOrigem.vl_saldo;

                p = (ApontMov) malloc(sizeof(TipoItemMov));

                p->conteudo = mov;

                if (S->pri == NULL)
                {
                    S->pri = p;
                    S->ult = p;
                    p->prox = NULL;
                }
                else
                {
                    S->ult->prox = p;
                    S->ult = p;
                    p->prox = NULL;
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
        else if (contaOrigem.codigo_conta < 0)
        {
            limpaMensagem();
            gotoxy(1, 22);
            printf("Codigo Invalido! Aperte ENTER: ");
            getch();
        }
    } while (contaOrigem.codigo_conta != 0);
}
