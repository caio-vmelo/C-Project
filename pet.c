#include "pessoa.h"
#define TAM 30
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


FILE *ff = NULL;

struct pet {
    char ppetNomes[255];
    char petCcodigo[15];
    char ppetTipo[50];
    char ppetDataNascimento[50];
    char petCcodigoPessoa[15];
    char llivresPet;
};

struct registrarpeti {
    struct pet *ppeett;
};

struct registrarpeti ptt[TAM];

void arquivopet() {
    ff = fopen("arquivopet.bin", "rb+");
    if (ff == NULL) {
        ff = fopen("arquivopet.bin", "wb+");
        if (ff == NULL) {
            printf("não abriu! :(\n");
        }
    }
}

void iniciarPt()
{
    arquivopet();
    for (int i = 0; i < TAM; ++i)
    {
        ptt[i].ppeett = malloc(sizeof(struct pet));
        ptt[i].ppeett->llivresPet = '0';
    }
    int j = 0;
    while(!feof(ff))//ENQUANTO NÃO FOR O FIM DO ARQUIVO
    {
        fread(ptt[j].ppeett,sizeof(struct pet),1,ff);
        j++;
        if(feof(ff)) break;
    }
    fclose(ff);
}

void excluirPessoaePet(int ccodigopessoaaremover, char xx[10]) {
    char codigodaoraremove[15];
    sprintf(codigodaoraremove, "%d", ccodigopessoaaremover);
    for(int j = 0; j < TAM; ++j){
        if (strcmp(codigodaoraremove, ptt[j].ppeett->petCcodigoPessoa) == 0) {
            printf("############ EXCLUINDO OS PETS DO SISTEMA ###############\n");
            strcpy(ptt[j].ppeett->petCcodigoPessoa, xx);
            strcpy(ptt[j].ppeett->ppetNomes, xx);
            strcpy(ptt[j].ppeett->petCcodigo, 0);
            strcpy(ptt[j].ppeett->ppetTipo, xx);
            strcpy(ptt[j].ppeett->ppetDataNascimento, xx);
            ptt[j].ppeett->llivresPet = '0';
            free(ptt[j].ppeett);
        }
    }
}

