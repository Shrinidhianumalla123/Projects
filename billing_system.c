
#include <stdio.h>
int main()
{

    float prices[5] = {600.00, 70.00, 1000.00, 899.00, 299};
    int choice, quantity;
    float total = 0.0;
    int more;
    printf("------ PRODUCTS AVAILABLE ------\n");
printf("1. LipGloss  - Rs 600.00\n");
printf("2. Lipliner  - Rs 70.00\n");
printf("3. Liptint   - Rs 1000.00\n");
printf("4. Lipstick  - Rs 899.00\n");
printf("5. Lipbalm   - Rs 299.00\n");
    do
    {
        printf("\nEnter product number (1-5): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 5)
        {
            printf("Invalid choice!\n");
            continue;
        }
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        total += prices[choice - 1] * quantity;

        printf("Do you want to add another item? (1-YES, 0-NO): ");
        scanf(" %d", &more);  

    } while (more == 1);

    float cgst = total*0.02;
    float sgst = total*0.02;
    float grandTotal = total + cgst + sgst;

    printf("\n------------ BILL ------------\n");
    printf("Total Amount : Rs %f\n", total);
    printf("CGST         : Rs %f\n", cgst);
    printf("SGST         : Rs %f\n", sgst);
    printf("--------------------------------\n");
    printf("Grand Total  : Rs %f\n", grandTotal);

    return 0;
}
