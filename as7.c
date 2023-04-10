#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 9
#define COLUMNS 9
#define INT_MAX 2147483647

int minDistance(int dist_from_src[], bool visited_nodes[]) {
    int min_dist = INT_MAX, min_index;
    for (int i = 0; i < COLUMNS; i++) {
        if (visited_nodes[i] == false && dist_from_src[i] <= min_dist) {
            min_dist = dist_from_src[i], min_index = i;
  }
    }
    return min_index; }

int main() {
    bool road_networks[ROWS][COLUMNS] = {
        //      {a, b, c, d, e, f, g, h, i} //
        /* a */ {1, 1, 0, 0, 0, 1, 0, 0, 0},
        /* b */ {1, 1, 1, 0, 0, 0, 0, 0, 0},
        /* c */ {0, 1, 1, 0, 1, 1, 0, 0, 1},
        /* d */ {0, 0, 0, 1, 1, 0, 0, 0, 0},
        /* e */ {0, 0, 0, 1, 1, 0, 0, 0, 0},
        /* f */ {1, 0, 1, 0, 0, 1, 0, 0, 0},
        /* g */ {1, 0, 0, 1, 0, 0, 1, 0, 0},
        /* h */ {0, 0, 0, 0, 0, 0, 0, 1, 1},
        /* i */ {0, 0, 0, 0, 0, 0, 0, 1, 1}
    };

    printf("        Adjacency Matrix       \n\n");
    for (int i = 0; i < ROWS + 1; i++) {
        for (int j = 0; j < COLUMNS + 1; j++) {
            if (i == 0 && j == 0) {
                printf("    ");
            }
            else if (i == 0 || j == 0) {
                switch (abs(i-j)) {
                    case 3: case 4: printf("[%c] ", 64 + abs(i-j)); break;
                    default: printf(" %c  ", 64 + abs(i-j)); break;
                }
            }
            else {
                printf(" %d  ", road_networks[i-1][j-1]);
            }
        }
        printf("\n");
    }   printf("\n");

    int src;
    printf("At which point are you currently located (0 - A, 1 - B, 2 - C, 3 - D, 4 - E, 5 - F, 6 - G, 7 - H, 8 - I): ");
    do {
        scanf("%d", &src);
        if (src < 0 || src > 8) {
            printf("You have inputted an invalid point address. Please try again: ");
        }
    } while (src < 0 || src > 8); printf("\n");
    
    int dist_from_src[COLUMNS];
    bool visited_nodes[COLUMNS];

    for (int i = 0; i < COLUMNS; i++) {
        dist_from_src[i] = INT_MAX, visited_nodes[i] = false;
    }
   
    dist_from_src[src] = 0;
\
    for (int count = 0; count < COLUMNS - 1; count++) {
        int current_node = minDistance(dist_from_src, visited_nodes);
        visited_nodes[current_node] = true;
        for (int adjacent_node = 0; adjacent_node < COLUMNS; adjacent_node++) {
            if (!visited_nodes[adjacent_node]
                && road_networks[current_node][adjacent_node]
                && dist_from_src[current_node] != INT_MAX
                && dist_from_src[current_node] + road_networks[current_node][adjacent_node] < dist_from_src[adjacent_node]) {
                    dist_from_src[adjacent_node] = dist_from_src[current_node] + road_networks[current_node][adjacent_node];
            }
        }
    }

    if (src == 2 || src == 3) {
        printf("Point %c is already a charging station\n", 65 + src);
    }
    else if (dist_from_src[2] == INT_MAX && dist_from_src[3] == INT_MAX) {
        printf("You are currently at Point %c.\n", 65 + src);
        printf("There are no near charging stations at this point.\n");
    }      
    else {
        printf("You are currently at Point %c.\n", 65 + src);
        printf("The nearest charging station to Point %c is Point %c.\n", 65 + src, 67 + (dist_from_src[2] > dist_from_src[3]));
    }
 
    return 0; 

}  