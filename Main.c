#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sum();
void driver();
void lap();
void gender();
void brand();
void year();
void average();
void under();

int main() {
    int boolean = 1;
    char command;

    while (boolean) {
        printf("Enter the command:");
        scanf("%c", &command);
        while (getchar() != '\n');
        switch (command) {
            case 's':
                sum();
                break;
            case 'd':
                driver();
                break;
            case 'l':
                lap();
                break;
            case 'g':
                gender();
                break;
            case 'b':
                brand();
                break;
            case 'y':
                year();
                break;
            case 'a':
                average();
                break;
            case 'u':
                under();
                break;
            default:
                printf("Try another command \n");
                break;
        }
    }
    return 0;
}

void sum() {
    FILE *f;
    char *token;
    char line[100];
    char name[100];
    char surname[100];
    char *sp;
    char *gender;
    int *year;
    float lap1;
    float lap2;
    float lap3;
    float lap4;
    float lap5;
    float autos[30];


    f = fopen("D:\\Install\\FIIT\\ZkPrPr1\\Project(Clion)ZPrPr1\\tabulka.csv", "r");

    if ((f = fopen("D:\\Install\\FIIT\\ZkPrPr1\\Project(Clion)ZPrPr1\\tabulka.csv", "r")) == NULL) {
        printf("Subor nie je mozne precitat.");
        fclose(f);
    }
    while (fgets(line, 100, f) != NULL) {
        sp = strtok(line, " ");
        strcpy(name, sp);
        sp = strtok(NULL, ";");
        strcpy(surname, sp);
        sp = strtok(NULL, ";");
        gender = sp;
        sp = strtok(NULL, ";");
        year = atoi(sp);
        sp = strtok(NULL, ";");
        strcpy(autos, sp);
        sp = strtok(NULL, ";");
        lap1 = atof(sp);
        sp = strtok(NULL, ";");
        lap2 = atof(sp);
        sp = strtok(NULL, ";");
        lap3 = atof(sp);
        sp = strtok(NULL, ";");
        lap4 = atof(sp);
        sp = strtok(NULL, ";");
        lap5 = atof(sp);

        printf(" %s %s, nar. %d, %s,Automobil: %s\n"
               "Casy okruhov: %.3f,%.3f,%.3f,%.3f,%.3f,\n", name, surname, year, gender, autos, lap1, lap2, lap3, lap4,
               lap5);
    }
    fclose(f);
}

void driver() {
    FILE *f;
    char *token;
    char line[100];
    char name[100];
    char surname[100];
    char *sp;
    char *gender;
    char *resurname;
    int *year;
    float lap1;
    float lap2;
    float lap3;
    float lap4;
    float lap5;
    float autos[30];

    f = fopen("D:\\Install\\FIIT\\ZkPrPr1\\Project(Clion)ZPrPr1\\tabulka.csv", "r");

    if ((f = fopen("D:\\Install\\FIIT\\ZkPrPr1\\Project(Clion)ZPrPr1\\tabulka.csv", "r")) == NULL) {
        printf("Subor nie je mozne precitat.");
        fclose(f);
    }
    printf("Enter surname of the racer:");
    scanf("%s", resurname);
    while (fgets(line, 100, f) != NULL) {
        sp = strtok(line, " ");
        strcpy(name, sp);
        sp = strtok(NULL, ";");
        strcpy(surname, sp);
        sp = strtok(NULL, ";");
        gender = sp;
        sp = strtok(NULL, ";");
        year = atoi(sp);
        sp = strtok(NULL, ";");
        strcpy(autos, sp);
        sp = strtok(NULL, ";");
        lap1 = atof(sp);
        sp = strtok(NULL, ";");
        lap2 = atof(sp);
        sp = strtok(NULL, ";");
        lap3 = atof(sp);
        sp = strtok(NULL, ";");
        lap4 = atof(sp);
        sp = strtok(NULL, ";");
        lap5 = atof(sp);


        if (strcmp(resurname, surname) == 0) {
            printf(" %s %s\n nar. %d, %s\nAutomobil: %s\n"
                   "Casy okruhov: %.3f,%.3f,%.3f,%.3f,%.3f,\n", name, surname, year, gender, autos, lap1, lap2, lap3,
                   lap4,
                   lap5);


            float bestLap = 1000;
            if (bestLap > lap1 && lap1 < lap2 && lap1 < lap3 && lap1 < lap4 && lap1 < lap5) {
                bestLap = lap1;
                printf("Najlepsie kolo:%.3f\n", bestLap);
            } else if (bestLap > lap2 && lap2 < lap3 && lap2 < lap4 && lap2 < lap5) {
                bestLap = lap2;
                printf("Najlepsie kolo:%.3f\n", bestLap);
            } else if (bestLap > lap3 && lap3 < lap4 && lap3 < lap5) {
                bestLap = lap3;
                printf("Najlepsie kolo:%.3f\n", bestLap);
            } else if (bestLap > lap4 && lap4 < lap5) {
                bestLap = lap4;
                printf("Najlepsie kolo:%.3f\n", bestLap);
            } else if (bestLap > lap5) {
                bestLap = lap5;
                printf("Najlepsie kolo:%.3f\n", bestLap);
            }


            float worstLap = 1;
            if (worstLap < lap2 && (lap1 > lap3) && lap1 > lap4 && lap1 > lap5) {
                worstLap = lap1;
                printf("Najhorsie kolo: %.3f\n", worstLap);
            } else if (worstLap < lap3 && (lap2 > lap4) && lap2 > lap5) {
                worstLap = lap2;
                printf("Najhorsie kolo: %.3f\n", worstLap);
            } else if (worstLap < lap4 && (lap3 > lap5)) {
                worstLap = lap3;
                printf("Najhorsie kolo: %.3f\n", worstLap);
            } else if (worstLap < lap4 && lap4 > lap5) {
                worstLap = lap4;
                printf("Najhorsie kolo: %.3f\n", worstLap);
            } else {
                worstLap = lap5;
                printf("Najhorsie kolo: %.3f\n", worstLap);

            }

            float stredne;
            stredne = (lap1 + lap2 + lap3 + lap4 + lap5) / 5;
            printf("Priemerne kolo: %.3f\n", stredne);

        }
    }
    while (getchar() != '\n');
    fclose(f);
}

