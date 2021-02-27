#!/bin/bash
#
# TO USE:
#
# Install experiencetable into your path, so that typing
#
#    experiencetable
#
# will attempt to run the program, rather than giving and error about
# not being found.
#
# Also note that you may need to modify the date format for your local
# system.  BSD and OSX have different date formatting capabilities.
# Alternatively, you could just output the file name, especially if you
# give your experience files meaningful names.
#
# You mmight also want to put in a header to output the frontmatter
# used by your CMS as part of this script.

# Hugo frontmatter
echo "---"
echo "title: \"Experience Totalsi\""
echo "---"
echo

FILES=.

if [ "$#" -eq 1 ]; then
	FILES=$1
fi

echo "# Experience Total"
echo 
experiencetable --markdown $FILES
echo

for f in `ls -rt ${FILES}/*.yaml`; do
	echo -n "## "
	date -r $f "+%B-%d-%Y"
	echo
	experiencetable --markdown $f 
	echo
done
