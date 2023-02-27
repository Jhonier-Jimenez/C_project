#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "base_struct.h"
#include <time.h>

//1
void count_people_by_city(t_node *node, int *count)
{
    // Clock section
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Start function
    for (int i = 0; i < 9; i++)
    {
        count[i] = 0;
    }

    char *city_names[] = {"Dallas", "New York City", "Los Angeles", "Mountain View", "Boston", "Washington D.C.", "San Diego", "Austin", "Not found"};

    t_node *current = node;
    while (current != NULL)
    {

        char *city_name = city_names[current->item.city];

        city_t city = get_city_t(city_name);

        count[city]++;

        current = current->next;
    }

    for (int i = 0; i < 9; i++)
    {
        printf("Para el estado %s: %d\n", city_names[i], count[i]);
    }

    // End clock section
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to execute the function with the use of linked lists is: %.9f seconds\n", cpu_time_used);
}

//2
void get_average_income_by_city_and_age(t_node *head, city_t city, int x_age, int y_age)
{
    // Clock section
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Start function
    int count = 0;
    int total_income = 0;
    float total;
    float probability;

    // Recorrer la lista enlazada
    t_node *current = head;
    while (current != NULL)
    {
        // Verificar si la persona actual vive en la ciudad y tiene la edad requerida
        if (current->item.city == city && current->item.age >= x_age && current->item.age <= y_age)
        {
            total_income += current->item.income;
            count++;
        }

        // Avanzar al siguiente nodo
        current = current->next;
    }

    // Calcular el promedio de ingresos
    if (count > 0)
    {
        total = (float)total_income / count;
    }
    else
    {
        total = 0.0;
    }
    printf("El promedio calculado para esta ciudad y estas edades es: %f\n", total);

    // End clock section
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to execute the function with the use of linked lists is: %.9f seconds\n", cpu_time_used);
}

//3
void get_probability_illness_by_age(t_node *head, int x_age)
{
    // Clock section
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Start function
    int count_total = 0;
    int count_ill = 0;
    float probability;

    // Recorrer la lista enlazada
    t_node *current = head;
    while (current != NULL)
    {
        // Verificar si la persona actual tiene la edad requerida o mayor
        if (current->item.age >= x_age)
        {
            count_total++;
            if (current->item.illness == true)
            {
                count_ill++;
            }
        }

        // Avanzar al siguiente nodo
        current = current->next;
    }

    // Calcular la probabilidad de estar enfermo
    if (count_total > 0)
    {
        probability = (float)count_ill / count_total;
    }
    else
    {
        probability = 0.0;
    }

    printf("La probabilidad es: %f\n", probability);

    // End clock section
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to execute the function with the use of linked lists is: %.9f seconds\n", cpu_time_used);
}

//4
void *get_node_by_id(t_node *head, unsigned int id)
{
    // Clock section
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Start function
    t_node *current = head;
    while (current != NULL)
    {
        if (current->item.id == id)
        {
            printf("nodo encontrado con id %d y con edad %d\n", current->item.id, current->item.age);
        }

        current = current->next;
    }

    printf("No fue posible encontrar nodo con esa información\n");

    // End clock section
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to execute the function with the use of linked lists is: %.9f seconds\n", cpu_time_used);
}


//5
void insert_node_in_middle(t_node *head, unsigned int id)
{
    // Clock section
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Start function
    t_node *current = head;
    while (current != NULL)
    {
        if (current->item.id == 74999)
        {
            // Found the node after which we will insert the new node
            t_node *new_node = (t_node*) malloc(sizeof(t_node));
            new_node->item.id = 75000;
            new_node->item.age = current->next->item.age; // We set the age of the new node equal to the next node's age
            new_node->item.city = current->next->item.city; // We set the city of the new node equal to the next node's city
            new_node->item.gender = current->next->item.gender; // We set the gender of the new node equal to the next node's gender
            new_node->item.income = current->next->item.income; // We set the income of the new node equal to the next node's income
            new_node->item.illness = current->next->item.illness; // We set the illness of the new node equal to the next node's illness
            new_node->next = current->next;
            current->next = new_node;
            // We need to recalculate the id of all the elements after the new element
            t_node *recalculate_node = new_node->next;
            while (recalculate_node != NULL)
            {
                recalculate_node->item.id++;
                recalculate_node = recalculate_node->next;
            }
            printf("New node with id %d has been inserted after node with id 74999\n", new_node->item.id);
            break;
        }
        current = current->next;
    }

    // End clock section
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to execute the function with the use of linked lists is: %.9f seconds\n", cpu_time_used);
}


void count_people_by_city_report(t_node *head, char *city_name, int x_age)
{
    // Clock section
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Start function
    city_t city = get_city_t(city_name);
    int count = 0;
    t_node *current = head;
    while (current != NULL)
    {
        if (current->item.city == city && current->item.age == x_age)
        {
            count++;
        }
        current = current->next;
    }

    printf("Hay %d personas que viven en %s y tienen %d años.\n", count, city_names[city], x_age);

    // End clock section
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to execute the function with the use of linked lists is: %.9f seconds\n", cpu_time_used);
}

void call_all_methods_list(t_node *head, char *city_name, int id, int X, int Y)
{
    // Clock section
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Start function
    int numero = 0;
    count_people_by_city(head, &numero);
    char *city_char = "Dallas";
	city_t city = get_city_t(city_char);
	get_average_income_by_city_and_age(head, city, 32,60);
    get_probability_illness_by_age(head, 32);
	get_node_by_id(head, 12);
	insert_node_in_middle(head,74000);
    count_people_by_city_report(head, city_name, X);
    

    // End clock section
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to execute all of the linked lists functions is: %.9f seconds\n", cpu_time_used);
}
