#include <iostream>
using namespace std;

class Aluno {
private:
    string nome;
    double np1, np2, exame, mediaFinal;

public:
    void setDados(string n, double n1, double n2) {
        nome = n;
        np1 = n1;
        np2 = n2;
        exame = 0.0;
        mediaFinal = 0.0;
    }

    void calcularMedia() {
        double mediaParcial = (np1 + np2) / 2.0;
        if (mediaParcial >= 7.0) {
            mediaFinal = mediaParcial;
        } else {
            cout << "O aluno precisara fazer o exame." << endl;
            cout << "Digite a nota do Exame: ";
            cin >> exame;
            mediaFinal = (mediaParcial + exame) / 2.0;
        }
    }

    void mostrarDados() {
        cout << "Aluno: " << nome << endl;
        cout << "NP1: " << np1 << endl;
        cout << "NP2: " << np2 << endl;
        if (exame > 0) {
            cout << "Exame: " << exame << endl;
        }
        cout << "Media Final: " << mediaFinal << endl;
        cout << (mediaFinal >= 5.0 ? "Aprovado" : "Reprovado") << endl;
    }
};

int main() {
    Aluno aluno;
    string nome;
    double np1, np2;

    cout << "Digite o nome do aluno: ";
    getline(cin, nome);
    cout << "Digite a nota NP1: ";
    cin >> np1;
    cout << "Digite a nota NP2: ";
    cin >> np2;

    aluno.setDados(nome, np1, np2);
    aluno.calcularMedia();
    aluno.mostrarDados();

    return 0;
}