void lap() {
    FILE *f;
    char *token;
    char line[100];
    char name[100];
    char surname[100];
    char *sp;
    char *gender;
    char *resurname;
    int *year;
    float lap1;
    float lap2;
    float lap3;
    float lap4;
    float lap5;
    float autos[30];
    char name0;

    f = fopen("D:\\Install\\FIIT\\ZkPrPr1\\Project(Clion)ZPrPr1\\tabulka.csv", "r");
    rewind(f);
    char buff;
    int racers;
    int number = 0;
    float bestLapAll = 10000;
    char racerSurname[50];
    char racerName[50];
    int bestLapAll_num = 0;

    if ((f = fopen("D:\\Install\\FIIT\\ZkPrPr1\\Project(Clion)ZPrPr1\\tabulka.csv", "r")) == NULL) {
        printf("Subor nie je mozne precitat.");
        fclose(f);
    }
    while (fgets(line, 100, f) != NULL) {
        sp = strtok(line, " ");
        strcpy(name, sp);
        sp = strtok(NULL, ";");
        strcpy(surname, sp);
        sp = strtok(NULL, ";");
        gender = sp;
        sp = strtok(NULL, ";");
        year = atoi(sp);
        sp = strtok(NULL, ";");
        strcpy(autos, sp);
        sp = strtok(NULL, ";");
        lap1 = atof(sp);
        sp = strtok(NULL, ";");
        lap2 = atof(sp);
        sp = strtok(NULL, ";");
        lap3 = atof(sp);
        sp = strtok(NULL, ";");
        lap4 = atof(sp);
        sp = strtok(NULL, ";");
        lap5 = atof(sp);

        int bestLap_num = 0;
        float bestLap = 1000;


        if (bestLap > lap1 && lap1 < lap2 && lap1 < lap3 && lap1 < lap4 && lap1 < lap5) {
            bestLap = lap1;
            bestLap_num = 1;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap2 && lap2 < lap3 && lap2 < lap4 && lap2 < lap5) {
            bestLap = lap2;
            bestLap_num = 2;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap3 && lap3 < lap4 && lap3 < lap5) {
            bestLap = lap3;
            bestLap_num = 3;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap4 && lap4 < lap5) {
            bestLap = lap4;
            bestLap_num = 4;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap5) {
            bestLap = lap5;
            bestLap_num = 5;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        }
        if (bestLapAll > bestLap) {
            bestLapAll = bestLap;
            strcpy(racerName, name);
            strcpy(racerSurname, surname);
            bestLapAll_num = bestLap_num;
        }
    }
    printf("Najlepsie kolo:%.3f\nJazdec: %s, %s\nCislo kola: %d\n", bestLapAll, racerName, racerSurname,
           bestLapAll_num);
    fclose(f);

}

