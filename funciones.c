#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *miArchivo;
struct equipos {
    char nomCompetencia[50];
    char nomEquipo[16][50];
    int partidosJugados[16];
    int partidosGanados[16];
    int empatados[16];
    int perdidos[16];
    int golesFavor[16];
    int golesContra[16];
    int diferenciaGoles[16];
    int puntos[16];
    int posicion[16];
};

void menu(struct equipos *menuPrincipal) {
    int opcion;
    do {
        printf("\n======================================== MENU PRINCIPAL ========================================");
        printf("\n|                                                                                             |");
        printf("\n|                                  1- CREAR FIXTURE                                           |");
        printf("\n|                                                                                             |");
        printf("\n|                                  2- VER FIXTURE                                             |");
        printf("\n|                                                                                             |");
        printf("\n|                                  3- SALIR                                                   |");
        printf("\n|                                                                                             |\n");
        printf("================================================================================================\n");

        printf("\nIngrese una opción: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1:
                system("cls");
                nombreCompetencia(menuPrincipal);
                cargaEquipos(menuPrincipal);
                crearArchivo(menuPrincipal);
                break;
            case 2:
                system("cls");
                verFixture(menuPrincipal);
                break;
            case 3:
                exit(0);
            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (opcion != 3);
}

void nombreCompetencia(struct equipos *nombreComp) {
    printf("Ingrese el nombre de la competencia: ");
    gets(nombreComp->nomCompetencia);
}

void cargaEquipos(struct equipos *crearFixture) {
    printf("Ingrese los nombres de los equipos para los grupos:\n");
    printf("Grupo A:\n");
    for (int i = 0; i < 4; i++) {
        printf("Equipo %d: ", i + 1);
        gets(crearFixture->nomEquipo[i]);
    }
    printf("Grupo B:\n");
    for (int i = 0; i < 4; i++) {
        printf("Equipo %d: ", i + 1);
        gets(crearFixture->nomEquipo[i + 4]);
    }
    printf("Grupo C:\n");
    for (int i = 0; i < 4; i++) {
        printf("Equipo %d: ", i + 1);
        gets(crearFixture->nomEquipo[i + 8]);
    }
    printf("Grupo D:\n");
    for (int i = 0; i < 4; i++) {
        printf("Equipo %d: ", i + 1);
        gets(crearFixture->nomEquipo[i + 12]);
    }

    for (int i = 0; i < 16; i++) {
        crearFixture->partidosJugados[i] = 0;
        crearFixture->partidosGanados[i] = 0;
        crearFixture->empatados[i] = 0;
        crearFixture->perdidos[i] = 0;
        crearFixture->golesFavor[i] = 0;
        crearFixture->golesContra[i] = 0;
        crearFixture->diferenciaGoles[i] = 0;
        crearFixture->puntos[i] = 0;
        crearFixture->posicion[i] = i + 1; 
    }
}

void crearArchivo(struct equipos *archivo) {
    miArchivo = fopen("fixture.txt", "w");
    if (miArchivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    
    fprintf(miArchivo, "\n================================= GRUPO A ===================================\n");
    fprintf(miArchivo, "| Equipo             | PJ   | PG   | PE   | PP   | Pts  | GF   | GC   | DG   |\n");
    fprintf(miArchivo, "|--------------------|------|------|------|------|------|------|------|------|\n");
    for (int i = 0; i < 4; i++) {
        fprintf(miArchivo, "| %-18s | %4d | %4d | %4d | %4d | %4d | %4d | %4d | %4d |\n", archivo->nomEquipo[i],
                archivo->partidosJugados[i], archivo->partidosGanados[i], archivo->empatados[i],
                archivo->perdidos[i], archivo->puntos[i], archivo->golesFavor[i],
                archivo->golesContra[i], archivo->diferenciaGoles[i]);
    }
    fprintf(miArchivo, "==============================================================================\n");

    fprintf(miArchivo, "\n================================== GRUPO B ==================================\n");
    fprintf(miArchivo, "| Equipo             | PJ   | PG   | PE   | PP   | Pts  | GF   | GC   | DG   |\n");
    fprintf(miArchivo, "|--------------------|------|------|------|------|------|------|------|------|\n");
    for (int i = 4; i < 8; i++) {
        fprintf(miArchivo, "| %-18s | %4d | %4d | %4d | %4d | %4d | %4d | %4d | %4d |\n", archivo->nomEquipo[i],
                archivo->partidosJugados[i], archivo->partidosGanados[i], archivo->empatados[i],
                archivo->perdidos[i], archivo->puntos[i], archivo->golesFavor[i],
                archivo->golesContra[i], archivo->diferenciaGoles[i]);
    }
    fprintf(miArchivo, "==============================================================================\n");

    fprintf(miArchivo, "\n================================ GRUPO C ====================================\n");
    fprintf(miArchivo, "| Equipo             | PJ   | PG   | PE   | PP   | Pts  | GF   | GC   | DG   |\n");
    fprintf(miArchivo, "|--------------------|------|------|------|------|------|------|------|------|\n");
    for (int i = 8; i < 12; i++) {
        fprintf(miArchivo, "| %-18s | %4d | %4d | %4d | %4d | %4d | %4d | %4d | %4d |\n", archivo->nomEquipo[i],
                archivo->partidosJugados[i], archivo->partidosGanados[i], archivo->empatados[i],
                archivo->perdidos[i], archivo->puntos[i], archivo->golesFavor[i],
                archivo->golesContra[i], archivo->diferenciaGoles[i]);
    }
    fprintf(miArchivo, "================================================================================\n");

    fprintf(miArchivo, "\n================================ GRUPO D ====================================\n");
    fprintf(miArchivo, "| Equipo             | PJ   | PG   | PE   | PP   | Pts  | GF   | GC   | DG   |\n");
    fprintf(miArchivo, "|--------------------|------|------|------|------|------|------|------|------|\n");
    for (int i = 12; i < 16; i++) {
        fprintf(miArchivo, "| %-18s | %4d | %4d | %4d | %4d | %4d | %4d | %4d | %4d |\n", archivo->nomEquipo[i],
                archivo->partidosJugados[i], archivo->partidosGanados[i], archivo->empatados[i],
                archivo->perdidos[i], archivo->puntos[i], archivo->golesFavor[i],
                archivo->golesContra[i], archivo->diferenciaGoles[i]);
    }
    fprintf(miArchivo, "===============================================================================\n");

    fclose(miArchivo);
    printf("Archivo 'fixture.txt' creado exitosamente.\n");
}


void verFixture(struct equipos *cargarGrupo) {
    int opcion;
    do {
        printf("\n======================================== MENU FIXTURE ==========================================\n");
        printf("|                                                                                             |\n");
        printf("|                                  1- VER FIXTURE COMPLETO                                    |\n");
        printf("|                                                                                             |\n");
        printf("|                                  2- VER UN GRUPO                                            |\n");
        printf("|                                                                                             |\n");
        printf("|                                  3- CARGAR RESULTADOS                                       |\n");
        printf("|                                                                                             |\n");
        printf("|                                  4- MODIFICAR DATOS                                         |\n");
        printf("|                                                                                             |\n");
        printf("|                                  5- VOLVER AL MENU PRINCIPAL                                |\n");
        printf("|                                                                                             |\n");
        printf("================================================================================================\n");

        printf("\nIngrese una opción: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1:
                system("cls");
                mostrarDatosArchivo(cargarGrupo);
                break;
            case 2:
                system("cls");
                mostrarUngrupo(cargarGrupo);
                break;
            case 3:
                system("cls");
                break;
            case 4:
                system("cls");
                break;
            case 5:
                system("cls");
                return;
            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (opcion != 5);
}

void mostrarDatosArchivo(struct equipos mostrarDatos) {
    miArchivo = fopen("fixture.txt", "r");
    if (miArchivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    char linea[256];
    while (fgets(linea, sizeof(linea), miArchivo)) {
        printf("%s", linea);
    }
    fclose(miArchivo);
}

void mostrarUngrupo(struct equipos *cargarGrupo) {
    miArchivo = fopen("fixture.txt", "r");
    if (miArchivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    char nombreGrupo;
    printf("Ingrese el grupo que desea ver (A, B, C, D): ");
    scanf(" %c", &nombreGrupo);

    char linea[256];
    int mostrar = 0;
    int grupoEncontrado = 0;
    while (fgets(linea, sizeof(linea), miArchivo)) {
        if ((strstr(linea, "GRUPO A") != NULL && (nombreGrupo == 'A' || nombreGrupo == 'a')) ||
            (strstr(linea, "GRUPO B") != NULL && (nombreGrupo == 'B' || nombreGrupo == 'b')) ||
            (strstr(linea, "GRUPO C") != NULL && (nombreGrupo == 'C' || nombreGrupo == 'c')) ||
            (strstr(linea, "GRUPO D") != NULL && (nombreGrupo == 'D' || nombreGrupo == 'd'))) {
            mostrar = 1;
            grupoEncontrado = 1;
        } else if (strstr(linea, "GRUPO") != NULL && grupoEncontrado == 1) {
            break;
        }

        if (mostrar) {
            printf("%s", linea);
        }
    }

    if (!grupoEncontrado) {
        printf("Grupo no encontrado.\n");
    }

    fclose(miArchivo);
}
