#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isStrongPassword(char pwd[])
{
    int upper = 0, lower = 0, digit = 0;

    if (strlen(pwd) < 6)
        return 0;

    for (int i = 0; pwd[i] != '\0'; i++)
    {
        if (isupper(pwd[i])) upper = 1;
        else if (islower(pwd[i])) lower = 1;
        else if (isdigit(pwd[i])) digit = 1;
    }

    return upper && lower && digit;
}

int main()
{
    char username[20] = "";
    char password[20] = "";
    char inputUser[20], inputPass[20];
    int choice, attempts;

    while (1)
    {
        printf("\n=============================================\n");
        printf("  GOVERNMENT CERTIFICATE MANAGEMENT PORTAL\n");
        printf("=============================================\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n--- USER REGISTRATION ---\n");
            printf("Create Username: ");
            scanf("%s", username);

            printf("Create Password: ");
            scanf("%s", password);

            while (!isStrongPassword(password))
            {
                printf("\nWeak Password!\n");
                printf("Password must contain:\n");
                printf("- Minimum 6 characters\n");
                printf("- Uppercase letter\n");
                printf("- Lowercase letter\n");
                printf("- Digit\n");

                printf("\nRe-enter Password: ");
                scanf("%s", password);
            }

            printf("\nRegistration Successful \n");
            break;

        case 2:
            if (strlen(username) == 0)
            {
                printf("\nPlease register first!\n");
                break;
            }

            attempts = 3;
            printf("\n--- GOVERNMENT PORTAL LOGIN ---\n");

            while (attempts > 0)
            {
                printf("Enter Username: ");
                scanf("%s", inputUser);

                printf("Enter Password: ");
                scanf("%s", inputPass);

                if (strcmp(username, inputUser) == 0 &&
                    strcmp(password, inputPass) == 0)
                {
                    printf("\n=============================================\n");
                    printf("  ACCESS GRANTED\n");
                    printf("  Welcome to Government Certificate Portal\n");
                    printf("=============================================\n");
                    break;
                }
                else
                {
                    attempts--;
                    printf("\nInvalid Credentials!\n");
                    printf("Attempts Remaining: %d\n", attempts);
                }
            }

            if (attempts == 0)
            {
                printf("\n=============================================\n");
                printf("  ACCOUNT LOCKED\n");
                printf("  Reason: Multiple Failed Login Attempts\n");
                printf("=============================================\n");
            }
            break;

        case 3:
            printf("\nExiting Government Portal...\n");
            return 0;

        default:
            printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}
