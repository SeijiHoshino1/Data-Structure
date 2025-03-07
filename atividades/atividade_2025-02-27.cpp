//construa um codigo em linguagem C ao qual o usuário consiga informar e armazenar
//em memória os dados de 5 carros (marca, modelo, cor, ano modelo, ano fabricacao,
//combustivel (gasolina, etanol, flex, eletrico ou hibrido) e placa.

//O usuário deverá cadastrar os 5 veiculos e posteriormente informar 
//uma placa qualquer para que o sistema efetue uma busca sequencial nos dados, 
//apresentando todas as informações (se encontrar) ou a mensagem 
//"veiculos nao localizado"

//Necessário utilização de estruturas homogêneas e/ou heterogêneas.

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct veiculo{
  char marca[20];
  char modelo[20];
  char cor[20];
  int combustivel; //1 gas/ 2 alc /3 flex / 4 diesel/ 5 elet / 6 hibrido
  char placa[9];
  int anoF, anoM; 
};

struct veiculo ve[5];

short int posVet=0; //para controle da quantidade de veiculos
void Learquivo(); //0 - leitura / 1 - gravacao
void mostraVeiculo(short int p);
short int procuraVeiculo(char* placa);
//----------------------------------------------
int main(){
  char placa[9];
  Learquivo();
  printf("placa a pesquisar: ");
  //opcao 1 de entrada
  scanf(" %[^\n]", placa);
  
  //opcao 2 de entrada
  //fgets(placa,9,stdin);
  //placa[strcspn(placa, "\n")] = '\0';
  
  //opcao 3 de entrada
  //gets(placa)
 
  if (procuraVeiculo(placa)>=0)
    mostraVeiculo(procuraVeiculo(placa));
  else
    printf("Placa nao localizada \n\n");  
  system("pause");
}
//----------------------------------------------
void mostraVeiculo(short int p){
     system("cls");
     printf("      Marca: %s \n",ve[p].marca);
     printf("     Modelo: %s \n",ve[p].modelo);
     printf("        Cor: %s \n",ve[p].cor);
     printf("Combustivel: %i \n",ve[p].combustivel);
     printf("      Placa: %s \n",ve[p].placa);
     printf("    Ano Fab: %i \n",ve[p].anoF);
     printf("    Ano Mod: %i \n",ve[p].anoM);
}
//----------------------------------------------
void Learquivo(){
  char linha[15]; 
  short int x;
  FILE *file; //associa variável file em tipo FILE (palavra reservada que caracteriza fim de string)
    file = fopen("Ativ2.txt", "r"); //Associa file em "Ativ2.txt" e tenta abrir arquivo para leitura
    if (file != NULL) { //se não ocorreu erro na abertura do arquivo
        posVet=0;
        x=0;
        while (fgets(linha, sizeof(linha), file) != NULL && strlen(linha)>0) { 
          x++;
          linha[strlen(linha)-1]='\0'; //garante que o último caractere da string será null 
          switch (x){
                 case 1:
                    strcpy(ve[posVet].marca,linha); 
                    break;
                 case 2:
                    strcpy(ve[posVet].modelo,linha);   
                    break;
                 case 3:
                    strcpy(ve[posVet].cor,linha);   
                    break;
                 case 4:
                    ve[posVet].combustivel=atoi(linha);   
                    break;
                 case 5:
                    strcpy(ve[posVet].placa,linha);   
                    break;
                 case 6:
                    ve[posVet].anoF=atoi(linha); //atoi converte string em int  
                    break;
                 case 7:
                    ve[posVet].anoM=atoi(linha );   
                    break;
          }
          if (x==7){ //caso já tenha lido todas as linhas de um veiculo
            posVet++;
            x=0;
          }  
        }
    }
    else{ //caso o arquivo nao seja encontrado ou houve erro na leitura
      printf("erro na abertura do arquivo \n\n");
      system("pause");
      exit(0);
   }
    fclose(file); //fecha arquivo
}
//----------------------------------------------
short int procuraVeiculo(char* placa){
  for (short int x=0; x<posVet; x++)
    if (strcmp(placa,ve[x].placa)==0)
      return x;  
  return -1;  
}
