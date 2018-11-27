#ifndef MINHA_BIBLIOTECA
#define MINHA_BIBLIOTECA


typedef int TipoL;


//TAD LINHA
typedef struct ListaNo{

    char nomeEstacao[50];
    struct ListaNo *prox;
    struct ListaNo *ant;

}*pListaNo;

typedef struct TLista{

    pListaNo iterador, primeiro, ultimo;
    int longitude;

}*Lista;



void menu(int *op); // : TESTE

void lerQtdLinhas(int *qtd);

Lista inicLista();

void carregarLinhas(Lista vet[], int tam);

void adicionaNoFim(Lista lst, char vet[]);

void adicionaNoInicio(Lista lst, char vet[]);

void exibirLista(Lista lst);

int verificarEstacao(Lista lst, char vet[]);

int quantidadeDeEstacoes(Lista lst);

void exibeElemNaPosicao(Lista lst, int pos);

void apresentacao(void);

#endif // : TESTE