void listarTodosPetsdoDono(){

    int codigodaPessoa;

    printf("Digite o codigo da pessoa.\n");
    scanf("%d", &codigodaPessoa);

    printf("############ OS PETS DESSA PESSOA SAO###############\n");
    char cellbit[15];
    sprintf(cellbit, "%d", codigodaPessoa);
    for(int i = 0; i < TAM ; i++){
        if (strcmp(cellbit, ptt[i].ppeett->petCcodigoPessoa) == 0) {
            printf("[Codigo do dono do pet: %s]\n", ptt[i].ppeett->petCcodigoPessoa);
            printf("[Nome no pet: %s]\n", ptt[i].ppeett->ppetNomes);
            printf("[codigo do pet: %s]\n", ptt[i].ppeett->petCcodigo);
            printf("[tipo pet: %s]\n", ptt[i].ppeett->ppetTipo);
            printf("[Data nascimento pet: %s]\n", ptt[i].ppeett->ppetDataNascimento);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
    }
}

int gerarCodigosPet(){
    srand(time(NULL));
    // gerando valores aleatorios na faixa de 0 a 10000000
    int code;
    code = rand() % 10000000;

    while(1){

        for(int i = 0; i<TAM; i++){
            int valida = atoi(ptt[i].ppeett->petCcodigo);
            if(code == valida){
                code = rand() % 10000000;
            }
            else{
                return code;
            }
        }
    }
}

int validaNomePet(int codigopp, char petnomevalidar[])
{
    char seila[15];
    sprintf(seila, "%d", codigopp);
    for(int i = 0; i < TAM; i++){
        if((strcmp(ptt[i].ppeett->ppetNomes, petnomevalidar) == 0) && (strcmp(ptt[i].ppeett->petCcodigoPessoa, seila) == 0)) {
            return 1;
        }
    }
    return 2;
}

void listarPetCodigo(){
    int codigodopet;

    printf("Digite o codigo do seu pet\n");
    scanf("%d", &codigodopet);
    char aruhieienmitaini[15];
    sprintf(aruhieienmitaini, "%d", codigodopet);

    for (int i = 0; i < TAM; ++i) {
        if(ptt[i].ppeett->llivresPet == '1'){
            if (strcmp(aruhieienmitaini, ptt[i].ppeett->petCcodigo) == 0) {
                printf("############ PET ###############\n");
                printf("[Codigo do dono do pet: %s]\n", ptt[i].ppeett->petCcodigoPessoa);
                printf("[Nome no pet: %s]\n", ptt[i].ppeett->ppetNomes);
                printf("[codigo do pet: %s]\n", ptt[i].ppeett->petCcodigo);
                printf("[tipo pet: %s]\n", ptt[i].ppeett->ppetTipo);
                printf("[Data nascimento pet: %s]\n", ptt[i].ppeett->ppetDataNascimento);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            }
        }
    }

}

int validaCodigoPet(int codigop)
{
    char codigoverifica[15];
    sprintf(codigoverifica, "%d", codigop);
    for(int i = 0; i < TAM; i++)
    {
        if (strcmp(ptt[i].ppeett->petCcodigo,codigoverifica) == 0)
        {
            return 1;
        }
    }
    return 2;
}

int alteraPet()
{
    int codigoUnicoPet;
    FILE *alterandopet = fopen("arquivopet.bin", "rb+");
    printf("\nDigite o codigo do pet no qual gostaria de alterar: ");
    scanf("%d", &codigoUnicoPet);

    int validacao = validaCodigoPet(codigoUnicoPet);

    if (validacao != 1)
    {
        printf("Esse codigo nao existe, por favor ensira um codigo valido\n");
        return 0;
    }

    char coisinhahaha[15];
    sprintf(coisinhahaha, "%d", codigoUnicoPet);
    for(int i = 0; i < TAM; i++)
    {
        if(strcmp(coisinhahaha, ptt[i].ppeett->petCcodigo) == 0)
        {
            printf("[Codigo: %s]\n", ptt[i].ppeett->petCcodigo);
            printf("~~~~~~~~~~~\n");


            getchar();
            printf("[Nome Anterior: %s]\n", ptt[i].ppeett->ppetNomes);
            printf("\nNovo nome: ");
            fflush(stdin);
            gets(ptt[i].ppeett->ppetNomes);

            printf("[Data de nascimento anterior: %s]\n", ptt[i].ppeett->ppetDataNascimento);
            printf("\nNova data de nascimento: ");
            fflush(stdin);
            gets(ptt[i].ppeett->ppetDataNascimento);


            printf("Cadastro Alterado com Sucesso\n");
            for (int j = 0; j<i; j++) {
                fseek(alterandopet, sizeof(struct pet), SEEK_SET);
            }
            fwrite(ptt[i].ppeett, sizeof(struct pet), 1, alterandopet);
        }
    }
    fclose(alterandopet);
    return 1;
}

int cadastrar_pet()
{
    char nomepetavalidar[50];
    int codigo;
    printf("Digite seu codigo: \n");
    arquivopet();

    scanf("%d", &codigo);

    int validacao = validaCodigo(codigo);

    if (validacao != 1)
    {
        printf("Esse codigo nao existe, por favor ensira um codigo valido\n");
        return 0;
    }

    int codigoUnicoPet = gerarCodigosPet();

    for(int i=0; i<TAM; i++){
        if(ptt[i].ppeett->llivresPet == '0')
        {

                do{
                    getchar();
                    printf("\nNome do pet: ");
                    fflush(stdin);
                    gets(nomepetavalidar);
                }   while(strcmp(nomepetavalidar, "") == 0);

                int response = validaNomePet(codigo, nomepetavalidar);

                if(response == 1)
                {
                    printf("Voce ja tem um pet com esse nome\n");
                    return 0;
                }

                do{
                    printf("\nDigite o tipo do seu PET(Cao/gato/cobra/passarinho)");
                    fflush(stdin);
                    gets(ptt[i].ppeett->ppetTipo);
                }   while(strcmp(ptt[i].ppeett->ppetTipo, "") == 0);

                do{
                    printf("\nData de nascimento do pet: ");
                    fflush(stdin);
                    gets(ptt[i].ppeett->ppetDataNascimento);
                }   while(strcmp(ptt[i].ppeett->ppetDataNascimento, "") == 0);


                printf("\n O codigo unico desse pet eh %d\n", codigoUnicoPet);
                char clion[15];
                sprintf(clion, "%d", codigoUnicoPet);
                strcpy(ptt[i].ppeett->petCcodigo, clion);
                strcpy(ptt[i].ppeett->ppetNomes,nomepetavalidar);
                char euvenhoempaz[15];
                sprintf(euvenhoempaz, "%d", codigo);
                strcpy(ptt[i].ppeett->petCcodigoPessoa, euvenhoempaz);
                ptt[i].ppeett->llivresPet = '1';
                fseek(ff, 0, SEEK_END);
                fwrite(ptt[i].ppeett, sizeof(struct pet), 1, ff);
                fclose(ff);

            printf("~~~~~~~~~~~\n");
            break;
        }
    }
    return 1;
}

void excluirPet()
{

    int codigodopet;
    FILE *acabeidetomarbanho = fopen("arquivopet.bin", "rb+");
    char x[10] = "null";
    printf("Digite o codigo do pet que deseja excluir\n");
    scanf("%d", &codigodopet);
    char givemesomemore[15];
    sprintf(givemesomemore, "%d", codigodopet);

    for (int i = 0; i < TAM; ++i) {

            if (strcmp(givemesomemore, ptt[i].ppeett->petCcodigo) == 0) {
                printf("############ EXCLUINDO PET ###############\n");
                strcpy(ptt[i].ppeett->petCcodigoPessoa, x);
                strcpy(ptt[i].ppeett->ppetNomes,x);
                strcpy(ptt[i].ppeett->petCcodigo, x);
                strcpy(ptt[i].ppeett->ppetTipo,x);
                strcpy(ptt[i].ppeett->ppetDataNascimento,x);
                ptt[i].ppeett->llivresPet = '0';
                for (int j = 0; j<i; j++) {
                    fseek(acabeidetomarbanho, sizeof(struct pet), SEEK_SET);
                }
                fwrite(ptt[i].ppeett, sizeof(struct pet), 1, acabeidetomarbanho);
                printf("Excluido com sucesso\n");
                free(ptt[i].ppeett);
            }
    }
    fclose(acabeidetomarbanho);
}

void ordemAlfabeticaPet()
{
    int i, j;
    int h;
    char str[TAM][255];
    char s[100];

    for(h = 0; h < TAM; h++) {
        strcpy(str[h], ptt[h].ppeett->ppetNomes);
    }

    for(i = 0; i < TAM; i++){
        for(j = i + 1; j < TAM; j++){
            if(strcmp(str[i], str[j]) > 0){
                strcpy(s, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], s);
            }
        }
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for(int a = 0; a < TAM; a++){
        for(int b = 0; b < TAM; b++){
            if(ptt[b].ppeett->llivresPet == '0'){continue;}
            if (strcmp(str[a] , ptt[b].ppeett->ppetNomes) == 0)
            {
                printf("[Nome do dono do Pet: %s]\n", ptt[b].ppeett->petCcodigoPessoa);
                printf("[Nome do Pet: %s]\n", ptt[b].ppeett->ppetNomes);
                printf("[Nascimento: %s]\n", ptt[b].ppeett->ppetDataNascimento);
                printf("[Tipo do Pet: %s]\n", ptt[b].ppeett->ppetTipo);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            }
        }
    }
}

void listarTipoPet()
{
    char tipo_pet[TAM];
    getchar();
    printf("Digite o tipo do pet:\n");
    fflush(stdin);
    gets(tipo_pet);

    for(int i = 0; i < TAM; i++)
    {
        if(strcmp(tipo_pet, ptt[i].ppeett->ppetTipo) == 0)
        {
            printf("[Codigo do dono do pet: %s]\n", ptt[i].ppeett->petCcodigoPessoa);
            printf("[Nome do pet: %s]\n", ptt[i].ppeett->ppetNomes);
            printf("[Tipo do pet: %s]\n", ptt[i].ppeett->ppetTipo);
            printf("[Codigo do pet: %s]\n", ptt[i].ppeett->petCcodigo);
            printf("~~~~~~~~~~~\n");
        }
    }
}

void libertandopt() {
    for(int i = 0; i<TAM; i++) {
        free(ptt[i].ppeett);
    }
}