#include <stdio.h>
#include <stdlib.h>
#include "base_struct.h"

void menu(item_t items[],t_node head)
{
    int choice;
    while (1)
    {
        printf("\nPlease choose a function to execute:\n");
        printf("1. Count persons in all cities\n");
        printf("2. Get average income for city and age range\n");
        printf("3. Find the chance of being ill given a starting age\n");
        printf("4. Find person by ID\n");
        printf("5. Insert an element in the middle and update IDs\n");
        printf("6. Count persons in city with age X\n");
        printf("7. Execute all functions\n");
        printf("8. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if(choice == 1){
            generarReporteCiudades(items);
            int numero = 0;
            count_people_by_city(&head, &numero);
        }

        else if (choice == 2)
        {
            char city_name[25];
            int x, y;
            printf("Please enter the city name: ");
            scanf("%s[^\n]", city_name);
            printf("Please enter the age range (X Y): ");
            scanf("%d %d", &x, &y);
            city_t city = get_city_t(city_name);
            get_average_income_by_city_and_age(&head, city, 32,60);
            get_average_income(items, city_name, x, y);
            fflush(stdin);
            fflush(stdout);
        }

        else if(choice == 3){
            generarProbabilidadEnfermedad(items);
            get_probability_illness_by_age(&head, 32);
        }

        else if (choice == 4)
        {
            int id;
            printf("Please enter the item ID: ");
            scanf("%d", &id);
            find_person_by_id(items, id);
            get_node_by_id(&head, id);
        }

        else if(choice == 5){
            insertarNuevoElemento(items);
            insert_node_in_middle(&head,2000);
        }

        else if (choice == 6)
        {
            char city_name[25];
            int x;
            printf("Please enter the city name: ");
            scanf("%s", city_name);
            printf("Please enter the age X: ");
            scanf("%d", &x);
            printf("City name: %s",city_name);
            find_persons_by_city_and_age(items, city_name, x);
            count_people_by_city_report(&head, city_name, x);
        }
        else if (choice == 7)
        {
            char city_name[25];
            int x, y, id;
            printf("Please enter the city name: ");
            scanf("%s", city_name);
            printf("Please enter the ID and age range (ID X Y): ");
            scanf("%d %d %d", &id, &x, &y);
            call_all_methods(items, city_name, id, x, y);
            call_all_methods_list(&head, city_name, id, x, y);
        }

        else if (choice == 8)
        {
            printf("Exiting...\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

// printf("\nIngrese un numero dependiendo de la ciudad: \n");
//         printf("1 para Dallas. \n");
//         printf("2 para New York City. \n");
//         printf("3 para Los Angeles. \n");
//         printf("4 para Mountain View. \n");
//         printf("5 para Boston. \n");
//         printf("6 para Washington D.C.. \n");
//         printf("7 para San Diego. \n");
//         printf("8 para Austin. \n");
//         scanf("%d", &city);
//         if (city > 0 && city < 9)
//         {
//             break;
//         }else {
// else {
//             printf("\nIntente de nuevo, ha ingresado un numero erroneo.\n");
//         }