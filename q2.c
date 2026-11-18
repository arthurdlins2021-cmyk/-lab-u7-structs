#include <stdio.h>

typedef struct {
    char nome[30];
    float n1, n2, n3;
} Aluno;

int main(void) {
    Aluno turma[3] = {
        {"Mariana", 8.0f, 7.5f, 8.5f},
        {"Ana", 9.0f, 9.0f, 9.0f},
        {"Rafael", 6.5f, 7.0f, 7.5f}
    };
    int indice_maior = 0;
    float maior_media = 0.0f;

    for (int i = 0; i < 3; i++) {
        float media_atual = (turma[i].n1 + turma[i].n2 + turma[i].n3) / 3.0f;
        if (i == 0 || media_atual > maior_media) {
            maior_media = media_atual;
            indice_maior = i;
        }
    }

    printf("Maior media: %s (%.2f)\n", turma[indice_maior].nome, maior_media);
    return 0;
}
