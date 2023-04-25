#!/bin/bash
NBR_COUNT=7
##
NBR=$(seq 1 $NBR_COUNT | sort -R | tr '\n' ' ' | rev | cut -c 2- | rev)
#NBR="2 1 3 4 5 0 -2"
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