void gender() {
    FILE *f;
    char line[100];
    char name[100];
    char surname[100];
    float lap1, lap2, lap3, lap4, lap5, bestLapAll = 10000, autos[30];
    char racerName[50], racerSurname[50], sex, *sp, gender, *token, name0, buff, *resurname;
    int bestLapAll_num = 0, year;
    int racers, number = 0;


    f = fopen("D:\\Install\\FIIT\\ZkPrPr1\\Project(Clion)ZPrPr1\\tabulka.csv", "r");
    rewind(f);
    printf("Enter sex of the racer:");
    scanf("%c", &sex);
    while (getchar() != '\n');
    if (sex == 'm' | sex == 'f') {
    } else {
        printf("This gender does not exist!\n");
        return;
    }


    if ((f = fopen("D:\\Install\\FIIT\\ZkPrPr1\\Project(Clion)ZPrPr1\\tabulka.csv", "r")) == NULL) {
        printf("Subor nie je mozne precitat.");
        fclose(f);
    }
    while (fgets(line, 100, f) != NULL) {
        sp = strtok(line, " ");
        strcpy(name, sp);
        sp = strtok(NULL, ";");
        strcpy(surname, sp);
        sp = strtok(NULL, ";");
        gender = *sp;
        if (gender != sex) {
            continue;
        }
        sp = strtok(NULL, ";");
        year = atoi(sp);
        sp = strtok(NULL, ";");
        strcpy(autos, sp);
        sp = strtok(NULL, ";");
        lap1 = atof(sp);
        sp = strtok(NULL, ";");
        lap2 = atof(sp);
        sp = strtok(NULL, ";");
        lap3 = atof(sp);
        sp = strtok(NULL, ";");
        lap4 = atof(sp);
        sp = strtok(NULL, ";");
        lap5 = atof(sp);

        int bestLap_num = 0;
        float bestLap = 1000;


        if (bestLap > lap1 && lap1 < lap2 && lap1 < lap3 && lap1 < lap4 && lap1 < lap5) {
            bestLap = lap1;
            bestLap_num = 1;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap2 && lap2 < lap3 && lap2 < lap4 && lap2 < lap5) {
            bestLap = lap2;
            bestLap_num = 2;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap3 && lap3 < lap4 && lap3 < lap5) {
            bestLap = lap3;
            bestLap_num = 3;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap4 && lap4 < lap5) {
            bestLap = lap4;
            bestLap_num = 4;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap5) {
            bestLap = lap5;
            bestLap_num = 5;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        }
        if (bestLapAll > bestLap) {
            bestLapAll = bestLap;
            strcpy(racerName, name);
            strcpy(racerSurname, surname);
            bestLapAll_num = bestLap_num;
        }

    }
    printf("Najlepsie kolo:%.3f\nJazdec: %s, %s\nCislo kola: %d\n", bestLapAll, racerName, racerSurname,
           bestLapAll_num);
    fclose(f);
}

