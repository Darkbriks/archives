#include "types.h"
#include "user.h"
#include "date.h"
#include <stddef.h>

// Fonction qui modifie le fuseau horaire de maniere extremement basique et imparfaite
uint set_timezone(uint hour, int timezone)
{
    return hour += timezone;
}

int main(int argc, char *argv[])
{
	struct rtcdate r;
	int timezone = 0;

	if (argc == 2 && argv[1][0] == '-' && argv[1][1] != '\0')
    {
        int i = atoi(argv[1] + 1);
        if (i >= -12 && i <= 12)
        {
            timezone = i;
        }
        else
        {
            printf(2, "Invalid timezone\n");
            exit();
        }
    }

	if (argc == 3 && argv[1][0] == '-' && argv[1][1] != '\0' && argv[2][0] == '-' && argv[2][1] != '\0')
    {
        int i = atoi(argv[1] + 1);
        if (i >= -12 && i <= 12)
        {
            timezone = i;
			timezone *= -1;
        }
        else
        {
            printf(2, "Invalid timezone\n");
            exit();
        }
    }

	else if (argc > 3)
    {
        printf(2, "Usage: date [-<timezone>] [-<backward>]\n");
        exit();
    }
	
	if (date(&r) == -1)
	{
		printf(2, "date failed\n");
		exit();
	}

	// Changement de fuseau
	r.hour = set_timezone(r.hour, timezone);
	
	// Code d'affichage de la date
	printf(1, "date : %d/%d/%d\n", r.day, r.month, r.year);
	printf(1, "time : %d:%d:%d\n", r.hour, r.minute, r.second);
	
	exit();
}
