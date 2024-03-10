/* Maintains a parts database (array version) */

#include <stdio.h>

#define NAME_LEN 25

#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

// int num_parts = 0;   /* number of parts currently stored */


/**********************************************************
 * read_line: Skips leading white-space characters, then  *
 *            reads the remainder of the input line and   *
 *            stores it in str. Truncates the line if its *
 *            length exceeds n. Returns the number of     *
 *            characters stored.                          *
 **********************************************************/
int read_line(char str[ ], int n);
int find_part(int number, const struct part inv[ ], int np);
void insert(struct part inv[ ], int *np);
void search(const struct part inv[ ], int np);
void update(struct part inv[ ], int np);
void print(const struct part inv[ ], int np);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void) {
    struct part inventory[MAX_PARTS];
    int num_parts = 0;
    char code;
    int *np = &num_parts;

    for (;;) {
        printf("Enter operation code: ");
        scanf("%c", &code);
        while (getchar() != '\n')   /* skips to end of line */
            ;
        switch (code) {
            case 'i': insert(inventory, np);
                break;
            case 's': search(inventory, *np);
                break;
            case 'u': update(inventory, *np);
                break;
            case 'p': print(inventory, *np);
                break;
            case 'q': return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}

/**********************************************************
 * find_part: Looks up a part number in the inventory     *
 *            array. Returns the array index if the part  *
 *            number is found; otherwise, returns -1.     *
 **********************************************************/
int find_part(int number, const struct part inv[ ], int np) {
    int i;

    for (i = 0; i < np; i++)
        if (inv[i].number == number)
            return i;
    return -1;
}

/**********************************************************
 * insert: Prompts the user for information about a new   *
 *         part and then inserts the part into the        *
 *         database. Prints an error message and returns  *
 *         prematurely if the part already exists or the  *
 *         database is full.                              *
 **********************************************************/
// 函数将新零件添加到数据库中。
void insert(struct part inv[ ], int *np) {
    int part_number;

    if (*np == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(part_number, inv, *np) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inv[*np].number = part_number;
    printf("Enter part name: ");
    read_line(inv[*np].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inv[*np].on_hand);
    (*np)++;
}

/**********************************************************
 * search: Prompts the user to enter a part number, then  *
 *         looks up the part in the database. If the part *
 *         exists, prints the name and quantity on hand;  *
 *         if not, prints an error message.               *
 **********************************************************/
// search函数通过零件号在数据库中搜索零件。
void search(const struct part inv[ ], int np) {
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, inv, np);
    if (i >= 0) {
        printf("Part name: %s\n", inv[i].name);
        printf("Quantity on hand: %d\n", inv[i].on_hand);
    }
    else
        printf("Part not found.\n");
}

/**********************************************************
 * update: Prompts the user to enter a part number.       *
 *         Prints an error message if the part doesn't    *
 *         exist; otherwise, prompts the user to enter    *
 *         change in quantity on hand and updates the     *
 *         database.                                      *
 **********************************************************/
// update函数更新数据库中零件的现有数量。
void update(struct part inv[ ], int np) {
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, inv, np);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inv[i].on_hand += change;
    }
    else
        printf("Part not found.\n");
}

/**********************************************************
 * print: Prints a listing of all parts in the database,  *
 *        showing the part number, part name, and         *
 *        quantity on hand. Parts are printed in the      *
 *        order in which they were entered into the       *
 *        database.                                       *
 **********************************************************/
// print函数打印数据库中所有零件的零件号，零件名称和现有数量。
void print(const struct part inv[ ], int np) {
    int i;

    printf("Part Number   Part Name                  "
        "Quantity on Hand\n");
    for (i = 0; i < np; i++)
        printf("%7d       %-25s%11d\n", inv[i].number, inv[i].name, inv[i].on_hand);
}
