#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "metro.h"



int main()
{
    system("mode con:cols=100 lines=40");
    system("color F0");

    int quantidade;
    lerQtdLinhas(&quantidade);
    FILE *arquivo;
    pListaNo aux;

    Lista linhas[quantidade];
    int opcao, i, linha, totalEstacoes = 0, posicao, x;
    char nome[50];




    //int qtsLinhas[quantidade];
    apresentacao();
    do{
        printf("Quantidade de linhas: %i\n", quantidade);
        menu(&opcao);

        switch(opcao){

            case 1:
                system("cls");

                printf("\n\n");
                printf("\t\t\t\tLinha Carregada com sucesso!\n\n");

                for(i = 0; i < quantidade; i++){
                    linhas[i] = inicLista();
                }
                carregarLinhas(linhas, quantidade);

                for(i = 0; i < quantidade; i++){
                    printf("LINHA %i: ", i+1);
                    exibirLista(linhas[i]);
                    printf("\n");
                }

                printf("\n\n OBS: inicLista() Utilizada!!!\n");
                printf("\n\n OBS: adicionaNoFim(Lista lst, char vet[]) Utilizada!!!\n\n\n");


                printf("\n");
                system("pause");
                system("cls");

                break;
            case 2:

                do{
                    system("cls");
                    printf("Digite a linha: ");
                    scanf("%i", &linha);
                    exibirLista(linhas[linha-1]);
                    printf("\n");
                    system("pause");

                if(linha <=0 && linha >= quantidade){
                    printf("Linha ao existe!");
                    system("cls");
                }

                }while(linha <=1 && linha > quantidade);

                break;
            case 3:
                    system("cls");
                    printf("Digite a linha: ");
                    scanf("%i", &linha);

                    printf("Digite a estacao: ");
                    scanf(" %[^\n]", nome);

                    printf("\n");
                    if(verificarEstacao(linhas[linha-1], nome)){
                        printf("Estacao encontrada!");
                    }else{
                        printf("Estacao nao encontrada");
                    }
                    printf("\n");
                    system("pause");

                break;

            case 4:
                system("cls");

                printf("\n\t\t============== INFORMACOES GERAIS DO METRO ==================\n\n\n\n");

                for(i = 0; i < quantidade; i++){
                    totalEstacoes += quantidadeDeEstacoes(linhas[i]);
                }
                printf("Quantidade de estacoes: %i \n\n", totalEstacoes);
                printf("Quantidade de Linhas: %i\n\n\n", quantidade);

                totalEstacoes = 0;
                for(i = 0; i < quantidade; i++){
                    totalEstacoes = quantidadeDeEstacoes(linhas[i]);
                    printf("\t\t\t QUANTIDADE DE ESTACAOES NA LINHA %i: %i\n", i+1, totalEstacoes);
                }

                printf("\n\n\t\t====================== LINHAS EM GERAL ===========================\n\n\n");

                for(i = 0; i < quantidade; i++){
                    printf("LINHA %i: ", i+1);
                    exibirLista(linhas[i]);
                    printf("\n");
                }
                printf("\n\n\n");
                printf("OBS. exibirLista(Lista lst) Utilizada!!!");

                printf("\n\n");
                system("pause");
                system("cls");
                break;

            case 5:
                system("cls");

                do{
                    system("cls");
                    printf("Digite a linha: ");
                    scanf("%i", &linha);

                if(linha <=0 && linha >= quantidade){
                    printf("Linha nao existe!");
                    system("cls");
                }

                }while(linha <=1 && linha > quantidade);

                do{
                    printf("Digite a posicao: ");
                    scanf("%i", &posicao);

                    if(posicao > linhas[linha-1]->longitude){
                        printf("Posicao nao existeee\n");
                        printf("TAM %i\n", linhas[linha-1]->longitude);
                    }
                }while(posicao > linhas[linha-1]->longitude);

                exibeElemNaPosicao(linhas[linha-1], posicao);
                printf("\n\n\n");
                printf("OBS. exibeElemNaPosicao(Lista lst, int pos) Utilizada!!!\n\n");
                system("pause");
                system("cls");
                break;

            case 6:
                system("cls");

                do{
                    system("cls");
                    printf("Digite a linha: ");
                    scanf("%i", &linha);

                if(linha <=0 && linha >= quantidade){
                    printf("Linha nao existe!");
                    system("cls");
                }

                }while(linha <=1 && linha > quantidade);
                printf("Digite o nome da estacao: ");
                scanf(" %[^\n]", nome);

                adicionaNoFim(linhas[linha-1], nome);
                printf("Estacao adicionada com sucesso\n\n\n\n");
                printf("\n\n OBS: adicionaNoFim(Lista lst, char vet[]) Utilizada!!!\n\n\n");
                system("pause");
                system("cls");

                break;

            case 7:
                system("cls");

                do{
                    system("cls");
                    printf("Digite a linha: ");
                    scanf("%i", &linha);

                if(linha <=0 && linha >= quantidade){
                    printf("Linha nao existe!");
                    system("cls");
                }

                }while(linha <=1 && linha > quantidade);
                printf("Digite o nome da estacao: ");
                scanf(" %[^\n]", nome);

                adicionaNoInicio(linhas[linha-1], nome);
                printf("Estacao adicionada com sucesso\n\n\n\n");
                printf("\n\n OBS: adicionaNoInicio(Lista lst, char vet[]) Utilizada!!!\n\n\n");
                system("pause");
                system("cls");
                break;

            case 8:
                system("cls");

                arquivo = fopen("entrada.txt", "w");
                if(arquivo == 0){
                    printf("Erro o abrir arquivo!\n");
                    fclose(arquivo);
                    exit(1);
                }else{

                    fprintf(arquivo,"%i\n", quantidade);

                    for(x = 0; x < quantidade; x++){
                        i = 0;

                        for(aux = linhas[x]->primeiro; i < linhas[x]->longitude; aux = aux->prox){
                            fprintf(arquivo,"%s", aux->nomeEstacao);
                            if((i+1) != linhas[x]->longitude){
                                fprintf(arquivo," ");
                            }

                            i++;
                        }
                        if((x+1) < quantidade){
                            fprintf(arquivo,"\n");
                        }

                    }

                }
                fclose(arquivo);

                printf("\n\n\t\t\tMetro Gravado com sucesso!!!\n\n\n\n");

                system("pause");
                system("cls");

                break;

            default:

                if(opcao != 0){
                    printf("OPCAO INVALIDA!!!\n\n");
                    Sleep(1500);
                    system("cls");
                }

        }

    }while(opcao != 0);

    printf("BYE BYE!\n");
    return 0;
}