void brand() {
    FILE *f;
    char line[100];
    char name[100];
    char surname[100];
    float lap1, lap2, lap3, lap4, lap5, bestLapAll = 10000, autos[30];
    char racerName[50], racerSurname[50], *sp, gender, *token, name0, buff, *resurname;
    int bestLapAll_num = 0, year;
    int racers, number = 0;
    int bestLap_num = 0;
    int bestLapPorshe_num = 0, bestLapFerrari_num = 0, bestLapBugatti_num = 0, bestLapHonda_num = 0;
    char mark[20];
    float bestLapPorshe = 10000, bestLapFerrari = 1000, bestlapBugatti = 1000, bestLapHonda = 1000;
    char racerNameFerrari[50], racerNameBugatti[50], racerNamePorshe[50], racerNameHonda[50];
    char racerSurnamePorshe[50], racerSurnameFerrari[50], racerSurnameBugatti[50], racerSurnameHonda[50];


    f = fopen("D:\\Install\\FIIT\\ZkPrPr1\\Project(Clion)ZPrPr1\\tabulka.csv", "r");
    rewind(f);

    if ((f = fopen("D:\\Install\\FIIT\\ZkPrPr1\\Project(Clion)ZPrPr1\\tabulka.csv", "r")) == NULL) {
        printf("Subor nie je mozne precitat.");
        fclose(f);
    }

    char markporsche[] = "porsche";
    char markbugatti[] = "bugatti";
    char markhonda[] = "honda";
    char markferrari[] = "ferrari";

    //    „porsche“, „bugatti“,
    //    „honda“, „ferrari“
    rewind(f);
    while (fgets(line, 100, f) != NULL) {
        sp = strtok(line, " ");
        strcpy(name, sp);
        sp = strtok(NULL, ";");
        strcpy(surname, sp);
        sp = strtok(NULL, ";");
        gender = *sp;
        sp = strtok(NULL, ";");
        year = atoi(sp);
        sp = strtok(NULL, ";");
        strcpy(autos, sp);
        sp = strtok(NULL, ";");
        lap1 = atof(sp);
        sp = strtok(NULL, ";");
        lap2 = atof(sp);
        sp = strtok(NULL, ";");
        lap3 = atof(sp);
        sp = strtok(NULL, ";");
        lap4 = atof(sp);
        sp = strtok(NULL, ";");
        lap5 = atof(sp);

        float bestLap = 1000;

        if (bestLap > lap1 && lap1 < lap2 && lap1 < lap3 && lap1 < lap4 && lap1 < lap5) {
            bestLap = lap1;
            bestLap_num = 1;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap2 && lap2 < lap3 && lap2 < lap4 && lap2 < lap5) {
            bestLap = lap2;
            bestLap_num = 2;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap3 && lap3 < lap4 && lap3 < lap5) {
            bestLap = lap3;
            bestLap_num = 3;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap4 && lap4 < lap5) {
            bestLap = lap4;
            bestLap_num = 4;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap5) {
            bestLap = lap5;
            bestLap_num = 5;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        }

        if (strcmp(markporsche, autos) == 0) {
            if (bestLapPorshe > bestLap) {
                bestLapPorshe = bestLap;
                strcpy(racerNamePorshe, name);
                strcpy(racerSurnamePorshe, surname);
                bestLapPorshe_num = bestLap_num;
            }
        }
        if (strcmp(markferrari, autos) == 0) {
            if (bestLapFerrari > bestLap) {
                bestLapFerrari = bestLap;
                strcpy(racerNameFerrari, name);
                strcpy(racerSurnameFerrari, surname);
                bestLapFerrari_num = bestLap_num;
            }
        }
        if (strcmp(markbugatti, autos) == 0) {
            if (bestlapBugatti > bestLap) {
                bestlapBugatti = bestLap;
                strcpy(racerNameBugatti, name);
                strcpy(racerSurnameBugatti, surname);
                bestLapBugatti_num = bestLap_num;
            }
        }
        if (strcmp(markhonda, autos) == 0) {
            if (bestLapHonda > bestLap) {
                bestLapHonda = bestLap;
                strcpy(racerNameHonda, name);
                strcpy(racerSurnameHonda, surname);
                bestLapHonda_num = bestLap_num;
            }
        }
    }

    if (bestLapPorshe != 1000) {
        printf("Znacka: %s\nNajlepsie kolo:%.3f\nJazdec: %s %s\nCislo kola: %d\n", markporsche, bestLapPorshe,
               racerNamePorshe, racerSurnamePorshe, bestLapPorshe_num);
    }
    if (bestLapFerrari != 1000) {
        printf("Znacka: %s\nNajlepsie kolo:%.3f\nJazdec: %s %s\nCislo kola: %d\n", markferrari, bestLapFerrari,
               racerNameFerrari, racerSurnameFerrari, bestLapFerrari_num);
    }
    if (bestlapBugatti != 1000) {
        printf("Znacka: %s\nNajlepsie kolo:%.3f\nJazdec: %s %s\nCislo kola: %d\n", markbugatti, bestlapBugatti,
               racerNameBugatti, racerSurnameBugatti, bestLapBugatti_num);
    }
    if (bestLapHonda != 1000) {
        printf("Znacka: %s\nNajlepsie kolo:%.3f\nJazdec: %s %s\nCislo kola: %d\n", markhonda, bestLapHonda,
               racerNameHonda, racerSurnameHonda, bestLapHonda_num);
    }
    fclose(f);

}
void  year(){
    FILE *f;
    char *token;
    char line[100];
    char name[100];
    char surname[100];
    char *sp;
    char *gender;
    int *year;
    float lap1;
    float lap2;
    float lap3;
    float lap4;
    float lap5;
    float autos[30];
    float bestLapAll = 10000;
    char racerName[50], racerSurname[50], name0, buff, *resurname;
    int bestLapAll_num = 0;
    int racers, number = 0;
    int bestLap_num = 0;
    int yearDO, yearOFracer;


    f = fopen("D:\\Install\\FIIT\\ZkPrPr1\\Project(Clion)ZPrPr1\\tabulka.csv", "r");

    if ((f = fopen("D:\\Install\\FIIT\\ZkPrPr1\\Project(Clion)ZPrPr1\\tabulka.csv", "r")) == NULL) {
        printf("Subor nie je mozne precitat.");
        fclose(f);
    }

    printf("Enter year:");
    scanf("%d", &yearDO);
    while (fgets(line, 100, f) != NULL) {
        sp = strtok(line, " ");
        strcpy(name, sp);
        sp = strtok(NULL, ";");
        strcpy(surname, sp);
        sp = strtok(NULL, ";");
        gender = sp;
        sp = strtok(NULL, ";");
        year = atoi(sp);
        if(year>yearDO){
            continue;
        }
        sp = strtok(NULL, ";");
        strcpy(autos, sp);
        sp = strtok(NULL, ";");
        lap1 = atof(sp);
        sp = strtok(NULL, ";");
        lap2 = atof(sp);
        sp = strtok(NULL, ";");
        lap3 = atof(sp);
        sp = strtok(NULL, ";");
        lap4 = atof(sp);
        sp = strtok(NULL, ";");
        lap5 = atof(sp);

        int bestLap_num = 0;
        float bestLap = 1000;

        if (bestLap > lap1 && lap1 < lap2 && lap1 < lap3 && lap1 < lap4 && lap1 < lap5) {
            bestLap = lap1;
            bestLap_num = 1;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap2 && lap2 < lap3 && lap2 < lap4 && lap2 < lap5) {
            bestLap = lap2;
            bestLap_num = 2;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap3 && lap3 < lap4 && lap3 < lap5) {
            bestLap = lap3;
            bestLap_num = 3;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap4 && lap4 < lap5) {
            bestLap = lap4;
            bestLap_num = 4;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        } else if (bestLap > lap5) {
            bestLap = lap5;
            bestLap_num = 5;
//            printf("Najlepsie kolo:%.3f\n", bestLap);
        }

        if (bestLapAll > bestLap) {
            bestLapAll = bestLap;
            strcpy(racerName, name);
            strcpy(racerSurname, surname);
            bestLapAll_num = bestLap_num;
            yearOFracer = year;
        }


    }
    if(bestLapAll!= 10000){
    printf("Najlepsie kolo:%.3f\nJazdec: %s %s\nnar. %d\nCislo kola: %d\n", bestLapAll, racerName, racerSurname, yearOFracer,
           bestLapAll_num);} else printf("There are nor racer who born before %d\n", yearDO);

    fclose(f);
    while (getchar() != '\n');
}
void average(){
    FILE *f;
    char *token;
    char line[100];
    char name[100];
    char surname[100];
    char *sp;
    char *gender;
    char *resurname;
    int *year;
    float lap1;
    float lap2;
    float lap3;
    float lap4;
    float lap5;
    float autos[30];
    char averageName[30], averageSurname[30];
    float averageLap= 1000;


    f = fopen("D:\\Install\\FIIT\\ZkPrPr1\\Project(Clion)ZPrPr1\\tabulka.csv", "r");

    if ((f = fopen("D:\\Install\\FIIT\\ZkPrPr1\\Project(Clion)ZPrPr1\\tabulka.csv", "r")) == NULL) {
        printf("Subor nie je mozne precitat.");
        fclose(f);
    }

    while (fgets(line, 100, f) != NULL) {
        sp = strtok(line, " ");
        strcpy(name, sp);
        sp = strtok(NULL, ";");
        strcpy(surname, sp);
        sp = strtok(NULL, ";");
        gender = sp;
        sp = strtok(NULL, ";");
        year = atoi(sp);
        sp = strtok(NULL, ";");
        strcpy(autos, sp);
        sp = strtok(NULL, ";");
        lap1 = atof(sp);
        sp = strtok(NULL, ";");
        lap2 = atof(sp);
        sp = strtok(NULL, ";");
        lap3 = atof(sp);
        sp = strtok(NULL, ";");
        lap4 = atof(sp);
        sp = strtok(NULL, ";");
        lap5 = atof(sp);

            float stredne;
            stredne = (lap1 + lap2 + lap3 + lap4 + lap5) / 5;
            printf("Priemerne kolo: %.3f\n", stredne);

        if (averageLap > stredne) {
            averageLap = stredne;
            strcpy(averageName, name);
            strcpy(averageSurname, surname);
        }
        }
    printf("Najlepsie:\n %s %s - %.3f\n", averageName, averageSurname, averageLap);
    fclose(f);
    }
void under() {
}
