#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "metro.h"

#define tempo 80
#define tempoCarregar 50
#define tam_car 6

void menu(int *op){

    printf("\n");
    printf("����������������������������������������������������������������������������������������������������");
    printf("����������������������������������������������������������������������������������������������������");
    printf("����������������������������������������������������������������������������������������������������");
    printf("����������������������������������������     M  E  N  U     ����������������������������������������");
    printf("����������������������������������������������������������������������������������������������������");
    printf("����������������������������������������������������������������������������������������������������");
    printf("�������������������������                                              �����������������������������");
    printf("�������������������������         [1] - CARREGAR METRO                 �����������������������������");
    printf("�������������������������                                              �����������������������������");
    printf("�������������������������         [2] - EXIBIR ESTACOES DE UMA LINHA   �����������������������������");
    printf("�������������������������                                              �����������������������������");
    printf("�������������������������         [3] - VERIFICAR ESTACAO EM UMA LINHA �����������������������������");
    printf("�������������������������                                              �����������������������������");
    printf("�������������������������         [4] - EXIBIR DADOS DO METRO          �����������������������������");
    printf("�������������������������                                              �����������������������������");
    printf("�������������������������         [5] - EXIBIR ESTACAO EM UMA POSICAO  �����������������������������");
    printf("�������������������������                                              �����������������������������");
    printf("�������������������������         [6] - ADICIONAR ESTACAO NO FIM       �����������������������������");
    printf("�������������������������                                              �����������������������������");
    printf("�������������������������         [7] - ADICIONAR ESTACAO NO INICIO    �����������������������������");
    printf("�������������������������                                              �����������������������������");
    printf("�������������������������         [8] - GRAVAR METRO                   �����������������������������");
    printf("�������������������������                                              �����������������������������");
    printf("�������������������������         [0] - SAIR                           �����������������������������");
    printf("�������������������������                                              �����������������������������");
    printf("����������������������������������������������������������������������������������������������������");
    printf("������������������������������������������������������������������������������   Version 1.0   �����");
    printf("����������������������������������������������������������������������������������������������������");

    printf("OPCAO:");
    scanf("%i", op);
}

Lista inicLista(){

    Lista p;

    p = (Lista) malloc(sizeof(struct TLista));

    if(p == NULL){

        printf("Erro ao criar lista!");
        exit(1);
    }

    p->iterador = NULL;
    p->primeiro = NULL;
    p->ultimo = NULL;
    p->longitude = 0;


    return p;
}

void carregarLinhas(Lista vet[], int tam){

    FILE *arquivo;
    int i, x;
    char caractere, aux[50];

    arquivo = fopen("entrada.txt", "r");

    if(arquivo == 0){
        printf("Erro ao abrir arquivo");
        fclose(arquivo);
        exit(1);
    }else{
        // PULA A PRIMEIRA LINHA DO ARQUIVO
        caractere = getc(arquivo);
        caractere = getc(arquivo);
        i = 0;
        x = 0;

            do{

                caractere = getc(arquivo);

                if(caractere != ' ' && caractere != '\n'){
                    aux[i] = caractere;
                    i++;
                }
                if(caractere ==  ' '){
                    aux[i] = '\0';
                    adicionaNoFim(vet[x], aux);
                    i = 0;
                }
                if(caractere == '\n'){
                    aux[i] = '\0';
                    adicionaNoFim(vet[x], aux);
                    x++;
                    i = 0;
                }

            }while(caractere != EOF);
            aux[i] = '\0';
            adicionaNoFim(vet[x], aux);

        fclose(arquivo);

    }

}

void lerQtdLinhas(int *qtd){

    FILE *arquivo;
    int i, qtd_aux;
    char caractere, aux[10];

    arquivo = fopen("entrada.txt", "r");

    if(arquivo == 0){
        printf("Erro ao abrir arquivo");
        fclose(arquivo);
        exit(1);
    }else{
        i = 0;

        do{
            caractere = getc(arquivo);

            if(caractere != '\n' && caractere != EOF){
                aux[i] = caractere;
                i++;
            }else{
                aux[i] = '\0';
                qtd_aux = atoi(aux);
                *qtd = qtd_aux;
            }
        }while(caractere != '\n');
        fclose(arquivo);
    }

}

void adicionaNoFim(Lista lst, char vet[]){

    pListaNo novoNo;

    novoNo = (pListaNo) malloc(sizeof(struct ListaNo));

    novoNo->ant = NULL;
    novoNo->prox = NULL;
    strcpy(novoNo->nomeEstacao, vet);

    if(lst->longitude == 0){

        lst->iterador = novoNo;
        lst->primeiro = novoNo;
        lst->ultimo = novoNo;
        lst->longitude++;

    }else{

        novoNo->ant = lst->ultimo;
        lst->ultimo->prox = novoNo;
        lst->ultimo = novoNo;
        lst->iterador = novoNo;
        lst->longitude++;
    }

}

