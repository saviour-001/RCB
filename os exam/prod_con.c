#include <stdio.h>
#include <stdlib.h>
int full = 0, empty = 3, x, mutex = 1;
int wait(int s)
{
    return (--s);
}
int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex = wait(mutex);//locked
    full = signal(full);//
    empty = wait(empty);
    x++;
    printf("\nProducer produces an item %d", x);
    mutex = signal(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes an item %d", x);
    x--;
    mutex = signal(mutex);
}
int main()
{
    while (1)
    {
        int choice;
        printf("\n\n1. Producer\n2. Consumer\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            if ((mutex == 1) && (empty != 0))
                producer();

            else
                printf("\nBuffer is full");
            break;
        }
        case 2:
        {
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("\nBuffer is empty");
            break;
        }
        case 3:
            exit(0);
        default:
            printf("\nInvalid choice! Please enter again.");
        }
    }
}