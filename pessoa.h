#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void iniciarPs();
void cadastro();
int alterarPessoa();
void excluirPessoa();
void listar();
void ordemAlfabeticaPessoa();
void listarPessoaCodigo();

int validaCodigo(int codigoh);
void libertandops();

#endif // PESSOA_H_INCLUDED
