<?php  
$date1 = new DateTime('2012-06-01 02:12:51');  
$date2 = $date1->diff(new DateTime('2014-05-12 11:10:00'));  
echo $date2->days.' Total days<br>';  
echo $date2->y.' years<br>';  
echo $date2->m.' months<br>';  
echo $date2->d.' days<br>';  
echo $date2->h.' hours<br>';  
echo $date2->i.' minutes<br>';  
echo $date2->s.' seconds<br>';  
?>  