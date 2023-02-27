#include "base_struct.h"
#include <time.h>

// ARRAY FUNCTIONS

//--------------------
// 1
void generarReporteCiudades(item_t items[])
{
    // Clock section
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Start function
    int city;
    item_t item;
    int size = 150000;
    int qPeople[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < size; i++)
    {
        item = items[i];
        city = item.city;
        switch (city)
        {
        case 0:
            qPeople[0] = qPeople[0] + 1;
            break;
        case 1:
            qPeople[1] = qPeople[1] + 1;
            break;
        case 2:
            qPeople[2] = qPeople[2] + 1;
            break;
        case 3:
            qPeople[3] = qPeople[3] + 1;
            break;
        case 4:
            qPeople[4] = qPeople[4] + 1;
            break;
        case 5:
            qPeople[5] = qPeople[5] + 1;
            break;
        case 6:
            qPeople[6] = qPeople[6] + 1;
            break;
        case 7:
            qPeople[7] = qPeople[7] + 1;
            break;
        default:
            qPeople[8] = qPeople[8] + 1;
            break;
        }
    }
    printf("- La cantidad en Dallas es: %d\n", qPeople[0]);
    printf("- La cantidad en New York es: %d\n", qPeople[1]);
    printf("- La cantidad en Los Angeles es: %d\n", qPeople[2]);
    printf("- La cantidad en Mountain View es: %d\n", qPeople[3]);
    printf("- La cantidad en Boston es: %d\n", qPeople[4]);
    printf("- La cantidad en Whashington D.C es: %d\n", qPeople[5]);
    printf("- La cantidad en San Diego es: %d\n", qPeople[6]);
    printf("- La cantidad en Austin es: %d\n", qPeople[7]);

    // End clock section
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to execute the function with the use of arrays is: %.9f seconds\n", cpu_time_used);
}

//--------------------
// 2
void get_average_income(item_t items[], char *city_name, int X, int Y)
{
    // Clock section
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Start function
    double sum = 0;
    int count = 0;
    city_t city = get_city_t(city_name);

    for (int i = 0; i < 150000; i++)
    {
        if (items[i].city == city && items[i].age >= X && items[i].age <= Y)
        {
            sum += items[i].income;
            count++;
        }
    }

    if (count == 0)
    {
        printf("No matching persons found in %s with ages between %d and %d\n", city_name, X, Y);
    }
    else
    {
        float result = sum / count;
        printf("Average income of persons in %s between ages %d and %d: %.2f\n", city_name, X, Y, result);
    }

    // End clock section
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to execute the function with the use of arrays is: %.9f seconds\n", cpu_time_used);
}

//--------------------
// 3

void generarProbabilidadEnfermedad(item_t items[])
{
    // Clock section
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Start function
    int age;
    item_t item;
    int size = 150000;
    int qPeople = 0;
    int qSickPeople = 0;

    printf("Ingrese la edad mínima: ");
    scanf("%d", &age);

    for (int i = 0; i < size; i++)
    {
        item = items[i];
        if (item.age >= age)
        {
            qPeople++;
            if (item.illness == true)
            {
                qSickPeople++;
            }
        }
    }

    printf("Cantidad de personas: %d\n", qPeople);
    printf("Cantidad personas enfermas: %d\n", qSickPeople);

    float prob = (float)qSickPeople / qPeople;
    prob = prob * 100;

    printf("La probabilidad de estar enfermo cuando se tienen %d o más años es del %f porciento.\n", age, prob);
    
    // End clock section
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to execute the function with the use of arrays is: %.9f seconds\n", cpu_time_used);
}

//--------------------
// 4
void find_person_by_id(item_t items[], int id)
{
    // Clock section
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Start function

    for (int i = 0; i < 150000; i++)
    {

        if (items[i].id == id)
        {
            printf("Item with ID %d:\n", id);
            printf("ID: %d\n", items[i].id);
            printf("City: %s\n", city_names[items[i].city]);
            printf("Age: %d\n", items[i].age);
            printf("Gender: %s\n", gender_names[items[i].gender]);
            printf("Income: %d\n", items[i].income);
            printf("Illness: %s\n", illness_values[items[i].illness]);
            // End clock section
            end = clock();
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Time taken to execute the function with the use of arrays is: %.9f seconds\n", cpu_time_used);
            return;
        }
    }

    printf("Item with ID %d not found.\n", id);


}
//--------------------
// 5

