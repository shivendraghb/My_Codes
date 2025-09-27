#define MAX_ROWS int
#define MAX_COLUMNS 32

#define ALIVE 'X'
#define DEAD '.'


typedef struct {
    unsigned short rows;
    unsigned short columns;
    unsigned MAX_ROWS current[MAX_COLUMNS];
    unsigned MAX_ROWS next[MAX_COLUMNS];

} Field;
int main(void)
{

    // Create 20x20 field.
    Field fieldMatrix = {
        .rows = 20,
        .columns = 20,
    };

    setAllDead(&fieldMatrix);
    fieldMatrix.current[0] = 2;// . X .
    fieldMatrix.current[1] = 4;// X . .
    fieldMatrix.current[2] = 7;// X X X

    int ch;

    while (1)
    {
        drawField(&fieldMatrix);

        printf("        Select one of the following options:\n");
        printf("        (enter) Step\n        (any)   Exit\n");

        ch = getchar();


        if (ch != '\n') {
            break;
        }
        createNextGeneration(&fieldMatrix);
        update(&fieldMatrix);

    }
    return 0;
}
void drawField(Field *field)
{

    for (short c=0;c<field->columns;c++) {
        for (short r=field->rows;r>=0;r--) {
            if ((field->current[c] & (1<<r)) >= 1) {
                printf("%c ",ALIVE);
            } else {
                printf("%c ",DEAD);
            }
        }
        printf("%u\n",field->current[c]);// Debug
    }
}
/*
 * Description: Perform game logic for next turn.
 * Input:       Field struct.
 */
void createNextGeneration(Field *field)
{
    for (short c=0;c<field->columns;c++) {
        unsigned MAX_ROWS rowNext = 0;// Assume everyone died
        for (short r=0;r<field->rows;r++) {
            int alive = isAlive(field,r,c);
            int cnt = getLiving3x3Count(field,r,c) - alive;

            if (alive) {
                if (cnt == 2 || cnt == 3) {// Living cell has 3 or 4 living neighbours survives
                    rowNext |= 1<<r;
                }
            } else {
                if (cnt == 3) {
                    rowNext |= 1<<r;// Dead cell becomes alive if it has exactly 3 living neighbours
                }
            }
        }
        field->next[c] = rowNext;
    }
}

/*
 * Description: Update next generation to current generation.
 * Input:       Field struct.
 */
void update(Field *field)
{
    for (short c=0;c<field->columns;c++) {
        field->current[c] = field->next[c];
    }
}

/*
 * Description: Get if cell at position is alive.
 * Input:       Field struct and position of cell.
 * Output:      1 if alive and 0 if dead.
 */
int isAlive(Field *field, unsigned short x, unsigned short y)
{
    if ((field->current[y] & (1<<x)) >= 1) {
        return 1;
    } else {
        return 0;
    }
}

/*
 * Description: Get living cells around (3x3) cell at position.
 * Input:       Field struct and Position of middle cell.
 * Output:      The amount of living cells.
 */
int getLiving3x3Count(Field *field, short x, short y)
{
    int sum = 0;
    unsigned MAX_ROWS tmp;

    unsigned MAX_ROWS mask = 1<<(x-1) | 1<<x | 1<<(x+1);// Mask of bits

    for (short c=y-1;c<(y+2);c++) {
        if (c < 0 || c >= field->rows) {// Skip if out-of-bounds
            continue;
        }

        tmp = field->current[c] & mask;// Grap row and mask
        tmp = tmp >> (x-1);// Shift to very right

        sum += (tmp & 1) + ((tmp>>1) & 1) + ((tmp>>2) & 1);// Count bits
    }
    return sum;
}
