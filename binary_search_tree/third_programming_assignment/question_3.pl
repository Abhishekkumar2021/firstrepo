sub similarity_percentage{#function for seeing similarity percentage
    my ($word, $possible_word) = @_;# arguement for function 
    @sprtcrw= split("",$word);#splitting word in character
    @sprtcrpsb = split("", $possible_word);#splitting possible word  in character
    $word_size = @sprtcrw;#size of seperate characters from word
    $possible_size = @sprtcrpsb;#size of seperate character from possible word

    $count = 0;
    for($i=0; $i < $word_size;$i++){
        $flag = 0;
        $to_search = $sprtcrw[$i];
        for($j=0; $j< $possible_size;$j++){
           $to_match = $sprtcrpsb[$j];
            if(ord($to_search) == ord($to_match) || ord($to_search) == ord(uc $to_match)){
                $flag = 1;
            }
        }
        if($flag == 1){
            $count++;
        }
    }
    $sum = $word_size + $possible_size;
    if($sum > 0){
        return $count*200/$sum;#returning the percentage of matching
    }
    else{
        return 0;
    }
}

@correct_words = ('All','great','men','have','been','taught','to','read','and','write','at','their','schools.','It','is','our','school','that','endows','us','with','the','right','values','at','an','early','age.','We','teach','a','set','of','strong','moral','values','that','serve','us','later','in','our','lives.','School','life','is','the','period','that','makes','up','most','of','your','childhood','memories.','We','learn','to','laugh,','cry,','share,','and','support','by','co-habiting','with','our','classmates.','Schools','are','the','framework','that','builds','our','moral','characters','and','serves','as','a','pathway','that','we','must','follow','to','achieve','our','dreams.''The','initial','years','pass','like','a','breeze','and','are','the','best','years','of','our','school','life','but,','the','advanced','grades','teach','us','that','life','is','not','always','easy.','We','fail','in','tests,','we','stay','awake','at','nights','to','finish','assignments,','we','get','scolded','by','teachers,','but','most','importantly,','we','learn','how','to','cope','up','with','the','hardships','that','life','throws','at','us.','Schools','have','a','tremendous','responsibility','in','shaping','the','minds','of','millions','of','young','minds','that','are','as','soft','as','wet','mud.','The','teachers','are','excellent','potters','who','mold','us','so','that','the','resultant','figure','is','ready','to','bear','the','weight','of','life','without','cracking.','Even','if','the','later','stages','of','school','life','feel','like','a','burden,','we','must','remember','that','our');

print "Enter a line  !\n";

$line = <STDIN>;

@seperate_words = split(' ', $line);

$seperate_words_size = $#seperate_words + 1;#size of input array

$correct_array_size = $#correct_words + 1;#size of array stored in file 

for($m=0; $m< $seperate_words_size; $m++){
    $num = 1;
    print "suggestions for ($seperate_words[$m]) are :\n";
    for($n=0; $n< $correct_array_size; $n++){
        $percentage = similarity_percentage($seperate_words[$m],$correct_words[$n]);#taking similarity percentage in variavle
        if($percentage>=85){#if similarity matches more than 85% then enter into this
            print "$num. ($correct_words[$n]) Is this suggestion correct? (y/n)\n";
            $num++;
            $choice = <STDIN>;#taking user'schoice for the suggestion
            if(ord($choice) == ord('y')){
                $seperate_words[$m]=$correct_words[$n];
                $n=$correct_array_size;
            }
        }
    }
}
print "Your corrected line is : ";#printing corrected line
for($t=0; $t<$seperate_words_size; $t++){
    print "$seperate_words[$t] ";
}