void insertarNuevoElemento(item_t items[])
{
    // Clock section
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Start function
    int size = 150000;
    int half = 75000;
    int city, gen, age, income, illness, i;
    item_t *newItems;

    newItems = (item_t *)malloc(sizeof(int) * (size + 1));

    for (i = 0; i < half; i++)
    {
        printf("%d\n", i);
        newItems[i] = items[i];
    }

    while (1)
    {
        printf("\nIngrese un numero dependiendo de la ciudad: \n");
        printf("1 para Dallas. \n");
        printf("2 para New York City. \n");
        printf("3 para Los Angeles. \n");
        printf("4 para Mountain View. \n");
        printf("5 para Boston. \n");
        printf("6 para Washington D.C.. \n");
        printf("7 para San Diego. \n");
        printf("8 para Austin. \n");
        scanf("%d", &city);
        if (city > 0 && city < 9)
        {
            break;
        }
        else
        {
            printf("\nIntente de nuevo, ha ingresado un numero erroneo.\n");
        }
    }
    newItems[half].city = city - 1;

    while (1)
    {
        printf("\nIngrese un numero dependiendo del genero: \n");
        printf("1 para femenino. \n");
        printf("2 para masculino. \n");
        printf("3 para no. \n");
        scanf("%d", &gen);
        if (gen > 0 && gen < 4)
        {
            break;
        }
        else
        {
            printf("\nIntente de nuevo, ha ingresado un numero erroneo.\n");
        }
    }
    switch (gen)
    {
    case 1:
        newItems[half].gender = FEMALE;
        break;
    case 2:
        newItems[half].gender = MALE;
        break;
    case 3:
        newItems[half].gender = NO;
        break;
    }

    printf("\nIngrese la edad: \n");
    scanf("%d", &age);
    newItems[half].age = age;

    printf("\nIngrese el salario: \n");
    scanf("%d", &income);
    newItems[half].income = income;

    while (1)
    {
        printf("\nIngrese un numero dependiendo del estado de salud: \n");
        printf("1 para esta enfermo. \n");
        printf("2 para no esta enfermo. \n");
        printf("3 para no sabe. \n");
        scanf("%d", &illness);
        if (illness > 0 && illness < 4)
        {
            break;
        }
        else
        {
            printf("\nIntente de nuevo, ha ingresado un numero erroneo.\n");
        }
    }
    switch (illness)
    {
    case 1:
        newItems[half].illness = true;
        break;
    case 2:
        newItems[half].illness = false;
        break;
    case 3:
        newItems[half].illness = fuzzy;
        break;
    }

    for (i = half; i < size; i++)
    {
        newItems[i + 1] = items[i];
    }

    printf("\nEl usuario anterior de la mitad tiene %d años.\n", items[half].age);
    printf("\nEl nuevo usuario de la mitad tiene %d años.\n", newItems[half].age);

    // End clock section
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to execute the function with the use of arrays is: %.9f seconds\n", cpu_time_used);
}

//-------------------
// 6

void find_persons_by_city_and_age(item_t items[], char *city_name, int X)
{
    // Clock section
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Start function
    int count = 0;
    for (int i = 0; i < 150000; i++)
    {
        if (items[i].city == get_city_t(city_name) && items[i].age == X)
        {
            count++;
        }
    }
    printf("Number of persons with age %d in %s: %d\n", X, city_name, count);
    
    // End clock section
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to execute the function with the use of arrays is: %.9f seconds\n", cpu_time_used);
}

//-------------------
// 7

void call_all_methods(item_t items[], char *city_name, int id, int X, int Y)
{
    // Clock section
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Start function
    get_average_income(items, city_name, X, Y);
    find_person_by_id(items, id);
    find_persons_by_city_and_age(items, city_name, X);


    // End clock section
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to execute all of the array functions is: %.9f seconds\n", cpu_time_used);
}