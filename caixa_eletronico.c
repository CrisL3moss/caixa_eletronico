#include <stdio.h>
#include <stdlib.h>


void main(){

float saldo = 1000.00; 
float divida = 0.00;
float valor;
int opcao = -1;

// Menu do Caixa

while (opcao != 7){


  printf("---- CAIXA ELETRÔNICO ----\n");
  printf("\n 1- Verificar Saldo\n");
  printf(" 2- Depositar Valor\n");
  printf(" 3- Sacar Valor\n");
  printf(" 4- Pedir Empréstimo\n");
  printf(" 5- Consultar Empréstimo\n");
  printf(" 6- Pagar Empréstimo\n");
  printf(" 7- Sair\n");
  printf("-------------------------\n");
  printf("Escolha uma opção: ");
  scanf("%d", &opcao);

  //tela do saldo
      if (opcao == 1) {
            printf("  SALDO ATUAL\n");
            printf("\n  R$ %.2f\n", saldo);
        }
 
    //tela do depósito
        else if (opcao == 2) {
           
            printf("  DEPÓSITO\n");
            printf("  Informe o valor que deseja depositar: R$ ");
            scanf("%lf", &valor);
 
            if (valor > 0) {
                saldo = saldo + valor;
                printf("\n  Deposito realizado com sucesso!\n");
                printf("  Valor depositado : R$ %.2f\n", valor);
                printf("  Novo saldo: R$ %.2f\n", saldo);
            } else {
                printf("\n  Valor invalido! Digite um valor maior que zero para depositar.\n");
            }
          
        }
 
        // tela do saque
        else if (opcao == 3) {

            printf("  SAQUE\n");
            printf("  Informe o valor que deseja para sacar: R$ ");
            scanf("%lf", &valor);
 
            if (valor <= 0) {
                printf("\n  Valor invalido! Digite um valor maior que zero.\n");
            } else {
                if (valor > saldo) {
                    printf("\n  Saldo insuficiente!\n");
                    printf("  Saldo disponivel: R$ %.2f\n", saldo);
                } else {
                    saldo = saldo - valor;
                    printf("\n  Saque realizado com sucesso!\n");
                    printf("  Valor sacado : R$ %.2f\n", valor);
                    printf("  Novo saldo   : R$ %.2f\n", saldo);
                }
            }
        }
 
        //tela de emprestimo
        else if (opcao == 4) {

            printf("  EMPRESTIMO\n");
            
            if (emprestimo > 0)  { //Caso ja tenha um emprestimo pendente
                printf("\n  Voce ja possui um emprestimo em aberto!\n");
                printf("  Valor pendente: R$ %.2f\n", emprestimo);
                printf("  Quite o emprestimo atual antes de solicitar outro.\n");

            } else { //Solicitar emprestimo
                printf("  Informe o valor do emprestimo: R$ ");
                scanf("%lf", &valor);
 
                if (valor <= 0) {
                    printf("\n  Valor invalido! Digite um valor maior que zero.\n");
                } else {
                    emprestimo = valor;
                    saldo = saldo + valor;
                    printf("\n  Emprestimo concedido com sucesso!\n");
                    printf("  Valor emprestado: R$ %.2f\n", valor);
                    printf("  Novo saldo      : R$ %.2f\n", saldo);
                }
            }
        }

 //tela consulta de emprestimo
        else if (opcao == 5) {
            printf("  CONSULTA DE EMPRESTIMO\n");
 
            if (emprestimo <= 0) { //Caso não tenha solicitado um empréstimo 
                printf("\n  Voce nao possui emprestimo em aberto.\n");
            } else {
                printf("\n  Emprestimo pendente: R$ %.2f\n", emprestimo);
            }
            printf("------------------------------------------\n");
        }

        //tela para pagar emprestimo
        else if (opcao == 6) {
            printf("  PAGAMENTO DE EMPRESTIMO\n");
 
            if (emprestimo <= 0) {
                printf("\n  Voce nao possui emprestimo em aberto.\n");
            } else {
                printf("  Emprestimo pendente: R$ %.2f\n", emprestimo);
                printf("  Informe o valor a pagar: R$ ");
                scanf("%lf", &valor);
 
                if (valor <= 0) {
                    printf("\n  Valor invalido! Digite um valor maior que zero.\n");
                } else {
                    //se não tiver dinheiro para pagar
                    if (valor > saldo) {
                        printf("\n  Saldo insuficiente para o pagamento!\n");
                        printf("  Saldo disponivel: R$ %.2f\n", saldo);
                    } else {

                        if (valor > emprestimo) {
                            printf("\n  Valor superior ao emprestimo!\n");
                            printf("  Pague no maximo: R$ %.2f\n", emprestimo);
                        } else {
                            saldo = saldo - valor;
                            emprestimo = emprestimo - valor;
                            printf("\n  Pagamento efetuado com sucesso!\n");
                            printf("  Valor pago : R$ %.2f\n", valor);
                            
                            //se quitou tudo mostrar:
                            if (emprestimo == 0) {
                                printf("  Emprestimo quitado! Parabens!\n");
                            } else {
                                printf("  Restante   : R$ %.2f\n", emprestimo);
                            }
 
                            printf("  Saldo atual: R$ %.2f\n", saldo);
                        }
                    }
                }
            }
        }
 
        //saida
        else if (opcao == 7) {
            printf("\n==========================================\n");
            printf("  Obrigado por utilizar nossos serviços!\n");
            printf("  Até logo!\n");
            printf("==========================================\n");
        }
 
        //se digitar uma opção que não existe
        else {
            printf("\n  Opção inválida! Escolha um numero entre 1 e 7.\n");
        }
    }
}