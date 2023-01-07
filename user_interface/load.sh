# Affiche une barre de chargement animée
# $1 : texte à afficher avant la barre de chargement
# $2 : nombre d'itérations
# $3 : durée de chaque itération en secondes
.././antman/antman decompress.txt 1 > compress.txt
################## \\ Option Compression/Decompression //#########################
Load_decompress_opt3() {
    {
        i="0"
        while (true)
        do
            sleep 1
            echo $i
            i=$(expr $i + 50)
            if [[ $i -eq 100 ]]; then break; fi
        done
        sleep 2
        exit 1
    } | whiptail --title "Giantman" --gauge "Loading.." 8 78 0
    show_percentage
}

Load_compress_opt3() {
    {
        i="0"
        while (true)
        do
            sleep 1
            echo $i
            i=$(expr $i + 50)
            if [[ $i -eq 100 ]]; then break; fi
        done
        sleep 2
        exit 1
    } | whiptail --title "Antman" --gauge "Loading.." 8 78 0
    Load_decompress_opt3
}

show_percentage() {
    fileName="compress.txt"
    mysize=$(find "$fileName" -printf "%s")

    fileName2="decompress.txt"
    mysize2=$(find "$fileName2" -printf "%s")

    percentage=$((($mysize * 100) / $mysize2))
    percentage=$((100 - $percentage))

    size1="${fileName} size is ${mysize} bytes."
    size2="${fileName2} size is ${mysize2} bytes."
    size_final="The size of our magnific program after decompression is $percentage"
    whiptail --title "Pourcentage" --msgbox "$size1\n$size2\n$size_final %" 10 78
    Window
}
################## \\ END Option Compression/Decompression //#########################

################## \\ Option Compression //#########################
draw_message_antman() {
    whiptail --title "Status Compression" --msgbox "Compression Finish" 8 78
    Window
}

Load_antman() {
    {
        i="0"
        while (true)
        do
            sleep 1
            echo $i
            i=$(expr $i + 50)
            if [[ $i -eq 100 ]]; then break; fi
        done
        sleep 2
        exit 1
    } | whiptail --title "Antman" --gauge "Loading.." 8 78 0
    draw_message_antman
}

antman() {
    local text=$(whiptail --title "Filepath" --inputbox "Entered path of file to encrypt:" 8 78 3>&1 1>&2 2>&3)
    whiptail --title "Filepath" --msgbox "Your path is : $text" 8 78
    Load_antman
}
################## \\ END Option Compression //#########################

################## \\ Option Decompression //#########################
draw_message_giantman() {
    whiptail --title "Status Compression" --msgbox "Compression Finish" 8 78
    Window
}

Load_giantman() {
    {
        i="0"
        while (true)
        do
            sleep 1
            echo $i
            i=$(expr $i + 50)
            if [[ $i -eq 100 ]]; then break; fi
        done
        sleep 2
        exit 1
    } | whiptail --title "Giantman" --gauge "Loading.." 8 78 0
    draw_message_giantman
}

giantman() {
    local text=$(whiptail --title "Filepath" --inputbox "Entered path of file to encrypt:" 8 78 3>&1 1>&2 2>&3)
    whiptail --title "Filepath" --msgbox "Your path is : $text" 8 78
    Load_giantman
}
################## \\ END Option Decompression //#########################

################## \\ Option Help //#########################
draw_help() {
    ligne1="                  Welcolme on the help system"
    ligne2="-> Option 1 for Antman"
    ligne3="-> Option 2 for Giantman"
    ligne4="-> Option 3 for Antman and Giantman"
    ligne5="-> Option 4 for help system"
    ligne6="a"
    ligne7="b"
    ligne8="c"
    ligne9="d"
    ligne10="e"
    whiptail --title "Message" --msgbox "$ligne1\n$ligne2\n$ligne3\n$ligne4\n$ligne5\n$ligne6\n$ligne7\n$ligne8\n$ligne9\n$ligne10\n" 20 70
    Window
}
################## \\ END Option Help //#########################
Window() {
    choice=$(whiptail --title "Antman Project" --menu "Menu" 15 60 4 \
        "1" "Compression" \
        "2" "Decompression" \
        "3" "Compression/Decompression" \
        "4" "Press this for help" 3>&1 1>&2 2>&3)
    case $choice in
        1)
            antman
            ;;
        2)
            giantman
            ;;
        3)
            Load_compress_opt3
            ;;
        4)
            draw_help
            ;;
    esac
}

Window
