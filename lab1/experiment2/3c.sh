present_date=$(date +"%s")
date_logged=`who am i | tr -s ' ' | cut -d ' '  -f 3`
time_logged=`who am i | tr -s ' ' | cut -d ' '  -f 4`
temp="$date_logged $time_logged"
past_date=`date -d "$temp" +"%s"`

diff=$(($present_date-$past_date))

echo "$(($diff / 3600)) hours and $((($diff / 60) % 60)) minutes and $((diff % 60)) seconds elapsed"








