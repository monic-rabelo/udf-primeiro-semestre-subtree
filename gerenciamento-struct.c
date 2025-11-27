#include <stdio.h>
#include <string.h> // biblioteca de manipulação de strings

int main() {
    struct Estudante {
        int matricula;
        float nota1;
        float nota2;
        float media;
        char nome[50];
    };

    // Declarando uma variavel do tipo struct aluno
    struct Estudante aluno;

    // Lendo os dados do aluno
    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);  // fgets para ler string com espaços em branco
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0'; // Remove o caractere de nova linha (\n) se existir
    
    printf("Digite a matricula: ");
    scanf("%d", &aluno.matricula);

    printf("Informe a primeira nota: ");
    scanf("%f", &aluno.nota1);

    printf("Informe a segunda nota: ");
    scanf("%f", &aluno.nota2);

    // Calculando a media
    aluno.media = (aluno.nota1 + aluno.nota2) / 2;

    // Exibindo os dados
    printf("\n--- Dados do Aluno ---\n");
    printf("Nome: %s\n", aluno.nome);
    printf("Matricula: %d\n", aluno.matricula);
    printf("Nota 1: %g\n", aluno.nota1);
    printf("Nota 2: %g\n", aluno.nota2);
    printf("Média: %g\n", aluno.media);
    
    // Situação do aluno pela media
    if (aluno.media >= 6) {
        printf("Aluno(a) %s aprovado!", aluno.nome);
    } else {
        printf("Aluno(a) %s reprovado!", aluno.nome);
    }

    return 0;
}