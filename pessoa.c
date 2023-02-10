#include "pet.h"
#define TAM 30
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int codigo;
char cpfavalidar[50];

FILE *f = NULL;

struct pesssoas {
    char nnomes[255];
    char rrg[50];
    char ccpf[20];
    char eendereco[255];
    char nnascimento[50];
    char rrendimento[50];
    char codigoPPessoa[15];
    char llivres;
};

struct registrandopessoa {
    struct pesssoas *pss;
};

struct registrandopessoa registrinho[TAM];

void arquivopessoa() {
    f = fopen("arquivopessoa.bin", "rb+");
    if (f == NULL) {
        f = fopen("arquivopessoa.bin", "wb+");
        if (f == NULL) {
            printf("não abriu! :(\n");
        }
    }
}

void iniciarPs()
{
    arquivopessoa();
    int i = 0;
    for(i;i<TAM;i++) {
        registrinho[i].pss = malloc(sizeof(struct pesssoas));
    }
    i = 0;

    for(int j = 0; j<TAM; j++) {
        registrinho[j].pss->llivres = '0';
    }
    while(!feof(f))//ENQUANTO NÃO FOR O FIM DO ARQUIVO
    {
        fread(registrinho[i].pss,sizeof(struct pesssoas),1,f);
        i++;
        if(feof(f)) break;
    }
    fclose(f);
}

int gerarCodigos(){
    srand(time(NULL));
    // gerando valores aleatorios na faixa de 0 a 10000000
    int code;
    code = rand() % 10000000;

    while(1){

        for(int i = 0; i<TAM; i++){
            int valida = atoi(registrinho[i].pss->codigoPPessoa);
            if(code == valida){
                code = rand() % 10000000;
            }
            else{
                return code;
            }
        }
    }
}

int validaCodigo(int codigoh)
{
        char codigoverifica[15];
        sprintf(codigoverifica, "%d", codigoh);
        for(int i = 0; i < TAM; i++)
        {
            if (strcmp(registrinho[i].pss->codigoPPessoa,codigoverifica) == 0)  return 1;
        }
    return 2;
}

int validaCPF(){

    if (cpfavalidar[3] != '.' || cpfavalidar[7] != '.' || cpfavalidar[11] != '-')
        return 1;

    for(int i = 0; i< TAM; i++){
        if((strcmp(registrinho[i].pss->ccpf,cpfavalidar) == 0) || (strcmp("",cpfavalidar) == 0)){
            return 1;
        }
    }
    return 2;
}

void ordemAlfabeticaPessoa(){

    int i, j, h;
    char str[TAM][255];
    char s[100];

    for(h = 0; h < TAM; h++) {
        strcpy(str[h],registrinho[h].pss->nnomes);
    }

    for(i=0;i<TAM;i++){
        for(j=i+1;j<TAM;j++){
            if(strcmp(str[i],str[j])>0){
                strcpy(s,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],s);
            }
        }
    }


    for(int a = 0; a< TAM; a++){
        for(int b = 0; b< TAM; b++){
            if(registrinho[b].pss->llivres == '0'){continue;};
            if (strcmp(str[a] , registrinho[b].pss->nnomes) == 0){
                printf("[Codigo: %s]\n", registrinho[b].pss->codigoPPessoa);
                printf("[Nome: %s]\n", registrinho[b].pss->nnomes);
                printf("[Rg: %s]\n", registrinho[b].pss->rrg);
                printf("[Cpf: %s]\n", registrinho[b].pss->ccpf);
                printf("[Endereco: %s]\n", registrinho[b].pss->eendereco);
                printf("[Nascimento: %s]\n", registrinho[b].pss->nnascimento);
                printf("[Rendimento mensal: %s]\n", registrinho[b].pss->rrendimento);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            }
        }
    }
}


void excluirPessoa(){

    int codigopessoaaremover;
    FILE *excluindohaha = fopen("arquivopessoa.bin", "rb+");
    char x[10] = "null";

    printf("Digite o codigo da pessoa que deseja excluir\n");
    scanf("%d", &codigopessoaaremover);

    for (int i = 0; i < TAM; i++) {
        int codigodaora = atoi(registrinho[i].pss->codigoPPessoa);
        if (codigopessoaaremover == codigodaora) {
           printf("############ EXCLUINDO PESSOA ###############\n");
           strcpy(registrinho[i].pss->codigoPPessoa, x);
           strcpy(registrinho[i].pss->nnomes,x);
           strcpy(registrinho[i].pss->rrg, x);
           strcpy(registrinho[i].pss->eendereco,x);
           strcpy(registrinho[i].pss->nnascimento,x);
           strcpy(registrinho[i].pss->rrendimento,x);
           strcpy(registrinho[i].pss->ccpf,x);
           registrinho[i].pss->llivres = '0';
           free(registrinho[i].pss);
           for (int j = 0; j<i; j++) {
               fseek(excluindohaha, sizeof(struct pesssoas), SEEK_SET);
           }
           fwrite(registrinho[i].pss, sizeof(struct pesssoas), 1, excluindohaha);
        }
    }

        excluirPessoaePet(codigopessoaaremover, x);
        fclose(excluindohaha);
        printf("Excluido com sucesso\n");

}

