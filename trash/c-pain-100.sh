#!/bin/bash
NBR_COUNT=100
##
NBR=$(seq 1 $NBR_COUNT | sort -R | tr '\n' ' ' | rev | cut -c 2- | rev)
#NBR="1502557360 -470646489 -684269179 -337500178 -1155889529 -466687375 -1118322647 1137291873 -465052512 -1342795899 -758153880 -1542406850 1974492363 751554036 -2093060848 -2106591680 -1357512995 1943161269 -1977124046 1499095247 1245147913 1027257904 -1103634933 1531865208 -1856512224 502950504 374512980 221703436 1493991068 -2008932933 806344182 -895827383 105863299 1702566496 -93371826 -100747993 -980207391 2141614420 -486310757 -1773061586 -134564047 1259852608 -1032457419 -1115290180 56482219 1999207772 -846497578 -445626750 1557560336 1797455789 -342235213 2110330557 -2057515839 1056210962 -1618216311 32868295 1562646029 1817434088 2147452372 -2083752020 -1354594474 -61673655 -1609147700 -1962077264 -285156574 -82392814 -2011449803 115368753 639991499 788557924 1788147732 1341853250 -753758352 -1487913075 -446560654 58225927 -9907160 -5467374 1761655637 -1711879084 -1120834716 -1149363229 1316950781 -2128472687 1768068515 -601494650 764371536 848863695 1947808545 1838167035 1936645317 788475174 -1432909358 -1443956784 2014406236 -2131371613 719501847 200261684 -1931927214 1426909950"
#NBR=$(seq 1 $NBR_COUNT | tr '\n' ' ' | rev | cut -c 2- | rev)
CMD=$( ./push_swap $NBR)
NBR_LINK=$( echo "$NBR" | tr ' ' ',' )
CMD_LINK=$( echo "$CMD" | sed -e"s/rra/g/g" -e"s/rrb/h/g" \
-e"s/rrr/i/g" -e"s/sa/a/g" -e"s/sb/b/g" -e"s/ss/c/g" \
-e"s/ra/d/g" -e"s/rb/e/g" -e"s/rr/f/g"  -e"s/pa/j/g" -e"s/pb/k/g" | tr -d '\n')
CMD_COUNT=${#CMD_LINK}
RESULT=$( echo $CMD | ./checker $NBR )
echo "Operations: $CMD_COUNT"
echo "Result $RESULT"
open "https://bluegales.github.io/push-swap-pain/?&nbr=$NBR_LINK&cmd=$CMD_LINK"