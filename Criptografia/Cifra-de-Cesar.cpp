#include <stdio.h>
#include <string.h>

// Funcao para criptografar a mensagem usando a Cifra de Cesar
void cifraDeCesar(char mensagem[], int deslocamento) {
    int i = 0;
    char ch;

    while (mensagem[i] != '\0') {
        ch = mensagem[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch + deslocamento;

            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            mensagem[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + deslocamento;

            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            mensagem[i] = ch;
        }
        i++;
    }
}

// Funcao para descriptografar a mensagem usando a Cifra de Cesar
void decifraDeCesar(char mensagem[], int deslocamento) {
    int i = 0;
    char ch;

    while (mensagem[i] != '\0') {
        ch = mensagem[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch - deslocamento;

            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }

            mensagem[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - deslocamento;

            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }

            mensagem[i] = ch;
        }
        i++;
    }
}

int main() {
    char mensagem[100];
    int deslocamento;
    int opcao;

    printf("Digite uma mensagem: ");
    fgets(mensagem, sizeof(mensagem), stdin);
    mensagem[strcspn(mensagem, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o deslocamento: ");
    scanf("%d", &deslocamento);

    printf("Escolha uma opcao:\n");
    printf("1. Criptografar\n");
    printf("2. Descriptografar\n");
    scanf("%d", &opcao);

    if (opcao == 1) {
        cifraDeCesar(mensagem, deslocamento);
        printf("Mensagem criptografada: %s\n", mensagem);
    } else if (opcao == 2) {
        decifraDeCesar(mensagem, deslocamento);
        printf("Mensagem descriptografada: %s\n", mensagem);
    } else {
        printf("Opcao invalida!\n");
    }

    return 0;
}