void listar()
{
    printf("############ LISTA DE NOMES ###############\n");

    for (int i = 0; i < TAM; ++i) {
        if(registrinho[i].pss->llivres == '1'){
            printf("[Codigo: %s]\n", registrinho[i].pss->codigoPPessoa);
            printf("[Nome: %s]\n", registrinho[i].pss->nnomes);
            printf("[Rg: %s]\n", registrinho[i].pss->rrg);
            printf("[Cpf: %s]\n", registrinho[i].pss->ccpf);
            printf("[Endereco: %s]\n", registrinho[i].pss->eendereco);
            printf("[Nascimento: %s]\n", registrinho[i].pss->nnascimento);
            printf("[Rendimento mensal: %s]\n", registrinho[i].pss->rrendimento);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
    }
    printf("###########################################\n");
}

int alterarPessoa(){

    FILE *alterando = fopen("arquivopessoa.bin", "rb+");
    printf("\nDigite o codigo da pessoa na qual gostaria de alterar: ");
    scanf("%d", &codigo);

    int validacao = validaCodigo(codigo);

    if (validacao != 1){
        printf("Esse codigo nao existe, por favor ensira um codigo valido\n");
        return 0;
    }

    char codigocoisado[15];
    sprintf(codigocoisado, "%d", codigo);

    for(int i = 0; i < TAM; i++){
        if(strcmp(codigocoisado, registrinho[i].pss->codigoPPessoa) == 0){

            printf("[Codigo: %s]\n", registrinho[i].pss->codigoPPessoa);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


            getchar();
            printf("[Nome Anterior: %s]", registrinho[i].pss->nnomes);
            printf("\nNovo nome: ");
            fflush(stdin);
            gets(registrinho[i].pss->nnomes);

            printf("[Rg Anterior: %s]\n", registrinho[i].pss->rrg);
            printf("\nNovo rg: ");
            fflush(stdin);
            gets(registrinho[i].pss->rrg);

            printf("[Cpf Anterior: %s]", registrinho[i].pss->ccpf);
            printf("\nNovo cpf: ");
            fflush(stdin);
            gets(registrinho[i].pss->ccpf);

            printf("[Endereco Anterior: %s]", registrinho[i].pss->eendereco);
            printf("\nNovo endereco: ");
            fflush(stdin);
            gets(registrinho[i].pss->eendereco);

            printf("[Data de Nascimento Anterior: %s]", registrinho[i].pss->nnascimento);
            printf("\nNova data de nascimento: ");
            fflush(stdin);
            gets(registrinho[i].pss->nnascimento);

            printf("[Rendimento Mensal Anterior: %s]", registrinho[i].pss->rrendimento);
            printf("\nNovo rendimento mensal: ");
            fflush(stdin);
            gets(registrinho[i].pss->rrendimento);


            printf("Cadastro Alterado com Sucesso\n");
            for (int j = 0; j<i; j++) {
                fseek(alterando, sizeof(struct pesssoas), SEEK_SET);
            }
            fwrite(registrinho[i].pss, sizeof(struct pesssoas), 1, alterando);
        }
    }
    fclose(alterando);
    return 1;

}

void listarPessoaCodigo()
{
    int codigoP;

    printf("Digite o seu codigo: \n");
    scanf("%d", &codigoP);

    char hahahhaa[15];
    sprintf(hahahhaa, "%d", codigoP);
    for (int i = 0; i < TAM; ++i)
    {
        if(registrinho[i].pss->llivres == '1'){
            if (strcmp(hahahhaa, registrinho[i].pss->codigoPPessoa) == 0) {
                printf("############ Pessoa ###############\n");
                printf("[Codigo: %s]\n", registrinho[i].pss->codigoPPessoa);
                printf("[Nome: %s]\n", registrinho[i].pss->nnomes);
                printf("[cpf: %s]\n", registrinho[i].pss->ccpf);
                printf("[RG: %s]\n", registrinho[i].pss->rrg);
                printf("[Data nascimento: %s]\n", registrinho[i].pss->nnascimento);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            }
        }
    }
}

void cadastro()
{
    for(int i=0; i<TAM; i++) {
        if(registrinho[i].pss->llivres == '0'){
            arquivopessoa();

            getchar();
            printf("\nDigite da forma adequada com os . e o - na posicao correta.");
            printf("\n*Obrigatorio* | Digite seu cpf: ");
            gets(cpfavalidar);

            int response = validaCPF();

            if(response == 1){
                printf("CPF invalido, tente novamente\n");
                return;
            }

            do {
                printf("\n*Obrigatorio* | Digite seu nome: ");
                fflush(stdin);
                gets(registrinho[i].pss->nnomes);
            }   while (strcmp(registrinho[i].pss->nnomes, "") == 0);

            printf("\nDigite seu rg: ");
            fflush(stdin);
            gets(registrinho[i].pss->rrg);

            printf("\nDigite seu endereco: ");
            fflush(stdin);
            gets(registrinho[i].pss->eendereco);

            do {
                printf("\n*Obrigatorio* | Digite sua data de nascimento no formato DD/MM/AAAA: ");
                fflush(stdin);
                gets(registrinho[i].pss->nnascimento);
            }   while (strcmp(registrinho[i].pss->nnascimento, "") == 0 || (registrinho[i].pss->nnascimento[2]) != '/' || (registrinho[i].pss->nnascimento[5] != '/'));

            printf("\nDigite seu rendimento mensal: ");
            fflush(stdin);
            gets(registrinho[i].pss->rrendimento);

            int eae = gerarCodigos();
            sprintf(registrinho[i].pss->codigoPPessoa, "%d", eae);
            strcpy(registrinho[i].pss->ccpf, cpfavalidar);

            fflush(stdin);
            printf("\n***************************************\n");
            printf("SEU CODIGO UNICO NO SISTEMA EH: %s\n", registrinho[i].pss->codigoPPessoa);
            printf("***************************************\n");
            registrinho[i].pss->llivres = '1';
            fseek(f, 0, SEEK_END);
            fwrite(registrinho[i].pss, sizeof(struct pesssoas), 1, f);
            fclose(f);
            break;
        }
    }
}

void libertandops() {
    for(int i = 0; i<TAM; i++) {
        free(registrinho[i].pss);
    }
}