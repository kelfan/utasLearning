#! /bin/sh
# This program copies a file into a safe directory without overwriting. For example, it # copies a file named foo to foo.1 if foo exists in the destination directory, or to # foo.2 if foo.1 exists in the destination directory.
# To run the script, two arguments are required in the command line, a source file, # followed by a destination directory. Without two arguments, the scrip displays the # usage information, and exits
if [ $# -ne 2 ] ; then
    echo "Usage: $0 source destination"; exit
# The script also requires that the second argument must be an existing directory file, # if not, displays an error message and exits
elif [ ! -d $2 ] ; then
    echo "Directory does not exist" ; exit
else
# assign the first argument (the source filename) as value to variable file file=$1
# If the source file does not exist in the destination directory, then simply copy it # into the directory
    if [ ! -f $2/$file ] ; then
        cp $1 $2
        # But if the source file does exist in the destination directory, then we have to do # something to avoid overwriting
    else
        copies=1 # The variable copies takes 1 as initial value 
        while true 
        do
            if [ ! -f $2/$file.$copies ] ; then
                cp $1 $2/$1.$copies
                echo "File $1 copied to $1.$copies"
                break
            else
                copies=`expr $copies + 1`
            fi
        done
    fi 
fi