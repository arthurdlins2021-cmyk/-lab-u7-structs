#include <stdio.h>

struct ponto {
    int x, y;
};

void move(struct ponto *p, int dx, int dy) {
    p->x = p->x + dx;
    p->y = p->y + dy;
}

int main(void) {
    struct ponto pt = {1, 1};
    move(&pt, 4, 2);
    printf("(%d, %d)\n", pt.x, pt.y);
    return 0;
}
