#!/bin/bash

./antman/antman test/test_ant option > tmp/tmp_antman
./giantman/giantman test/test_giant > tmp/tmp_giantman

./antman/antman test/test_ant 2> tmp/error_tmp_antman
./giantman/giantman test/test_giant 2> tmp/error_tmp_giantman

echo ""
fileName="tmp/tmp_antman"
mysize=$(find "$fileName" -printf "%s")
echo "${fileName} size is ${mysize} bytes."
echo ""

fileName2="tmp/tmp_giantman"
mysize2=$(find "$fileName2" -printf "%s")
echo "${fileName2} size is ${mysize2} bytes."
echo ""

percentage=$((($mysize2 * 100) / $mysize))
percentage=$((100 - $percentage))
echo "The file was compressed and reduced to $percentage % of its original size."

# ERROR

fileNameerror="tmp/error_tmp_antman"
mysizeerror=$(find "$fileNameerror" -printf "%s")

fileNameerror2="tmp/error_tmp_antman"
mysizeerror2=$(find "$fileNameerror2" -printf "%s")
echo ""

if [ -z $my_sizeerror ];
then
    echo "Il n'y a pas d'erreurs dans le antman"
else
    nb_erreurs_antman=$(cat tmp/error_tmp_antman)
    echo "Il y a $nb_erreurs_antman dans le antman"
fi

if [ -z $my_sizeerror2 ]
then
    echo "Il n'y a pas d'erreurs dans le giantman"
else
    nb_erreurs_giantman=$(cat tmp/error_tmp_giantman)
    echo "Il y a $nb_erreurs_giantman dans le giantman"
fi
