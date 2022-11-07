/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aurelio
 *
 * Created on December 8, 2019, 4:17 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

extern char *optarg;
extern int optind, opterr, optopt;

/*
 * 
 */
int main(int argc, char** argv) {
    char opt;
    bool interactif = false;
    bool errflag = false;
    bool i_isset = false;
    bool n_isset = false;
    int repet = -1;

    while ((opt = getopt(argc, argv, "in:")) != -1) {
        switch (opt) {
            case 'a':
                printf("boummm \n");
                break;
            case 'i': //mode interactif
                if (!n_isset) {
                    printf("nombre de valeur : ");
                    scanf("%i", &repet);
                    i_isset = true;
                } else {
                    errflag = true;
                }
                break;
            case 'n':
                if (!i_isset) {
                    repet = atoi(optarg);
                    n_isset = true;
                } else {
                    errflag = true;
                }
                break;
            case ':': /* -f or -o without operand */
                fprintf(stderr, "Option -%c requires an operand\n", optopt);
                errflag = true;
                break;
            case '?':
            default:
                break;
        }
    }

    if (!errflag) {
        while (repet-- != 0) {
            printf("%d\n", rand() % 1000);
            usleep(500000);

        }
    } else {
        printf("Usage : -nN | -i" );
    }
    return (EXIT_SUCCESS);
}


