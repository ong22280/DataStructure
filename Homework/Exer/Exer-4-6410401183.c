#include <stdio.h>



void main(void){
    struct address{
        char district[100];
        char city[100];
    };
    struct flower{
        int id;
        char name[100];
        double price;
        struct address st_addr;
    };
    struct flower f[100];
    for (int i=0; i<3; i++){
        printf("Enter flower id: ");
        scanf("%d", &f[i].id);
        printf("Enter flower name: ");
        scanf("%s", f[i].name);
        printf("Enter flower price: ");
        scanf("%lf", &f[i].price);
        printf("Enter flower district: ");
        scanf("%s", f[i].st_addr.district);
        printf("Enter flower city: ");
        scanf("%s", f[i].st_addr.city);
    }
    // print all flowers
    for (int i=0; i<3; i++){
        printf("Flower id: %d\n", f[i].id);
        printf("Flower name: %s\n", f[i].name);
        printf("Flower price: %lf\n", f[i].price);
        printf("Flower district: %s\n", f[i].st_addr.district);
        printf("Flower city: %s\n", f[i].st_addr.city);
    }
}