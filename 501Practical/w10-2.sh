#! /bin/sh 
# This script repeatedly accepts a two digit code (such as 01, 02, etc) and its
# corresponding description (such as engineer) from keyboard, performs some # validation check, and then adds the entry into a text file named newlist 
# First create a new blank text file named newlist, if it does not currently exist 
if [ ! -f newlist ]; then 
 echo > newlist
fi
# Start the outer loop by prompting the user to enter a code 
while echo -e "Designation code: \c" do 
  read code
  case "$code" in
# Ensure the two digit code is in correct format, and does not currently exist 
    [0-9][0-9]) if grep "$code" newlist >/dev/null
                then echo "Code exists"; continue
                fi ;;
             *) echo "Invalid code"  ; continue ;;
esac 
# Start the inner loop by prompting the user to enter a description 
while echo -e "Description: \c"; do 
read desc 
    case "$desc" in
# This is how to ensure that the user has entered a valid description, which # contains letters and spaces only 
*[!\ a-zA-Z]*) echo "Can contain only letters and spaces"; continue ;;
# If the user simply presses the Enter key, without typing anything 
esac 
done 
"") echo "Description not entered" ; continue ;;
# The user has entered a valid description, add it together with # the previously entered valid code into the file 
*) echo "$code|$desc" >> newlist ; break ;; 
    echo -e "\nEnter another entry? (y/n): \c"
    read answer
    case "$answer" in
[yY]*) continue ;; *) break ;; 
esac 
done 
