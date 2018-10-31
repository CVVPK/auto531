# Auto 5/3/1

This program is used to automate the process of calculating the main lifts for the 5/3/1 training program. It outputs the planned warm up and work sets to a file named liftTomorrow.txt to be used as a template for an automated email that is sent the day before the planned lift. It requires to set the starting date of the program and starting training maxes (90% of actual 1RM as described in the book) for all 4 lifts.

Use getDate(day,month,year) to find the starting date in seconds which is what the program uses to know what cycle and week you're working on. It calculates deloads every other cycle as recommended in Beyond 5/3/1.