void adicionaNoInicio(Lista lst, char vet[]){

    pListaNo novoNo;

    novoNo = (pListaNo) malloc(sizeof(struct ListaNo));

    novoNo->ant = NULL;
    novoNo->prox = NULL;
    strcpy(novoNo->nomeEstacao, vet);

    if(lst->longitude == 0){

        lst->iterador = novoNo;
        lst->primeiro = novoNo;
        lst->ultimo = novoNo;
        lst->longitude++;

    }else{

        novoNo->prox = lst->primeiro;
        lst->primeiro->ant = novoNo;
        lst->primeiro = novoNo;
        lst->iterador = novoNo;
        lst->longitude++;

    }

}

void exibirLista(Lista lst){

	pListaNo aux;
    int i;

    if(lst == NULL){

        printf("Lista Vazia!\n");

    }else{
    i = 0;

    printf("\t");
    for(aux = lst->primeiro; i < lst->longitude; aux = aux->prox){
        printf("%s ", aux->nomeEstacao);
        i++;
        }
    }

}

int verificarEstacao(Lista lst, char vet[]){

    pListaNo aux;
    int i, teste = 0;
    i = 0;

    for(aux = lst->primeiro; i < lst->longitude; aux = aux->prox){

        if(strcmp(aux->nomeEstacao, vet)){

        }else{
            teste = 1;
        }
        i++;
    }

    return teste;
}


int quantidadeDeEstacoes(Lista lst){

    pListaNo aux;
    int i, contador = 0, x;

    if(lst == NULL){

        printf("Lista Vazia!\n");

    }else{
    i = 0;

    for(aux = lst->primeiro; i < lst->longitude; aux = aux->prox){
        contador++;
        i++;
        }
    }

    return contador;
}

void exibeElemNaPosicao(Lista lst, int pos){

    pListaNo aux;
    int i;

    if(lst == NULL){
        printf("Linha nao iniciada!");

    }else if(pos > lst->longitude){
        printf("Posicao nao existe");
    }else{
        i = 0;
        for(aux = lst->primeiro; i < (pos-1); aux = aux->prox){

            i++;
        }
        printf("Estacao na posicao escolhida: %s\n\n", aux->nomeEstacao);
    }
}

void apresentacao(void){

    int i, t;

    printf("����������������������������������������������������������������������������������������������������");
    printf("����������������������������������������������������������������������������������������������������");
    printf("���������������������������������������������������������  �����������������������������������������");
    printf("����������������������������������������������������������������������������������������������������");
    printf("�����������������������������������           ��������       ���������������������������������������");
    printf("�����������������������������������  �������  ����������   �����������������������������������������");
    printf("�����������������������������������  �������������������   �����������������������������������������");
    printf("�����������������������������������  �������������������   �����������������������������������������");
    printf("�����������������������������������           ����������   �����������������������������������������");
    printf("��������������������������������������������  ����������   �����������������������������������������");
    printf("��������������������������������������������  ����������   �����������������������������������������");
    printf("�����������������������������������  �������  ����������   �����������������������������������������");
    printf("�����������������������������������           ���  ���       ���������������������������������������");
    printf("����������������������������������������������������������������������������������������������������");
    printf("����������������������������������������������������������������������������������������������������");
    printf("����������������������������������������������������������������������������������������������������");
    printf("����������������������������������������������������������������������������������������������������");
    printf("����������������������������������������������������������������������������������������������������");
    printf("���������������������������      ");
    for(i=0; i<1; i++){
        printf("M "); Sleep(tempo); printf("E "); Sleep(tempo); printf("T "); Sleep(tempo); printf("R "); Sleep(tempo);
        printf("O "); Sleep(tempo); printf("L "); Sleep(tempo); printf("A "); Sleep(tempo); printf("N "); Sleep(tempo);
        printf("D "); Sleep(tempo); printf("I ");  Sleep(tempo); printf("A ");  Sleep(tempo); printf(" ");  Sleep(tempo);
        printf(" "); Sleep(tempo); printf(" "); Sleep(tempo); printf(" "); Sleep(tempo); printf(" ");  Sleep(tempo);
        printf(" ");  Sleep(tempo); printf(" ");  Sleep(tempo);
        printf("1 "); Sleep(tempo); printf(". "); Sleep(tempo); printf("0      "); Sleep(tempo);
    }
    printf("����������������������������������������������������������������������������������������������������");
    printf("����������������������������������������������������������������������������������������������������");
    printf("����������������������������������������������������������������������������������������������������");
    printf("���������������������������");
    printf("\n\n\n\n");
    printf("\t\t\t");
    printf("                     AGUARDE...\n");
    printf("\n");
    printf("\t");
    for(i=0; i<40; i++){
        printf("��");
        Sleep(tempoCarregar);
    }
    Sleep(1000);

    for(t=0; t<3; t++){
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t");
        printf("  CARREGANDO");

        for(i=0; i<1; i++){

        printf("."); Sleep(100); printf(".");
        Sleep(100);  printf("."); Sleep(100);
        printf("."); Sleep(100);

        }
    }Sleep(500);
    system("cls");
}
