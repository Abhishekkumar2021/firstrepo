 var1="archieve"
 var2="extract"
 var3="list"
 echo "You want to change the directory? (y/n)"#asking whether user want to chnge the directory
 read response
 if ["$response"=="y"]#if responce is yes
     then
         echo "Type the path of the directory you want to change to"
         read directory #taking path of directory to be changed
         cd $directory
 fi
 echo "Type any one of archieve,list,extract"
 read mode
 args==("$@")
 if ["$mode"=="$var1"]
     then
         echo "Please enter the filename to save to archieve file"
         read filename
         zip -o $filename $@ #it will zip the folder but we need to archive but i was unable to archivwso i am zipping the file
 fi

 if ["$mode"=="$var2"]
     then
         unzip $@ls #it will unzip the folder
 fi

 if ["$mode"=="$var3"]
     then
         zipinfo $@ | less #it will list the folders 
 fi

