#include <stdio.h>
#include "pessoa.h"
#include "pet.h"

enum escolha {cadastrar_pessoa = 1, alterar_pessoa = 2, remover_pessoa = 3, listar_pessoas = 4, listar_pessoas_alfabeticamente = 5, listar_pessoas_porcodigo = 6,
    cadastrar_pets = 7, alterar_pets = 8, listar_porcodigo_pets = 9, listar_pets_porcodigo_dapessoa = 10, listaralfapet = 11,
    remover_pets = 12, listar_portipo_pets = 13, encerrar = 14} n;

int main()
{
    iniciarPs();
    iniciarPt();

    do {
        printf("\n______PESSOA______");
        printf("\nO que voce gostaria de fazer?");
        printf("\nDigite 1 para: Cadastrar uma pessoa");
        printf("\nDigite 2 para: Alterar uma pessoa");
        printf("\nDigite 3 para: Remover uma pessoa");
        printf("\nDigite 4 para: Listar todas as pessoas");
        printf("\nDigite 5 para: Listar todas as pessoas em ordem alfabetica");
        printf("\nDigite 6 para: Listar uma pessoa com base no codigo");
        printf("\n______PET______");
        printf("\nDigite 7 para:  Cadastrar um pet");
        printf("\nDigite 8 para:  Alterar um pet");
        printf("\nDigite 9 para:  Listar um pet com base no codigo do pet");
        printf("\nDigite 10 para: Listar um pet com base no codigo da pessoa");
        printf("\nDigite 11 para: Listar todos os pets em ordem alfabetica");
        printf("\nDigite 12 para: Remover PET");
        printf("\nDigite 13 para: Listar por tipo de pet");
        printf("\nDigite 14 para: Encerrar o programa");
        printf("\n");

        scanf("%d", &n);
        switch (n)
        {
            case cadastrar_pessoa:
                cadastro();
                break;

            case alterar_pessoa:
                alterarPessoa();
                break;

            case remover_pessoa:
                excluirPessoa();
                break;

            case listar_pessoas:
                listar();
                break;

            case listar_pessoas_alfabeticamente:
                ordemAlfabeticaPessoa();
                break;

            case listar_pessoas_porcodigo:
                listarPessoaCodigo();
                break;

            case cadastrar_pets:
                cadastrar_pet();
                break;

            case alterar_pets:
                alteraPet();
                break;

            case listar_porcodigo_pets:
                listarPetCodigo();
                break;

            case listar_pets_porcodigo_dapessoa:
                listarTodosPetsdoDono();
                break;

            case listaralfapet:
                ordemAlfabeticaPet();
                break;

            case remover_pets:
                excluirPet();
                break;

            case listar_portipo_pets:
                listarTipoPet();
                break;

            case encerrar:
                break;

            default:
                printf("Selecione uma opcao valida\n\n\n");
                break;
        }
    }   while(n != 14);
    libertandops();
    libertandopt();

    return 0;
}

