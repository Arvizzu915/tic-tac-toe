#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{


    char turnoJugador = 'X';
    char otroJugador = 'O';
    bool ganador = false;
    bool valido = true;
    char casilla;
    int turnos = 0;

    char gato[3][3] = { {'0', '1', '2'},
                        {'3', '4', '5'},
                        {'6', '7', '8'} };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << gato[i][j] << " ";
        }
        cout << endl;
    }

    do
    {
        do
        {
            valido = false;
            cout << "turno del jugador " << turnoJugador << endl;
            cout << "Casilla: ";
            cin >> casilla;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (gato[i][j] == casilla)
                    {
                        if (gato[i][j] != turnoJugador && gato[i][j] != otroJugador)
                        {
                            valido = true;
                            gato[i][j] = turnoJugador;
                            turnos++;
                            cout << turnos << endl;

                            if (turnoJugador == 'X') {
                                turnoJugador = 'O';
                                otroJugador = 'X';
                            }
                            else if (turnoJugador == 'O') {
                                turnoJugador = 'X';
                                otroJugador = 'O';
                            }
                        }
                    }
                }
            }

            system("cls");

            if (!valido)
            {
                cout << "invalido" << endl;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        cout << gato[i][j] << " ";
                    }
                    cout << endl;
                }
            }


        } while (!valido);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << gato[i][j] << " ";
                }
            cout << endl;
        }

        if ((gato[0][0] == 'X' && gato[0][1] == 'X' && gato[0][2] == 'X') || 
            (gato[1][0] == 'X' && gato[1][1] == 'X' && gato[1][2] == 'X') || 
            (gato[2][0] == 'X' && gato[2][1] == 'X' && gato[2][2] == 'X') ||
            (gato[0][0] == 'X' && gato[1][0] == 'X' && gato[2][0] == 'X') ||
            (gato[0][1] == 'X' && gato[1][1] == 'X' && gato[2][1] == 'X') || 
            (gato[0][2] == 'X' && gato[1][2] == 'X' && gato[2][2] == 'X') || 
            (gato[0][0] == 'X' && gato[1][1] == 'X' && gato[2][2] == 'X') || 
            (gato[0][2] == 'X' && gato[1][1] == 'X' && gato[2][0] == 'X'))
        {
            ganador = true;
            cout << "Gano X" << endl;
        }
        if ((gato[0][0] == 'O' && gato[0][1] == 'O' && gato[0][2] == 'O') ||
            (gato[1][0] == 'O' && gato[1][1] == 'O' && gato[1][2] == 'O') ||
            (gato[2][0] == 'O' && gato[2][1] == 'O' && gato[2][2] == 'O') ||
            (gato[0][0] == 'O' && gato[1][0] == 'O' && gato[2][0] == 'O') ||
            (gato[0][1] == 'O' && gato[1][1] == 'O' && gato[2][1] == 'O') ||
            (gato[0][2] == 'O' && gato[1][2] == 'O' && gato[2][2] == 'O') ||
            (gato[0][0] == 'O' && gato[1][1] == 'O' && gato[2][2] == 'O') ||
            (gato[0][2] == 'O' && gato[1][1] == 'O' && gato[2][0] == 'O'))
        {
            ganador = true;
            cout << "Gano O" << endl;
        }


    } while (!ganador || turnos < 9);

    cout << "se acabo";

}