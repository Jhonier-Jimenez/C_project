#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "base_struct.h"


void count_people_by_city(t_node *node, int *count) {
    for (int i = 0; i < 9; i++) {
        count[i] = 0;
    }

    char *city_names[] = {"Dallas", "New York City", "Los Angeles", "Mountain View", "Boston", "Washington D.C.", "San Diego", "Austin", "Not found"};

    t_node *current = node;
    while (current != NULL) {

        char *city_name = city_names[current->item.city];

        city_t city = get_city_t(city_name);

        count[city]++;

        current = current->next;
    }

    for (int i = 0; i < 9; i++) {
        printf("Para el estado %s: %d\n", city_names[i], count[i]);
    }
    
}

void get_average_income_by_city_and_age(t_node *head, city_t city, int x_age, int y_age) {
    int count = 0;
    int total_income = 0;
    float total;
    float probability;

    // Recorrer la lista enlazada
    t_node *current = head;
    while (current != NULL) {
        // Verificar si la persona actual vive en la ciudad y tiene la edad requerida
        if (current->item.city == city && current->item.age >= x_age && current->item.age <= y_age) {
            total_income += current->item.income;
            count++;
        }

        // Avanzar al siguiente nodo
        current = current->next;
    }

    // Calcular el promedio de ingresos
    if (count > 0) {
        total = (float) total_income / count;
    } else {
        total = 0.0;
    }
    printf("El promedio calculado para esta ciudad y estas edades es: %f\n", total);
}

void get_probability_illness_by_age(t_node *head, int x_age) {
    int count_total = 0;
    int count_ill = 0;
    float probability;

    // Recorrer la lista enlazada
    t_node *current = head;
    while (current != NULL) {
        // Verificar si la persona actual tiene la edad requerida o mayor
        if (current->item.age >= x_age) {
            count_total++;
            if (current->item.illness == true) {
                count_ill++;
            }
        }

        // Avanzar al siguiente nodo
        current = current->next;
    }

    // Calcular la probabilidad de estar enfermo
    if (count_total > 0) {
        probability = (float) count_ill / count_total;
    } else {
        probability = 0.0;
    }

    printf("La probabilidad es: %f\n", probability);
}

void *get_node_by_id(t_node *head, unsigned int id) {
    t_node *current = head;
    while (current != NULL) {
        if (current->item.id == id) {
            printf("nodo encontrado con id %d y con edad %d\n", current->item.id, current->item.age);
        }


        current = current->next;
    }

    printf("No fue posible encontrar nodo con esa información\n");
}