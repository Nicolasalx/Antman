################## \\ Option Compression/Decompression //#########################
draw_feature() {
    ligne1="                  Welcolme on the features"
    ligne2="- This program is an interface for compressing and decompressing files."
    ligne3="- It displays a menu with several options for the users to choose from, including options for compressing and decompressing files."
    ligne4="- The antman function allows the user to select a file to compress and an output location for the compressed file."
    ligne5="- It then displays a progress bar while the file is being compressed, and finally shows the percentage of the file size after compression."
    ligne6="- The giantman function allows the user to select a file to decompress and an output location for the decompressed file."
    ligne7="- It then displays a progress bar while the file is being decompressed, and finally shows the percentage of the file size after decompression."
    ligne8="- The ls_antman_choose_file_start, ls_antman_choose_file_end, Load_antman, ls_giantman_choose_file_start, ls_giantman_choose_file_end, Load_giantman functions are helper functions for the antman and giantman functions."
    ligne9="- They allow the user to select a file and output location for compressing or decompressing, and display a progress bar while the file is being processed."
    ligne10="- The Window function displays the menu again, allowing the user to choose another option."
    ligne11="- The draw_feature function displays the menu with the options, and the feature function calls draw_feature and then Window."
    whiptail --title "FEATURES" --msgbox "$ligne1\n\n$ligne2\n$ligne3\n\n$ligne4\n$ligne5\n\n$ligne6\n$ligne7\n\n$ligne8\n$ligne9\n\n$ligne10\n$ligne11\n" 37 70
    Window
}

feature() {
    draw_feature
}

################## \\ END Option Compression/Decompression //#########################

################## \\ Option Compression //#########################
file_choose_1=""
file_choose_2=""
username="$USER"

ls_antman_choose_file_start() {
    options=$(ls -1 | awk '{print NR " " $0}')
    selected=$(whiptail --title "Antman" --menu "Choose a file to zip" 20 78 10 $options 3>&1 1>&2 2>&3)
    option=$(echo "$options" | grep "^$selected " | awk '{print $2}')
    file_choose_1="$option"
    if [ -z $selected ]; then Window; else Load_antman; fi
}

Load_antman() {
    {
        i="0"
        while (true)
        do
            sleep 0.01
            echo $i
            i=$(expr $i + 1)
            if [[ $i -eq 100 ]]; then break; fi
        done
        sleep 0.1
        exit 1
    } | whiptail --title "Antman" --gauge "Loading.." 8 78 0

    filename=$file_choose_1
    extension="${filename##*.}"
    ./antman_bonus $file_choose_1 > $file_choose_1.data
    show_percentage
}

show_percentage() {
    fileName="$file_choose_1"
    mysize=$(find "$fileName" -printf "%s")

    fileName2="$file_choose_1.data"
    mysize2=$(find "$fileName2" -printf "%s")

    percentage=$((($mysize2 * 100) / $mysize))
    percentage=$((($percentage - 100) * - 1))

    size1="${fileName} size is ${mysize} bytes."
    size2="${fileName2} size is ${mysize2} bytes."
    size_final="The size of our magnific program after decompression is $percentage"
    whiptail --title "Percentage" --msgbox "$size1\n$size2\n$size_final %" 10 78
    rm $file_choose_1
    Window
}



antman() {
    ls_antman_choose_file_start
}
################## \\ END Option Compression //#########################

################## \\ Option Decompression //#########################
file_choose_1=""
file_choose_2=""
username="$USER"

ls_giantman_choose_file_start() {
    options=$(ls -1 | awk '{print NR " " $0}')
    selected=$(whiptail --title "Giantman" --menu "Choose a file to dezip" 20 78 10 $options 3>&1 1>&2 2>&3)
    option=$(echo "$options" | grep "^$selected " | awk '{print $2}')
    file_choose_1="$option"
    if [ -z $selected ]; then Window; else Load_giantman; fi
}

draw_comparaison_file() {
    ligne1="The comparaison between File1 and File2 is 100% same."
    whiptail --title "Comparaison" --msgbox "$ligne1" 8 70
    rm $file_choose_1
    Window
}

Load_giantman() {
    {
        i="0"
        while (true)
        do
            sleep 0.01
            echo $i
            i=$(expr $i + 1)
            if [[ $i -eq 100 ]]; then break; fi
        done
        sleep 0.1
        exit 1
    } | whiptail --title "Giantman" --gauge "Loading.." 8 78 0
    fichier=$file_choose_1
    emplacement=$(echo $fichier | awk -F. '{for(i=NF;i>0;i--)if(length($i)){print length($0) - length($i) - 1; exit}}')
    stocker=$(echo "$fichier" | cut -c1-$emplacement)
    ./giantman_bonus $file_choose_1 > $stocker
    draw_comparaison_file
}

giantman()
{
    ls_giantman_choose_file_start
}

################## \\ END Option Decompression //#########################

################## \\ Option Help //#########################
draw_help() {
    ligne1="                  Welcolme on the help system"
    ligne2="-> Choose Option 1 for compress it's the part of Antman."
    ligne3="-> Choose Option 2 for decompress it's the part of Giantman."
    ligne4="-> Choose Option 3 for draw features for description of the program."
    ligne5="-> Choose Option 4 for display help for the program."
    ligne6="                            ANTMAN"
    ligne7="- For compress a file u need to choose the file at compress."
    ligne8="- After u choose the emplacement for stock the file compress."
    ligne9="- The loading compression is starting and stop when it's finish."
    ligne10="- The percentage of compression is write."
    ligne11="- The percentage is based on the size of the file before compress and the file compressed which is the file in the new emplacement".
    ligne12="                           GIANTMAN"
    ligne13="- For decompress a file u need to choose the file at decompress precedently compress."
    ligne14="- After u choose the emplacement for stock the file decompress"
    ligne15="- The loading decompression is starting and stop when it's finish."
    ligne16="- The similitude in percentage is write."
    ligne17="- The percentage is based on the comparaison of the file line per line."
    ligne18="                           FEATURES"
    ligne19="- The features is the description of the program."
    ligne20="- He describes the entire program steps."
    ligne21="- If u press Ok it will choose the option where ur pointer is placed."
    ligne22="- If u press Cancel it will back to the menu."
    whiptail --title "HELP" --msgbox "$ligne1\n\n$ligne2\n$ligne3\n$ligne4\n$ligne5\n\n$ligne6\n$ligne7\n$ligne8\n$ligne9\n$ligne10\n$ligne11\n\n$ligne12\n$ligne13\n$ligne14\n$ligne15\n$ligne16\n$ligne17\n\n$ligne18\n$ligne19\n$ligne20\n\n$ligne21\n$ligne22\n" 38 70
    Window
}

################## \\ END Option Help //#########################
Window() {
    choice=$(whiptail --title "Antman Project" --menu "Menu" 15 60 4 \
        "1" "Antman" \
        "2" "Giantman" \
        "3" "Features" \
        "4" "Press this for help" 3>&1 1>&2 2>&3)
    case $choice in
        1)
            antman
            ;;
        2)
            giantman
            ;;
        3)
            feature
            ;;
        4)
            draw_help
            ;;
    esac
}

username="$USER"
cd pwd
make re
Window
