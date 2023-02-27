#ifndef __BASE_SRUC_H_
#define __BASE_SRUC_H_

typedef enum
{
	D = 0, //->"Dallas"
	N = 1, //-> "New York City""
	L = 2, //-> "Los Angeles"
	M = 3, //-> "Mountain View"
	B = 4, //-> "Boston"
	W = 5, //-> "Washington D.C."
	S = 6, //-> "San Diego"
	A = 7, //-> "Austin"
	E = 8, //-> "Not found"
} city_t;

const char *const city_names[9];

city_t get_city_t(char *city_name);

typedef enum
{
	FEMALE,
	MALE,
	NO
} gender_t;

const char *const gender_names[3];

gender_t get_gender_t(char *gender_name);

typedef enum
{
	false,
	true,
	fuzzy
} bool_t;

const char *const illness_values[3];

bool_t get_illness_t(char *illness_value);

typedef struct s_item
{
	unsigned int id;
	city_t city;
	unsigned int age;
	gender_t gender;
	int income;
	bool_t illness;
} item_t;

typedef struct s_node
{
    /* data */
    struct s_item item;
    struct s_node *next;
} t_node;

t_node *initializeNode(t_node *node);

t_node *addNode(t_node *node, item_t name);

// ARRAY FUNCTIONS
void generarReporteCiudades(item_t items[]);
void get_average_income(item_t items[], char *city_name, int X, int Y);
void generarProbabilidadEnfermedad(item_t items[]);
void find_person_by_id(item_t items[], int id);
void insertarNuevoElemento(item_t items[]);
void find_persons_by_city_and_age(item_t items[], char *city_name, int X);
void call_all_methods(item_t items[], char *city_name, int id, int X, int Y);

// LIST FUNCTIONS
void count_people_by_city(t_node *node, int *count);
void get_average_income_by_city_and_age(t_node *head, city_t city, int x_age, int y_age);
void get_probability_illness_by_age(t_node *head, int x_age);
void *get_node_by_id(t_node *head, unsigned int id);
void insert_node_in_middle(t_node *head, unsigned int id);
void count_people_by_city_report(t_node *head, char *city_name, int x_age);
void call_all_methods_list(t_node *head, char *city_name, int id, int X, int Y);

//MENU
void menu(item_t items[],t_node head);

#endif
