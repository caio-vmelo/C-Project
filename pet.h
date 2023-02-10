#ifndef PET_H_INCLUDED
#define PET_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void iniciarPt();
int cadastrar_pet();
int alteraPet();
void listarPetCodigo();
void listarTodosPetsdoDono();
void ordemAlfabeticaPet();
void excluirPet();
void listarTipoPet();

void excluirPessoaePet(int ccodigopessoaaremover, char xx[10]);
void libertandopt();

#endif // PET_H_INCLUDED
