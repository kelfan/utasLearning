// if 语句

int x = 10;
int y = 5;
int result = 0;

if (x % y == 0) {
    result = 1;
    if (x < y) {
        result = 2;
    } else {
        result = 3;
    }
} else {
    result = 4;
}


// switch 语句 
string day;
string message;

Console.Write("What day is it today? ");
day = Console.ReadLine();

switch (day.ToLower())
{
    case "sunday":    message = "Time for the weekly shopping"; break;
    case "monday":    message = "I hate Mondays - Garfield"; break;
    case "tuesday":   message = "Only four more days to go"; break;
    case "wednesday": message = "Middle of the week!"; break;
    case "thursday":  message = "Will there be thunder later?"; break;
    case "friday":    message = "TGIF!"; break;
    case "saturday":  message = "It's the weekend!"; break;
    default: message = "I don't understand what day of the week '" + day + "' is."; break;
}

Console.WriteLine(message);

// array 
int[] counts = {1, 0, 5, 7, 4, 2, 1};

// for 循环 
            int[] counts={1,0,5,7,4,2,1};
            for (int i = 0; i <= 6; i++)
            {
                Console.Write("{0} | ",i);
                for (int j = 1; j <= counts[i]; j++)
                {
                    Console.Write('*');
                }
                Console.WriteLine();
            }